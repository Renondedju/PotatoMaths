/*
 * MIT License
 * 
 * Copyright (c) 2019 Renondedju, 6xray
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
 * \brief 3x3 Matrix class
 * \tparam TType Matrix data type
 */
template<typename TType = float>
class Matrix3x3 final : public SquareMatrix<3, TType>
{
    private:

        using Parent = SquareMatrix<3, TType>;

    public:

        #pragma region Constructors

        constexpr Matrix3x3()                           = default;
        constexpr Matrix3x3(Matrix3x3 const& in_matrix) = default;
        constexpr Matrix3x3(Matrix3x3&&      in_matrix) = default;
                 ~Matrix3x3()                           = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix3x3, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix3x3, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(Matrix3x3, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(Matrix3x3, typename Parent::Parent)

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr Matrix3x3& operator=(Matrix3x3 const& in_other) noexcept = default;
        constexpr Matrix3x3& operator=(Matrix3x3&&	    in_other) noexcept = default;

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix3x3, Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix3x3, Parent)

        DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(Matrix3x3, typename Parent::Parent)
        DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(Matrix3x3, typename Parent::Parent)

        #pragma endregion
};

// Matrix specializations
using Matrix3x3f = Matrix3x3<float>;
using Matrix3x3d = Matrix3x3<double>;
using Matrix3x3i = Matrix3x3<int>;