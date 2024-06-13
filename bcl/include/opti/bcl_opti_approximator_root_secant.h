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

#ifndef BCL_OPTI_APPROXIMATOR_ROOT_SECANT_H_
#define BCL_OPTI_APPROXIMATOR_ROOT_SECANT_H_

// include the namespace header
#include "bcl_opti.h"

// include other forward headers - sorted alphabetically

// includes from bcl - sorted alphabetically
#include "bcl_opti_approximator_modular_base.h"
#include "math/bcl_math_function_interface_serializable.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace opti
  {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class ApproximatorRootSecant
    //! @brief Implementation of Secant Method to find a root for a continuous function without a derivative
    //!
    //! @see http://en.wikipedia.org/wiki/Secant_method
    //!
    //! @tparam t_ArgumentResultType argument and result type of the objective function,
    //!         which are the same. subtraction, devision has to be defined for that type
    //!
    //! @see @link example_opti_approximator_root_secant.cpp @endlink
    //! @author woetzen, fischea
    //! @date Dec 17, 2012
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template< typename t_ArgumentResultType>
    class ApproximatorRootSecant :
      public ApproximatorModularBase< t_ArgumentResultType, t_ArgumentResultType>
    {

    //////////
    // data //
    //////////

    private:

      //! ShPtr to the objective function
      util::ShPtr< math::FunctionInterfaceSerializable< t_ArgumentResultType, t_ArgumentResultType> > m_Objective;

      //! ShPtr ShPtr to the previous approximation result
      util::ShPtr< storage::Pair< t_ArgumentResultType, t_ArgumentResultType> > m_Previous;

    public:

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      ApproximatorRootSecant() :
        ApproximatorModularBase< t_ArgumentResultType, t_ArgumentResultType>( e_SmallerAbsIsBetter),
        m_Objective(),
        m_Previous()
      {
      }

      //! @brief construct from objective function and criterion
      //! @param OBJECTIVE the objective function
      //! @param LEFT_BORDER left border of the approximation interval
      //! @param RIGHT_BORDER right border of the approximation interval
      ApproximatorRootSecant
      (
        const math::FunctionInterfaceSerializable< t_ArgumentResultType, t_ArgumentResultType> &OBJECTIVE,
        const CriterionInterface< t_ArgumentResultType, t_ArgumentResultType> &CRITERION,
        const t_ArgumentResultType &LEFT_BORDER,
        const t_ArgumentResultType &RIGHT_BORDER
      ) :
        ApproximatorModularBase< t_ArgumentResultType, t_ArgumentResultType>( e_SmallerAbsIsBetter),
        m_Objective( util::CloneToShPtr( OBJECTIVE)),
        m_Previous
        (
          util::ShPtr< storage::Pair< t_ArgumentResultType, t_ArgumentResultType> >
          (
            new storage::Pair< t_ArgumentResultType, t_ArgumentResultType>
            (
              LEFT_BORDER, m_Objective->operator()( LEFT_BORDER)
            )
          )
        )
      {
        // set the termination criterion
        this->SetCriterion( CRITERION);

        // track the initial argument
        this->Track
        (
          util::CloneToShPtr
          (
            storage::Pair< t_ArgumentResultType, t_ArgumentResultType>
            (
              RIGHT_BORDER, m_Objective->operator()( RIGHT_BORDER)
            )
          )
        );
      }

      //! @brief Clone function
      //! @return pointer to a new ApproximatorRootSecant< t_ArgumentResultType>
      ApproximatorRootSecant *Clone() const
      {
        return new ApproximatorRootSecant( *this);
      }

    /////////////////
    // data access //
    /////////////////

      //! @brief returns the class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const
      {
        return GetStaticClassName( *this);
      }

    ////////////////
    // operations //
    ////////////////

    protected:

      //! @brief conducts the next approximation step and stores the approximation
      void Next()
      {
        // current approximation
        const util::ShPtr< storage::Pair< t_ArgumentResultType, t_ArgumentResultType> > sp_current
        (
          this->GetTracker().GetCurrent()
        );

        // determine next argument Xn+1 = Xn - f(Xn) * ((Xn)-(Xn-1)) / (f(Xn)-f(Xn-1))
        util::ShPtr< storage::Pair< t_ArgumentResultType, t_ArgumentResultType> > sp_next
        (
          new storage::Pair< t_ArgumentResultType, t_ArgumentResultType>
          (
            sp_current->First() - sp_current->Second() * ( sp_current->First() - m_Previous->First()) /
            ( sp_current->Second() - m_Previous->Second()),
            t_ArgumentResultType()
          )
        );

        // calculate according next function value
        sp_next->Second() = m_Objective->operator()( sp_next->First());

        // track the next approximation step
        m_Previous = sp_current;
        this->Track( sp_next);
      }

      //! @brief evaluates whether the approximation can continue
      //! @return true, if the approximation can continue - otherwise false
      bool CanContinue() const
      {
        return true;
      }

    //////////////////////
    // input and output //
    //////////////////////

      //! @brief read from std::istream
      //! @param ISTREAM input stream
      //! @return istream which was read from
      std::istream &Read( std::istream &ISTREAM)
      {
        // call Read of base class
        ApproximatorModularBase< t_ArgumentResultType, t_ArgumentResultType>::Read( ISTREAM);

        // read members
        io::Serialize::Read( m_Objective, ISTREAM);
        io::Serialize::Read( m_Previous, ISTREAM);

        // end
        return ISTREAM;
      }

      //! @brief write to std::ostream
      //! @param OSTREAM output stream to write to
      //! @param INDENT number of indentations
      //! @return output stream which was written to
      std::ostream &Write( std::ostream &OSTREAM, const size_t INDENT) const
      {
        // call Write of base class
        ApproximatorModularBase< t_ArgumentResultType, t_ArgumentResultType>::Write( OSTREAM, INDENT) << '\n';

        // write members
        io::Serialize::Write( m_Objective, OSTREAM, INDENT) << '\n';
        io::Serialize::Write( m_Previous, OSTREAM, INDENT);

        // end
        return OSTREAM;
      }

    }; // template class ApproximatorRootSecant< t_ArgumentResultType>

  } // namespace opti
} // namespace bcl

#endif // BCL_OPTI_APPROXIMATOR_ROOT_SECANT_H_
