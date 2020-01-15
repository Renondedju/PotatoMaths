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

template <typename TType, IsFloatingPoint<TType> = true>
TType LinearInterpolation(TType in_p)
{
    return in_p;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuadraticEaseIn(TType in_p)
{
    return in_p * in_p;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuadraticEaseOut(TType in_p)
{
    return -(in_p * (in_p - 2.0f));
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuadraticEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 2.0f * in_p * in_p;

    return (-2.0f * in_p * in_p) + (4.0f * in_p) - 1.0f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType CubicEaseIn(TType in_p)
{
    return in_p * in_p * in_p;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType CubicEaseOut(TType in_p)
{
    TType f = (in_p - 1.0f);
    return f * f * f + 1.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType CubicEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 4.0f * in_p * in_p * in_p;

    TType f = ((2.0f * in_p) - 2.0f);
    return 0.5f * f * f * f + 1.0f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType QuarticEaseIn(TType in_p)
{
    return in_p * in_p * in_p * in_p;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuarticEaseOut(TType in_p)
{
    TType f = (in_p - 1.0f);
    return f * f * f * (1.0f - in_p) + 1.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuarticEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 8.0f * in_p * in_p * in_p * in_p;

    TType f = (in_p - 1.0f);
    return -8.0f * f * f * f * f + 1.0f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType QuinticEaseIn(TType in_p)
{
    return in_p * in_p * in_p * in_p * in_p;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuinticEaseOut(TType in_p)
{
    TType f = (in_p - 1.0f);
    return f * f * f * f * f + 1.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType QuinticEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 16.0f * in_p * in_p * in_p * in_p * in_p;

    TType f = ((2.0f * in_p) - 2.0f);
    return  0.5f * f * f * f * f * f + 1.0f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType SineEaseIn(TType in_p)
{
    return Sin<TType>((in_p - 1.0f) * POTATO_CONSTANTS_PI_2) + 1.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType SineEaseOut(TType in_p)
{
    return Sin<TType>(in_p * POTATO_CONSTANTS_PI_2);
}

template <typename TType, IsFloatingPoint<TType> = true>
TType SineEaseInOut(TType in_p)
{
    return 0.5f * (1.0f - Cos<TType>(in_p * POTATO_CONSTANTS_PI));
}


template <typename TType, IsFloatingPoint<TType> = true>
TType CircularEaseIn(TType in_p)
{
    return 1.0f - Sqrt<TType>(1.0f - (in_p * in_p));
}

template <typename TType, IsFloatingPoint<TType> = true>
TType CircularEaseOut(TType in_p)
{
    return Sqrt<TType>((2.0f - in_p) * in_p);
}

template <typename TType, IsFloatingPoint<TType> = true>
TType CircularEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 0.5f * (1.0f - Sqrt<TType>(1.0f - 4.0f * (in_p * in_p)));

    return 0.5f * (Sqrt<TType>(-((2.0f * in_p) - 3.0f) * ((2.0f * in_p) - 1.0f)) + 1.0f);
}


template <typename TType, IsFloatingPoint<TType> = true>
TType ExponentialEaseIn(TType in_p)
{
    return (in_p == 0.0f) ? in_p : Pow<TType>(2.0f, 10.0f * (in_p - 1.0f));
}

template <typename TType, IsFloatingPoint<TType> = true>
TType ExponentialEaseOut(TType in_p)
{
    return (in_p == 1.0f) ? in_p : 1.0f - Pow<TType>(2.0f, -10.0f * in_p);
}

template <typename TType, IsFloatingPoint<TType> = true>
TType ExponentialEaseInOut(TType in_p)
{
    if(in_p == 0.0f || in_p == 1.0f) return in_p;
    
    if(in_p < 0.5f)
        return 0.5f * Pow<TType>(2.0f, (20.0f * in_p) - 10.0f);

    return -0.5f * Pow<TType>(2.0f, (-20.0f * in_p) + 10.0f) + 1.0f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType ElasticEaseIn(TType in_p)
{
    return Sin<TType>(13.0f * POTATO_CONSTANTS_PI_2 * in_p) * Pow<TType>(2.0f, 10.0f * (in_p - 1.0f));
}

template <typename TType, IsFloatingPoint<TType> = true>
TType ElasticEaseOut(TType in_p)
{
    return Sin<TType>(-13.0f * POTATO_CONSTANTS_PI_2 * (in_p + 1.0f)) * Pow<TType>(2.0f, -10.0f * in_p) + 1.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType ElasticEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 0.5f * Sin<TType>(13.0f * POTATO_CONSTANTS_PI_2 * (2.0f * in_p)) * Pow<TType>(2.0f, 10.0f * ((2.0f * in_p) - 1.0f));

    return 0.5f * (Sin<TType>(-13.0f * POTATO_CONSTANTS_PI_2 * ((2.0f * in_p - 1.0f) + 1.0f)) * Pow<TType>(2.0f, -10.0f * (2.0f * in_p - 1.0f)) + 2.0f);
}


template <typename TType, IsFloatingPoint<TType> = true>
TType BackEaseIn(TType in_p)
{
    return in_p * in_p * in_p - in_p * Sin<TType>(in_p * POTATO_CONSTANTS_PI);
}

template <typename TType, IsFloatingPoint<TType> = true>
TType BackEaseOut(TType in_p)
{
    TType f = (1.0f - in_p);
    return 1.0f - (f * f * f - f * Sin<TType>(f * POTATO_CONSTANTS_PI));
}

template <typename TType, IsFloatingPoint<TType> = true>
TType BackEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
    {
        TType f = 2.0f * in_p;
        return 0.5f * (f * f * f - f * Sin<TType>(f * POTATO_CONSTANTS_PI));
    }

    TType f = (1.0f - (2.0f*in_p - 1.0f));
    return 0.5f * (1.0f - (f * f * f - f * Sin<TType>(f * POTATO_CONSTANTS_PI))) + 0.5f;
}


template <typename TType, IsFloatingPoint<TType> = true>
TType BounceEaseIn(TType in_p)
{
    return 1.0f - BounceEaseOut<TType>(1.0f - in_p);
}

template <typename TType, IsFloatingPoint<TType> = true>
TType BounceEaseOut(TType in_p)
{
    if(in_p < 4.0f/11.0f)
        return (121.0f * in_p * in_p)/16.0f;

    if(in_p < 8.0f/11.0f)
        return (363.0f/40.0f * in_p * in_p) - (99.0f/10.0f * in_p) + 17.0f/5.0f;

    if(in_p < 9.0f/10.0f)
        return (4356.0f/361.0f * in_p * in_p) - (35442.0f/1805.0f * in_p) + 16061.0f/1805.0f;

    return (54.0f/5.0f * in_p * in_p) - (513.0f/25.0f * in_p) + 268.0f/25.0f;
}

template <typename TType, IsFloatingPoint<TType> = true>
TType BounceEaseInOut(TType in_p)
{
    if(in_p < 0.5f)
        return 0.5f * BounceEaseIn<TType>(in_p*2.0f);

    return 0.5f * BounceEaseOut<TType>(in_p * 2.0f - 1.0f) + 0.5f;
}
