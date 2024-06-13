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

// include header of this class
#include "bcl_descriptor_numeric_string.h"
// includes from bcl - sorted alphabetically
#include "bcl_descriptor_iterator.h"
#include "io/bcl_io_file.h"
#include "io/bcl_io_ifstream.h"
#include "io/bcl_io_serialization.h"
#include "linal/bcl_linal_matrix.h"
#include "linal/bcl_linal_vector_reference.h"
#include "storage/bcl_storage_list.h"
#include "type/bcl_type_compare.h"
#include "util/bcl_util_logger_interface.h"
#include "util/bcl_util_string_functions.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace descriptor
  {

  //////////////////////////////////
  // construction and destruction //
  //////////////////////////////////

    //! @brief virtual copy constructor
    template< typename t_DataType>
    NumericString< t_DataType> *NumericString< t_DataType>::Clone() const
    {
      return new NumericString( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief returns class name
    //! @return the class name as const ref std::string
    template< typename t_DataType>
    const std::string &NumericString< t_DataType>::GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

    //! @brief return the data label
    //! @return data label as string
    template< typename t_DataType>
    const std::string &NumericString< t_DataType>::GetAlias() const
    {
      static const std::string s_name( "ToString");
      return s_name;
    }

    //! @brief get the normal dimension for this descriptor
    //! @return the normal dimension for this descriptor
    template< typename t_DataType>
    size_t NumericString< t_DataType>::GetNormalDimension() const
    {
      return m_NumericProperty->GetType().GetDimension();
    }

    //! @brief return the type of symmetry this descriptor has
    //! @return e.g. symmetric if this descriptor returns the same value for A-B as B-A, Asymmetric otherwise
    template< typename t_DataType>
    Type::Symmetry NumericString< t_DataType>::GetSymmetry() const
    {
      return m_NumericProperty->GetSymmetry();
    }

    //! @brief return whether this descriptor is valid if repeated elements are given
    //! @return true if this descriptor is valid if repeated elements are given
    //! This will be the case if the descriptor may have a legitimate value for A-A
    template< typename t_DataType>
    bool NumericString< t_DataType>::ConsiderRepeatedElements() const
    {
      return m_NumericProperty->ConsiderRepeatedElements();
    }

    //! @brief get the feature size under the normal dimension setting (e.g. GetNormalDimension())
    //! @return the feature size, assuming this feature has its normal dimension setting
    template< typename t_DataType>
    size_t NumericString< t_DataType>::GetNormalSizeOfFeatures() const
    {
      return 14 * m_NumericProperty->GetNormalSizeOfFeatures();
    }

  //////////////////////
  // input and output //
  //////////////////////

    //! @brief return parameters for member data that are set up from the labels
    //! @return parameters for member data that are set up from the labels
    template< typename t_DataType>
    io::Serializer NumericString< t_DataType>::GetSerializer() const
    {
      io::Serializer parameters;
      parameters.SetClassDescription
      (
        "Calculates a numeric descriptor and converts it into a string"
      );
      parameters.AddInitializer
      (
        "",
        "data label for a numeric descriptor",
        io::Serialization::GetAgent( &m_NumericProperty)
      );

      return parameters;
    }

  ////////////////
  // operations //
  ////////////////

    //! @brief hook that derived classes can override to add behavior after every time SetObject is called
    template< typename t_DataType>
    void NumericString< t_DataType>::SetObjectHook()
    {
      m_NumericProperty->SetObject( *this->GetCurrentObject());
    }

    //! @brief hook that derived classes can override to add behavior after every time SetDimension is called
    template< typename t_DataType>
    void NumericString< t_DataType>::SetDimensionHook()
    {
      m_NumericProperty->SetDimension( this->GetDimensionSetting());
    }

    //! @brief calculate the descriptors for a given sequence iterator position, ignoring cache
    //! @param ITR sequence iterator pointing to the tuple of sequence elements of interest; will be for the native dimension of the class
    //! @param STORAGE storage for the descriptor
    //! The inheriting class can assume that ITR is of native dimension and that STORAGE is zeroed and of the proper
    //! dimension
    template< typename t_DataType>
    void NumericString< t_DataType>::RecalculateImpl
    (
      const Iterator< t_DataType> &ITR,
      linal::VectorReference< char> &STORAGE
    )
    {
      // compute the key property
      const linal::VectorConstReference< float> key_linal( m_NumericProperty->operator()( ITR));

      // ensure that only one value was retrieved
      BCL_Assert
      (
        key_linal.GetSize() == m_NumericProperty->GetNormalSizeOfFeatures(),
        "Tried to implicitly convert dimensions; use SequenceSum(" + m_NumericProperty->GetString() + ") instead!"
      );

      char *itr_storage( STORAGE.Begin());
      util::Format formatter;
      formatter.W( 13);
      formatter.S();
      for( const float *itr( key_linal.Begin()), *itr_end( key_linal.End()); itr != itr_end; ++itr)
      {
        const std::string numeric( formatter( *itr));
        itr_storage = std::copy( numeric.begin(), numeric.end(), itr_storage);
      }
    }

  } // namespace descriptor
} // namespace bcl
