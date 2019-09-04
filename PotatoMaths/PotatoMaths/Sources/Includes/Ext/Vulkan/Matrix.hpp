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

#include "Ext/Vulkan/Matrix.inl"

POTATO_END_VK_EXT