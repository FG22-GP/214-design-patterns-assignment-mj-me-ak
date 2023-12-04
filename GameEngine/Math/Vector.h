#pragma once
#include <string>

class Vector
{
public:
    int x;
    int y;

    Vector()
    {
        x = 0;
        y = 0;
    }
    
    Vector(int x, int y) : x(x), y(y)
    {
    }

    bool operator==(const Vector& point) const;
    std::string ToString() const;
};
