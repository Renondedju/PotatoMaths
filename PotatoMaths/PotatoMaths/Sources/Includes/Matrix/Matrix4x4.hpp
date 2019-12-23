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
 * \brief 4x4 Matrix class
 * \tparam TType Matrix data type
 */
template<typename TType = float>
class __declspec(novtable) Matrix4x4 final : public SquareMatrix<4, TType>
{
    public:

        using Parent = SquareMatrix<4, TType>;

        #pragma region Constructors

        constexpr Matrix4x4()                           = default;
        constexpr Matrix4x4(Matrix4x4 const& in_matrix) = default;
        constexpr Matrix4x4(Matrix4x4&&      in_matrix) = default;
                 ~Matrix4x4()                           = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix4x4, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix4x4, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix4x4, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix4x4, typename Parent::Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr Matrix4x4& operator=(Matrix4x4 const& in_other) noexcept = default;
        constexpr Matrix4x4& operator=(Matrix4x4&&	    in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix4x4, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix4x4, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix4x4, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix4x4, typename Parent::Parent)

        #pragma endregion
};

// Matrix specializations
using Matrix4x4f = Matrix4x4<float>;
using Matrix4x4d = Matrix4x4<double>;
using Matrix4x4i = Matrix4x4<int>;