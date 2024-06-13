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

#ifndef BCL_SCORESTAT_LOOP_ANGLE_H_
#define BCL_SCORESTAT_LOOP_ANGLE_H_

// include the namespace header
#include "bcl_scorestat.h"

// include other forward headers - sorted alphabetically

// includes from bcl - sorted alphabetically
#include "assemble/bcl_assemble_analyze_protein_ensemble_interface.h"
#include "assemble/bcl_assemble_protein_model.h"
#include "math/bcl_math_histogram.h"
#include "storage/bcl_storage_table.h"
#include "storage/bcl_storage_vector.h"

namespace bcl
{
  namespace scorestat
  {
    /////////////////////////////////////////////////////////////////////
    //!
    //! @class LoopAngle
    //! @brief extracts loop angle statistics from protein models
    //!
    //! @see @link example_loop_angle.cpp @endlink
    //! @author putnamdk
    //! @date Nov 1, 2014
    //////////////////////////////////////////////////////////////////////

    class BCL_API LoopAngle :
      public assemble::AnalyzeProteinEnsembleInterface
    {

    public:

        //! Constants
        enum
        {
          s_DefaultNumberBinsX = 50,
          s_DefaultNumberBinsY = 20
        };

        //! output options
        enum OutputOption
        {
          e_NormalizedByCount,
          e_NormalizedByColumn,
          e_Log,
          e_Raw,
          e_Table,
          s_NumberOutputOptions
        };

        //! @brief OutputOption as string
        //! @param OutputOption the OutputOption
        //! @return the string for the OutputOption
        static const std::string &GetOutputOptionName( const OutputOption &OUTPUT_OPTION);

        //! @brief Output filename as string
        //! @param OutputOption the desired Output Type
        //! @return the string for the output file extension
        static const std::string &GetOutputFileName( const OutputOption &OUTPUT_OPTION);

        //! @brief OutputOptionEnum enum I/O helper
        typedef util::WrapperEnum< OutputOption, &GetOutputOptionName, s_NumberOutputOptions> OutputOptionEnum;

    private:

    //////////
    // data //
    //////////

      //! output options
      OutputOptionEnum m_OutputOption;

      //! Chains to use for analysis
      std::string m_Chains;

      //! Flag to output model for visualization
      bool m_VisualizationFlag;

    public:

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      LoopAngle();

      //! @brief virtual copy constructor
      LoopAngle *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const;

      //! @brief gives the string to append to the the end of a filename to identify this analysis
      //! @return gives the string to append to the the end of a filename to identify this analysis
      const std::string &GetOutFilePostfix() const;

      //! @brief returns the name used for this class in an object data label
      //! @return the name used for this class in an object data label
      const std::string &GetAlias() const;

    ///////////////
    // operators //
    ///////////////

      //! @brief takes an ensemble and does an analysis resulting in string containing formatted information
      //! @param ENSEMBLE the ensemble that will be analyzed
      //! @return string which has the analyzed information about the ensemble
      std::string operator()( const assemble::ProteinEnsemble &ENSEMBLE) const;

    protected:

    //////////////////////
    // helper functions //
    //////////////////////

      //! @brief return parameters for member data that are set up from the labels
      //! @return parameters for member data that are set up from the labels
      io::Serializer GetSerializer() const;

    }; // end class LoopAngleStatistics
  } // namespace scorestat
} // namespace bcl

#endif // BCL_SCORESTAT_LOOP_ANGLE_H_