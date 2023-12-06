#pragma once

class InputScheme
{
public:
    InputScheme(int up, int down, int left, int right)
        : up(up),
          down(down),
          left(left),
          right(right)
    {
        
    }
    int up;
    int down;
    int left;
    int right;
};
