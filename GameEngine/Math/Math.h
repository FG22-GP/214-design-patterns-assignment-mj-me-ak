#pragma once

class Math
{
public:
    static int Lerp(int a, int b, float t)
    {
        return static_cast<int>(static_cast<float>(a) + t * static_cast<float>(b - a));
    }

    static float InverseLerp(float a, float b, float v)
    {
        return (v - a) / (b - a);
    }
};
