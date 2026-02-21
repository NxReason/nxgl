#pragma once
#include "nxgl/math/Vec3.hpp"

struct Mat4 {
  float elements[16];

  Mat4() {
    for (int i = 0; i < 16; i++) elements[i] = 0.0f;
    elements[0 + 0 * 4] = 1.0f;
    elements[1 + 1 * 4] = 1.0f;
    elements[2 + 2 * 4] = 1.0f;
    elements[3 + 3 * 4] = 1.0f;
  }

  float& at(int row, int col) { return elements[row + col * 4]; }

  static Mat4 translate(const Vec3& translation) {
    Mat4 result;
    result.elements[0 + 3 * 4] = translation.x;
    result.elements[1 + 3 * 4] = translation.y;
    result.elements[2 + 3 * 4] = translation.z;
    return result;
  }

  static Mat4 scale(const Vec3& scale) {
    Mat4 result;
    result.elements[0 + 0 * 4] = scale.x;
    result.elements[1 + 1 * 4] = scale.y;
    result.elements[2 + 2 * 4] = scale.z;
    return result;
  }

  static Mat4 scale(float s) {
    return scale({ s, s, s });
  }

  static Mat4 rotate(float angleRad, const Vec3& axis) {
    Mat4 result;
    float c = cos(angleRad);
    float s = sin(angleRad);

    if (axis.z > 0) { // z-axis
      result.elements[0 + 0 * 4] = c;
      result.elements[0 + 1 * 4] = -s;
      result.elements[1 + 0 * 4] = s;
      result.elements[1 + 1 * 4] = c;
    }

    if (axis.x > 0) {
      result.elements[1 + 1 * 4] = c;
      result.elements[1 + 2 * 4] = -s;
      result.elements[2 + 1 * 4] = s;
      result.elements[2 + 2 * 4] = c;
    }

    if (axis.y > 0) {
      result.elements[0 + 0 * 4] = c;
      result.elements[0 + 2 * 4] = s;
      result.elements[2 + 0 * 4] = -s;
      result.elements[2 + 2 * 4] = c;
    }

    return result;
  }

  static Mat4 ortho(float left, float right, float bottom, float top, float near, float far) {
    Mat4 result;
    for (int i = 0; i < 16; i++) result.elements[i] = 0.0f;

    // diagonal scale
    result.elements[0 + 0 * 4] = 2.0f / (right - left);
    result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
    result.elements[2 + 2 * 4] = -2.0f / (far - near);

    result.elements[0 + 3 * 4] = -(right + left) / (right - left);
    result.elements[1 + 3 * 4] = -(top + bottom) / (top - bottom);
    result.elements[2 + 3 * 4] = -(far + near) / (far - near);

    result.elements[3 + 3 * 4] = 1.0f;

    return result;
  }

  static Mat4 perspective(float fovDeg, float aspect, float near, float far) {
    Mat4 result;
    for (int i = 0; i < 16; i++) result.elements[i] = 0.0f;

    float fovRad = fovDeg * (3.14159265f / 180.0f);
    float tanHalfFov = tan(fovRad / 2.0f);

    result.elements[0 + 0 * 4] = 1.0f / (aspect * tanHalfFov);
    result.elements[1 + 1 * 4] = 1.0f / tanHalfFov;
    result.elements[2 + 2 * 4] = -(far + near) / (far - near);

    result.elements[3 + 2 * 4] = -1.0f;

    result.elements[2 + 3 * 4] = -(2.0f * far * near) / (far - near);

    return result;
  }
};


inline Mat4 operator*(const Mat4& left, const Mat4& right) {
  Mat4 result;
  for (int col = 0; col < 4; col++) {
    for (int row = 0; row < 4; row++) {
      float sum = 0.0f;
      for (int e = 0; e < 4; e++) {
        sum += left.elements[row + e * 4] * right.elements[e + col * 4];
      }
      result.elements[row + col * 4] = sum;
    }
  }
  return result;
}