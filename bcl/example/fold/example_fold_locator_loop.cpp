// (c) Copyright BCL @ Vanderbilt University 2014
// (c) BCL Homepage: http://www.meilerlab.org/bclcommons
// (c) BCL Code Repository: https://github.com/BCLCommons/bcl
// (c)
// (c) The BioChemical Library (BCL) was originally developed by contributing members of the Meiler Lab @ Vanderbilt University.
// (c)
// (c) The BCL is now made available as an open-source software package distributed under the permissive MIT license,
// (c) developed and maintained by the Meiler Lab at Vanderbilt University and contributing members of the BCL Commons.
// (c)
// (c) External code contributions to the BCL are welcome. Please visit the BCL Commons GitHub page for information on how you can contribute.
// (c)
// (c) This file is part of the BCL software suite and is made available under the MIT license.
// (c)

// include example header
#include "example.h"
// include the header of the class which this example is for
#include "fold/bcl_fold_locator_loop.h"

// includes from bcl - sorted alphabetically
#include "io/bcl_io_file.h"
#include "pdb/bcl_pdb_factory.h"
#include "pdb/bcl_pdb_handler.h"

// external includes - sorted alphabetically

namespace bcl
{

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //!
  //! @example example_fold_locator_loop.cpp
  //! @brief this example tests the implementation of fold::LocatorLoop
  //!
  //! @author fischea
  //! @date Dec 20, 2014
  //! @remarks status complete
  //! @remarks reviewed by nobody on
  //!
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  class ExampleFoldLocatorLoop :
    public ExampleInterface
  {

  //////////
  // data //
  //////////

  public:

    //! single instance of this class
    static const ExampleClass::EnumType s_Instance;

  //////////////////////////////////
  // construction and destruction //
  //////////////////////////////////

    //! @brief clone function
    //! @return pointer to a new ExampleFoldLocatorLoop
    ExampleFoldLocatorLoop *Clone() const
    {
      return new ExampleFoldLocatorLoop( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief returns the name of this class
    //! @return the name of this class
    const std::string &GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

  ////////////////
  // operations //
  ////////////////

    //! @brief run routine
    //! this is performing the execution of the example
    int Run() const
    {
      // read in protein model without loop coordinates for testing
      const std::string pdb_file_name( AddExampleInputPathToFilename( e_Fold, "1x91_no_loops.pdb"));
      io::IFStream pdb_file;
      BCL_ExampleMustOpenInputFile( pdb_file, pdb_file_name);
      const pdb::Handler pdb_handler( pdb_file, true);
      const pdb::Factory factory( biol::GetAAClasses().e_AABackBone);
      const assemble::ProteinModel model_no_loops( factory.ProteinModelFromPDB( pdb_handler));
      io::File::CloseClearFStream( pdb_file);

      // read in protein model with some loop coordinates for testing
      const std::string pdb_file_name_2( AddExampleInputPathToFilename( e_Fold, "1x91_some_loop_coords.pdb"));
      io::IFStream pdb_file_2;
      BCL_ExampleMustOpenInputFile( pdb_file_2, pdb_file_name_2);
      const pdb::Handler pdb_handler_2( pdb_file_2, true);
      const assemble::ProteinModel model_some_loops( factory.ProteinModelFromPDB( pdb_handler_2));
      io::File::CloseClearFStream( pdb_file_2);

      // read in protein model with all loop coordinates for testing
      const std::string pdb_file_name_3( AddExampleInputPathToFilename( e_Fold, "1x91.pdb"));
      io::IFStream pdb_file_3;
      BCL_ExampleMustOpenInputFile( pdb_file_3, pdb_file_name_3);
      const pdb::Handler pdb_handler_3( pdb_file_3, true);
      const assemble::ProteinModel model_all_loops( factory.ProteinModelFromPDB( pdb_handler_3));
      io::File::CloseClearFStream( pdb_file_3);

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      // ignore terminal loop regions and find undefined loops
      fold::LocatorLoop locator_1_1;

      // don't ignore terminal loop regions and find undefined loops
      fold::LocatorLoop locator_0_1( false, true);

      // ignore terminal loop regions and find defined loops
      fold::LocatorLoop locator_1_0( true, false);

      // don't ignore terminal loop regions and find defined loops
      fold::LocatorLoop locator_0_0( false, false);

    /////////////////
    // data access //
    /////////////////

      // check class name
      BCL_ExampleCheck( locator_1_1.GetClassIdentifier(), ( GetStaticClassName< fold::LocatorLoop>()));

    ////////////////
    // operations //
    ////////////////

      // test locator_1_1 for a model with no defined loops
      const util::ShPtrVector< fold::LoopParameters> segments_1( locator_1_1.Locate( model_no_loops));
      const util::ShPtr< fold::LoopParameters> &loop_1_1( segments_1.FirstElement());
      BCL_ExampleCheck( segments_1.GetSize(), 5);
      BCL_Example_Check
      (
        loop_1_1->GetAnchors()( 0) == 15 && loop_1_1->GetAnchors()( 1) == 17,
        "loop 1 of model 1 is incorrect"
      );

      // test locator_1_1 for a model with partially defined loops
      const util::ShPtrVector< fold::LoopParameters> segments_2( locator_1_1.Locate( model_some_loops));
      const util::ShPtr< fold::LoopParameters> &loop_1_2( segments_2.FirstElement());
      BCL_ExampleCheck( segments_2.GetSize(), 2);
      BCL_Example_Check
      (
        loop_1_2->GetAnchors()( 0) == 15 && loop_1_2->GetAnchors()( 1) == 20,
        "loop 1 of model 2 is incorrect"
      );

      // test locator_1_1 for a model with all loops defined
      const util::ShPtrVector< fold::LoopParameters> segments_3( locator_1_1.Locate( model_all_loops));
      BCL_ExampleCheck( segments_3.GetSize(), 0);

      // test locator_0_1 for a model with all loops defined
      const util::ShPtrVector< fold::LoopParameters> segments_4( locator_0_1.Locate( model_some_loops));
      BCL_ExampleCheck( segments_4.GetSize(), 4);
      const util::ShPtr< fold::LoopParameters> &loop_4_1( segments_4.FirstElement());
      BCL_Example_Check
      (
        loop_4_1->GetAnchors()( 0) == 1 && loop_4_1->GetAnchors()( 1) == 5,
        "loop 1 of model 4 is incorrect"
      );
      const util::ShPtr< fold::LoopParameters> &loop_4_2( segments_4.LastElement());
      BCL_Example_Check
      (
        loop_4_2->GetAnchors()( 0) == 82 && loop_4_2->GetAnchors()( 1) == 91,
        "loop 4 of model 4 is incorrect"
      );

      // test locator_1_0
      const util::ShPtrVector< fold::LoopParameters> segments_5( locator_1_0.Locate( model_all_loops));
      BCL_ExampleCheck( segments_5.GetSize(), 5);
      const util::ShPtrVector< fold::LoopParameters> segments_6( locator_1_0.Locate( model_no_loops));
      BCL_ExampleCheck( segments_6.GetSize(), 0);

      // test locator_0_0 for a model with all loops defined
      const util::ShPtrVector< fold::LoopParameters> segments_7( locator_0_0.Locate( model_all_loops));
      BCL_ExampleCheck( segments_7.GetSize(), 6);

    //////////////////////
    // input and output //
    //////////////////////

      // write object
      WriteBCLObject( locator_1_1);

      // read object
      fold::LocatorLoop locator_1_1_read;
      ReadBCLObject( locator_1_1_read);

      // compare behavior of read in object to written out object
      const util::ShPtrVector< fold::LoopParameters> segments_read( locator_1_1_read.Locate( model_some_loops));
      const util::ShPtr< fold::LoopParameters> &loop_1_read( segments_read.FirstElement());
      BCL_ExampleCheck( segments_2.GetSize(), segments_read.GetSize());
      BCL_Example_Check
      (
        loop_1_read->GetAnchors()( 0) == 15 && loop_1_read->GetAnchors()( 1) == 20,
        "correctness of the loop"
      );

      return 0;
    }

  }; // class ExampleFoldLocatorLoop

  //! single instance of this class
  const ExampleClass::EnumType ExampleFoldLocatorLoop::s_Instance
  (
    GetExamples().AddEnum( ExampleFoldLocatorLoop())
  );

} // namespace bcl
