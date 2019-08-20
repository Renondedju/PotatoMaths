/*
 *  MIT License
 *
 *  Copyright (c) 2019 Renondedju, 6xray
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#pragma once

#include "Types/NamedType.hpp"

/**
 * \brief Less than class
 * 
 * This class is meant to be used in conjunction with the NamedType class.
 * This allows for better and quicker operator integrations to named types
 * 
 * \tparam TStrongTypedef Base NamedType
 * \see NamedType
 */
template <typename TStrongTypedef>
struct Less
{
	/**
	 * \brief Less than operator
	 * \param in_rhs Right hand side operand
	 * \param in_lhs Left hand side operand
	 * \return Returns true if lhs is less than rhs, false otherwise.
	 */
	friend constexpr bool operator<(TStrongTypedef const& in_rhs, TStrongTypedef const& in_lhs) noexcept
	{
		using Type = internal::UnderlyingType<TStrongTypedef>;

		return static_cast<Type const>(in_rhs) < static_cast<Type const>(in_lhs);
	}
};