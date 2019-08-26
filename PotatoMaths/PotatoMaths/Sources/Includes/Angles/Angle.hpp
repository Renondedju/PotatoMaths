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

#include "Types/NamedType.hpp"
#include "Types/Operators/Bitwise.hpp"
#include "Types/Operators/Arithmetic.hpp"
#include "Types/Operators/Comparison.hpp"

#include "Angles/EAngleUnit.hpp"

// Used in conversion operators
#include "Constants.hpp"

namespace internal
{
    struct AnglePhantom {};
}

template <enum class EAngleUnit TAngleUnit, typename TType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
class Angle;

/**
 * \brief Degrees strong typing class
 * \tparam TType Underlying type
 */
template <enum class EAngleUnit TAngleUnit, typename TType>
class __declspec(novtable) Angle<TAngleUnit, TType> final:
    NamedType<TType, internal::AnglePhantom>,
    Arithmetic<Angle<TAngleUnit, TType>>,
    Comparison<Angle<TAngleUnit, TType>>,
    Bitwise   <Angle<TAngleUnit, TType>>
{
    public:

        #pragma region Constructors

        constexpr Angle()                       noexcept = default;
        constexpr Angle(Angle const& in_matrix) noexcept = default;
        constexpr Angle(Angle&&      in_matrix) noexcept = default;
        ~Angle()                                noexcept = default;

        using NamedType<TType, internal::AnglePhantom>::NamedType;

        #pragma endregion

        #pragma region Operators

        constexpr Angle& operator=(Angle const& in_other) noexcept = default;
        constexpr Angle& operator=(Angle&&		in_other) noexcept = default;

        /**
         * \brief Degree angle conversion
         * \tparam TOtherType New precision
         */
        template <typename TOtherType>
        [[nodiscard]]
        constexpr explicit operator Angle<EAngleUnit::Degree, TOtherType>() const noexcept;

        /**
         * \brief Radian angle conversion
         * \tparam TOtherType New precision
         */
        template <typename TOtherType>
        [[nodiscard]]
        constexpr explicit operator Angle<EAngleUnit::Radian, TOtherType>() const noexcept;

        #pragma endregion
};

#include "Angles/Angle.inl"

template <enum class EAngleUnit TAngleUnit>
using PreciseAngle = Angle<TAngleUnit, double>;

template <enum class EAngleUnit TAngleUnit>
using RelativeAngle = Angle<TAngleUnit, int>;