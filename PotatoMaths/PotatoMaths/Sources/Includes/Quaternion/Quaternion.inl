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

template <typename TType>
constexpr Quaternion<TType>::Quaternion() noexcept:
    w {1.0f},
    x {0.0f},
    y {0.0f},
    z {0.0f}
{}

template <typename TType>
constexpr Quaternion<TType>::Quaternion(TType const in_w, TType const in_x, TType const in_y, TType const in_z) noexcept:
    w {in_w},
    x {in_x},
    y {in_y},
    z {in_z}
{}

template <typename TType>
template<typename TAngleType>
constexpr Quaternion<TType>::Quaternion(GenericDegrees<TAngleType> const in_angle_x,
                                        GenericDegrees<TAngleType> const in_angle_y,
                                        GenericDegrees<TAngleType> const in_angle_z) noexcept
{
    GenericRadians<TAngleType> half_x_angle = static_cast<GenericRadians<TAngleType>>(in_angle_x) / 2.0f;
    GenericRadians<TAngleType> half_y_angle = static_cast<GenericRadians<TAngleType>>(in_angle_y) / 2.0f;
    GenericRadians<TAngleType> half_z_angle = static_cast<GenericRadians<TAngleType>>(in_angle_z) / 2.0f;

    TType const cos_x = Cos<TType>(half_x_angle);
    TType const cos_y = Cos<TType>(half_y_angle);
    TType const cos_z = Cos<TType>(half_z_angle);

    TType const sin_x = Sin<TType>(half_x_angle);
    TType const sin_y = Sin<TType>(half_y_angle);
    TType const sin_z = Sin<TType>(half_z_angle);

    w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
    x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
    y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
    z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
}

template <typename TType>
template <bool TShortestPath>
constexpr Quaternion<TType> Quaternion<TType>::Lerp(Quaternion const& in_lhs, Quaternion const& in_rhs, float const in_ratio) noexcept
{
    float conjugate_ratio = 1.0f - in_ratio;

    if constexpr (TShortestPath)
    {
        float const sign = (Quaternion::Dot(in_lhs, in_rhs) < 0.0f) ? -1.0f : 1.0f;

        return Quaternion(conjugate_ratio * in_lhs.w + sign * in_ratio * in_rhs.w,
                          conjugate_ratio * in_lhs.x + sign * in_ratio * in_rhs.x,
                          conjugate_ratio * in_lhs.y + sign * in_ratio * in_rhs.y,
                          conjugate_ratio * in_lhs.z + sign * in_ratio * in_rhs.z);
    }

    return Quaternion(conjugate_ratio * in_lhs.w + in_ratio * in_rhs.w,
                      conjugate_ratio * in_lhs.x + in_ratio * in_rhs.x,
                      conjugate_ratio * in_lhs.y + in_ratio * in_rhs.y,
                      conjugate_ratio * in_lhs.z + in_ratio * in_rhs.z);
}

template <typename TType>
template <bool TShortestPath>
constexpr Quaternion<TType> Quaternion<TType>::Slerp(Quaternion const& in_lhs, Quaternion const& in_rhs, float const in_ratio) noexcept
{
    TType const dot_result = Quaternion::Dot(in_lhs, in_rhs);
    TType const abs_dot    = Abs <TType>(dot_result);
    TType const theta      = ACos<TType>(abs_dot);
    TType const sin_theta  = Sin <TType>(theta);

    if constexpr (TShortestPath)
    {
        float const sign = (dot_result < 0.0f) ? -1.0f : 1.0f;

        return Quaternion::Normalize(Quaternion(in_lhs * (Sin<TType>(1.0f - in_ratio) * theta) / sin_theta + in_rhs * Sin<TType>(sign * in_ratio * theta) / sin_theta));
    }

    return Quaternion::Normalize(Quaternion(in_lhs * (Sin<TType>(1.0f - in_ratio) * theta) / sin_theta + in_rhs * Sin<TType>(in_ratio * theta) / sin_theta));
}

