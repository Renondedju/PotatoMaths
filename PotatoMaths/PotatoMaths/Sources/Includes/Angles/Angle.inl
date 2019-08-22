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

template <EAngleUnit TAngleUnit, typename TType>
template <typename TOtherType>
constexpr Angle<TAngleUnit, TType>::operator Angle<EAngleUnit::Degree, TOtherType>() const noexcept
{
    if constexpr (TAngleUnit == EAngleUnit::Radian)
		return Angle<EAngleUnit::Degree, TOtherType>(static_cast<TOtherType>(*this) * static_cast<TOtherType>(180.0) / static_cast<TOtherType>(POTATO_PI));

    return Angle<EAngleUnit::Degree, TOtherType>(static_cast<TOtherType>(*this));
}

template <EAngleUnit TAngleUnit, typename TType>
template <typename TOtherType>
constexpr Angle<TAngleUnit, TType>::operator Angle<EAngleUnit::Radian, TOtherType>() const noexcept
{
    if constexpr (TAngleUnit == EAngleUnit::Degree)
		return Angle<EAngleUnit::Radian, TOtherType>(static_cast<TOtherType>(*this) * static_cast<TOtherType>(POTATO_PI) / static_cast<TOtherType>(180.0));

    return Angle<EAngleUnit::Radian, TOtherType>(static_cast<TOtherType>(*this));
}