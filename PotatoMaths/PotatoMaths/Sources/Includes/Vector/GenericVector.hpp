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

#include "Vector/BaseVector.hpp"

/**
 * \brief GenericVector class
 * \tparam TSize Vector size
 * \tparam TType Underlying type
 */
template <size_t TSize, typename TType = float>
class GenericVector final : public BaseVector<GenericVector<TSize, TType>, TSize, TType>
{
    public:

        using Parent = BaseVector<GenericVector<TSize, TType>, TSize, TType>;

        #pragma region Members

        TType data[TSize];

        #pragma endregion

        #pragma region Constructors

        /**
         * \brief Generic constructor
         * \tparam TValuesType Type of passed values
         * \param in_values Values to init the vector with
         */
        template <typename... TValuesType, typename = std::enable_if_t<sizeof...(TValuesType) == TSize>>
        constexpr GenericVector(TValuesType... in_values)       noexcept;
        constexpr GenericVector()                               noexcept;

        constexpr GenericVector(GenericVector const& in_matrix) noexcept = default;
        constexpr GenericVector(GenericVector&&      in_matrix) noexcept = default;
                 ~GenericVector()                               noexcept = default;

        using Parent::Parent;

        #pragma endregion

        #pragma region Operators

        constexpr GenericVector& operator=(GenericVector const& in_other) noexcept = default;
        constexpr GenericVector& operator=(GenericVector&&	    in_other) noexcept = default;

        #pragma endregion
};

#include "Vector/GenericVector.inl"