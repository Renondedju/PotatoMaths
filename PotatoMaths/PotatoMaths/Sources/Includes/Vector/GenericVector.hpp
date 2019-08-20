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
    public:

        #pragma region Members

        TType data[TLength];

        #pragma endregion

        #pragma region Constructors

        constexpr GenericVector()                               noexcept;
        constexpr GenericVector(GenericVector const& in_vector) noexcept = default;
        constexpr GenericVector(GenericVector&&      in_vector) noexcept = default;
        virtual  ~GenericVector()                               noexcept = default;

        #pragma endregion

        #pragma region Methods

        /**
         * Performs a linear interpolation between 2 vectors of the same type
         */
        [[nodiscard]]
        constexpr static GenericVector Lerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept;

        /**
         *
         */
        [[nodiscard]]
        constexpr static GenericVector Slerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept;

        /**
         * \brief Data getter
         *
         * \param in_index Index of the data.
         *
         * \return The data at the given index.
         */
        [[nodiscard]]
        constexpr TType const&   At(size_t in_index) const noexcept;

        /**
         * \brief Data getter/setter
         *
         * \param in_index Index of the data.
         *
         * \return The data at the given index.
         */
        [[nodiscard]]
        constexpr TType&         At(size_t in_index) noexcept;

        /**
         * \brief Computes the length of the vector in TType value.
         * In some cases, you might want to use SqrLength which is less expensive to compute.
         *
         * \return The length of the vector.
         */
        [[nodiscard]]
        constexpr TType          Length() const noexcept;

        /**
         * \brief Computes the squared length of the vector in TType value.
         *
         * \return The squared length of the vector.
         */
        [[nodiscard]] 
        constexpr TType          SqrLength() const noexcept;

        /**
         * \brief Normalize the vector. If the vector is null (all components are set to 0), nothing is done.
         */
        constexpr GenericVector& Normalize() noexcept;

        /**
         * \brief Returns the normalized vector. If the vector is null (all components are set to 0), then vector zero is returned.
         *
         * \return The normalized vector.
         */
        [[nodiscard]]
        constexpr GenericVector  GetNormalized() const noexcept;

        #pragma endregion

        #pragma region Operators

        constexpr GenericVector& operator=(GenericVector const& in_vector) noexcept = default;
        constexpr GenericVector& operator=(GenericVector&&      in_vector) noexcept = default;

        #pragma endregion
};

#include "GenericVector.inl"