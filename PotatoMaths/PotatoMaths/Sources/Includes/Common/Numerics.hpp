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

#include "Angles/Radians.hpp"
#include "Meta/TypeSubstitution.hpp"

/**
 * \brief Absolute value function
 *
 * \tparam TType Type to operate with
 * \param in_value Value to get the absolute of
 *
 * \return Absolute value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Abs(TType in_value) noexcept;

/**
 * \brief Power function
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 * \param in_exponent Exponent
 *
 * \return Empowered value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Pow(TType in_value, TType in_exponent) noexcept;

/**
 * \brief Converts a value given to the nearest greater or equal integer.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Ceiled value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Ceil(TType in_value) noexcept;

/**
 * \brief Clamps the value given between two value given min and max included
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 * \param in_min Minimum value
 * \param in_max Maximum value
 *
 * \return Clamped value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Clamp(TType in_value, TType in_min, TType in_max) noexcept;

/**
 * \brief Clamps the value given between 0 and 1 included
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Clamped value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Clamp01(TType in_value) noexcept;

/**
 * \brief Converts a value to the nearest integer. Rounds up when the fraction is .5
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Rounded value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Round(TType in_value) noexcept;

/**
 * \brief Converts a value given to the nearest less or equal integer.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Floored value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Floor(TType in_value) noexcept;

/**
 * \brief Compute a value with the magnitude of first argument and the sign of the second.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 * \param in_sign Sign value
 *
 * \return Signed value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType CopySign(TType in_value, TType in_sign) noexcept;

/**
 * \brief Compute the cosine of an angle given in radians
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Cosine of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Cos(GenericRadians<TType> in_value) noexcept;

/**
 * \brief Compute the arc cosine of an angle given in radians
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Arc cosine of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType ACos(GenericRadians<TType> in_value) noexcept;

/**
 * \brief Compute the sine of an angle given in radians
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Sinus of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Sin(GenericRadians<TType> in_value) noexcept;

/**
 * \brief Compute the tangent of an angle given in radians
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return The tangent of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Tan(GenericRadians<TType> in_value) noexcept;

/**
 * \brief Computes the exponential raised to the specified power
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Exponential value of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Exp(TType in_value) noexcept;

/**
 * \brief Compute the base 2 raised to the power given
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Result of two raised to the power of in_value.
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Exp2(TType in_value) noexcept;

/**
 * \brief Compute the modulo of in_value by in_modulo
 * \note Always returns remainder toward 0, not toward the smaller multiple of in_modulo.
 *
 * \tparam TType Type to operate with
 *
 * \param in_value Input value
 * \param in_modulo Modulo
 *
 * \return Remainder of in_value / in_modulo.
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Mod(TType in_value, TType in_modulo) noexcept;

/**
 * \brief Returns the fractional part of the given value.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Fractional part of in_value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Frac(TType in_value) noexcept;

/**
 * \brief Compute the square root of the given value
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Square root of in_value.
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Sqrt(TType in_value) noexcept;

/**
 * \brief Compute the inverse square root of the given value
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return Inverse square root of in_value.
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType InvSqrt(TType in_value) noexcept;

/**
 * \brief Check if the given value is a finite value.
 *
 * A finite value is any floating-point value that is neither infinite nor NaN (Not-A-Number).
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return True if the value is finite, false otherwise
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr bool IsFinite(TType in_value) noexcept;

/**
 * \brief Check if the given value is a infinite value.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return True if the value is infinite, false otherwise
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr bool IsInfinite(TType in_value) noexcept;

/**
 * \brief Check if the value given is not a number (NaN)
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 *
 * \return True if the value is Nan, false otherwise
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr bool IsNan(TType in_value) noexcept;

/**
 * \brief Computes a linear interpolation between two value
 *
 * \tparam TType Type to operate with
 *
 * \param in_source Source number
 * \param in_destination Destination number
 * \param in_ratio Interpolation ratio
 *
 * \return Interpolated value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Lerp(TType in_source, TType in_destination, TType in_ratio) noexcept;

/**
 * \brief PingPongs in_value, so that it is never larger than in_range and never smaller than 0.0.
 *
 * The returned value will move back and forth between 0 and in_range.
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 * \param in_range Range of the ping pong
 *
 * \return Transformed value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType PingPong(TType in_value, TType in_range) noexcept;

/**
 * \brief Loops a given value on a given range
 *
 * \tparam TType Type to operate with
 * \param in_value Input value
 * \param in_range Range of the loop
 *
 * \return Looped value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Repeat(TType in_value, TType in_range) noexcept;

/**
 * \brief Returns the minimum of the 2 passed values
 *
 * \tparam TType Type to operate with
 * \param in_lhs Left hand side operand
 * \param in_rhs Right hand side operand
 *
 * \return Minimum value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Min(TType in_lhs, TType in_rhs) noexcept;

/**
 * \brief  Returns the maximum of the 2 passed values
 *
 * \tparam TType Type to operate with
 * \param in_lhs Left hand side operand
 * \param in_rhs Right hand side operand
 *
 * \return Maximum value
 */
