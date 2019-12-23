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

template<typename TMatrixType>
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
constexpr Matrix4x4<TMatrixType> RotationMatrixX(GenericRadians<TRadiansType> const in_angle) noexcept
{
    TMatrixType cos = static_cast<TMatrixType>(Cos<TRadiansType>(in_angle));
    TMatrixType sin = static_cast<TMatrixType>(Sin<TRadiansType>(in_angle));

    return Matrix4x4<TMatrixType>(1.0,  0.0,  0.0,  0.0,
                                  0.0,  cos, -sin,  0.0,
                                  0.0,  sin,  cos,  0.0,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrixY(GenericRadians<TRadiansType> const in_angle) noexcept
{
    TMatrixType cos = static_cast<TMatrixType>(Cos<TRadiansType>(in_angle));
    TMatrixType sin = static_cast<TMatrixType>(Sin<TRadiansType>(in_angle));

    return Matrix4x4<TMatrixType>(cos,  0.0,  sin,  0.0,
                                  0.0,  1.0,  0.0,  0.0,
                                 -sin,  0.0,  cos,  0.0,
                                  0.0,  0.0,  0.0,  1.0); 
}

template <typename TRadiansType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> RotationMatrixZ(GenericRadians<TRadiansType> const in_angle) noexcept
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
    GenericRadians<TRadiansType> const in_angle_x,
    GenericRadians<TRadiansType> const in_angle_y,
    GenericRadians<TRadiansType> const in_angle_z) noexcept
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

template <typename TType, typename TMatrixType, IsArithmetic<TType>>
constexpr Matrix4x4<TMatrixType> PerspectiveProjectionMatrix(GenericDegrees<TType> const in_fov, TType const in_aspect, TType const in_near, TType const in_far) noexcept
{
    float scale = 1.0f / Tan(static_cast<GenericRadians<TType>>(in_fov / static_cast<TType>(2)));

    return Matrix4x4<TMatrixType>(scale / in_aspect,  0.0  , 0.0                                    ,  0.0,
                                  0.0              , -scale, 0.0                                    ,  0.0,
                                  0.0              ,  0.0  , in_far / (in_near - in_far)            , -1.0,
                                  0.0              ,  0.0  , (in_near * in_far) / (in_near - in_far),  0.0);
}

template <typename TType, typename TMatrixType, IsArithmetic<TType>>
constexpr Matrix4x4<TMatrixType> OrthogonalProjectionMatrix(
        TType const in_left, TType const in_right, TType const in_bottom,
        TType const in_top,  TType const in_near , TType const in_far) noexcept
{
      return Matrix4x4<TMatrixType>(2.0f / (in_right - in_left),
      0.0f,
      0.0f,
      0.0f,

      0.0f,
      2.0f / (in_bottom - in_top),
      0.0f,
      0.0f,

      0.0f,
      0.0f,
      1.0f / (in_near - in_far),
      0.0f,

      -(in_right + in_left) / (in_right - in_left),
      -(in_bottom + in_top) / (in_bottom - in_top),
      in_near / (in_near - in_far),
      1.0f);
}

template <typename TVectorType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> LookAtMatrix(
        Vector3<TVectorType> const& in_from,
        Vector3<TVectorType> const& in_to,
        Vector3<TVectorType> const& in_up) noexcept
{
    Vector3<TVectorType> const forward   ((in_to - in_from   ).GetNormalized());
    Vector3<TVectorType> const right     (in_up.Cross(forward).GetNormalized());
    Vector3<TVectorType> const up        (forward.Cross(right));

    return Matrix4x4
    (
        right.m_x,  up.m_x, forward.m_x,    in_from.m_x,
        right.m_y,  up.m_y, forward.m_y,    in_from.m_y,
        right.m_z,  up.m_z, forward.m_z,    in_from.m_z,
        0.0f,       0.0f,   0.0f,           1.0f
    );
}

template <typename TVectorType, typename TQuaternionType, typename TMatrixType>
constexpr Matrix4x4<TMatrixType> ModelMatrix(
        Vector3   <TVectorType>     const& in_position,
        Quaternion<TQuaternionType> const& in_rotation,
        Vector3   <TVectorType>     const& in_scale) noexcept
{
    float const sqr_x (in_rotation.x * in_rotation.x);
    float const sqr_y (in_rotation.y * in_rotation.y);
    float const sqr_z (in_rotation.z * in_rotation.z);

    return Matrix4x4<TMatrixType>
    (
        (1 - 2 * (sqr_y + sqr_z)) * in_scale.m_x,
        2 * (in_rotation.m_x * in_rotation.m_y - in_rotation.m_z * in_rotation.m_w) * in_scale.m_y,
        2 * (in_rotation.m_x * in_rotation.m_z + in_rotation.m_y * in_rotation.m_w) * in_scale.m_z ,
        in_position.m_x,

        2 * (in_rotation.m_x * in_rotation.m_y + in_rotation.m_z * in_rotation.m_w) * in_scale.m_x,
        (1 - 2 * (sqr_x + sqr_z)) * in_scale.m_y,
        2 * (in_rotation.m_y * in_rotation.m_z - in_rotation.m_x * in_rotation.m_w) * in_scale.m_z,
        in_position.m_y,

        2 * (in_rotation.m_x * in_rotation.m_z - in_rotation.m_y * in_rotation.m_w) * in_scale.m_x,
        2 * (in_rotation.m_y * in_rotation.m_z + in_rotation.m_x * in_rotation.m_w) * in_scale.m_y,
        (1 - 2 * (sqr_x + sqr_y)) * in_scale.m_z,
        in_position.m_z,

        0.0f,
        0.0f,
        0.0f,
        1.0f
    );
}