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
 * \brief 1x4 Matrix class
 * \tparam TType Matrix data type
 */
template<typename TType = float>
class __declspec(novtable) Matrix1x4 final : public GenericMatrix<1, 4, TType>
{
    public:

        using Parent = GenericMatrix<1, 4, TType>;

        #pragma region Constructors

        constexpr Matrix1x4()                           = default;
        constexpr Matrix1x4(Matrix1x4 const& in_matrix) = default;
        constexpr Matrix1x4(Matrix1x4&&      in_matrix) = default;
                 ~Matrix1x4()                           = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix1x4, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix1x4, Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr Matrix1x4& operator=(Matrix1x4 const& in_other) noexcept = default;
        constexpr Matrix1x4& operator=(Matrix1x4&&	    in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix1x4, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix1x4, Parent)

        #pragma endregion
};

// Matrix specializations
using Matrix1x4i = Matrix1x4<int>;
using Matrix1x4f = Matrix1x4<float>;
using Matrix1x4d = Matrix1x4<double>;