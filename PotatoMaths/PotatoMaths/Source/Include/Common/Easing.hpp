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

#include "Meta/TypeSubstitution.hpp"

// -> Linear interpolation (no easing)

/**
 * \brief Modeled after the line y = x
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType LinearInterpolation(TType in_p) noexcept;

// -> Quadratic easing: p^2

/**
 * \brief Modeled after the parabola y = x^2
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuadraticEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the parabola y = -x^2 + 2x
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuadraticEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise quadratic
 * y = (1/2)((2x)^2)             ; [0, 0.5)
 * y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuadraticEaseInOut(TType in_p) noexcept;

// -> Cubic easing: p^3

/**
 * \brief Modeled after the cubic y = x^3
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CubicEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the cubic y = (x - 1)^3 + 1
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CubicEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise cubic
 * y = (1/2)((2x)^3)       ; [0, 0.5)
 * y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CubicEaseInOut(TType in_p) noexcept;

// -> Quartic easing: p^4

/**
 * \brief Modeled after the quartic x^4
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuarticEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the quartic y = 1 - (x - 1)^4
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuarticEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise quartic
 * y = (1/2)((2x)^4)        ; [0, 0.5)
 * y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuarticEaseInOut(TType in_p) noexcept;

// -> Quintic easing: p^5

/**
 * \brief Modeled after the quintic y = x^5
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuinticEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the quintic y = (x - 1)^5 + 1
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuinticEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise quintic
 * y = (1/2)((2x)^5)       ; [0, 0.5)
 * y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType QuinticEaseInOut(TType in_p) noexcept;

// -> Sine wave easing: sin(p * PI/2)

/**
 * \brief Modeled after quarter-cycle of sine wave
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType SineEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after quarter-cycle of sine wave (different phase)
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType SineEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after half sine wave
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType SineEaseInOut(TType in_p) noexcept;

// -> Circular easing: sqrt(1 - p^2)

/**
 * \brief Modeled after shifted quadrant IV of unit circle
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CircularEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after shifted quadrant II of unit circle
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CircularEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise circular function
 * y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
 * y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType CircularEaseInOut(TType in_p) noexcept;

// -> Exponential easing, base 2

/**
 * \brief Modeled after the exponential function y = 2^(10(x - 1))
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ExponentialEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the exponential function y = -2^(-10x) + 1
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ExponentialEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise exponential
 * y = (1/2)2^(10(2x - 1))         ; [0,0.5)
 * y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ExponentialEaseInOut(TType in_p) noexcept;

// -> Exponentially-damped sine wave easing

/**
 * \brief Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ElasticEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ElasticEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise exponentially-damped sine wave:
 * y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5)
 * y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType ElasticEaseInOut(TType in_p) noexcept;

// -> Overshooting cubic easing

/**
 * \brief Modeled after the overshooting cubic y = x^3-x*sin(x*pi)
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BackEaseIn(TType in_p) noexcept;

/**
 * \brief Modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi))
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BackEaseOut(TType in_p) noexcept;

/**
 * \brief Modeled after the piecewise overshooting cubic function:
 * y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5)
 * y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1]
 *
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BackEaseInOut(TType in_p) noexcept;

// -> Exponentially-decaying bounce easing

/**
 * \brief
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BounceEaseIn(TType in_p) noexcept;

/**
 * \brief
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BounceEaseOut(TType in_p) noexcept;

/**
 * \brief
 * \tparam TType Type to operate with
 * \param in_p Value to ease, should be contained in the following range [0; 1]
 * \return Eased value, contained in the following range [0; 1]
 */
template <typename TType, IsFloatingPoint<TType> = true>
[[nodiscard]] TType BounceEaseInOut(TType in_p) noexcept;

#include "Common/Easing.inl"

#ifdef POTATO_ENABLE_TEMPLATE_PREGEN

// Template pre generation
extern template float  LinearInterpolation<float> (float)  noexcept;
extern template double LinearInterpolation<double>(double) noexcept;

