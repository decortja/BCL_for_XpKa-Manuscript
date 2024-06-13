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

// initialize the static initialization fiasco finder, if macro ENABLE_FIASCO_FINDER is defined
#include "util/bcl_util_static_initialization_fiasco_finder.h"
BCL_StaticInitializationFiascoFinder

// include header of this class
#include "io/bcl_io_ofstream.h"

// includes from bcl - sorted alphabetically

// external includes - sorted alphabetically

namespace bcl
{
  namespace io
  {
  //////////////////////////////////
  // construction and destruction //
  //////////////////////////////////

    //! @brief default constructor
    OFStream::OFStream() :
      StreamInterface(),
      std::ostream()
    {
      std::ostream::init( &( *StreamInterface::m_Buffer));
    }

    //! @brief construct from filename and open_mode
    OFStream::OFStream( const char *name, const std::ios_base::openmode open_mode) :
      StreamInterface(),
      std::ostream()
    {
      std::ostream::init( &( *StreamInterface::m_Buffer));
      open( name, open_mode | std::ios::out);
    }

    //! @brief destructor
    OFStream::~OFStream()
    {
    }

    //! @brief acces stream buffer
    //__streambuf_type
    StreamBufferInterface *OFStream::rdbuf() const
    {
      return StreamInterface::rdbuf();
    }

  ///////////////
  // operators //
  ///////////////

  ////////////////
  // operations //
  ////////////////

    //! @brief open is used to open the OFStream
    void OFStream::open( const char *name, const std::ios::openmode open_mode)
    {
      // call base class open
      StreamInterface::open( name, open_mode | std::ios::out);

      // set the stream buffer
      std::ostream::rdbuf( &( *m_Buffer));
    }

  //////////////////////
  // input and output //
  //////////////////////

  //////////////////////
  // helper functions //
  //////////////////////

  } // namespace io
} // namespace bcl
