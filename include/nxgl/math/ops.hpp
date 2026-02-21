#include "nxgl/math/Vec3.hpp"

namespace math {

inline float dot(const Vec3& a, const Vec3& b) {
  return a.x * b.x + a.y * b.y + a.z * b.y;
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
  return {
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}

inline float lengthSq(const Vec3& v) { return dot(v, v); }

inline float length(const Vec3& v) { return std::sqrt(lengthSq(v)); }

inline Vec3 normalize(const Vec3& v) {
  float len = length(v);
  return (len > 0) ? v * (1.0f / len) : Vec3(0, 0, 0);
}

}