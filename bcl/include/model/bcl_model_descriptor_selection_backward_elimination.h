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

#ifndef BCL_MODEL_DESCRIPTOR_SELECTION_BACKWARD_ELIMINATION_H_
#define BCL_MODEL_DESCRIPTOR_SELECTION_BACKWARD_ELIMINATION_H_

// include the namespace header
#include "bcl_model.h"

// include other forward headers - sorted alphabetically
#include "storage/bcl_storage.fwd.hh"
#include "util/bcl_util.fwd.hh"

// includes from bcl - sorted alphabetically
#include "bcl_model_descriptor_selection_interface.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace model
  {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class DescriptorSelectionBackwardElimination
    //! @brief class for sequential feature backward elimination
    //! @details this class performs sequential feature backward eliminatiom given an initial and total set of descriptors.
    //!          the initial set of descriptors determines the current round in the selection process.
    //!
    //! @see @link example_model_descriptor_selection_backward_elimination.cpp @endlink
    //! @author butkiem1
    //! @date May 31, 2011
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API DescriptorSelectionBackwardElimination :
      public DescriptorSelectionInterface
    {

    private:

    //////////
    // data //
    //////////

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    public:

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief Clone function
      //! @return pointer to new DescriptorSelectionBackwardElimination
      DescriptorSelectionBackwardElimination *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief get a short name for this class
      //! @return a short name for this class
      const std::string &GetAlias() const;

      //! @brief returns class name of the object behind a pointer or the current object
      //! @return the class name
      const std::string &GetClassIdentifier() const
      {
        return GetStaticClassName( *this);
      }

      //! @brief get default initialized descriptor set
      //! @param TOTAL descriptor set with all available descriptor groups
      //! @return initialized descriptor set
      util::ObjectDataLabel GetInitialDescriptorSet( const util::ObjectDataLabel &TOTAL) const
      {
        return TOTAL;
      }

    ////////////////
    // operations //
    ////////////////

    ///////////////
    // operators //
    ///////////////

      //! @brief assemble all descriptor combinations based on an initial and a total descriptor set as an object label
      //! @param INITIAL initial descriptor set as an object label
      //! @param TOTAL all available descriptor groups in descriptor selection process
      //! @return container with all possible descriptor combinations based on initial descriptor set
      const storage::Vector< util::ObjectDataLabel> operator()
      (
        const util::ObjectDataLabel &INITIAL,
        const util::ObjectDataLabel &TOTAL
      ) const;

    //////////////////////
    // input and output //
    //////////////////////

    //////////////////////
    // helper functions //
    //////////////////////

    protected:

      //! @brief return parameters for member data that are set up from the labels
      //! @return parameters for member data that are set up from the labels
      io::Serializer GetSerializer() const;

    }; // class DescriptorSelectionBackwardElimination

  } // namespace model
} // namespace bcl

#endif // BCL_MODEL_DESCRIPTOR_SELECTION_BACKWARD_ELIMINATION_H_
