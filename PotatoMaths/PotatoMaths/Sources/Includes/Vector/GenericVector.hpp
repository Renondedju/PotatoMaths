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

#include <type_traits>

template <size_t TLength, typename TType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
class GenericVector;

template <size_t TLength, typename TType>
class _declspec(novtable) GenericVector<TLength, TType>
{

        #pragma region Members

        TType data[TLength];

        #pragma endregion

        #pragma region Constructors

        constexpr GenericVector()                               noexcept = default;
        constexpr GenericVector(GenericVector const& in_vector) noexcept = default;
        constexpr GenericVector(GenericVector&&      in_vector) noexcept = default;
        virtual  ~GenericVector()                               noexcept = default;

        #pragma endregion

        #pragma region Methods

        [[nodiscard]]
        constexpr TType const& At(size_t in_index) const noexcept;

        [[nodiscard]]
        constexpr TType&       At(size_t in_index)       noexcept;

        [[nodiscard]]
        constexpr TType        Length() const noexcept;

        [[nodiscard]]
        constexpr TType        SqrLength() const noexcept;

        #pragma endregion

        #pragma region Operators

        constexpr GenericVector& operator=(GenericVector const& in_vector) noexcept = default;
        constexpr GenericVector& operator=(GenericVector&&      in_vector) noexcept = default;

        #pragma endregion
};

#include "GenericVector.inl"