extern template float  QuadraticEaseIn<float> (float)  noexcept;
extern template double QuadraticEaseIn<double>(double) noexcept;
extern template float  QuadraticEaseOut<float> (float)  noexcept;
extern template double QuadraticEaseOut<double>(double) noexcept;
extern template float  QuadraticEaseInOut<float> (float)  noexcept;
extern template double QuadraticEaseInOut<double>(double) noexcept;

extern template float  CubicEaseIn<float> (float)  noexcept;
extern template double CubicEaseIn<double>(double) noexcept;
extern template float  CubicEaseOut<float> (float)  noexcept;
extern template double CubicEaseOut<double>(double) noexcept;
extern template float  CubicEaseInOut<float> (float)  noexcept;
extern template double CubicEaseInOut<double>(double) noexcept;

extern template float  QuarticEaseIn<float> (float)  noexcept;
extern template double QuarticEaseIn<double>(double) noexcept;
extern template float  QuarticEaseOut<float> (float)  noexcept;
extern template double QuarticEaseOut<double>(double) noexcept;
extern template float  QuarticEaseInOut<float> (float)  noexcept;
extern template double QuarticEaseInOut<double>(double) noexcept;

extern template float  QuinticEaseIn<float> (float)  noexcept;
extern template double QuinticEaseIn<double>(double) noexcept;
extern template float  QuinticEaseOut<float> (float)  noexcept;
extern template double QuinticEaseOut<double>(double) noexcept;
extern template float  QuinticEaseInOut<float> (float)  noexcept;
extern template double QuinticEaseInOut<double>(double) noexcept;

extern template float  SineEaseIn<float> (float)  noexcept;
extern template double SineEaseIn<double>(double) noexcept;
extern template float  SineEaseOut<float> (float)  noexcept;
extern template double SineEaseOut<double>(double) noexcept;
extern template float  SineEaseInOut<float> (float)  noexcept;
extern template double SineEaseInOut<double>(double) noexcept;

extern template float  CircularEaseIn<float> (float)  noexcept;
extern template double CircularEaseIn<double>(double) noexcept;
extern template float  CircularEaseOut<float> (float)  noexcept;
extern template double CircularEaseOut<double>(double) noexcept;
extern template float  CircularEaseInOut<float> (float)  noexcept;
extern template double CircularEaseInOut<double>(double) noexcept;

extern template float  ExponentialEaseIn<float> (float)  noexcept;
extern template double ExponentialEaseIn<double>(double) noexcept;
extern template float  ExponentialEaseOut<float> (float)  noexcept;
extern template double ExponentialEaseOut<double>(double) noexcept;
extern template float  ExponentialEaseInOut<float> (float)  noexcept;
extern template double ExponentialEaseInOut<double>(double) noexcept;

extern template float  ElasticEaseIn<float> (float)  noexcept;
extern template double ElasticEaseIn<double>(double) noexcept;
extern template float  ElasticEaseOut<float> (float)  noexcept;
extern template double ElasticEaseOut<double>(double) noexcept;
extern template float  ElasticEaseInOut<float> (float)  noexcept;
extern template double ElasticEaseInOut<double>(double) noexcept;

extern template float  BackEaseIn<float> (float)  noexcept;
extern template double BackEaseIn<double>(double) noexcept;
extern template float  BackEaseOut<float> (float)  noexcept;
extern template double BackEaseOut<double>(double) noexcept;
extern template float  BackEaseInOut<float> (float)  noexcept;
extern template double BackEaseInOut<double>(double) noexcept;

extern template float  BounceEaseIn<float> (float)  noexcept;
extern template double BounceEaseIn<double>(double) noexcept;
extern template float  BounceEaseOut<float> (float)  noexcept;
extern template double BounceEaseOut<double>(double) noexcept;
extern template float  BounceEaseInOut<float> (float)  noexcept;
extern template double BounceEaseInOut<double>(double) noexcept;

#endif