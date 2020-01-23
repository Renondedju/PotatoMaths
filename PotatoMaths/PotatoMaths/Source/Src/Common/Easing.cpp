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

#ifdef POTATO_ENABLE_TEMPLATE_PREGEN

#include "Common/Easing.hpp"

// Template pre generation
template float  LinearInterpolation<float> (float)  noexcept;
template double LinearInterpolation<double>(double) noexcept;

template float  QuadraticEaseIn<float> (float)  noexcept;
template double QuadraticEaseIn<double>(double) noexcept;
template float  QuadraticEaseOut<float> (float)  noexcept;
template double QuadraticEaseOut<double>(double) noexcept;
template float  QuadraticEaseInOut<float> (float)  noexcept;
template double QuadraticEaseInOut<double>(double) noexcept;

template float  CubicEaseIn<float> (float)  noexcept;
template double CubicEaseIn<double>(double) noexcept;
template float  CubicEaseOut<float> (float)  noexcept;
template double CubicEaseOut<double>(double) noexcept;
template float  CubicEaseInOut<float> (float)  noexcept;
template double CubicEaseInOut<double>(double) noexcept;

template float  QuarticEaseIn<float> (float)  noexcept;
template double QuarticEaseIn<double>(double) noexcept;
template float  QuarticEaseOut<float> (float)  noexcept;
template double QuarticEaseOut<double>(double) noexcept;
template float  QuarticEaseInOut<float> (float)  noexcept;
template double QuarticEaseInOut<double>(double) noexcept;

template float  QuinticEaseIn<float> (float)  noexcept;
template double QuinticEaseIn<double>(double) noexcept;
template float  QuinticEaseOut<float> (float)  noexcept;
template double QuinticEaseOut<double>(double) noexcept;
template float  QuinticEaseInOut<float> (float)  noexcept;
template double QuinticEaseInOut<double>(double) noexcept;

template float  SineEaseIn<float> (float)  noexcept;
template double SineEaseIn<double>(double) noexcept;
template float  SineEaseOut<float> (float)  noexcept;
template double SineEaseOut<double>(double) noexcept;
template float  SineEaseInOut<float> (float)  noexcept;
template double SineEaseInOut<double>(double) noexcept;

template float  CircularEaseIn<float> (float)  noexcept;
template double CircularEaseIn<double>(double) noexcept;
template float  CircularEaseOut<float> (float)  noexcept;
template double CircularEaseOut<double>(double) noexcept;
template float  CircularEaseInOut<float> (float)  noexcept;
template double CircularEaseInOut<double>(double) noexcept;

template float  ExponentialEaseIn<float> (float)  noexcept;
template double ExponentialEaseIn<double>(double) noexcept;
template float  ExponentialEaseOut<float> (float)  noexcept;
template double ExponentialEaseOut<double>(double) noexcept;
template float  ExponentialEaseInOut<float> (float)  noexcept;
template double ExponentialEaseInOut<double>(double) noexcept;

template float  ElasticEaseIn<float> (float)  noexcept;
template double ElasticEaseIn<double>(double) noexcept;
template float  ElasticEaseOut<float> (float)  noexcept;
template double ElasticEaseOut<double>(double) noexcept;
template float  ElasticEaseInOut<float> (float)  noexcept;
template double ElasticEaseInOut<double>(double) noexcept;

template float  BackEaseIn<float> (float)  noexcept;
template double BackEaseIn<double>(double) noexcept;
template float  BackEaseOut<float> (float)  noexcept;
template double BackEaseOut<double>(double) noexcept;
template float  BackEaseInOut<float> (float)  noexcept;
template double BackEaseInOut<double>(double) noexcept;

template float  BounceEaseIn<float> (float)  noexcept;
template double BounceEaseIn<double>(double) noexcept;
template float  BounceEaseOut<float> (float)  noexcept;
template double BounceEaseOut<double>(double) noexcept;
template float  BounceEaseInOut<float> (float)  noexcept;
template double BounceEaseInOut<double>(double) noexcept;

#endif