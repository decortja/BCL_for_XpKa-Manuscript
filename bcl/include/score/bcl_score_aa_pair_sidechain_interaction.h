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

#ifndef BCL_SCORE_AA_PAIR_SIDECHAIN_INTERACTION_H_
#define BCL_SCORE_AA_PAIR_SIDECHAIN_INTERACTION_H_

// include the namespace header
#include "bcl_score.h"

// include other forward headers - sorted alphabetically
#include "math/bcl_math.fwd.hh"

// includes from bcl - sorted alphabetically
#include "bcl_score_aa_pair_distance.h"
#include "util/bcl_util_implementation.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace score
  {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class AAPairSidechainInteraction
    //! @brief This is a Function derived class for scoring AA pair distances based on their relative side chain orientation
    //!
    //! @see @link example_score_aa_pair_sidechain_interaction.cpp @endlink
    //! @author woetzen
    //! @date 02.03.2006
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API AAPairSidechainInteraction :
      public AAPairDistanceInterface
    {

    private:

    //////////
    // data //
    //////////

      //! scheme to be used in outputting schemes
      std::string m_Scheme;

      //! AAPairDistance object to be used to calculate the score
      util::Implementation< AAPairDistance> m_AAPairDistance;

    public:

    //////////
    // data //
    //////////

      //! single instance of this class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

      //! @brief returns default scheme
      //! @return default scheme
      static const std::string &GetDefaultScheme();

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief constructor from a specified histogram file
      //! @param HISTOGRAM_FILENAME filename of the histogram to be used
      //! @param SCHEME scheme to be used
      AAPairSidechainInteraction
      (
      );

      //! @brief constructor from a specified histogram file
      //! @param HISTOGRAM_FILENAME filename of the histogram to be used
      //! @param SCHEME scheme to be used
      AAPairSidechainInteraction
      (
        const std::string &HISTOGRAM_FILENAME,
        const std::string &SCHEME
      );

      //! @brief virtual copy constructor
      //! @return pointer to a new AAPairDistance object that is copied from this one
      AAPairSidechainInteraction *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const;

      //! @brief gets the scheme for this function class
      //! @return the scheme for this function class
      const std::string &GetScheme() const;

      //! @brief access to the minimal sequence separation
      //! @return minimal sequence separation in sequence distance
      size_t GetMinimalSequenceSeparation() const
      {
        return m_AAPairDistance->GetMinimalSequenceSeparation();
      }

      //! @brief access to the maximal distance that is considered
      //! @return the maximal distance between two amino acids that is scored
      double GetDistanceCutoff() const
      {
        return m_AAPairDistance->GetDistanceCutoff();
      }

      //! @brief are amino acids of different chains considered
      //! @return return true, if amino acid pairs of different chains are considered
      bool GetConsiderDifferentChain() const
      {
        return m_AAPairDistance->GetConsiderDifferentChain();
      }

    ///////////////
    // operators //
    ///////////////

      //! @brief calculate the weighted energy according to distance and AATypes for given amino acid pair
      //! @param AMINO_ACID_A first amino acid of interest
      //! @param AMINO_ACID_B second amino acid of interest
      //! @return the weighted energy according to distance and AATypes for given amino acid pair
      double operator()
      (
        const biol::AABase &AMINO_ACID_A,
        const biol::AABase &AMINO_ACID_B
      ) const;

      //! @brief calculate amino acid pairing potential for given amino acid pair
      //! @param AMINO_ACID_A first amino acid of interest
      //! @param AMINO_ACID_B second amino acid of interest
      //! @param DISTANCE distance between the amino acid pair
      //! @return amino acid pairing potential for given amino acid pair
      double operator()
      (
        const biol::AABase &AMINO_ACID_A,
        const biol::AABase &AMINO_ACID_B,
        const double DISTANCE
      ) const;

    ////////////////
    // operations //
    ////////////////

      //! @brief calculate the weight of interaction for given amino acid pair
      //! @param AMINO_ACID_A first amino acid of interest
      //! @param AMINO_ACID_B second amino acid of interest
      //! @return the weight of interaction for given amino acid pair
      static double WeightOfInteraction
      (
        const biol::AABase &AMINO_ACID_A,
        const biol::AABase &AMINO_ACID_B
      );

      //! @brief calculates a weight for the angle
      //! 0 - 45 returns 0; 45 - 90 is a cos transition to 0; larger 90 returns 0
      //! @param ANGLE_RAD angle in readians
      //! @return calculated weight for the angle
      static double Weight90To45Transition( const double ANGLE_RAD);

    //////////////////////
    // input and output //
    //////////////////////
    protected:

      //! @brief write to ostream
      //! @param OSTREAM is the output stream
      //! @return returns the output stream
      std::ostream &Write( std::ostream &OSTREAM, const size_t INDENT) const;

      //! @brief read from istream
      //! @param ISTREAM is the input stream
      //! @return returns the input stream
      std::istream &Read( std::istream &ISTREAM);

    public:

      //! @brief write the Scheme and the function value for the ARGUMENT to the STREAM
      //! @param AMINO_ACID_A first amino acid of interest
      //! @param AMINO_ACID_B second amino acid of interest
      //! @param OSTREAM the std::ostream to be written to
      //! @return std::ostream which was written to
      std::ostream &
      WriteDetailedSchemeAndValues
      (
        const biol::AABase &AMINO_ACID_A,
        const biol::AABase &AMINO_ACID_B,
        std::ostream &OSTREAM
      ) const;

    //////////////////////
    // helper functions //
    //////////////////////

    }; //class AAPairSidechainInteraction

  } // namespace score
} // namespace bcl

#endif //BCL_SCORE_AA_PAIR_SIDECHAIN_INTERACTION_H_
