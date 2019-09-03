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

#pragma warning(push)
#pragma warning(disable : 4201) // Warning C4201 nonstandard extension used: nameless struct/union

#include "Vector/GenericVector.hpp"

template <typename TType> class Vector2;
template <typename TType> class Vector3;

/**
 * \brief Vector 4 class 
 * \tparam TType Underlying type
 */
template <typename TType = float>
class Vector4 final : public GenericVector<Vector4<TType>, 4, TType>
{
    public:

        using Parent = GenericVector<Vector4<TType>, 4, TType>;

        #pragma region Members

        union
        {
            TType data[4];

            struct
            {
                TType x;
                TType y;
                TType z;
                TType w;
            };
        };

        #pragma endregion

        #pragma region Constructors

        /**
         * \brief Component constructor
         * \param in_x X component
         * \param in_y Y component
         * \param in_z Z component
         * \param in_w W component
         */
        constexpr Vector4(TType in_x, TType in_y, TType in_z, TType in_w) noexcept;
        constexpr Vector4()                                               noexcept;

        constexpr Vector4(Vector4 const& in_matrix) noexcept = default;
        constexpr Vector4(Vector4&&      in_matrix) noexcept = default;
                 ~Vector4()                         noexcept = default;

        using Parent::Parent;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Homogenizes the vector
         * \return Vector instance
         */
        Vector4& Homogenize() noexcept;

        #pragma endregion

        #pragma region Operators

        constexpr Vector4& operator=(Vector4 const& in_other) noexcept = default;
        constexpr Vector4& operator=(Vector4&&	    in_other) noexcept = default;

        explicit operator Vector2<TType>() const noexcept;
        explicit operator Vector3<TType>() const noexcept;

        #pragma endregion
};

#pragma warning(pop) 

#include "Vector/Vector4.inl"

using Vector4f = Vector4<float>;
using Vector4d = Vector4<double>;
using Vector4i = Vector4<int>;