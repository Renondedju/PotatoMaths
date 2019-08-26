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

#pragma region Constructors

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>
    ::GenericVector() noexcept :
        data {static_cast<TType>(0)}
{}

template <size_t TLength, typename TType>
template <typename ... TValues, typename>
constexpr GenericVector<TLength, TType>
    ::GenericVector(TValues ... in_values) noexcept :
        data {TType(in_values)...}
{}

#pragma endregion

#pragma region Methods

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::Lerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept
{
    return in_from + in_ratio * (in_to - in_from);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::Slerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept
{
    TType const dot = Dot(in_from, in_to);
    TType const theta = acos(dot) * in_ratio;

    GenericVector relativeVec = in_from - in_to * dot;

    relativeVec.Normalize();

    return ((in_from * cos(theta)) + relativeVec * sin(theta));
}

template <size_t TLength, typename TType>
constexpr TType GenericVector<TLength, TType>
    ::Dot(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept
{
    return in_lhs.Dot(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::Cross(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept
{
    return in_lhs.Cross(in_rhs);
}

template <size_t TLength, typename TType>
constexpr TType& GenericVector<TLength, TType>
    ::At(size_t in_index) noexcept
{
    return data[in_index];
}

template <size_t TLength, typename TType>
constexpr TType const& GenericVector<TLength, TType>
    ::At(size_t in_index) const noexcept
{
    return data[in_index];
}

template <size_t TLength, typename TType>
constexpr TType GenericVector<TLength, TType>
    ::SqrLength() const noexcept
{
    size_t sqrLength = 0;

    for (size_t i = 0; i < TLength; i++)
        sqrLength = data[i] * data[i];

    return sqrLength;
}

template <size_t TLength, typename TType>
constexpr TType GenericVector<TLength, TType>
    ::Length() const noexcept
{
    return sqrt(SqrLength());
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Normalize() noexcept
{
    TType const length (Length());

    if (length)
    {
        for (size_t i = 0; i < TLength; i++)
            data[i] /= length;
    }

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::GetNormalized() const noexcept
{
    return GenericVector<TLength, TType>(*this).Normalize();
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Add(GenericVector const& in_other) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] += in_other.At(i);

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Subtract(GenericVector const& in_other) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] -= in_other.At(i);

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Multiply(GenericVector const& in_other) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] *= in_other.At(i);

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Divide(GenericVector const& in_other) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] = (in_other.At(i) != 0) ? data[i] / in_other.At(i) : 0;

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Add(TType in_value) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] += in_value;

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Subtract(TType in_value) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] -= in_value;

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Multiply(TType in_value) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] *= in_value;

    return *this;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::Divide(TType in_value) noexcept
{
    for (size_t i = 0; i < TLength; i++)
        data[i] = (in_value != 0) ? data[i] / in_value : 0;

    return *this;
}

template <size_t TLength, typename TType>
constexpr bool GenericVector<TLength, TType>
    ::IsEqual(GenericVector const& in_other) const noexcept
{
    for (size_t i = 0; i < TLength; i++)
    {
        if (data[i] != in_other.At(i))
            return false;
    }

    return true;
}

template <size_t TLength, typename TType>
constexpr bool GenericVector<TLength, TType>
    ::IsNotEqual(GenericVector const& in_other) const noexcept
{
    for (size_t i = 0; i < TLength; i++)
    {
        if (data[i] == in_other.At(i))
            return false;
    }

    return true;
}

template <size_t TLength, typename TType>
constexpr TType GenericVector<TLength, TType>
    ::Dot(GenericVector const& in_other) const noexcept
{
    TType dot = 0;

    for (size_t i = 0; i < TLength; i++)
        dot += data[i] * in_other.At(i);

    return dot;
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::Cross(GenericVector const& in_other) const noexcept
{
    GenericVector result;

    for (size_t i = 0; i < TLength; i++)
        result.At(i) =  data[(i + 1) % TLength] * in_other.At((i + 2) % TLength) -
                        in_other.At((i + 1) % TLength) * data[(i + 2) % TLength];

    return result;
}

#pragma endregion

#pragma region Operators

template <size_t TLength, typename TType>
constexpr bool GenericVector<TLength, TType>
    ::operator==(GenericVector const& in_rhs) const noexcept
{
    return IsEqual(in_rhs);
}

template <size_t TLength, typename TType>
constexpr bool GenericVector<TLength, TType>
    ::operator!=(GenericVector const& in_rhs) const noexcept
{
    return IsNotEqual(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator+(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Add(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator-(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Subtract(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator*(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Multiply(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator/(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Divide(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator+(TType in_factor) const noexcept
{
    return GenericVector(*this).Add(in_factor);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator-(TType in_factor) const noexcept
{
    return GenericVector(*this).Subtract(in_factor);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator*(TType in_factor) const noexcept
{
    return GenericVector(*this).Multiply(in_factor);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator/(TType in_factor) const noexcept
{
    return GenericVector(*this).Divide(in_factor);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator+=(GenericVector const& in_rhs) const noexcept
{
    return Add(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator-=(GenericVector const& in_rhs) const noexcept
{
    return Subtract(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator*=(GenericVector const& in_rhs) const noexcept
{
    return Multiply(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator/=(GenericVector const& in_rhs) const noexcept
{
    return Divide(in_rhs);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator+=(TType in_factor) const noexcept
{
    return Add(in_factor);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator-=(TType in_factor) const noexcept
{
    return Subtract(in_factor);
}
template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator*=(TType in_factor) const noexcept
{
    return Multiply(in_factor);
}
template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>& GenericVector<TLength, TType>
    ::operator/=(TType in_factor) const noexcept
{
    return Divide(in_factor);
}

template <size_t TLength, typename TType>
constexpr TType const& GenericVector<TLength, TType>
    ::operator[](size_t in_index) const noexcept
{
    return At(in_index);
}

template <size_t TLength, typename TType>
constexpr TType& GenericVector<TLength, TType>
    ::operator[](size_t in_index) noexcept
{
    return At(in_index);
}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::operator-() const noexcept
{
    return GenericVector(*this).Multiply(-1);
}

#pragma endregion 