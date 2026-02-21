#pragma once
#include <cmath>

class Vec3 {
public:
  union {
    struct { float x, y, z; };
    float data[3];
  };

  Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
   : x(x), y(y), z(z) {};

  float& operator[](int index) { return data[index]; }
  const float& operator[](int index) const { return data[index]; }

  Vec3& operator+=(const Vec3& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
  }
};

inline Vec3 operator+(const Vec3& a, const Vec3& b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
inline Vec3 operator-(const Vec3& a, const Vec3& b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }

inline Vec3 operator*(const Vec3& v, float s) { return { v.x * s, v.y * s, v.z * s }; }
inline Vec3 operator*(float s, const Vec3& v) { return v * s; }

