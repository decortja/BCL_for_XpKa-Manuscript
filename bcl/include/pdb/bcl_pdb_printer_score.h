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

#ifndef BCL_PDB_PRINTER_SCORE_H_
#define BCL_PDB_PRINTER_SCORE_H_

// include the namespace header
#include "bcl_pdb.h"

// include other forward headers - sorted alphabetically
#include "assemble/bcl_assemble.fwd.hh"
#include "score/bcl_score.fwd.hh"
#include "storage/bcl_storage.fwd.hh"
#include "util/bcl_util.fwd.hh"

// includes from bcl - sorted alphabetically
#include "quality/bcl_quality_measures.h"
#include "storage/bcl_storage_set.h"
#include "util/bcl_util_function_interface.h"
#include "util/bcl_util_sh_ptr.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace pdb
  {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class PrinterScore
    //! @brief Scores a protein model and writes PDB lines
    //! @details Evaluates protein model using scoring function and quality measures and writes output to pdb lines.
    //!          This printer is stored in a Factory and will attach the score table to any PDB written.
    //!
    //! @see @link example_pdb_printer_score.cpp @endlink
    //! @author weinerbe
    //! @date Nov 16, 2011
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API PrinterScore :
      public util::FunctionInterface< assemble::ProteinModel, util::ShPtrList< Line> >
    {

    private:

    //////////
    // data //
    //////////

      //! scoring function for a more detailed score output
      util::ShPtr< score::ProteinModelScoreSum> m_ScoringFunction;

      //! set of qualities to be calculated and printed
      storage::Set< quality::Measure> m_Qualities;

    public:

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

      //! remark number used in PDB lines
      static const size_t s_RemarkNumber = 10;

      //! @brief get format for table column format
      //! @return format for table column format
      static const util::Format &GetTableColumnFormat();

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      PrinterScore();

      //! @brief construct with member variables
      //! @param SP_SCORE optional scoring function
      //! @param QUALITY_MEASURES set of quality measures to calculate
      PrinterScore
      (
        const util::ShPtr< score::ProteinModelScoreSum> &SP_SCORE,
        const storage::Set< quality::Measure> &QUALITY_MEASURES = storage::Set< quality::Measure>()
      );

      //! @brief Clone function
      //! @return pointer to new PrinterScore
      PrinterScore *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const;

    ////////////////
    // operations //
    ////////////////

      //! @brief writes a storage table to PDB lines
      //! @param TABLE table to be written
      //! @param WRITE_EMPTY_REMARK_LINE bool whether to precede table with empty remark line
      //! @return PDB lines
      static util::ShPtrList< Line> WriteTableToLines
      (
        const storage::Table< double> &TABLE,
        const bool WRITE_EMPTY_REMARK_LINE = true
      );

    ///////////////
    // operators //
    ///////////////

      //! @brief takes a protein model and returns PDB lines
      //! @param PROTEIN_MODEL protein model to print
      //! @return PDB lines
      util::ShPtrList< Line> operator()( const assemble::ProteinModel &PROTEIN_MODEL) const;

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

    }; // class PrinterScore

  } // namespace pdb
} // namespace bcl

#endif // BCL_PDB_PRINTER_SCORE_H_ 
