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

#include "Matrix/GenericMatrix.hpp"

template<size_t TSize, typename TType = float>
class SquareMatrix : public GenericMatrix<TSize, TSize, TType>
{
	public:

		#pragma region Constructors

		constexpr SquareMatrix()                              noexcept = default;
		constexpr SquareMatrix(SquareMatrix const& in_matrix) noexcept = default;
		constexpr SquareMatrix(SquareMatrix&&      in_matrix) noexcept = default;
		constexpr ~SquareMatrix()                             noexcept = default;

		#pragma endregion

		#pragma region Static Methods

		/**
		 * \brief Creates an identity matrix, also called unit matrix
		 * \return Identity matrix
		 */
		static constexpr SquareMatrix Identity() noexcept;

		#pragma endregion 

		#pragma region Methods

		/**
		 * \brief Computes the transposed matrix
		 * \return Transposed matrix
		 */
		constexpr SquareMatrix& Transpose() noexcept;

		#pragma endregion 

		#pragma region Operators

		constexpr SquareMatrix& operator=(SquareMatrix const& in_other) noexcept = default;
		constexpr SquareMatrix& operator=(SquareMatrix&&	  in_other) noexcept = default;

		#pragma endregion
};

		
