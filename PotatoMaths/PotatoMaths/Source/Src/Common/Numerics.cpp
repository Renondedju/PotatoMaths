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

#include "Common/Numerics.hpp"

template float  Abs(float)  noexcept;
template double Abs(double) noexcept;

template float  Pow(float , float ) noexcept;
template double Pow(double, double) noexcept;

template float  Ceil(float)  noexcept;
template double Ceil(double) noexcept;

template float  Clamp(float , float , float)  noexcept;
template double Clamp(double, double, double) noexcept;

template float  Clamp01(float)  noexcept;
template double Clamp01(double) noexcept;

template float  Round(float)  noexcept;
template double Round(double) noexcept;

template float  Floor(float)  noexcept;
template double Floor(double) noexcept;

template float  CopySign(float , float)  noexcept;
template double CopySign(double, double) noexcept;

template float  Cos(GenericRadians<float>)  noexcept;
template double Cos(GenericRadians<double>) noexcept;

template float  ACos(GenericRadians<float>)  noexcept;
template double ACos(GenericRadians<double>) noexcept;

template float  Sin(GenericRadians<float>)  noexcept;
template double Sin(GenericRadians<double>) noexcept;

template float  Tan(GenericRadians<float>)  noexcept;
template double Tan(GenericRadians<double>) noexcept;

template float  Exp(float)  noexcept;
template double Exp(double) noexcept;

template float  Exp2(float)  noexcept;
template double Exp2(double) noexcept;

template float  Mod(float , float)  noexcept;
template double Mod(double, double) noexcept;

template float  Frac(float)  noexcept;
template double Frac(double) noexcept;

template float  Sqrt(float)  noexcept;
template double Sqrt(double) noexcept;

template float  InvSqrt(float)  noexcept;
template double InvSqrt(double) noexcept;

template bool IsFinite(float)  noexcept;
template bool IsFinite(double) noexcept;

template bool IsInfinite(float)  noexcept;
template bool IsInfinite(double) noexcept;

template bool IsNan(float)  noexcept;
template bool IsNan(double) noexcept;

template float  Lerp(float , float , float)  noexcept;
template double Lerp(double, double, double) noexcept;

template float  PingPong(float , float)  noexcept;
template double PingPong(double, double) noexcept;

template float  Repeat(float , float)  noexcept;
template double Repeat(double, double) noexcept;

template float  Min(float , float)  noexcept;
template double Min(double, double) noexcept;

template float  Max(float , float)  noexcept;
template double Max(double, double) noexcept;

#endif