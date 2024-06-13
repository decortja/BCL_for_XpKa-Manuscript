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
#include "descriptor/bcl_descriptor_positional.hpp"

// includes from bcl - sorted alphabetically
#include "biol/bcl_biol_aa_base.h"
#include "biol/bcl_biol_mutation.h"
#include "chemistry/bcl_chemistry_atom_conformational_interface.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace descriptor
  {

    // anonymous namespace to prevent namespace pollution
    namespace
    {
      //! add all implementations of interset
      template< typename t_DataType, typename t_ReturnType>
      util::SiPtr< const util::ObjectInterface> AddInstances()
      {
        util::SiPtr< const util::ObjectInterface> result;
        const size_t max_dimensions( 4);
        for( size_t i( 0); i < max_dimensions; ++i)
        {
          result =
            *util::Enumerated< Base< t_DataType, t_ReturnType> >::AddInstance
            (
              new Positional< t_DataType, t_ReturnType>( i)
            );
        }
        return result;
      }
    }
     // instantiate s_Instance
    template< typename t_DataType, typename t_ReturnType>
    const util::SiPtr< const util::ObjectInterface> Positional< t_DataType, t_ReturnType>::s_Instance
    (
      AddInstances< t_DataType, t_ReturnType>()
    );

    template class BCL_API Positional< chemistry::AtomConformationalInterface, char>;
    template class BCL_API Positional< chemistry::AtomConformationalInterface, float>;
    template class BCL_API Positional< biol::AABase, char>;
    template class BCL_API Positional< biol::AABase, float>;
    template class BCL_API Positional< biol::Mutation, float>;
    template class BCL_API Positional< biol::Mutation, char>;
    template class BCL_API Positional< char, char>;
    template class BCL_API Positional< char, float>;

  } // namespace descriptor
} // namespace bcl
