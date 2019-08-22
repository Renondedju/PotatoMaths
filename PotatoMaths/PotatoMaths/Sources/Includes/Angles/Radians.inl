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

constexpr Angle<EAngleUnit::Radian, float> operator"" _rad(long double const in_angle) noexcept
{
    return Angle<EAngleUnit::Radian, float>(in_angle);
}

constexpr Angle<EAngleUnit::Radian, float> operator"" _rad(size_t const in_angle) noexcept
{
    return Angle<EAngleUnit::Radian, float>(in_angle);
}

constexpr PreciseAngle<EAngleUnit::Radian> operator"" _prad(long double const in_angle) noexcept
{
    return PreciseAngle<EAngleUnit::Radian>(in_angle);
}

constexpr PreciseAngle<EAngleUnit::Radian> operator"" _prad(size_t const in_angle) noexcept
{
    return PreciseAngle<EAngleUnit::Radian>(in_angle);
}

constexpr RelativeAngle<EAngleUnit::Radian> operator"" _rrad(long double const in_angle) noexcept
{
    return RelativeAngle<EAngleUnit::Radian>(in_angle);
}
constexpr RelativeAngle<EAngleUnit::Radian> operator"" _rrad(size_t const in_angle) noexcept
{
    return RelativeAngle<EAngleUnit::Radian>(in_angle);
}