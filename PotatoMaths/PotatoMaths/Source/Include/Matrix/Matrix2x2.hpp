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

#include "Matrix/SquareMatrix.hpp"

/**
 * \brief 2x2 Matrix class
 * \tparam TType Matrix data type
 */
template<typename TType = float>
class __declspec(novtable) Matrix2x2 final : public SquareMatrix<2, TType>
{
    private:

        using Parent = SquareMatrix<2, TType>;

    public:

        #pragma region Constructors

        constexpr Matrix2x2()                           = default;
        constexpr Matrix2x2(Matrix2x2 const& in_matrix) = default;
        constexpr Matrix2x2(Matrix2x2&&      in_matrix) = default;
                 ~Matrix2x2()                           = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix2x2, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix2x2, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix2x2, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix2x2, typename Parent::Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr Matrix2x2& operator=(Matrix2x2 const& in_other) noexcept = default;
        constexpr Matrix2x2& operator=(Matrix2x2&&	    in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix2x2, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix2x2, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix2x2, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix2x2, typename Parent::Parent)

        #pragma endregion
};

// Matrix specializations
using Matrix2x2i = Matrix2x2<int>;
using Matrix2x2f = Matrix2x2<float>;
using Matrix2x2d = Matrix2x2<double>;