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

#include "Angles/Angle.hpp"

/**
 * \brief Degrees (float)
 */
template<typename TType = float>
using GenericDegrees = Angle<EAngleUnit::Degree, TType>;
using Degrees        = Angle<EAngleUnit::Degree, float>;

constexpr Angle<EAngleUnit::Degree, float> operator"" _deg(long double in_angle) noexcept;
constexpr Angle<EAngleUnit::Degree, float> operator"" _deg(size_t      in_angle) noexcept;

/**
 * \brief Precise degrees (double)
 */
using PreciseDegrees = PreciseAngle<EAngleUnit::Degree>;

constexpr PreciseAngle<EAngleUnit::Degree> operator"" _pdeg(long double in_angle) noexcept;
constexpr PreciseAngle<EAngleUnit::Degree> operator"" _pdeg(size_t      in_angle) noexcept;

/**
 * \brief Relative degrees (integers)
 */
using RelativeDegrees = RelativeAngle<EAngleUnit::Degree>;

constexpr RelativeAngle<EAngleUnit::Degree> operator"" _rdeg(long double in_angle) noexcept;
constexpr RelativeAngle<EAngleUnit::Degree> operator"" _rdeg(size_t      in_angle) noexcept;

#include "Angles/Degree.inl"

// Pre instantiation
extern template class Angle<EAngleUnit::Degree, int>;
extern template class Angle<EAngleUnit::Degree, float>;
extern template class Angle<EAngleUnit::Degree, double>;