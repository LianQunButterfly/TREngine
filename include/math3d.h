#pragma once
/*
数学类 目前只有Vector3
*/
struct  Vector3f
{
    float x, y, z;
    
    Vector3f() : x(0), y(0), z(0) {}
    Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    
    // ... other methods ...
};
