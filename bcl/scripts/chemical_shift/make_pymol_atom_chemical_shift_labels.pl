#!/usr/bin/perl 
use Getopt::Long;

sub label_state
{
  # get arguments
  ( my $state, my $c_actual_spectrum_line, my $c_predicted_spectrum_line) = @_;
  
  # constants
  my $vdw_min = 0.35; # radius of bond stick 
  my $vdw_max = 1.0; # can be changed to have a larger effect
  
  # store script for creating labels
  my $labels = "";  
  
  # split actual spectrum into signals
  @c_actual_spectrum = split( /\|/, $c_actual_spectrum_line);
  @c_predicted_spectrum = split( /\|/, $c_predicted_spectrum_line);
  
  print "actual 13C: @c_actual_spectrum\n" if( defined $verbose);
  print "predicted 13C: @c_predicted_spectrum\n" if( defined $verbose);

  ## create label
  %actual_shifts = ();
  for my $atom ( @c_actual_spectrum)
  {
    my @current = split( /\;/, $atom);
    if( $#current < 2)
    {
      next;
    }
    $actual_shifts{ $current[2]} = $current[ 0];
  }
  %predicted_shifts = ();
  for my $atom ( @c_predicted_spectrum)
  {
    my @current = split( /\;/, $atom);
    if( $#current < 2)
    {
      next;
    }
    $predicted_shifts{ $current[2]} = $current[ 0];
  } 
  
  # number deviations
  my $number_deviations = 0;
  for my $id ( sort keys( %predicted_shifts))
  {
    my $missing_shift = 0;
    my $predicted_shift = $predicted_shifts{ $id};
    my $actual_shift = 0;
    if( exists( $actual_shifts{ $id}))
    {
      $actual_shift = $actual_shifts{ $id};
    }
    else
    {
      $actual_shift = $predicted_shift;
      $missing_shift = 1;
    }
    my $diff = abs( $actual_shift - $predicted_shift);
    my $current_selection = "id ".( $id + 1)." and state ".$state;
    
    # label string
    if( $missing_shift)
    {
      $labels .= "label ".$current_selection.", \"p: ".$predicted_shift."\"\n";
    }
    elsif( $diff == 0)
    {
      $labels .= "label ".$current_selection.", \"ap: ".$actual_shift."\"\n";
    }
    else
    {
      $labels .= "label ".$current_selection.", \"a: ".$actual_shift." p: ".$predicted_shift."\"\n";
    }
    
    # label color and atom highlighting
    if( $missing_shift)
    {
      # change label appearence
      $labels .= "set label_color, green, ".$current_selection."\n";
    }
    elsif( $max_deviation < $diff)
    {
      # change label appearence
      $labels .= "set label_color, red, ".$current_selection."\n";

      # change atom appearence
      my $ddiff = $diff - $max_deviation;
      my $deviation_reduced = $ddiff / ( $max_deviation);
      # min 
      $deviation_reduced = ($deviation_reduced, 1.0)[ $deviation_reduced > 1.0];
      my $vdw = $vdw_min + $deviation_reduced * ($vdw_max - $vdw_min);
      
      # atoms as speher with radius as a function of the deviation from the max
      $labels .= "show spheres, ".$current_selection."\n";
      $labels .= "color grey, ".$current_selection."\n";
      $labels .= "alter molecule and ".$current_selection.", vdw=".$vdw."\n";
      ++$number_deviations;
    }
  }
  
  # do not label, if there is no large enough deviation
  if( $skip_max && $number_deviations == 0)
  {
    $labels = "";
  }
  
  return $labels;
}

@possible_spec_types = ( "13C", "1H");

## form the usage string
$usage =
"
usage:  

\t one sdf file containing multiple molecules can be given. From the \"> <Spectrum {type} 0>\" mdl misc property as
\t long as it is NMRShiftDB conform, the atom chemical shift labels are generated by labeling the atoms with the shift,
\t coloring violations and drawing spheres which radius if a function of the magnitude of the violation.

\t-sdf                 \tthe mdl file to generate labels for (as full path)
\t-m or -max_deviation \tmax ppm deviation to be colored differently
\t-t ot -type          \ttype of spectra {".join( ", ", @possible_spec_types)."}
\t-o or -output        \tfolder for output files molecules.sdf and molecules.pml
\t-s or -skip          \tskip molecules that do not have at least one atom with the given maximal chemical shift deviation
\t-h or -help          \tdisplay help
\t-v or -verbose       \tverbose mode\n\n

author\t Nils Woetzel, Ralf Mueller
date\t 05/12/2011\n
";

## initialize command line variables
$mdl;
$max_deviation = 10000;
$spec_type = "13C";
$output_path = ".";
$skip_max;
$verbose;
$help;

## print help and die if no arguments were given
die $usage if( $#ARGV == -1);

## set the options
$cl_check = GetOptions
(
  "mdl=s"             => \$mdl,
  "max_deviation|m:f" => \$max_deviation,
  "t|type=s"          => \$spec_type,
  "o|output=s"        => \$output_path,
  "s|skip"            => \$skip_max,
  "h|help"            => \$help,
  "v|verbose"         => \$verbose
);

if( defined $verbose)
{
  ## display all variables
  print "mdl_file|".$mdl."|\n";
  print "h|help|".$help."|\n";
  print "v|verbose|".$verbose."|\n";
}

die $usage if defined $help;
die $usage if( !$cl_check);
die $usage if( !grep { $_ eq $spec_type} @possible_spec_types);

## open the mdl file and find the spectra
open( MDL, $mdl) or die "given mdl file \"$mdl\" does not exist!\n";
$script_file = $output_path."/molecules.pml";
open( SCRIPT, ">".$script_file) or die "cannot open $script_file for writing!\n";
$sdf_file = $output_path."/molecules.sdf";
open( SDF, ">".$sdf_file) or die "cannot open $sdf_file for writing!\n";

print SCRIPT "#loading mdl/sdf file\n";
print SCRIPT "load ".$sdf_file.", molecule\n\n";
#print SCRIPT "alter molecule, vdw=0.75\n";
#print SCRIPT "set label_color, red\n";
print SCRIPT "set label_size, -0.5\n";
print SCRIPT "show sticks\n";
print SCRIPT "set valence, 1\n";

print SCRIPT "# adding labels to atoms\n";

$state = 1;
%spectra = ();
$current_mdl = "";
while( my $line = <MDL>)
{
  $current_mdl .= $line;
  if( $line =~ /.+Spectrum $spec_type.+/)
  {
    my $current_spectra_line = <MDL>;
    $spectra{ $line} = $current_spectra_line;
    $current_mdl .= $current_spectra_line;
  }
  
  if( $line =~ /\$\$\$\$/)
  {
    my @spectra_names = sort( keys( %spectra));
    if( $#spectra_names < 1)
    {
      print "no spectra available for state $state\n" if( defined $verbose);      
    }
    else
    {
      my $c_actual_spectrum = $spectra{ $spectra_names[ 0]};
      my $c_predicted_spectrum = $spectra{ $spectra_names[ $#spectra_names]};
      
      my $labels = label_state( $state, $c_actual_spectrum, $c_predicted_spectrum);
      if( length( $labels))
      {
        print "created lables for $state\n" if( defined $verbose);
        print SCRIPT $labels."\n";
        print SDF $current_mdl;
        ++$state;
      }
    }
    %spectra = ();
    $current_mdl = "";
  }
}

close( SCRIPT);
close( MDL);

print "inserted ".( $state - 1)." molecules into $sdf_file\n";