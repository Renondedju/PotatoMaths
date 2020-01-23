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

#include "Ext/Vulkan/Ext.hpp"
#include "Matrix/Matrix3x3.hpp"
#include "Quaternion/Quaternion.hpp"

POTATO_BEGIN_VK_EXT

/**
 * \brief Computes an homogenous rotation 3x3 matrix for a given quaternion
 *
 * \tparam TMatrixType Underlying type of the rotation matrix
 * \tparam TQuaternionType Underlying type of the quaternion
 *
 * \param in_quaternion Quaternion to compute the rotation matrix for
 *
 * \return Homogenous 3x3 rotation matrix
 */
template <typename TMatrixType, typename TQuaternionType>
constexpr Matrix3x3<TMatrixType> RotationMatrix(Quaternion<TQuaternionType> const& in_quaternion) noexcept;

#include "Ext/Vulkan/Quaternion.inl"

POTATO_END_VK_EXT