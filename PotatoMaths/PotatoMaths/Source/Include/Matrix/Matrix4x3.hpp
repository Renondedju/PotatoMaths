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

/**
 * \brief 4x3 Matrix class
 * \tparam TType Matrix data type
 */
template<typename TType = float>
class __declspec(novtable) Matrix4x3 final : public GenericMatrix<4, 3, TType>
{
    public:

        using Parent = GenericMatrix<4, 3, TType>;

        #pragma region Constructors

        constexpr Matrix4x3()                           = default;
        constexpr Matrix4x3(Matrix4x3 const& in_matrix) = default;
        constexpr Matrix4x3(Matrix4x3&&      in_matrix) = default;
                 ~Matrix4x3()                           = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix4x3, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix4x3, Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr Matrix4x3& operator=(Matrix4x3 const& in_other) noexcept = default;
        constexpr Matrix4x3& operator=(Matrix4x3&&	    in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix4x3, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix4x3, Parent)

        #pragma endregion
};

// Matrix specializations
using Matrix4x3i = Matrix4x3<int>;
using Matrix4x3f = Matrix4x3<float>;
using Matrix4x3d = Matrix4x3<double>;