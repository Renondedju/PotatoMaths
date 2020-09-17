/*
 * MIT License
 * 
 * Copyright (c) 2019-2020 Basile Combet
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "Matrix/GenericMatrix.hpp"
#include "Vector/GenericVector.hpp"

template<size_t TSize, typename TType = float>
class __declspec(novtable) SquareMatrix : public GenericMatrix<TSize, TSize, TType>
{
    public:

        using Parent = GenericMatrix<TSize, TSize, TType>;

        #pragma region Constructors

        constexpr SquareMatrix()                              = default;
        constexpr SquareMatrix(SquareMatrix const& in_matrix) = default;
        constexpr SquareMatrix(SquareMatrix&&      in_matrix) = default;
                 ~SquareMatrix()                              = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(SquareMatrix, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(SquareMatrix, Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Static Methods

        /**
         * \brief Creates an identity matrix, also called unit matrix
         * \return Identity matrix
         */
        static constexpr SquareMatrix Identity() noexcept;

        #pragma endregion 

        #pragma region Methods

        /**
         * \brief Computes the transposed matrix
         * \return Transposed matrix
         */
        constexpr SquareMatrix& Transpose() noexcept;

        /**
         * \brief Lower�upper (LU) decomposition or factorization factors a matrix as the product of a lower triangular matrix and an upper triangular matrix.
         * 
         * \param out_l_matrix Lower triangular matrix
         * \param out_u_matrix Upper triangular matrix
         */
        constexpr void LUDecomposition(SquareMatrix<TSize, TType>& out_l_matrix, SquareMatrix<TSize, TType>& out_u_matrix) const noexcept;

        /**
         * \brief Solves Ax = b where A is a lower triangular matrix with non-zero diagonal elements.
         * \param in_vector The b operand in Ax = b
         * \return The resultant x vector
         */
        constexpr GenericVector<TSize, TType> ForwardSubstitution (GenericVector<TSize, TType> const& in_vector) const noexcept;

        /**
         * \brief Solves Ax = b where A is a upper triangular matrix with non-zero diagonal elements.
         * \param in_vector The b operand in Ax = b
         * \return The resultant x vector
         */
        constexpr GenericVector<TSize, TType> BackwardSubstitution(GenericVector<TSize, TType> const& in_vector) const noexcept;

        /**
         * \brief Inverts this matrix and returns the result
         * \return Inverted matrix
         */
        constexpr SquareMatrix<TSize, TType> GetInverted() const noexcept; 

        #pragma endregion 

        #pragma region Operators

        constexpr SquareMatrix& operator=(SquareMatrix const& in_other) noexcept = default;
        constexpr SquareMatrix& operator=(SquareMatrix&&      in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(SquareMatrix, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(SquareMatrix, Parent)

        #pragma endregion
};

#include "Matrix/SquareMatrix.inl"