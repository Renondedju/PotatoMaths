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

template <typename TMatrixType, typename TQuaternionType>
constexpr Matrix3x3<TMatrixType> RotationMatrix(Quaternion<TQuaternionType> const& in_quaternion) noexcept
{
    float const sqr_x (in_quaternion.x * in_quaternion.x);
    float const sqr_y (in_quaternion.y * in_quaternion.y);
    float const sqr_z (in_quaternion.z * in_quaternion.z);

    return Matrix3x3<TMatrixType>
    (
        1 - 2 * (sqr_y + sqr_z),
        2 * (in_quaternion.m_x * in_quaternion.m_y - in_quaternion.m_z * in_quaternion.m_w),
        2 * (in_quaternion.m_x * in_quaternion.m_z + in_quaternion.m_y * in_quaternion.m_w),

        2 * (in_quaternion.m_x * in_quaternion.m_y + in_quaternion.m_z * in_quaternion.m_w),
        1 - 2 * (sqr_x + sqr_z),
        2 * (in_quaternion.m_y * in_quaternion.m_z - in_quaternion.m_x * in_quaternion.m_w),

        2 * (in_quaternion.m_x * in_quaternion.m_z - in_quaternion.m_y * in_quaternion.m_w),
        2 * (in_quaternion.m_y * in_quaternion.m_z + in_quaternion.m_x * in_quaternion.m_w),
        1 - 2 * (sqr_x + sqr_y)
    );
}
