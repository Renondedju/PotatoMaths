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

template <typename TType, typename>
constexpr TType Abs(TType in_value) noexcept
{
    return (in_value < 0) ? -in_value : in_value;
}

template <typename TType, typename>
constexpr TType Pow(TType in_value, TType in_exponent) noexcept
{
    return static_cast<TType>(std::pow(in_value, in_exponent));
}

template <typename TType, typename>
constexpr TType Ceil(TType in_value) noexcept
{
    return static_cast<TType>(std::ceil(in_value));
}

template <typename TType, typename>
constexpr TType Clamp(TType in_value, TType in_min, TType in_max) noexcept
{
    return (in_value < in_min) ? in_min : (in_value > in_max) ? in_max : in_value;
}

template <typename TType, typename>
constexpr TType Clamp01(TType in_value) noexcept
{
    return (in_value < static_cast<TType>(0)) ? static_cast<TType>(0) : (in_value > static_cast<TType>(1)) ? static_cast<TType>(1) : in_value;
}

template <typename TType, typename>
constexpr TType Round(TType in_value) noexcept
{
    return static_cast<TType>(std::round(in_value));
}

template <typename TType, typename>
constexpr TType Floor(TType in_value) noexcept
{
    return static_cast<TType>(std::floor(in_value));
}

template <typename TType, typename>
constexpr TType CopySign(TType in_value, TType in_sign) noexcept
{
    return static_cast<TType>(std::copysign(in_value, in_sign));
}

template <typename TType, typename>
constexpr TType Cos(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::cos(in_value));
}

template <typename TType, typename>
constexpr TType Sin(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::sin(in_value));
}

template <typename TType, typename>
constexpr TType Tan(GenericRadians<TType> in_value) noexcept
{
    return static_cast<TType>(std::tan(in_value));
}

template <typename TType, typename>
constexpr TType Exp(TType in_value) noexcept
{
    return static_cast<TType>(std::exp(in_value));
}

template <typename TType, typename>
constexpr TType Exp2(TType in_value) noexcept
{
    return static_cast<TType>(std::exp2(in_value));
}

template <typename TType, typename>
constexpr TType Mod(TType in_value, TType in_modulo) noexcept
{
    return static_cast<TType>(std::modf(in_value, in_modulo));
}

template <typename TType, typename>
constexpr TType Frac(TType in_value) noexcept
{
    return in_value - Floor<TType>(in_value);
}

template <typename TType, typename>
constexpr TType Sqrt(TType in_value) noexcept
{
    return static_cast<TType>(std::sqrt(in_value));
}

template <typename TType, typename>
constexpr TType InvSqrt(TType in_value) noexcept
{
    return static_cast<TType>(1) / Sqrt<TType>(in_value);
}

template <typename TType, typename>
constexpr bool IsFinite(TType in_value) noexcept
{
    return std::isfinite(in_value);
}

template <typename TType, typename>
constexpr bool IsInfinite(TType in_value) noexcept
{
    return std::isinf(in_value);
}

template <typename TType, typename>
constexpr bool IsNan(TType in_value) noexcept
{
    return std::isnan(in_value);
}

template <typename TType, typename>
constexpr TType Lerp(TType in_source, TType in_destination, TType in_ratio) noexcept
{
    return (in_source + in_ratio * (in_destination - in_source));
}

template <typename TType, typename>
constexpr TType PingPong(TType in_value, TType in_range) noexcept
{
    return in_range - Abs<TType>(Repeat<TType>(in_value, static_cast<TType>(2) * in_range) - in_range);
}

template <typename TType, typename>
constexpr TType Repeat(TType in_value, TType in_range) noexcept
{
    return Clamp<TType>(in_value - Floor<TType>(in_value / in_range) * in_range, 0.0, in_range);
}

template <typename TType, typename>
constexpr TType Min(TType in_lhs, TType in_rhs) noexcept
{
    return (in_lhs > in_rhs) ? in_rhs : in_lhs;
}

template <typename TType, typename>
constexpr TType Max(TType in_lhs, TType in_rhs) noexcept
{
    return (in_lhs < in_rhs) ? in_rhs : in_lhs;
}