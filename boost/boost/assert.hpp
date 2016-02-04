//
//  boost/assert.hpp - BOOST_ASSERT(expr)
//                     BOOST_ASSERT_MSG(expr, msg)
//                     BOOST_VERIFY(expr)
//                     BOOST_VERIFY_MSG(expr, msg)
//                     BOOST_ASSERT_IS_VOID
//
//  Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2007, 2014 Peter Dimov
//  Copyright (c) Beman Dawes 2011
//  Copyright (c) 2015 Ion Gaztanaga
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  Note: There are no include guards. This is intentional.
//
//  See http://www.boost.org/libs/assert/assert.html for documentation.
//

//
// Stop inspect complaining about use of 'assert':
//
// boostinspect:naassert_macro
//

//
// BOOST_ASSERT, BOOST_ASSERT_MSG, BOOST_ASSERT_IS_VOID
//

#undef BOOST_ASSERT
#undef BOOST_ASSERT_MSG
#undef BOOST_ASSERT_IS_VOID

#if defined(BOOST_DISABLE_ASSERTS) || ( defined(BOOST_ENABLE_ASSERT_DEBUG_HANDLER) && defined(NDEBUG) )

# define BOOST_ASSERT(expr) ((void)0)
# define BOOST_ASSERT_MSG(expr, msg) ((void)0)
# define BOOST_ASSERT_IS_VOID

#elif defined(BOOST_ENABLE_ASSERT_HANDLER) || ( defined(BOOST_ENABLE_ASSERT_DEBUG_HANDLER) && !defined(NDEBUG) )

<<<<<<< HEAD
#include <boost/config.hpp> // for BOOST_LIKELY
=======
#include <boost/config.hpp>
>>>>>>> github/build-bot-2.1.x
#include <boost/current_function.hpp>

namespace boost
{
    void assertion_failed(char const * expr, char const * function, char const * file, long line); // user defined
    void assertion_failed_msg(char const * expr, char const * msg, char const * function, char const * file, long line); // user defined
} // namespace boost

<<<<<<< HEAD
#define BOOST_ASSERT(expr) (BOOST_LIKELY(!!(expr))? ((void)0): ::boost::assertion_failed(#expr, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))
#define BOOST_ASSERT_MSG(expr, msg) (BOOST_LIKELY(!!(expr))? ((void)0): ::boost::assertion_failed_msg(#expr, msg, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))
=======
#define BOOST_ASSERT(expr) (BOOST_LIKELY(!!(expr)) \
  ? ((void)0) \
  : ::boost::assertion_failed(#expr, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))
>>>>>>> github/build-bot-2.1.x

#else

# include <assert.h> // .h to support old libraries w/o <cassert> - effect is the same

# define BOOST_ASSERT(expr) assert(expr)
# define BOOST_ASSERT_MSG(expr, msg) assert((expr)&&(msg))
#if defined(NDEBUG)
# define BOOST_ASSERT_IS_VOID
#endif

<<<<<<< HEAD
=======
//--------------------------------------------------------------------------------------//
//                                   BOOST_ASSERT_MSG                                   //
//--------------------------------------------------------------------------------------//

# undef BOOST_ASSERT_MSG

#if defined(BOOST_DISABLE_ASSERTS) || defined(NDEBUG)

  #define BOOST_ASSERT_MSG(expr, msg) ((void)0)

#elif defined(BOOST_ENABLE_ASSERT_HANDLER)

  #include <boost/config.hpp>
  #include <boost/current_function.hpp>

  namespace boost
  {
    void assertion_failed_msg(char const * expr, char const * msg,
                              char const * function, char const * file, long line); // user defined
  } // namespace boost

  #define BOOST_ASSERT_MSG(expr, msg) (BOOST_LIKELY(!!(expr)) \
    ? ((void)0) \
    : ::boost::assertion_failed_msg(#expr, msg, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))

#else
  #ifndef BOOST_ASSERT_HPP
    #define BOOST_ASSERT_HPP
    #include <cstdlib>
    #include <iostream>
    #include <boost/config.hpp>
    #include <boost/current_function.hpp>

    //  IDE's like Visual Studio perform better if output goes to std::cout or
    //  some other stream, so allow user to configure output stream:
    #ifndef BOOST_ASSERT_MSG_OSTREAM
    # define BOOST_ASSERT_MSG_OSTREAM std::cerr
    #endif

    namespace boost
    {
      namespace assertion
      {
        namespace detail
        {
          // Note: The template is needed to make the function non-inline and avoid linking errors
          template< typename CharT >
          BOOST_NOINLINE void assertion_failed_msg(CharT const * expr, char const * msg, char const * function,
            char const * file, long line)
          {
            BOOST_ASSERT_MSG_OSTREAM
              << "***** Internal Program Error - assertion (" << expr << ") failed in "
              << function << ":\n"
              << file << '(' << line << "): " << msg << std::endl;
#ifdef UNDER_CE
            // The Windows CE CRT library does not have abort() so use exit(-1) instead.
            std::exit(-1);
#else
            std::abort();
#endif
          }
        } // detail
      } // assertion
    } // detail
  #endif

  #define BOOST_ASSERT_MSG(expr, msg) (BOOST_LIKELY(!!(expr)) \
    ? ((void)0) \
    : ::boost::assertion::detail::assertion_failed_msg(#expr, msg, \
          BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))
>>>>>>> github/build-bot-2.1.x
#endif

//
// BOOST_VERIFY, BOOST_VERIFY_MSG
//

#undef BOOST_VERIFY
#undef BOOST_VERIFY_MSG

#if defined(BOOST_DISABLE_ASSERTS) || ( !defined(BOOST_ENABLE_ASSERT_HANDLER) && defined(NDEBUG) )

# define BOOST_VERIFY(expr) ((void)(expr))
# define BOOST_VERIFY_MSG(expr, msg) ((void)(expr))

#else

# define BOOST_VERIFY(expr) BOOST_ASSERT(expr)
# define BOOST_VERIFY_MSG(expr, msg) BOOST_ASSERT_MSG(expr,msg)

#endif
