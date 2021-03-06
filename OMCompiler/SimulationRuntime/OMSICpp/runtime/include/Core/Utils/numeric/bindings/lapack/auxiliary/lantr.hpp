//
// Copyright (c) 2002--2010
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_AUXILIARY_LANTR_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_AUXILIARY_LANTR_HPP

#include <boost/assert.hpp>
#include <Core/Utils/numeric/bindings/begin.hpp>
#include <Core/Utils/numeric/bindings/detail/array.hpp>
#include <Core/Utils/numeric/bindings/diag_tag.hpp>
#include <Core/Utils/numeric/bindings/is_column_major.hpp>
#include <Core/Utils/numeric/bindings/is_mutable.hpp>
#include <Core/Utils/numeric/bindings/lapack/workspace.hpp>
#include <Core/Utils/numeric/bindings/remove_imaginary.hpp>
#include <Core/Utils/numeric/bindings/size.hpp>
#include <Core/Utils/numeric/bindings/stride.hpp>
#include <Core/Utils/numeric/bindings/uplo_tag.hpp>
#include <Core/Utils/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for lantr is the netlib-compatible backend.
//
#include <Core/Utils/numeric/bindings/lapack/detail/lapack.h>
#include <Core/Utils/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost
{
    namespace numeric
    {
        namespace bindings
        {
            namespace lapack
            {
                //
                // The detail namespace contains value-type-overloaded functions that
                // dispatch to the appropriate back-end LAPACK-routine.
                //
                namespace detail
                {
                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * float value-type.
                    //
                    template <typename UpLo, typename Diag>
                    inline std::ptrdiff_t lantr(const char norm, const UpLo, const Diag,
                                                const fortran_int_t m, const fortran_int_t n, const float* a,
                                                const fortran_int_t lda, float* work)
                    {
                        fortran_int_t info(0);
                        LAPACK_SLANTR(&norm, &lapack_option<UpLo>::value, &lapack_option<
                                          Diag>::value, &m, &n, a, &lda, work);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * double value-type.
                    //
                    template <typename UpLo, typename Diag>
                    inline std::ptrdiff_t lantr(const char norm, const UpLo, const Diag,
                                                const fortran_int_t m, const fortran_int_t n, const double* a,
                                                const fortran_int_t lda, double* work)
                    {
                        fortran_int_t info(0);
                        LAPACK_DLANTR(&norm, &lapack_option<UpLo>::value, &lapack_option<
                                          Diag>::value, &m, &n, a, &lda, work);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * complex<float> value-type.
                    //
                    template <typename UpLo, typename Diag>
                    inline std::ptrdiff_t lantr(const char norm, const UpLo, const Diag,
                                                const fortran_int_t m, const fortran_int_t n,
                                                const std::complex<float>* a, const fortran_int_t lda, float* work)
                    {
                        fortran_int_t info(0);
                        LAPACK_CLANTR(&norm, &lapack_option<UpLo>::value, &lapack_option<
                                          Diag>::value, &m, &n, a, &lda, work);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * complex<double> value-type.
                    //
                    template <typename UpLo, typename Diag>
                    inline std::ptrdiff_t lantr(const char norm, const UpLo, const Diag,
                                                const fortran_int_t m, const fortran_int_t n,
                                                const std::complex<double>* a, const fortran_int_t lda,
                                                double* work)
                    {
                        fortran_int_t info(0);
                        LAPACK_ZLANTR(&norm, &lapack_option<UpLo>::value, &lapack_option<
                                          Diag>::value, &m, &n, a, &lda, work);
                        return info;
                    }
                } // namespace detail

                //
                // Value-type based template class. Use this class if you need a type
                // for dispatching to lantr.
                //
                template <typename Value>
                struct lantr_impl
                {
                    typedef Value value_type;
                    typedef typename remove_imaginary<Value>::type real_type;

                    //
                    // Static member function for user-defined workspaces, that
                    // * Deduces the required arguments for dispatching to LAPACK, and
                    // * Asserts that most arguments make sense.
                    //
                    template <typename MatrixA, typename WORK>
                    static std::ptrdiff_t invoke(const char norm, const MatrixA& a,
                                                 detail::workspace1<WORK> work)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        typedef typename result_of::diag_tag<MatrixA>::type diag;
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixA>::value));
                        BOOST_ASSERT(bindings::size(work.select(real_type())) >=
                            min_size_work(norm, bindings::size_row(a)));
                        BOOST_ASSERT(bindings::size_column(a) >= 0);
                        BOOST_ASSERT(bindings::size_minor(a) == 1 ||
                            bindings::stride_minor(a) == 1);
                        BOOST_ASSERT(bindings::size_row(a) >= 0);
                        BOOST_ASSERT(bindings::stride_major(a) >= std::max<
                            std::ptrdiff_t>(bindings::size_row(a), 1));
                        return detail::lantr(norm, uplo(), diag(), bindings::size_row(a),
                                             bindings::size_column(a), bindings::begin_value(a),
                                             bindings::stride_major(a),
                                             bindings::begin_value(work.select(real_type())));
                    }

                    //
                    // Static member function that
                    // * Figures out the minimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member function
                    // * Enables the unblocked algorithm (BLAS level 2)
                    //
                    template <typename MatrixA>
                    static std::ptrdiff_t invoke(const char norm, const MatrixA& a,
                                                 minimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        typedef typename result_of::diag_tag<MatrixA>::type diag;
                        bindings::detail::array<real_type> tmp_work(min_size_work(norm,
                                                                                  bindings::size_row(a)));
                        return invoke(norm, a, workspace(tmp_work));
                    }

                    //
                    // Static member function that
                    // * Figures out the optimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member
                    // * Enables the blocked algorithm (BLAS level 3)
                    //
                    template <typename MatrixA>
                    static std::ptrdiff_t invoke(const char norm, const MatrixA& a,
                                                 optimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        typedef typename result_of::diag_tag<MatrixA>::type diag;
                        return invoke(norm, a, minimal_workspace());
                    }

                    //
                    // Static member function that returns the minimum size of
                    // workspace-array work.
                    //
                    static std::ptrdiff_t min_size_work(const char norm,
                                                        const std::ptrdiff_t m)
                    {
                        if (norm == 'I')
                            return std::max<std::ptrdiff_t>(1, m);
                        else
                            return 1;
                    }
                };


                //
                // Functions for direct use. These functions are overloaded for temporaries,
                // so that wrapped types can still be passed and used for write-access. In
                // addition, if applicable, they are overloaded for user-defined workspaces.
                // Calls to these functions are passed to the lantr_impl classes. In the
                // documentation, most overloads are collapsed to avoid a large number of
                // prototypes which are very similar.
                //

                //
                // Overloaded function for lantr. Its overload differs for
                // * User-defined workspace
                //
                template <typename MatrixA, typename Workspace>
                inline typename boost::enable_if<detail::is_workspace<Workspace>,
                                                 std::ptrdiff_t>::type
                lantr(const char norm, const MatrixA& a, Workspace work)
                {
                    return lantr_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(norm, a, work);
                }

                //
                // Overloaded function for lantr. Its overload differs for
                // * Default workspace-type (optimal)
                //
                template <typename MatrixA>
                inline typename boost::disable_if<detail::is_workspace<MatrixA>,
                                                  std::ptrdiff_t>::type
                lantr(const char norm, const MatrixA& a)
                {
                    return lantr_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(norm, a, optimal_workspace());
                }
            } // namespace lapack
        } // namespace bindings
    } // namespace numeric
} // namespace boost

#endif
