// file      : odb/boost/unordered/container-traits.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_BOOST_UNORDERED_CONTAINER_TRAITS_HXX
#define ODB_BOOST_UNORDERED_CONTAINER_TRAITS_HXX

#include <boost/version.hpp>

// Unordered containers are available since 1.36.0.
//
#if BOOST_VERSION >= 103600

#include <odb/pre.hxx>

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

#include <odb/container-traits.hxx>

namespace odb
{
  // unordered_set
  //
  template <typename V, typename H, typename P, typename A>
  class access::container_traits< ::boost::unordered_set<V, H, P, A> >
  {
  public:
    static container_kind const kind = ck_set;

    typedef ::boost::unordered_set<V, H, P, A> container_type;
    typedef V value_type;

    typedef set_functions<value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (*i);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        value_type v;
        more = f.load_all (v);
        c.insert (v);
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_all ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (*i);
    }

    static void
    erase (const functions& f)
    {
      f.delete_all ();
    }
  };

  // unordered_multiset
  //
  // @@ Does multiset preserve insertion order of equal elements? The
  // current implementation in the generated code does not guarantee
  // this.
  //
  template <typename V, typename H, typename P, typename A>
  class access::container_traits< ::boost::unordered_multiset<V, H, P, A> >
  {
  public:
    static container_kind const kind = ck_multiset;

    typedef ::boost::unordered_multiset<V, H, P, A> container_type;
    typedef V value_type;

    typedef set_functions<value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (*i);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        value_type v;
        more = f.load_all (v);
        c.insert (v);
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_all ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (*i);
    }

    static void
    erase (const functions& f)
    {
      f.delete_all ();
    }
  };

  // unordered_map
  //
  template <typename K, typename V, typename H, typename P, typename A>
  class access::container_traits< ::boost::unordered_map<K, V, H, P, A> >
  {
  public:
    static container_kind const kind = ck_map;

    typedef ::boost::unordered_map<K, V, H, P, A> container_type;

    typedef K key_type;
    typedef V value_type;
    typedef typename container_type::value_type pair_type;

    typedef map_functions<key_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (i->first, i->second);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        key_type k;
        value_type v;
        more = f.load_all (k, v);
        c.insert (pair_type (k, v));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_all ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (i->first, i->second);
    }

    static void
    erase (const functions& f)
    {
      f.delete_all ();
    }
  };

  // unordered_multimap
  //
  // @@ Does multimap preserve insertion order of equal elements? The
  // current implementation in the generated code does not guarantee
  // this.
  //
  template <typename K, typename V, typename H, typename P, typename A>
  class access::container_traits< ::boost::unordered_multimap<K, V, H, P, A> >
  {
  public:
    static container_kind const kind = ck_multimap;

    typedef ::boost::unordered_multimap<K, V, H, P, A> container_type;

    typedef K key_type;
    typedef V value_type;
    typedef typename container_type::value_type pair_type;

    typedef map_functions<key_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (i->first, i->second);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        key_type k;
        value_type v;
        more = f.load_all (k, v);
        c.insert (pair_type (k, v));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_all ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert_one (i->first, i->second);
    }

    static void
    erase (const functions& f)
    {
      f.delete_all ();
    }
  };
}

#include <odb/post.hxx>

#endif // BOOST_VERSION
#endif // ODB_BOOST_UNORDERED_CONTAINER_TRAITS_HXX