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

#include <cmath>

template <typename TType, IsArithmetic<TType>>
constexpr TType Abs(TType in_value) noexcept
{
    return (in_value < 0) ? -in_value : in_value;
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Pow(TType in_value, TType in_exponent) noexcept
{
    return static_cast<TType>(std::pow(in_value, in_exponent));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Ceil(TType in_value) noexcept
{
    return static_cast<TType>(std::ceil(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Clamp(TType in_value, TType in_min, TType in_max) noexcept
{
    return (in_value < in_min) ? in_min : (in_value > in_max) ? in_max : in_value;
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Clamp01(TType in_value) noexcept
{
    return (in_value < static_cast<TType>(0)) ? static_cast<TType>(0) : (in_value > static_cast<TType>(1)) ? static_cast<TType>(1) : in_value;
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Round(TType in_value) noexcept
{
    return static_cast<TType>(std::round(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Floor(TType in_value) noexcept
{
    return static_cast<TType>(std::floor(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType CopySign(TType in_value, TType in_sign) noexcept
{
    return static_cast<TType>(std::copysign(in_value, in_sign));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Cos(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::cos(static_cast<TType>(in_value)));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType ACos(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::acos(static_cast<TType>(in_value)));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Sin(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::sin(static_cast<TType>(in_value)));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Tan(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::tan(static_cast<TType>(in_value)));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Exp(TType in_value) noexcept
{
    return static_cast<TType>(std::exp(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Exp2(TType in_value) noexcept
{
    return static_cast<TType>(std::exp2(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Mod(TType in_value, TType in_modulo) noexcept
{
    return static_cast<TType>(std::modf(in_value, &in_modulo));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Frac(TType in_value) noexcept
{
    return in_value - Floor<TType>(in_value);
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Sqrt(TType in_value) noexcept
{
    return static_cast<TType>(std::sqrt(in_value));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType InvSqrt(TType in_value) noexcept
{
    return static_cast<TType>(1) / Sqrt<TType>(in_value);
}

template <typename TType, IsArithmetic<TType>>
constexpr bool IsFinite(TType in_value) noexcept
{
    return std::isfinite(in_value);
}

template <typename TType, IsArithmetic<TType>>
constexpr bool IsInfinite(TType in_value) noexcept
{
    return std::isinf(in_value);
}

template <typename TType, IsArithmetic<TType>>
constexpr bool IsNan(TType in_value) noexcept
{
    return std::isnan(in_value);
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Lerp(TType in_source, TType in_destination, TType in_ratio) noexcept
{
    return (in_source + in_ratio * (in_destination - in_source));
}

template <typename TType, IsArithmetic<TType>>
constexpr TType PingPong(TType in_value, TType in_range) noexcept
{
    return in_range - Abs<TType>(Repeat<TType>(in_value, static_cast<TType>(2) * in_range) - in_range);
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Repeat(TType in_value, TType in_range) noexcept
{
    return Clamp<TType>(in_value - Floor<TType>(in_value / in_range) * in_range, 0.0, in_range);
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Min(TType in_lhs, TType in_rhs) noexcept
{
    return (in_lhs > in_rhs) ? in_rhs : in_lhs;
}

template <typename TType, IsArithmetic<TType>>
constexpr TType MinExceptZero(TType in_lhs, TType in_rhs) noexcept
{
    if (in_lhs == static_cast<TType>(0))
        return in_rhs;

    return Min<TType>(in_lhs, in_rhs);
}

template <typename TType, IsArithmetic<TType>>
constexpr TType MinExceptZero(std::initializer_list<TType> in_list) noexcept
{
    TType count = std::numeric_limits<TType>::max();
    for (TType const& element: in_list)
        count = MinExceptZero<TType>(count, element);

    return count;
}

template <typename TType, IsArithmetic<TType>>
constexpr TType Max(TType in_lhs, TType in_rhs) noexcept
{
    return (in_lhs < in_rhs) ? in_rhs : in_lhs;
}
