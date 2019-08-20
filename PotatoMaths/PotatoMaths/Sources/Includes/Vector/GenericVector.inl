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

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType>
    ::GenericVector() noexcept :
        data {static_cast<TType>(0)}
{}

template <size_t TLength, typename TType>
constexpr GenericVector<TLength, TType> GenericVector<TLength, TType>
    ::Lerp(GenericVector const& in_from, GenericVector const& in_to, float in_ratio) noexcept
{
    //TODO

    return GenericVector<TLength, TType>();
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
