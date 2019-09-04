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

#include "Ext/Vulkan/Ext.hpp"

#include "Quaternion/Quaternion.hpp"
#include "Numerics/Numerics.hpp"
#include "Matrix/Matrix4x4.hpp"
#include "Angles/Radians.hpp"
#include "Vector/Vector3.hpp"

POTATO_BEGIN_VK_EXT

/**
 * \brief Returns the clip space of the Vulkan API.
 *
 * This matrix is generally used in conjunction with a projection matrix to convert an object from the view space to the clip space
 * This matrix allows to do the following transformations:
 *  Position.y = -Position.y;
 *  Position.z = (Position.z + Position.w) / 2.0;
 *
 * \see An example of the use of this matrix: https://github.com/LunarG/VulkanSamples/commit/0dd36179880238014512c0637b0ba9f41febe803
 * 
 * \tparam TMatrixType Matrix return type (default: float)
 * \return Vulkan clip space matrix
 */
template<typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> ClipSpace() noexcept;

/**
 * \brief Generates a translation matrix.
 *
 * \tparam TVectorType Underlying type of the input translation
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_translation Translation of the matrix
 *
 * \return Translation matrix
 */
template<typename TVectorType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> TranslationMatrix(Vector3<TVectorType> const& in_translation) noexcept;

/**
 * \brief Creates a rotation matrix for the X axis
 *
 * \tparam TRadiansType Underlying type of the input angle
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_angle Angle of the X axis rotation (in radians)
 *
 * \return X axis rotation matrix
 */
template<typename TRadiansType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> RotationMatrixX(GenericRadians<TRadiansType> in_angle) noexcept;

/**
 * \brief Creates a rotation matrix for the Y axis
 *
 * \tparam TRadiansType Underlying type of the input angle
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_angle Angle of the Y axis rotation (in radians)
 *
 * \return Y axis rotation matrix
 */
template<typename TRadiansType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> RotationMatrixY(GenericRadians<TRadiansType> in_angle) noexcept;

/**
 * \brief Creates a rotation matrix for the Z axis
 *
 * \tparam TRadiansType Underlying type of the input angle
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_angle Angle of the Z axis rotation (in radians)
 *
 * \return Z axis rotation matrix
 */
template<typename TRadiansType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> RotationMatrixZ(GenericRadians<TRadiansType> in_angle) noexcept;

/**
 * \brief Creates a rotation matrix
 *
 * \tparam TRadiansType Underlying type of the input angles
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_angle_x X Angle of the matrix
 * \param in_angle_y Y Angle of the matrix
 * \param in_angle_z Z Angle of the matrix
 *
 * \return Rotation matrix
 */
template<typename TRadiansType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> RotationMatrix(
        GenericRadians<TRadiansType> in_angle_x,
        GenericRadians<TRadiansType> in_angle_y,
        GenericRadians<TRadiansType> in_angle_z) noexcept;

/**
 * \brief Creates a scale matrix
 *
 * \tparam TVectorType Underlying type of the input scale
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_scale Scale of the matrix
 *
 * \return Scale matrix
 */
template<typename TVectorType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> ScaleMatrix(Vector3<TVectorType> const& in_scale) noexcept;

/**
 * \brief Creates a perspective projection matrix
 *
 * \tparam TType Input type
 * \tparam TMatrixType Underlying matrix type
 *
 * \param in_fov Field of view
 * \param in_aspect Aspect ratio of the viewport
 * \param in_near Near plane distance (cannot be 0 or negative !)
 * \param in_far Far plane distance
 *
 * \return New perspective projection matrix
 */
template <typename TType, typename TMatrixType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
constexpr Matrix4x4<TMatrixType> PerspectiveProjectionMatrix(TType in_fov, TType in_aspect, TType in_near, TType in_far) noexcept;

/**
 * \brief Creates an orthogonal projection matrix
 *
 * \tparam TType Input type 
 * \tparam TMatrixType Underlying matrix type
 *
 * \param in_left Left plane distance
 * \param in_right Right plane distance
 * \param in_bottom Bottom plane distance
 * \param in_top Top plane distance
 * \param in_near Near plane distance
 * \param in_far Far plane distance
 *
 * \return Orthogonal projection matrix
 */
template <typename TType, typename TMatrixType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
constexpr Matrix4x4<TMatrixType> OrthogonalProjectionMatrix(
        TType in_left  , TType in_right, 
        TType in_bottom, TType in_top, 
        TType in_near  , TType in_far) noexcept;

/**
 * \brief Creates model matrix to look at a specific point in the world
 *
 * \tparam TVectorType Underlying type of input vectors 
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_from Position to look from
 * \param in_to Position to look at
 * \param in_up Up vector
 *
 * \return Look at matrix
 */
template<typename TVectorType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> LookAtMatrix(
        Vector3<TVectorType> const& in_from,
        Vector3<TVectorType> const& in_to,
        Vector3<TVectorType> const& in_up) noexcept;

/**
 * \brief Model matrix, also called TRS
 *
 * \tparam TVectorType Underling type if input vectors
 * \tparam TQuaternionType Underlying type of input quaternion
 * \tparam TMatrixType Underlying type of the output matrix
 *
 * \param in_position Model position
 * \param in_rotation Model rotation
 * \param in_scale Model scale
 *
 * \return Model (TRS) matrix
 */
template<typename TVectorType, typename TQuaternionType, typename TMatrixType = float>
constexpr Matrix4x4<TMatrixType> ModelMatrix(
        Vector3   <TVectorType>     const& in_position,
        Quaternion<TQuaternionType> const& in_rotation,
        Vector3   <TVectorType>     const& in_scale) noexcept;

#include "Ext/Vulkan/Matrix.inl"

POTATO_END_VK_EXT