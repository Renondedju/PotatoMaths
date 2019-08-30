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
                 ~GenericVector()                               noexcept = default;

        template<typename... TValues, typename = std::enable_if_t<sizeof...(TValues) == TLength>>
        constexpr GenericVector(TValues... in_values) noexcept;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Performs a linear interpolation between 2 vectors of the same type.
         *
         * \param in_from 
         * \param in_to 
         * \param in_ratio
         *
         * \return 
         */
        [[nodiscard]]
        constexpr static GenericVector Lerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept;

        /**
         * \brief Performs a circular interpolation between 2 vectors of the same type.
         *
         * \param in_from
         * \param in_to
         * \param in_ratio
         *
         * \return
         */
        [[nodiscard]]
        constexpr static GenericVector Slerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept;
        /**
         * \brief Return the dot product value performed with 2 vectors
         *
         * \param in_lhs The first vector
         * \param in_rhs The second vector
         *
         * \return The dot product
         */
        [[nodiscard]]
        constexpr static TType Dot(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept;

        /**
         * \brief Return the cross product value performed with 2 vectors
         *
         * \param in_lhs The first vector
         * \param in_rhs The second vector
         *
         * \return The cross product
         */
        [[nodiscard]]
        constexpr static GenericVector Cross(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept;

        /**
         * \brief Data getter
         *
         * \param in_index Index of the data.
         *
         * \return The data at the given index.
         */
        [[nodiscard]]
        constexpr TType const& At(size_t in_index) const noexcept;

        /**
         * \brief Data getter/setter
         *
         * \param in_index Index of the data.
         *
         * \return The data at the given index.
         */
        [[nodiscard]]
        constexpr TType& At(size_t in_index) noexcept;

        /**
         * \brief Computes the length of the vector in TType value.
         * In some cases, you might want to use SqrLength which is less expensive to compute.
         *
         * \return The length of the vector.
         */
        [[nodiscard]]
        constexpr TType Length() const noexcept;

        /**
         * \brief Computes the squared length of the vector in TType value.
         *
         * \return The squared length of the vector.
         */
        [[nodiscard]] 
        constexpr TType SqrLength() const noexcept;

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
        constexpr GenericVector GetNormalized() const noexcept;

        /**
         * \brief Adds the current vector with another.
         *
         * \param in_other The other vector to add with.
         *
         * \return The result of the addition.
         */
        [[nodiscard]]
        constexpr GenericVector& Add(GenericVector const& in_other) noexcept;

        /**
         * \brief Subtracts the current vector with another.
         *
         * \param in_other The other vector to subtract with.
         *
         * \return The result of the subtraction.
         */
        [[nodiscard]]
        constexpr GenericVector& Subtract(GenericVector const& in_other) noexcept;

        /**
         * \brief Multiplies the current vector with another.
         *
         * \param in_other The other vector to multiply with.
         *
         * \return The result of the multiplication.
         */
        [[nodiscard]]
        constexpr GenericVector& Multiply(GenericVector const& in_other) noexcept;

        /**
         * \brief Divides the current vector with another.
         * If a component of the given vector is equal to 0, the current vector equivalent component is set to 0.
         *
         * \param in_other The other vector to divide with.
         *
         * \return The result of the division.
         */
        [[nodiscard]]
        constexpr GenericVector& Divide(GenericVector const& in_other) noexcept;

        /**
         * \brief Adds the current vector with another.
         *
         * \param in_value The other vector to add with.
         *
         * \return The result of the addition.
         */
        [[nodiscard]]
        constexpr GenericVector& Add(TType in_value) noexcept;

        /**
         * \brief Subtracts the current vector with another.
         *
         * \param in_value The other vector to subtract with.
         *
         * \return The result of the subtraction.
         */
        [[nodiscard]]
        constexpr GenericVector& Subtract(TType in_value) noexcept;

        /**
         * \brief Multiplies the current vector with another.
         *
         * \param in_value The other vector to multiply with.
         *
         * \return The result of the multiplication.
         */
        [[nodiscard]]
        constexpr GenericVector& Multiply(TType in_value) noexcept;

        /**
         * \brief Divides the current vector with another.
         * If a component of the given vector is equal to 0, the current vector equivalent component is set to 0.
         *
         * \param in_value The other vector to divide with.
         *
         * \return The result of the division.
         */
        [[nodiscard]]
        constexpr GenericVector& Divide(TType in_value) noexcept;

        /**
         * \brief Checks if the vector is equals to the given one.
         *
         * \param in_other The other vector given to perform the check.
         *
         * \return True if they are equal, false otherwise.
         */
        [[nodiscard]]
        constexpr bool IsEqual(GenericVector const& in_other) const noexcept;

        /**
         * \brief Checks if the vector is not equals to the given one.
         *
         * \param in_other The other vector given to perform the check.
         *
         * \return True if they are not equal, false otherwise.
         */
        [[nodiscard]]
        constexpr bool IsNotEqual(GenericVector const& in_other) const noexcept;

        /**
         * \brief Return the dot product value performed with another vector
         *
         * \param in_other The other vector
         *
         * \return The dot product 
         */
        [[nodiscard]]
        constexpr TType Dot(GenericVector const& in_other) const noexcept;

        /**
         * \brief Return the cross product value performed with another vector
         *
         * \param in_other The other vector
         *
         * \return The cross product
         */
        [[nodiscard]]
        constexpr GenericVector Cross(GenericVector const& in_other) const noexcept;

        #pragma endregion

        #pragma region Operators

        constexpr GenericVector& operator=(GenericVector const& in_vector) noexcept = default;

        constexpr GenericVector& operator=(GenericVector&&      in_vector) noexcept = default;

        constexpr bool operator==(GenericVector const& in_rhs) const noexcept;

        constexpr bool operator!=(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector operator+(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector operator-(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector operator*(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector operator/(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector& operator+=(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector& operator-=(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector& operator*=(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector& operator/=(GenericVector const& in_rhs) const noexcept;

        constexpr GenericVector operator+(TType in_factor) const noexcept;

        constexpr GenericVector operator-(TType in_factor) const noexcept;

        constexpr GenericVector operator*(TType in_factor) const noexcept;

        constexpr GenericVector operator/(TType in_factor) const noexcept;

        constexpr GenericVector& operator+=(TType in_factor) const noexcept;

        constexpr GenericVector& operator-=(TType in_factor) const noexcept;

        constexpr GenericVector& operator*=(TType in_factor) const noexcept;

        constexpr GenericVector& operator/=(TType in_factor) const noexcept;

        constexpr TType const& operator[](size_t in_index) const noexcept;

        constexpr TType& operator[](size_t in_index) noexcept;

        constexpr GenericVector operator-() const noexcept;

        #pragma endregion
};

#include "GenericVector.inl"