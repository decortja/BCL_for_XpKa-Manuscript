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

#ifndef BCL_FOLD_MUTATE_PROTEIN_MODEL_REPLICATE_CONFORMATION_H_
#define BCL_FOLD_MUTATE_PROTEIN_MODEL_REPLICATE_CONFORMATION_H_

// include the namespace header
#include "bcl_fold.h"

// include other forward headers - sorted alphabetically
#include "assemble/bcl_assemble.fwd.hh"
#include "math/bcl_math.fwd.hh"
#include "util/bcl_util.fwd.hh"

// includes from bcl - sorted alphabetically
#include "find/bcl_find_collector_interface.h"
#include "math/bcl_math_mutate_interface.h"
#include "util/bcl_util_sh_ptr.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace fold
  {
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class MutateProteinModelReplicateConformation
    //! @brief TODO: add a brief comment
    //! @details TODO: add an detailed description to this class
    //!
    //! @see @link example_fold_mutate_protein_model_replicate_conformation.cpp @endlink
    //! @author alexanns
    //! @date May 1, 2012
    //!
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API MutateProteinModelReplicateConformation :
      public math::MutateInterface< assemble::ProteinModel>
    {

    private:

    //////////
    // data //
    //////////

      //! method for collecting the conformations of the protein model that should be replicated
      util::ShPtr
      <
        find::CollectorInterface< util::SiPtrList< const assemble::ProteinModel>, assemble::ProteinModel>
      > m_ConformationCollector;

      //! number of times each collected conformation should be copied
      int m_NumberReplications;

      //! scheme
      std::string m_Scheme;

    public:

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      MutateProteinModelReplicateConformation();

      //! @brief constructor taking parameters
      //! @param LOCATOR the method for locating the conformation to replicate
      //! @param NUMBER_REPLICATIONS the number of times each collected conformation should be copied
      //! @param SCHEME Scheme to be used
      MutateProteinModelReplicateConformation
      (
        const util::ShPtr
        <
          find::CollectorInterface< util::SiPtrList< const assemble::ProteinModel>, assemble::ProteinModel>
        > &CONFORMATION,
        int NUMBER_REPLICATIONS,
        const std::string &SCHEME = GetStaticClassName< MutateProteinModelReplicateConformation>()
      );

      //! @brief Clone function
      //! @return pointer to new MutateProteinModelReplicateConformation
      MutateProteinModelReplicateConformation *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const;

      //! @brief gets the scheme for this mutate
      //! @return the scheme for this mutate
      const std::string &GetScheme() const
      {
        return m_Scheme;
      }

    ////////////////
    // operations //
    ////////////////

    ///////////////
    // operators //
    ///////////////

      //! @brief virtual operator taking an ARGUMENT and returning a mutate object of t_ArgumentType
      //! @param PROTEIN_MODEL protein model interest
      //! @return MutateResult with ProteinModel after the mutate
      math::MutateResult< assemble::ProteinModel> operator()( const assemble::ProteinModel &PROTEIN_MODEL) const;

    //////////////////////
    // input and output //
    //////////////////////

    protected:

      //! @brief read from std::istream
      //! @param ISTREAM input stream
      //! @return istream which was read from
      std::istream &Read( std::istream &ISTREAM);

      //! @brief write to std::ostream
      //! @param OSTREAM outputstream to write to
      //! @param INDENT number of indentations
      //! @return outputstream which was written to
      std::ostream &Write( std::ostream &OSTREAM, const size_t INDENT) const;

    //////////////////////
    // helper functions //
    //////////////////////

    private:

    }; // class MutateProteinModelReplicateConformation

  } // namespace fold
} // namespace bcl

#endif // BCL_FOLD_MUTATE_PROTEIN_MODEL_REPLICATE_CONFORMATION_H_ 