template <typename TType, IsArithmetic<TType> = true>
[[nodiscard]] constexpr TType Max(TType in_lhs, TType in_rhs) noexcept;

#include "Common/Numerics.inl"

#ifdef POTATO_ENABLE_TEMPLATE_PREGEN

extern template float  Abs(float)  noexcept;
extern template double Abs(double) noexcept;

extern template float  Pow(float , float ) noexcept;
extern template double Pow(double, double) noexcept;

extern template float  Ceil(float)  noexcept;
extern template double Ceil(double) noexcept;

extern template float  Clamp(float , float , float)  noexcept;
extern template double Clamp(double, double, double) noexcept;

extern template float  Clamp01(float)  noexcept;
extern template double Clamp01(double) noexcept;

extern template float  Round(float)  noexcept;
extern template double Round(double) noexcept;

extern template float  Floor(float)  noexcept;
extern template double Floor(double) noexcept;

extern template float  CopySign(float , float)  noexcept;
extern template double CopySign(double, double) noexcept;

extern template float  Cos(GenericRadians<float>)  noexcept;
extern template double Cos(GenericRadians<double>) noexcept;

extern template float  ACos(GenericRadians<float>)  noexcept;
extern template double ACos(GenericRadians<double>) noexcept;

extern template float  Sin(GenericRadians<float>)  noexcept;
extern template double Sin(GenericRadians<double>) noexcept;

extern template float  Tan(GenericRadians<float>)  noexcept;
extern template double Tan(GenericRadians<double>) noexcept;

extern template float  Exp(float)  noexcept;
extern template double Exp(double) noexcept;

extern template float  Exp2(float)  noexcept;
extern template double Exp2(double) noexcept;

extern template float  Mod(float , float)  noexcept;
extern template double Mod(double, double) noexcept;

extern template float  Frac(float)  noexcept;
extern template double Frac(double) noexcept;

extern template float  Sqrt(float)  noexcept;
extern template double Sqrt(double) noexcept;

extern template float  InvSqrt(float)  noexcept;
extern template double InvSqrt(double) noexcept;

extern template bool IsFinite(float)  noexcept;
extern template bool IsFinite(double) noexcept;

extern template bool IsInfinite(float)  noexcept;
extern template bool IsInfinite(double) noexcept;

extern template bool IsNan(float)  noexcept;
extern template bool IsNan(double) noexcept;

extern template float  Lerp(float , float , float)  noexcept;
extern template double Lerp(double, double, double) noexcept;

extern template float  PingPong(float , float)  noexcept;
extern template double PingPong(double, double) noexcept;

extern template float  Repeat(float , float)  noexcept;
extern template double Repeat(double, double) noexcept;

extern template float  Min(float , float)  noexcept;
extern template double Min(double, double) noexcept;

extern template float  Max(float , float)  noexcept;
extern template double Max(double, double) noexcept;

#endif