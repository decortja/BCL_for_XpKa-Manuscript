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

#ifndef BCL_UTIL_BINARY_FUNCTION_WRAPPER_H_
#define BCL_UTIL_BINARY_FUNCTION_WRAPPER_H_

// include the namespace header
#include "bcl_util.h"

// include other forward headers - sorted alphabetically

// includes from bcl - sorted alphabetically
#include "bcl_util_three_input_function_interface.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace util
  {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class BinaryFunctionWrapper
    //! @brief This class wraps binary functions.
    //! @details Use this class to prepare to pass in a function to create a job for parallelization.
    //! Functions could be non-static members (const or non-const) or static members
    //!
    //! @see @link example_util_binary_function_wrapper.cpp @endlink
    //! @author riddeljs
    //! @date 12.02.2008
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template< typename t_ArgumentType1, typename t_ArgumentType2, typename t_ResultType, typename t_FunctionClass>
    class BinaryFunctionWrapper :
      public ThreeInputFunctionInterface< t_FunctionClass, t_ArgumentType1, t_ArgumentType2, t_ResultType>
    {
    private:

      //! pointer to the function, belonging to class FunctionClass, we call for a job
      // is the function a constant member function or static function?  Have three different members.
      t_ResultType ( t_FunctionClass::*m_Function)( t_ArgumentType1 &, t_ArgumentType2 &);
      t_ResultType ( t_FunctionClass::*m_Query)( t_ArgumentType1 &, t_ArgumentType2 &) const;
      t_ResultType ( *m_StaticFun)( t_ArgumentType1 &, t_ArgumentType2 &);
      size_t m_FunctionType;

    public:

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief given a static function to submit to the job, initialize instance of the wrapper.
      BinaryFunctionWrapper
      (
        t_ResultType ( *FUNCTION_TO_SUBMIT)( t_ArgumentType1 &, t_ArgumentType2 &)
      ) :
        m_Function(),
        m_Query(),
        m_StaticFun( FUNCTION_TO_SUBMIT),
        m_FunctionType( 0)
      {
      }

      //! @brief given a query to submit to the job, initialize instance of the wrapper.
      BinaryFunctionWrapper
      (
        t_ResultType ( t_FunctionClass::*QUERY_TO_SUBMIT)( t_ArgumentType1 &, t_ArgumentType2 &) const
      ) :
        m_Function(),
        m_Query( QUERY_TO_SUBMIT),
        m_StaticFun(),
        m_FunctionType( 1)
      {
      }

      //! @brief given a function to submit to the job, initialize instance of the wrapper
      BinaryFunctionWrapper
      (
        t_ResultType ( t_FunctionClass::*FUNCTION_TO_SUBMIT)( t_ArgumentType1 &, t_ArgumentType2 &)
      ) :
        m_Function( FUNCTION_TO_SUBMIT),
        m_Query(),
        m_StaticFun(),
        m_FunctionType( 2)
      {
      }

      //! virtual copy constructor
      BinaryFunctionWrapper< t_ArgumentType1, t_ArgumentType2, t_ResultType, t_FunctionClass> *Clone() const
      {
        return new BinaryFunctionWrapper< t_ArgumentType1, t_ArgumentType2, t_ResultType, t_FunctionClass>( *this);
      }

    /////////////////
    // data access //
    /////////////////

      //! returns class name
      //! the class name as const ref std::string
      const std::string &GetClassIdentifier() const
      {
         return GetStaticClassName( *this);
      }

    ////////////////
    // operations //
    ////////////////

    ///////////////
    // operators //
    ///////////////

      //! @brief operator the implements the operation on the argument returning a result
      //! @param OBJECT
      //! @param ARGUMENT1 argument 1 to function
      //! @param ARGUMENT2 argument 2 to function
      //! @return the Result of the operation, even if void
      t_ResultType operator()( t_FunctionClass &OBJECT, t_ArgumentType1 &ARGUMENT1, t_ArgumentType2 &ARGUMENT2)
      {
        switch( m_FunctionType)
        {
          case 0:
            return ( *m_StaticFun)( ARGUMENT1, ARGUMENT2);
          case 1:
            return ( OBJECT.*m_Query)( ARGUMENT1, ARGUMENT2);
          default:
            return ( OBJECT.*m_Function)( ARGUMENT1, ARGUMENT2);
        }
      }

    //////////////////////
    // input and output //
    //////////////////////
    
    protected:

      //! @brief read from std::istream
      //! @param ISTREAM input stream
      //! @return istream which was read from
      std::istream &Read( std::istream &ISTREAM)
      {
        // end
        return ISTREAM;
      }

      //! @brief write to std::ostream
      //! @param OSTREAM output stream to write to
      //! @param INDENT - number of indentations
      //! @return output stream which was written to
      std::ostream &Write( std::ostream &OSTREAM, const size_t INDENT) const
      {
        // end
        return OSTREAM;
      }

    }; // template class BinaryFunctionWrapper

  } // namespace util
} // namespace bcl

#endif //BCL_UTIL_BINARY_FUNCTION_WRAPPER_H_