template <typename TType>
constexpr TType Quaternion<TType>::Dot(Quaternion const& in_lhs, Quaternion const& in_rhs) noexcept
{
    return in_lhs.w * in_rhs.w + in_lhs.x * in_rhs.x + in_lhs.y * in_rhs.y + in_lhs.z * in_rhs.z;
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::Normalize(Quaternion const& in_quaternion) noexcept
{
    TType const length = Quaternion::Length(in_quaternion);
    return Quaternion(in_quaternion.w / length, in_quaternion.x / length, in_quaternion.y / length, in_quaternion.z / length);
}

template <typename TType>
constexpr TType Quaternion<TType>::SqrLength(Quaternion const& in_quaternion) noexcept
{
    return in_quaternion.w * in_quaternion.w + in_quaternion.x * in_quaternion.x + in_quaternion.y * in_quaternion.y + in_quaternion.z * in_quaternion.z;
}

template <typename TType>
constexpr TType Quaternion<TType>::Length(Quaternion const& in_quaternion) noexcept
{
    return Sqrt<TType>(Quaternion::SqrLength(in_quaternion));
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::Invert(Quaternion const& in_quaternion) noexcept
{
    return Quaternion(in_quaternion.w, -in_quaternion.x, -in_quaternion.y, -in_quaternion.z);
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::Multiply(Quaternion const& in_lhs, Quaternion const& in_rhs) noexcept
{
    return Quaternion(in_lhs.w * in_rhs.w - (in_lhs.x * in_rhs.x + in_lhs.y * in_rhs.y + in_lhs.z * in_rhs.z),
                      in_lhs.w * in_rhs.x + in_rhs.w * in_lhs.x + (in_lhs.y * in_rhs.z - in_rhs.y * in_lhs.z),
                      in_lhs.w * in_rhs.y + in_rhs.w * in_lhs.y + (in_lhs.z * in_rhs.x - in_rhs.z * in_lhs.x),
                      in_lhs.w * in_rhs.z + in_rhs.w * in_lhs.z + (in_lhs.x * in_rhs.y - in_rhs.x * in_lhs.y));
}

template <typename TType>
template <typename TOtherType>
constexpr Quaternion<TType>::operator Quaternion<TOtherType>() const noexcept
{
    return Quaternion<TOtherType>(static_cast<TOtherType>(w), static_cast<TOtherType>(x), static_cast<TOtherType>(y), static_cast<TOtherType>(z));
}

template <typename TType>
template <bool TShortestPath>
constexpr Quaternion<TType> Quaternion<TType>::Lerp(Quaternion const& in_other, float const in_ratio) const noexcept
{
    return Lerp<TShortestPath>(*this, in_other, in_ratio);
}

template <typename TType>
template <bool TShortestPath>
constexpr Quaternion<TType> Quaternion<TType>::Slerp(Quaternion const& in_other, float const in_ratio) const noexcept
{
    return Slerp<TShortestPath>(*this, in_other, in_ratio);
}

template <typename TType>
constexpr TType Quaternion<TType>::Dot(Quaternion const& in_other) noexcept
{
    return Dot(*this, in_other);
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::GetNormalized() const noexcept
{
    return Normalize(*this);
}

template <typename TType>
constexpr Quaternion<TType>& Quaternion<TType>::Normalize() noexcept
{
    *this = Normalize(*this);
    return *this;
}

template <typename TType>
constexpr TType Quaternion<TType>::SqrLength() noexcept
{
    return SqrLength(*this);
}

template <typename TType>
constexpr TType Quaternion<TType>::Length() noexcept
{
    return Length(*this);
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::GetInverted() const noexcept
{
    return Invert(*this);
}

template <typename TType>
constexpr Quaternion<TType>& Quaternion<TType>::Invert() noexcept
{
    *this = Invert(*this);
    return *this;
}

template <typename TType>
constexpr Quaternion<TType> Quaternion<TType>::GetMultiplied(Quaternion const& in_other) const noexcept
{
    return Multiply(*this, in_other);
}

template <typename TType>
constexpr Quaternion<TType>& Quaternion<TType>::Multiply(Quaternion const& in_other) noexcept
{
    *this = Multiply(*this, in_other);
    return *this;
}