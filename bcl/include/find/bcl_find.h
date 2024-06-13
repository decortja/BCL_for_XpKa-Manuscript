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

#ifndef BCL_FIND_H_
#define BCL_FIND_H_

// include the namespace forward header
#include "bcl_find.fwd.hh"

// include other forward headers - sorted alphabetically

// includes from bcl - sorted alphabetically
#include "bcl.h"

// external includes - sorted alphabetically

namespace bcl
{
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //!
  //! @file bcl_find.h
  //! @brief namespace for locator, collector and picker classes
  //! @details This namespace provides following interfaces for collecting, locating and picking components from given
  //! arguments with or without extra criteria, as well as wrappers.
  //!
  //!
  //! @see @link example_find.cpp @endlink
  //! @author karakam
  //! @date Jul 22, 2010
  //!
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  namespace find
  {

    //! @brief identifier for the name space
    //! @return the name of the namespace
    BCL_API
    const std::string &GetNamespaceIdentifier();

  } // namespace find
} // namespace bcl

#endif // BCL_FIND_H_
