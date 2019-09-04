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

#include <cmath>

#include "Angles/Degrees.hpp"
#include "Angles/Radians.hpp"

template <typename TType = float, typename = std::enable_if_t<std::is_arithmetic_v<TType>>>
class Quaternion;

/**
 * \brief Quaternion class, used to represent 3D orientations and rotations.
 *
 * Unit quaternions provide a convenient mathematical notation for representing orientations and rotations of objects in three dimensions.
 * Compared to Euler angles they are simpler to compose and avoid the problem of gimbal lock.
 * Compared to rotation matrices they are more compact, more numerically stable, and more efficient.
 *
 * \tparam TType Base type of the quaternion
 */
template <typename TType>
class Quaternion<TType>
{
    public:

        #pragma region Members

        union { TType w; TType a; };
        union { TType x; TType b; };
        union { TType y; TType c; };
        union { TType z; TType d; };

        #pragma endregion

        #pragma region Constructors

        constexpr Quaternion()                            noexcept;
        constexpr Quaternion(Quaternion const& in_matrix) noexcept = default;
        constexpr Quaternion(Quaternion&&      in_matrix) noexcept = default;
                 ~Quaternion()                            noexcept = default;

        /**
         * \brief Creates a quaternion with the given values
         * 
         * \param in_w w component of the quaternion
         * \param in_x x component of the quaternion
         * \param in_y y component of the quaternion
         * \param in_z z component of the quaternion
         */
        constexpr Quaternion(TType in_w, TType in_x, TType in_y, TType in_z) noexcept;

        /**
         * \brief Creates a quaternion with the given rotations (using euler angles)
         * 
         * \param in_angle_x Angle to rotate around the x axis (in degrees)
         * \param in_angle_y Angle to rotate around the y axis (in degrees)
         * \param in_angle_z Angle to rotate around the z axis (in degrees)
         */
        template<typename TAngleType>
        constexpr Quaternion(GenericDegrees<TAngleType> in_angle_x, GenericDegrees<TAngleType> in_angle_y, GenericDegrees<TAngleType> in_angle_z) noexcept;

        #pragma endregion

        #pragma region Static Methods

        /**
         * \brief Quaternion linear interpolation
         * 
         * \tparam TShortestPath True if the method should lerp from in_lhs to in_rhs using the shortest path, false otherwise
         *
         * \param in_lhs The start quaternion
         * \param in_rhs The end quaternion
         * \param in_ratio The interpolation ratio. Should be between 0 and 1
         * 
         * \return A new quaternion which is the result of the linear interpolation between in_lhs and in_rhs at in_ratio
         */
        template <bool TShortestPath = true>
        static constexpr Quaternion Lerp(Quaternion const& in_lhs, Quaternion const& in_rhs, float in_ratio) noexcept;

        /**
         * \brief Quaternion spherical interpolation
         *
         * \tparam TShortestPath True if the method should slerp from in_lhs to in_rhs using the shortest path, false otherwise
         *
         * \param in_lhs The start quaternion
         * \param in_rhs The end quaternion
         * \param in_ratio The interpolation ratio. Should be between 0 and 1
         *
         * \return A new quaternion which is the result of the spherical linear interpolation between in_lhs and in_rhs at in_ratio
         */
        template <bool TShortestPath = true>
        static constexpr Quaternion Slerp(Quaternion const& in_lhs, Quaternion const& in_rhs, float in_ratio) noexcept;

        /**
         * \brief Computes the dot product between two quaternions
         * 
         * \param in_lhs Left hand side quaternion
         * \param in_rhs Right hand side quaternion
         * 
         * \return The resulting dot product
         */
        static constexpr TType Dot(Quaternion const& in_lhs, Quaternion const& in_rhs) noexcept;

        /**
         * \brief Normalizes a quaternion
         *
         * \param in_quaternion Quaternion to be normalized
         * \return Normalized quaternion
         */
        static constexpr Quaternion Normalize(Quaternion const& in_quaternion) noexcept;

        /**
         * \brief Computes the square length of the quaternion
         *
         * \param in_quaternion Quaternion instance
         * \return Squared length of the quaternion
         */
        static constexpr TType SqrLength(Quaternion const& in_quaternion) noexcept;

