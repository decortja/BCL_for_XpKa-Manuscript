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

// initialize the static initialization fiasco finder, if macro ENABLE_FIASCO_FINDER is defined
#include "util/bcl_util_static_initialization_fiasco_finder.h"
BCL_StaticInitializationFiascoFinder

// include header of this class
#include "chemistry/bcl_chemistry_molecular_constitution_shared.h"

// includes from bcl - sorted alphabetically

// external includes - sorted alphabetically

namespace bcl
{
  namespace chemistry
  {

  //////////////////////////////////
  // construction and destruction //
  //////////////////////////////////

    //! @brief default constructor
    MolecularConstitutionShared::MolecularConstitutionShared()
    {
    }

    //! @brief constructor given atoms with conformation and molecule configuration
    //! @params CONSTITUTION atom constitution objects
    MolecularConstitutionShared::MolecularConstitutionShared
    (
      const AtomVector< AtomConstitutionalShared> &CONSTITUTION
    ) :
      FragmentConstitutionShared( CONSTITUTION)
    {
      for
      (
        AtomVector< AtomConstitutionalShared>::const_iterator
          itr( CONSTITUTION.Begin()), itr_end( CONSTITUTION.End());
        itr != itr_end;
        ++itr
      )
      {
        BCL_Assert( itr->GetValenceBonds().GetSize() == 0, " Molecule should have satisfied valence");
      }
    }

    //! @brief constructor with a conformation interface
    //! @params CONFORMATION conformation interface
    MolecularConstitutionShared::MolecularConstitutionShared( const ConformationInterface &CONFORMATION)
      : FragmentConstitutionShared( CONFORMATION)
    {
      for
      (
        iterate::Generic< const AtomConstitutionalInterface> itr( GetAtomsIterator());
        itr.NotAtEnd();
        ++itr
      )
      {
        BCL_Assert( itr->GetValenceBonds().GetSize() == 0, " Molecule should have satisfied valence");
      }
    }

    //! @brief Clone function
    //! @return pointer to new MolecularConstitutionShared
    MolecularConstitutionShared *MolecularConstitutionShared::Clone() const
    {
      return new MolecularConstitutionShared( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief returns class name of the object behind a pointer or the current object
    //! @return the class name
    const std::string &MolecularConstitutionShared::GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

    //! @brief read from std::istream
    //! @param ISTREAM input stream
    //! @return istream which was read from
    std::istream &MolecularConstitutionShared::Read( std::istream &ISTREAM)
    {

      return ISTREAM;
    }

    //! @brief write to std::ostream
    //! @param OSTREAM output stream to write to
    //! @param INDENT number of indentations
    //! @return output stream which was written to
    std::ostream &MolecularConstitutionShared::Write( std::ostream &OSTREAM, const size_t INDENT) const
    {

      return OSTREAM;
    }

    // define s_Instance
    const util::SiPtr< const util::ObjectInterface> MolecularConstitutionShared::s_Instance
    (
      GetObjectInstances().AddInstance( new MolecularConstitutionShared())
    );

  } // namespace chemistry
} // namespace bcl
