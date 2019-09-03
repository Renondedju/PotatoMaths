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

template <size_t TSize, typename TType>
template <typename ... TValuesType, typename>
constexpr GenericVector<TSize, TType>::GenericVector(TValuesType... in_values) noexcept:
    data {TType(in_values)...}
{}

template <size_t TSize, typename TType>
constexpr GenericVector<TSize, TType>::GenericVector(TType const* in_array) noexcept:
    data {}
{
    memcpy(data, in_array, TSize * sizeof TType);
}

template <size_t TSize, typename TType>
constexpr GenericVector<TSize, TType>::GenericVector() noexcept:
    Parent()
{}