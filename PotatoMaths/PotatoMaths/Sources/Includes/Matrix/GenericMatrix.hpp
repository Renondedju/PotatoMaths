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

#include <type_traits>

/**
 * \brief Generic matrix implementation
 * 
 * \tparam TRows Number of rows of the matrix
 * \tparam TColumns Number of columns of the matrix
 * \tparam TType Type of the matrix (default is float)
 * 
 * \note The matrix convention can be useful if you use multiple graphics API such as OpenGL, Vulkan or Direct3D
 */
template <size_t TRows, size_t TColumns, typename TType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
class GenericMatrix
{
	public:

		#pragma region Members

		TType data[TRows * TColumns];

		#pragma endregion

		#pragma region Constructors

		constexpr GenericMatrix()                               noexcept = default;
		constexpr GenericMatrix(GenericMatrix const& in_matrix) noexcept = default;
		constexpr GenericMatrix(GenericMatrix&&      in_matrix) noexcept = default;
		constexpr ~GenericMatrix()                              noexcept = default;

		#pragma endregion

		#pragma region Methods

		/**
		 * \brief Computes the transposed matrix
		 * \return Transposed matrix
		 */
		constexpr GenericMatrix<TColumns, TRows, TType> GetTransposed() const noexcept;

		/**
		 * \brief Multiplies 2 matrices together. 
		 * 
		 * \tparam TOtherRows Other matrix rows count
		 * \tparam TOtherColumns Other matrix columns count
		 * \tparam TOtherType Other matrix type
		 * \tparam TReturnType Type of the new matrix (default is std::common_type_t<TType, TOtherType>)
		 * 
		 * \return New matrix resulting of the multiplication of the 2 previous matrices
		 */
		template <size_t TOtherRows, size_t TOtherColumns, typename TOtherType,
			typename TReturnType = std::common_type_t<TType, TOtherType>,
			typename			 = std::enable_if_t<TColumns == TOtherRows>>
		constexpr GenericMatrix<TRows, TOtherColumns, TReturnType> Multiply(GenericMatrix<TOtherRows, TOtherColumns, TOtherType> const& in_other_matrix) const noexcept;
		 
		/**
		 * \brief Inverses the matrix
		 * \return Matrix instance
		 */
		constexpr GenericMatrix& Inverse() noexcept;

		/**
		 * \brief Returns the inverted version of the matrix
		 * \return New inverted matrix
		 */
		constexpr GenericMatrix GetInversed() const noexcept;

		/**
		 * \brief Data getter/setter
		 * 
		 * \param in_row Row index (from 0 to TRows - 1)
		 * \param in_column Column index (from 0 to TColumns - 1)
		 * 
		 * \return Value at the selected position
		 */
		constexpr TType const& At(size_t in_row, size_t in_column) const noexcept;
		constexpr TType&	   At(size_t in_row, size_t in_column)		 noexcept;

		/**
		 * \brief Data getter/setter
		 * 
		 * \tparam TInRow Row index (from 0 to TRows - 1)
		 * \tparam TInColumn Column index (from 0 to TColumns - 1)
		 * 
		 * \note Use this method instead of the non templated method at as much as possible
		 * 
		 * \return Value at the selected position
		 */
		template<size_t TInRow, size_t TInColumn, typename = std::enable_if_t<TInRow < TRows && TInColumn < TColumns>>
		constexpr TType const& At() const noexcept;
		
		template<size_t TInRow, size_t TInColumn, typename = std::enable_if_t<TInRow < TRows && TInColumn < TColumns>>
		constexpr TType&	   At()		  noexcept;

		#pragma endregion

		#pragma region Operators

		constexpr GenericMatrix& operator=(GenericMatrix const& in_other) noexcept = default;
		constexpr GenericMatrix& operator=(GenericMatrix&&		in_other) noexcept = default;

		#pragma endregion
};

#include "Matrix/GenericMatrix.inl"