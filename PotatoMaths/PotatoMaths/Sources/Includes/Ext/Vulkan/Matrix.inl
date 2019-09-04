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

template<typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> ClipSpace() noexcept
{
    return Matrix4x4<TMatrixType>(1.0,  0.0,  0.0,  0.0,
                                  0.0, -1.0,  0.0,  0.0,
                                  0.0,  0.0,  0.5,  0.5,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TVectorType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> TranslationMatrix(Vector3<TVectorType> const& in_translation) noexcept
{
    return Matrix4x4<TMatrixType>(1.0,  0.0,  0.0,  in_translation.x,
                                  0.0,  1.0,  0.0,  in_translation.y,
                                  0.0,  0.0,  1.0,  in_translation.z,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrixX(GenericRadians<TRadiansType> in_angle) noexcept
{
    TMatrixType cos = static_cast<TMatrixType>(Cos<TRadiansType>(in_angle));
    TMatrixType sin = static_cast<TMatrixType>(Sin<TRadiansType>(in_angle));

    return Matrix4x4<TMatrixType>(1.0,  0.0,  0.0,  0.0,
                                  0.0,  cos, -sin,  0.0,
                                  0.0,  sin,  cos,  0.0,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrixY(GenericRadians<TRadiansType> in_angle) noexcept
{
    TMatrixType cos = static_cast<TMatrixType>(Cos<TRadiansType>(in_angle));
    TMatrixType sin = static_cast<TMatrixType>(Sin<TRadiansType>(in_angle));

    return Matrix4x4<TMatrixType>(cos,  0.0,  sin,  0.0,
                                  0.0,  1.0,  0.0,  0.0,
                                 -sin,  0.0,  cos,  0.0,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrixZ(GenericRadians<TRadiansType> in_angle) noexcept
{
    TMatrixType cos = static_cast<TMatrixType>(Cos<TRadiansType>(in_angle));
    TMatrixType sin = static_cast<TMatrixType>(Sin<TRadiansType>(in_angle));

    return Matrix4x4<TMatrixType>(cos, -sin,  0.0,  0.0,
                                  sin,  cos,  0.0,  0.0,
                                  0.0,  0.0,  1.0,  0.0,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrix(
    GenericRadians<TRadiansType> in_angle_x,
    GenericRadians<TRadiansType> in_angle_y,
    GenericRadians<TRadiansType> in_angle_z) noexcept
{
    return RotationMatrixZ(in_angle_x) * RotationMatrixY(in_angle_y) * RotationMatrixX(in_angle_z);
}

template <typename TVectorType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> ScaleMatrix(Vector3<TVectorType> const& in_scale) noexcept
{
    return Matrix4x4<TMatrixType>(in_scale.x,  0.0       ,  0.0       ,  0.0,
                                  0.0       ,  in_scale.y,  0.0       ,  0.0,
                                  0.0       ,  0.0       ,  in_scale.z,  0.0,
                                  0.0       ,  0.0       ,  0.0       ,  1.0); 
}