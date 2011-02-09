// file      : odb/boost/date-time/exceptions.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_BOOST_DATE_TIME_EXCEPTIONS_HXX
#define ODB_BOOST_DATE_TIME_EXCEPTIONS_HXX

#include <odb/pre.hxx>

#include <odb/boost/exception.hxx>
#include <odb/boost/details/export.hxx>

namespace odb
{
  namespace boost
  {
    namespace date_time
    {
      struct LIBODB_BOOST_EXPORT special_value: odb::boost::exception
      {
        virtual const char*
        what () const throw ();
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_BOOST_DATE_TIME_EXCEPTIONS_HXX