        /**
         * \brief Computes the length of the quaternion
         *
         * \param in_quaternion Quaternion instance
         * \return Length of the quaternion
         */
        static constexpr TType Length(Quaternion const& in_quaternion) noexcept;

        /**
         * \brief Inverts the passed quaternion
         *
         * \param in_quaternion Quaternion instance
         * \return Inverted quaternion
         */
        static constexpr Quaternion Invert(Quaternion const& in_quaternion) noexcept;

        /**
         * \brief Multiplies 2 quaternions together. This effectively represents composing the two rotations.
         * \param in_lhs Left hand side quaternion
         * \param in_rhs Right hand side quaternion
         * \return Resulting quaternions
         */
        static constexpr Quaternion Multiply(Quaternion const& in_lhs, Quaternion const& in_rhs) noexcept;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Quaternion linear interpolation
         * 
         * \tparam TShortestPath True if the method should lerp from in_lhs to in_rhs using the shortest path, false otherwise
         *
         * \param in_other Destination quaternion
         * \param in_ratio The interpolation ratio. Should be between 0 and 1
         * 
         * \return A new quaternion which is the result of the linear interpolation between in_lhs and in_rhs at in_ratio
         */
        template <bool TShortestPath = true>
        [[nodiscard]]
        constexpr Quaternion Lerp(Quaternion const& in_other, float in_ratio) const noexcept;

        /**
         * \brief Quaternion spherical interpolation
         *
         * \tparam TShortestPath True if the method should slerp from in_lhs to in_rhs using the shortest path, false otherwise
         *
         * \param in_other Destination quaternion
         * \param in_ratio The interpolation ratio. Should be between 0 and 1
         *
         * \return A new quaternion which is the result of the spherical linear interpolation between in_lhs and in_rhs at in_ratio
         */
        template <bool TShortestPath = true>
        [[nodiscard]]
        constexpr Quaternion Slerp(Quaternion const& in_other, float in_ratio) const noexcept;

        /**
         * \brief Computes the dot product between two quaternions
         * 
         * \param in_other Other quaternion
         * 
         * \return The resulting dot product
         */
        [[nodiscard]]
        constexpr TType Dot(Quaternion const& in_other) noexcept;

        /**
         * \brief Normalizes the quaternion
         * \return New normalized quaternion instance
         */
        [[nodiscard]]
        constexpr Quaternion GetNormalized() const noexcept;

        /**
         * \brief Normalizes the quaternion
         * \return Normalized quaternion
         */
        constexpr Quaternion& Normalize() noexcept;

        /**
         * \brief Computes the square length of the quaternion
         * \return Squared length of the quaternion
         */
        [[nodiscard]]
        constexpr TType SqrLength() noexcept;

        /**
         * \brief Computes the length of the quaternion
         * \return Length of the quaternion
         */
        [[nodiscard]]
        constexpr TType Length() noexcept;

        /**
         * \brief Inverts the quaternion
         * \return New inverted quaternion instance
         */
        [[nodiscard]]
        constexpr Quaternion GetInverted() const noexcept;

        /**
         * \brief Inverts the quaternion
         * \return Inverted quaternion
         */
        constexpr Quaternion& Invert() noexcept;

        /**
         * \brief Multiplies 2 quaternions together. This effectively represents composing the two rotations.
         * \param in_other Right hand side quaternion
         * \return New resulting quaternion instance
         */
        [[nodiscard]]
        constexpr Quaternion GetMultiplied(Quaternion const& in_other) const noexcept;

        /**
         * \brief Multiplies 2 quaternions together. This effectively represents composing the two rotations.
         * \param in_other Right hand side quaternion
         * \return Resulting quaternion
         */
        constexpr Quaternion& Multiply(Quaternion const& in_other) noexcept;

        #pragma endregion 

        #pragma region Operators

        constexpr Quaternion& operator=(Quaternion const& in_other) noexcept = default;
        constexpr Quaternion& operator=(Quaternion&&	  in_other) noexcept = default;

        /**
         * \brief Quaternion type cast
         * \tparam TOtherType Other quaternion type
         */
        template <typename TOtherType>
        explicit constexpr operator Quaternion<TOtherType>() const noexcept;

        #pragma endregion
};

#include "Quaternion/Quaternion.inl"