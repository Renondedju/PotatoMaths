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

template <size_t TRows, size_t TColumns, typename TType>
constexpr GenericMatrix<TRows, TColumns, TType>
	::GenericMatrix() noexcept:
		m_data {static_cast<TType>(0)}
{}

template <size_t TRows, size_t TColumns, typename TType>
template <typename ... TValues, typename>
constexpr GenericMatrix<TRows, TColumns, TType>
	::GenericMatrix(TValues... in_values) noexcept:
		m_data {TType(in_values)...}
{}

template <size_t TRows, size_t TColumns, typename TType>
constexpr size_t GenericMatrix<TRows, TColumns, TType>
	::Elements() const noexcept
{
	return TRows * TColumns;
}

template <size_t TRows, size_t TColumns, typename TType>
constexpr GenericMatrix<TColumns, TRows, TType> GenericMatrix<TRows, TColumns, TType>
	::GetTransposed() const noexcept
{
	GenericMatrix<TColumns, TRows, TType> transposed;

	for (size_t i = 0ull; i < Elements() / 2ull; ++i)
		transposed.m_data[i] = m_data[Elements() - i];

	return transposed;
}

template <size_t TRows, size_t TColumns, typename TType>
template <size_t TOtherRows, size_t TOtherColumns, typename TOtherType, typename TReturnType, typename>
constexpr GenericMatrix<TRows, TOtherColumns, TReturnType> GenericMatrix<TRows, TColumns, TType>
	::GetMultiplied(GenericMatrix<TOtherRows, TOtherColumns, TOtherType> const& in_other_matrix) const noexcept
{
	GenericMatrix<TRows, TOtherColumns, TReturnType> new_matrix;

	for (size_t row = 0ull; row < TRows; ++row)
    {
        for (size_t column = 0ull; column < TOtherColumns; ++column)
        {
            new_matrix.At(row, column) = static_cast<TReturnType>(0);
            for (size_t other_row = 0ull; other_row < TOtherRows; ++other_row)
                new_matrix.At(row, column) += At(row, other_row) * in_other_matrix.At(other_row, column);
        }
    }

	return new_matrix;
}

template <size_t TRows, size_t TColumns, typename TType>
constexpr TType const& GenericMatrix<TRows, TColumns, TType>
	::At(size_t in_row, size_t in_column) const noexcept
{
	return m_data[TRows * in_row + in_column];
}

template <size_t TRows, size_t TColumns, typename TType>
constexpr TType& GenericMatrix<TRows, TColumns, TType>
	::At(size_t in_row, size_t in_column) noexcept
{
	return m_data[TRows * in_row + in_column];
}

template <size_t TRows, size_t TColumns, typename TType>
template <size_t TInRow, size_t TInColumn>
constexpr TType const& GenericMatrix<TRows, TColumns, TType>
	::At() const noexcept
{
	return m_data[TRows * TInRow + TInColumn];
}

template <size_t TRows, size_t TColumns, typename TType>
template <size_t TInRow, size_t TInColumn>
constexpr TType& GenericMatrix<TRows, TColumns, TType>
	::At() noexcept
{
	return m_data[TRows * TInRow + TInColumn];
}