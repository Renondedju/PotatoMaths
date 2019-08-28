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
constexpr SquareMatrix<TSize, TType> SquareMatrix<TSize, TType>
    ::Identity() noexcept
{
    SquareMatrix<TSize, TType> identity_matrix;

    for (size_t i = 0ull; i < TSize; ++i)
        identity_matrix.At(i, i) = static_cast<TType>(1);

    return identity_matrix;
}

template <size_t TSize, typename TType>
constexpr SquareMatrix<TSize, TType>& SquareMatrix<TSize, TType>
    ::Transpose() noexcept
{
    for (size_t i = 0ull; i < Parent::Elements() / 2; ++i)
        std::swap(Parent::data[i], Parent::data[Parent::Elements() - i]);

    return *this;
}

template <size_t TSize, typename TType>
constexpr void SquareMatrix<TSize, TType>
    ::LUDecomposition(SquareMatrix<TSize, TType>& out_l_matrix, SquareMatrix<TSize, TType>& out_u_matrix) const noexcept
{
    // Decomposing matrix into Upper and Lower
    // Triangular matrix 
    for (size_t i = 0ull; i < TSize; ++i)
    {
        // Upper Triangular 
        for (size_t k = i; k < TSize; ++k)
        {
            // Summation of L(i, j) * U(j, k) 
            TType sum = 0; 
            for (size_t j = 0ull; j < i; ++j) 
                sum += out_l_matrix.At(i, j) * out_u_matrix.At(j, k); 

            // Evaluating U(i, k) 
            out_u_matrix.At(i, k) = Parent::At(i, k) - sum; 
        }

        // Lower Triangular 
        for (size_t k = i; k < TSize; ++k)
        {
            if (i == k) 
                out_l_matrix.At(i, i) = static_cast<TType>(1); // Diagonal as 1 
            else
            { 
                // Summation of L(k, j) * U(j, i) 
                TType sum = 0; 
                for (int j = 0; j < i; j++) 
                    sum += out_l_matrix.At(k, j) * out_u_matrix.At(j, i); 

                // Evaluating L(k, i) 
                out_l_matrix.At(k, i) = (Parent::At(k, i) - sum) / out_u_matrix.At(i, i); 
            } 
        }
    }
}

// FIXME: Not working yet
template <size_t TSize, typename TType>
constexpr SquareMatrix<TSize, TType> SquareMatrix<TSize, TType>
    ::GetInverted() const noexcept
{
    SquareMatrix<TSize, TType> inverted_matrix;

    // Computing the LU matrices
    SquareMatrix<TSize, TType> l_matrix;
    SquareMatrix<TSize, TType> u_matrix;
    LUDecomposition(l_matrix, u_matrix);

    GenericMatrix<TSize, 1, TType> column_matrix;
    for (size_t column = 0Ui64; column < TSize; ++column)
    {
        // Filling the column matrix
        for (size_t row = 0Ui64; row < TSize; ++row)
            column_matrix.At(row, 0) = Parent::At(row, column);

        // Computing the inverted column
        column_matrix = u_matrix.GetMultiplied(l_matrix.GetMultiplied(column_matrix));

        // Filling the inverted matrix with the newly computed column
        for (size_t row = 0Ui64; row < TSize; ++row)
            inverted_matrix.At(row, column) = column_matrix.At(row, 0);
    }

    return inverted_matrix;
}