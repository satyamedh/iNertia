//
// Created by Satyamedh on 8/11/2026.
//

#ifndef INERTIA_QUATERNION_H
#define INERTIA_QUATERNION_H
#include "precision.h"
#include "Vector3.h"

namespace iNertia {
    class Quaternion {
        public:
            real w, x, y, z;

            Quaternion(): w(1), x(0), y(0), z(0) {}
            Quaternion(const real w, const real x, const real y, const real z): w(w), x(x), y(y), z(z) {}

            void normalize() {
                if (const real mag = real_sqrt(w*w + x*x + y*y + z*z); mag > 0) {
                    w /= mag;
                    x /= mag;
                    y /= mag;
                    z /= mag;
                }
            }

            Quaternion operator*(const Quaternion& other) const {
                return {
                    w * other.w - x * other.x - y * other.y - z * other.z,
                    w * other.x + x * other.w + y * other.z - z * other.y,
                    w * other.y - x * other.z + y * other.w + z * other.x,
                    w * other.z + x * other.y - y * other.x + z * other.w
                };
            }

            void operator*=(const Quaternion& other) {
                *this = *this * other;
            }

            Quaternion &operator+=(const Quaternion & quaternion) {
                w += quaternion.w;
                x += quaternion.x;
                y += quaternion.y;
                z += quaternion.z;
                return *this;
            }

            void addScaledVector(const Vector3& vector, const real scale) {
                Quaternion q(0, vector.x * scale, vector.y * scale, vector.z * scale);
                *this += q * (*this);
            }

            void rotateByVector(const Vector3& vector) {
                Quaternion q(0, vector.x, vector.y, vector.z);
                *this += q * (*this);
            }
    };
}

#endif //INERTIA_QUATERNION_H
