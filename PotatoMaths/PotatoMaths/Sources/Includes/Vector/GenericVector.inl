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

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>
    ::GenericVector() noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    memset(&derived.data, 0, TLength * sizeof TType);
}

#pragma endregion

#pragma region Methods

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::Lerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept
{
    return in_from + in_ratio * (in_to - in_from);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::Slerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept
{
    TType const dot   = Dot(in_from, in_to);
    TType const theta = acos(dot) * in_ratio;

    GenericVector relative_vec = in_from - in_to * dot;

    relative_vec.Normalize();

    return ((in_from * cos(theta)) + relative_vec * sin(theta));
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType GenericVector<TDerived, TLength, TType>
    ::Dot(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept
{
    return in_lhs.Dot(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::Cross(GenericVector const& in_lhs, GenericVector const& in_rhs) noexcept
{
    return in_lhs.Cross(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType& GenericVector<TDerived, TLength, TType>
    ::At(size_t in_index) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    return derived.data[in_index];
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType const& GenericVector<TDerived, TLength, TType>
    ::At(size_t in_index) const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    return derived.data[in_index];
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType GenericVector<TDerived, TLength, TType>
    ::SqrLength() const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    size_t sqr_length = 0;

    for (size_t i = 0; i < TLength; ++i)
        sqr_length += derived.data[i] * derived.data[i];

    return sqr_length;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType GenericVector<TDerived, TLength, TType>
    ::Length() const noexcept
{
    return sqrt(SqrLength());
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Normalize() noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    TType const length (Length());

    if (length)
    {
        for (size_t i = 0; i < TLength; i++)
            derived.data[i] /= length;
    }

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::GetNormalized() const noexcept
{
    return GenericVector<TDerived, TLength, TType>(*this).Normalize();
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Add(GenericVector const& in_other) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] += in_other.At(i);

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Subtract(GenericVector const& in_other) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] -= in_other.At(i);

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Multiply(GenericVector const& in_other) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] *= in_other.At(i);

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Divide(GenericVector const& in_other) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] = (in_other.At(i) != 0) ? derived.data[i] / in_other.At(i) : 0;

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Add(TType in_value) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] += in_value;

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Subtract(TType in_value) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] -= in_value;

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Multiply(TType in_value) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] *= in_value;

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::Divide(TType in_value) noexcept
{
    TDerived& derived = static_cast<TDerived&>(*this);
    for (size_t i = 0; i < TLength; i++)
        derived.data[i] = (in_value != 0) ? derived.data[i] / in_value : 0;

    return *this;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr bool GenericVector<TDerived, TLength, TType>
    ::IsEqual(GenericVector const& in_other) const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    for (size_t i = 0; i < TLength; i++)
    {
        if (derived.data[i] != in_other.At(i))
            return false;
    }

    return true;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr bool GenericVector<TDerived, TLength, TType>
    ::IsNotEqual(GenericVector const& in_other) const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    for (size_t i = 0; i < TLength; i++)
    {
        if (derived.data[i] == in_other.At(i))
            return false;
    }

    return true;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType GenericVector<TDerived, TLength, TType>
    ::Dot(GenericVector const& in_other) const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    TType dot = 0;

    for (size_t i = 0; i < TLength; i++)
        dot += derived.data[i] * in_other.At(i);

    return dot;
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::Cross(GenericVector const& in_other) const noexcept
{
    TDerived const& derived = static_cast<TDerived const&>(*this);
    GenericVector result;

    for (size_t i = 0; i < TLength; i++)
        result.At(i) =  derived.data[(i + 1) % TLength] * in_other.At((i + 2) % TLength) -
                        in_other.At((i + 1) % TLength) * derived.data[(i + 2) % TLength];

    return result;
}

#pragma endregion

#pragma region Operators

template <typename TDerived, size_t TLength, typename TType>
constexpr bool GenericVector<TDerived, TLength, TType>
    ::operator==(GenericVector const& in_rhs) const noexcept
{
    return IsEqual(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr bool GenericVector<TDerived, TLength, TType>
    ::operator!=(GenericVector const& in_rhs) const noexcept
{
    return IsNotEqual(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator+(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Add(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator-(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Subtract(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator*(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Multiply(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator/(GenericVector const& in_rhs) const noexcept
{
    return GenericVector(*this).Divide(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator+(TType in_factor) const noexcept
{
    return GenericVector(*this).Add(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator-(TType in_factor) const noexcept
{
    return GenericVector(*this).Subtract(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator*(TType in_factor) const noexcept
{
    return GenericVector(*this).Multiply(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator/(TType in_factor) const noexcept
{
    return GenericVector(*this).Divide(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator+=(GenericVector const& in_rhs) noexcept
{
    return Add(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator-=(GenericVector const& in_rhs) noexcept
{
    return Subtract(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator*=(GenericVector const& in_rhs) noexcept
{
    return Multiply(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator/=(GenericVector const& in_rhs) noexcept
{
    return Divide(in_rhs);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator+=(TType in_factor) noexcept
{
    return Add(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator-=(TType in_factor) noexcept
{
    return Subtract(in_factor);
}
template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator*=(TType in_factor) noexcept
{
    return Multiply(in_factor);
}
template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType>& GenericVector<TDerived, TLength, TType>
    ::operator/=(TType in_factor) noexcept
{
    return Divide(in_factor);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType const& GenericVector<TDerived, TLength, TType>
    ::operator[](size_t const in_index) const noexcept
{
    return At(in_index);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr TType& GenericVector<TDerived, TLength, TType>
    ::operator[](size_t const in_index) noexcept
{
    return At(in_index);
}

template <typename TDerived, size_t TLength, typename TType>
constexpr GenericVector<TDerived, TLength, TType> GenericVector<TDerived, TLength, TType>
    ::operator-() const noexcept
{
    return GenericVector(*this).Multiply(-1);
}

#pragma endregion 