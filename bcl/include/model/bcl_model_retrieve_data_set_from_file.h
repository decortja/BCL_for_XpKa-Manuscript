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

#ifndef BCL_MODEL_RETRIEVE_DATA_SET_FROM_FILE_H_
#define BCL_MODEL_RETRIEVE_DATA_SET_FROM_FILE_H_

// include the namespace header
#include "bcl_model.h"

// include other forward headers - sorted alphabetically

// includes from bcl - sorted alphabetically
#include "bcl_model_data_set_select_columns.h"
#include "bcl_model_retrieve_data_set_base.h"
#include "math/bcl_math_range_set.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace model
  {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class RetrieveDataSetFromFile
    //! @brief retrieve data sets from a file
    //!
    //! @see @link example_model_retrieve_data_set_from_file.cpp @endlink
    //! @author mendenjl
    //! @date Jan 29, 2011
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API RetrieveDataSetFromFile :
      public RetrieveDataSetBase
    {
    private:

    //////////
    // data //
    //////////

      std::string m_Filename;                //!< file from which the data set can be retrieved
      size_t m_NumberChunks;                 //!< split the file into this many parts, to retrieve the chunks specified
      math::RangeSet< size_t> m_ChunkRanges; //!< ranges of chunks to extract from the file
      DataSetSelectColumns    m_Features;    //!< Feature columns that will be selected
      DataSetSelectColumns    m_Results;     //!< Result columns that will be selected

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    public:

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      //! @param FILENAME the file to retrieve the data set from
      //! @param NUMBER_CHUNKS # of chunks the file should be split into (conceptually), used to divide the file into disparate datasets
      //! @param CHUNKS chunks to load
      RetrieveDataSetFromFile
      (
        const std::string &FILENAME = std::string(),
        const size_t &NUMBER_CHUNKS = 1,
        const math::RangeSet< size_t> &CHUNKS = math::RangeSet< size_t>()
      );

      //! @brief Clone function
      //! @return pointer to new RetrieveDataSetFromFile
      RetrieveDataSetFromFile *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name of the object behind a pointer or the current object
      //! @return the class name
      const std::string &GetClassIdentifier() const;

      //! @brief returns the name used for this class in an object data label
      //! @return the name used for this class in an object data label
      const std::string &GetAlias() const;

      //! @brief Get the code / label set for the feature (1st part) of the data set with sizes of each property
      //! @return the code / label for the feature (1st part) of the data set with sizes of each property
      //! the feature code set
      FeatureLabelSet GetFeatureLabelsWithSizes() const;

      //! @brief Get the code / label for the result (2nd part) of the data set with sizes of each property
      //! @return the code / label for the result (2nd part) of the data set with sizes of each property
      //! the feature code set
      FeatureLabelSet GetResultCodeWithSizes() const;

      //! @brief Get the code / label for the ids of the data set with sizes of each property
      //! @return the code / label for the ids of the data set with sizes of each property
      //! the feature code set
      FeatureLabelSet GetIdCodeWithSizes() const;

      //! @brief Set the code / label for the feature (1st part) of the data set
      //! @param CODE the new code
      void SelectFeatures( const util::ObjectDataLabel &CODE);

      //! @brief Set the code / label for the result (2nd part) of the data set
      //! @param CODE the new code
      void SelectResults( const util::ObjectDataLabel &CODE);

      //! @brief get the number of partitions requested by the user, along with the partition ids
      //! @return the number of partitions requested by the user, along with the partition ids
      storage::Pair< size_t, math::RangeSet< size_t> > GetNumberPartitionsAndIds() const;

    ////////////////
    // operations //
    ////////////////

      //! @brief generate dataset
      //! @return generated dataset
      util::ShPtr< descriptor::Dataset> GenerateDataSet();

    //////////////////////
    // helper functions //
    //////////////////////

    protected:

      //! @brief return parameters for member data that are set up from the labels
      //! @return parameters for member data that are set up from the labels
      virtual io::Serializer GetSerializer() const;

      //! @brief get the nominal (e.g. best estimate without generating the entire dataset) size of the dataset
      //! @return the nominal (e.g. best estimate without generating the entire dataset) size of the dataset
      virtual size_t GetNominalSize() const;

      //! @brief get the size of the complete dataset without chunking
      //! @return the size of the complete dataset without chunking
      size_t GetTotalDatasetSize() const;

      //! @brief get the sizes of the features and results in the dataset without loading the whole dataset
      //! @return the sizes of the features and results in the dataset without loading the whole dataset
      storage::VectorND< 2, size_t> GetFeatureResultSizes() const;

    }; // class RetrieveDataSetFromFile

  } // namespace model
} // namespace bcl

#endif // BCL_MODEL_RETRIEVE_DATA_SET_FROM_FILE_H_