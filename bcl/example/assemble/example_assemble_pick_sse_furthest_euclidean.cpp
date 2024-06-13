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

// include example header
#include "example.h"
// include the header of the class which this example is for
#include "assemble/bcl_assemble_pick_sse_furthest_euclidean.h"

// includes from bcl - sorted alphabetically
#include "example_proteins.h"
#include "assemble/bcl_assemble_protein_model.h"

// external includes - sorted alphabetically

namespace bcl
{
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //!
  //! @example example_assemble_pick_sse_furthest_euclidean.cpp
  //!
  //! @author loweew
  //! @date Nov 6, 2010
  //! @remarks status complete
  //! @remarks reviewed by nobody on
  //!
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  class ExampleAssemblePickSSEFurthestEuclidean :
    public ExampleInterface
  {
  public:

    ExampleAssemblePickSSEFurthestEuclidean *Clone() const
    {
      return new ExampleAssemblePickSSEFurthestEuclidean( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief returns class name
    //! @return the class name as const ref std::string
    const std::string &GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

    int Run() const
    {
      // create string "pdb_filename" which has path for example pdb file
      const std::string pdb_filename( AddExampleInputPathToFilename( e_Biology, "1C1D.pdb"));

      // create ProteinModel "protein_model" from "pdb"
      BCL_MessageStd( "building models from pdb chains and sse information");
      storage::Map< biol::SSType, size_t> ssetype_min_size;
      ssetype_min_size[ biol::GetSSTypes().HELIX] = 0;
      assemble::ProteinModel protein_model
      (
        Proteins::GetModel( pdb_filename, biol::GetAAClasses().e_AABackBone, ssetype_min_size)
      );

      // create SiPtrVector "sse_vector" and initialize with all SSEs of "protein_model"
      util::SiPtrVector< const assemble::SSE> sse_vector( protein_model.GetSSEs());

      // iterate through "sse_vector"
      for
      (
        storage::Vector< util::SiPtr< const assemble::SSE> >::const_iterator
          sse_itr( sse_vector.Begin()), sse_itr_end( sse_vector.End());
        sse_itr != sse_itr_end;
        ++sse_itr
      )
      {
        // create double "current_distance" initialize to the distance between "protein_center" and the center of the
        // SSE currently denoted by "sse_itr"
        const double current_distance( linal::Distance( protein_model.GetCenter(), ( *sse_itr)->GetCenter()));

        // print the distance the SSE currently denoted by "sse_itr" is away from the center of "protein_model"
        BCL_MessageStd
        (
          "Current SSE is " + util::Format()( current_distance)
          + " away from the center of the protein"
        );
      }

      // test default constructor
      assemble::PickSSEFurthestEuclidean pick;
      BCL_MessageStd( "test default constructor");
      // test copy constructor
      BCL_MessageStd( "test copy constructor");
      assemble::PickSSEFurthestEuclidean copy_constr( pick);

      // test Pick function
      BCL_MessageStd( "test Pick function");
      const util::SiPtrList< const assemble::SSE> sse_list( sse_vector.Begin(), sse_vector.End());
      util::SiPtr< const assemble::SSE> sp_sse( pick.Pick( sse_list, protein_model.GetCenter()));
      // print the distance the located SSE is from the center of the protein
      BCL_MessageStd
      (
        "Furthest SSE is " + util::Format()( linal::Distance( sp_sse->GetCenter(), protein_model.GetCenter()))
        + " away from the center of the protein"
      );

      const double expected_distance( 50.796);
      // make sure that the located SSE is in fact the most distant SSE from the center of the protein
      BCL_Example_Check
      (
        math::EqualWithinTolerance( expected_distance, linal::Distance( sp_sse->GetCenter(), protein_model.GetCenter())),
        "Furthest SSE located is " + util::Format()( linal::Distance( sp_sse->GetCenter(), protein_model.GetCenter()))
        + " away from the center of the protein, but should be " + util::Format()( expected_distance)
      );

      return 0;
    }

    static const ExampleClass::EnumType s_Instance;

  }; //end ExampleAssemblePickSSEFurthestEuclidean

  const ExampleClass::EnumType ExampleAssemblePickSSEFurthestEuclidean::s_Instance
  (
    GetExamples().AddEnum( ExampleAssemblePickSSEFurthestEuclidean())
  );

} // namespace bcl
