/*
 * MIT License
 * 
 * Copyright (c) 2019-2020 Basile Combet
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

#include <iomanip>
#include <ostream>

#include "Meta/TypeSubstitution.hpp"

template <size_t TRows, size_t TColumns, typename TType, IsArithmetic<TType> = true>
class GenericMatrix;

/**
 * \brief Generic matrix implementation
 * 
 * \tparam TRows Number of rows of the matrix
 * \tparam TColumns Number of columns of the matrix
 * \tparam TType Type of the matrix (default is float)
 * 
 * \note The matrix convention can be useful if you use multiple graphics API such as OpenGL, Vulkan or Direct3D
 */
template <size_t TRows, size_t TColumns, typename TType>
class __declspec(novtable) GenericMatrix<TRows, TColumns, TType>
{
    public:

        #pragma region Members

        TType data[TRows * TColumns];

        #pragma endregion

        #pragma region Constructors

        constexpr GenericMatrix() noexcept;
        constexpr GenericMatrix(GenericMatrix const& in_matrix) = default;
        constexpr GenericMatrix(GenericMatrix&&      in_matrix) = default;
                 ~GenericMatrix()                               = default;

        /**
         * \brief Element by element constructor
         * \tparam TValues Initial values types
         * \param in_values Initial values
         */
        template<typename... TValues, std::enable_if_t<sizeof...(TValues) == TRows * TColumns, bool> = true>
        constexpr GenericMatrix(TValues... in_values) noexcept;

        /**
         * \brief Array constructor
         * \param in_values array
         */
        constexpr GenericMatrix(TType const (&in_values)[TRows * TColumns]) noexcept;

        #pragma endregion

        #pragma region Static Methods

        /**
         * \brief Gets the number of elements stored in the matrix
         * \return Elements count of the matrix
         */
        [[nodiscard]]
        static constexpr size_t Elements() noexcept;

        #pragma endregion 
    
        #pragma region Methods
    
        /**
         * \brief Computes the transposed matrix
         * \return Transposed matrix
         */
        [[nodiscard]]
        constexpr GenericMatrix<TColumns, TRows, TType> GetTransposed() const noexcept;

        /**
         * \brief Multiplies this matrix with another one and returns the new resultant matrix 
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
                                   std::enable_if_t<TColumns == TOtherRows, bool> = true>
        [[nodiscard]]
        constexpr GenericMatrix<TRows, TOtherColumns, TReturnType> GetMultiplied(GenericMatrix<TOtherRows, TOtherColumns, TOtherType> const& in_other_matrix) const noexcept;

        /**
         * \brief Data getter/setter
         * 
         * \param in_row Row index (from 0 to TRows - 1)
         * \param in_column Column index (from 0 to TColumns - 1)
         * 
         * \return Value at the selected position
         */
        [[nodiscard]]
        constexpr TType const& At(size_t in_row, size_t in_column) const noexcept;
        [[nodiscard]]
        constexpr TType&	   At(size_t in_row, size_t in_column)		 noexcept;

        /**
         * \brief Templated data getter/setter
         * 
         * \tparam TInRow Row index (from 0 to TRows - 1)
         * \tparam TInColumn Column index (from 0 to TColumns - 1)
         * 
         * \note Use this method instead of the non templated method at as much as possible
         * 
         * \return Value at the selected position
         */
        template<size_t TInRow, size_t TInColumn>
        [[nodiscard]]
        constexpr TType const& At() const noexcept;
        
        template<size_t TInRow, size_t TInColumn>
        [[nodiscard]]
        constexpr TType&	   At()		  noexcept;

        #pragma endregion

        #pragma region Operators

        constexpr GenericMatrix& operator=(GenericMatrix const& in_other) noexcept = default;
        constexpr GenericMatrix& operator=(GenericMatrix&&		in_other) noexcept = default;

        #pragma endregion
};

#include "Matrix/GenericMatrix.inl"

/**
 * \brief ostream <<operator overload for the GenericMatrix class
 * 
 * \tparam TRows Number of rows of the matrix to display
 * \tparam TColumns Number of columns of the matrix to display
 * \tparam TType Type of the matrix to display
 * 
 * \param inout_stream Output stream 
 * \param in_matrix Matrix to display
 * 
 * \return Output stream instance
 */
template<size_t TRows, size_t TColumns, typename TType>
std::ostream & operator<<(std::ostream & inout_stream, GenericMatrix<TRows, TColumns, TType> const & in_matrix)
{
    inout_stream << std::setprecision(3) << std::fixed;
    for (size_t row = 0ull; row < TRows; ++row)
    {
        for (size_t column = 0ull; column < TColumns; ++column)
            inout_stream << ' ' << in_matrix.At(row, column);
        inout_stream << '\n';
    }

    return inout_stream;
}

/**
 * \brief Declares a compatibility copy constructor 
 * \param in_this_type class requiring the compatibility
 * \param in_parent_type Parent class
 */
#define DECLARE_MATRIX_COMPATIBILITY_COPY_CONSTRUCTOR(in_this_type, in_parent_type) \
    constexpr in_this_type(in_parent_type const& in_matrix) noexcept \
    { *this = static_cast<in_this_type>(in_matrix); }

/**
 * \brief Declares a compatibility move constructor 
 * \param in_this_type class requiring the compatibility
 * \param in_parent_type Parent class
 */
#define DECLARE_MATRIX_COMPATIBILITY_MOVE_CONSTRUCTOR(in_this_type, in_parent_type) \
    constexpr in_this_type(in_parent_type&& in_matrix) noexcept \
    { *this = std::forward<in_this_type>(static_cast<in_this_type&&>(in_matrix)); }

/**
 * \brief Declares a compatibility copy operator
 * \param in_this_type class requiring the compatibility
 * \param in_parent_type Parent class
 */
#define DECLARE_MATRIX_COMPATIBILITY_COPY_OPERATOR(in_this_type, in_parent_type) \
    constexpr in_this_type& operator=(in_parent_type const& in_matrix) noexcept \
    { *this = static_cast<in_this_type>(in_matrix); return *this; }

/**
 * \brief Declares a compatibility move operator 
 * \param in_this_type class requiring the compatibility
 * \param in_parent_type Parent class
 */
#define DECLARE_MATRIX_COMPATIBILITY_MOVE_OPERATOR(in_this_type, in_parent_type) \
    constexpr in_this_type& operator=(in_parent_type&& in_matrix) noexcept \
    { *this = std::forward<in_this_type>(static_cast<in_this_type&&>(in_matrix)); return *this; }