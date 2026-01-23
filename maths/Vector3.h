//
// Created by satyamedh on 23/01/26.
//

#ifndef INERTIA_VECTOR3_H
#define INERTIA_VECTOR3_H
#include "precision.h"

namespace iNertia {
    class Vector3 {
    public:
        real x, y, z; // left out padding; armv5 *shouldn't* benefit from alignment, will test out later tho

        Vector3(): x(0), y(0), z(0) {}
        Vector3(const real x, const real y, const real z): x(x), y(y), z(z) {}

        void operator+=(const Vector3& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
        }

        Vector3 operator+(const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        void addScaledVector(const Vector3& other, const real scale) {
            this->x += other.x * scale;
            this->y += other.y * scale;
            this->z += other.z * scale;
        }

        void operator-=(const Vector3& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
        }

        Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        void operator*=(const real scalar) {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
        }

        Vector3 operator*(const real scalar) const {
            return Vector3(this->x*scalar, this->y*scalar, this->z*scalar);
        }

        void componentProductUpdate(const Vector3& other) {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
        }

        real dotProduct(const Vector3& other) const {
            return this->x*other.x + this->y*other.y + this->z*other.z;
        }

        real operator*(const Vector3& other) const {
            return this->x*other.x + this->y*other.y + this->z*other.z;
        }

        Vector3 crossProduct(const Vector3& other) const {
            return Vector3(
                    this->y*other.z - this->z*other.y,
                    this->z*other.x - this->x*other.z,
                    this->x*other.y - this->y*other.x
            );
        }

        void operator%=(const Vector3& other) {
            *this = this->crossProduct(other);
        }

        Vector3 operator%(const Vector3& other) const {
            return Vector3(
                    this->y*other.z - this->z*other.y,
                    this->z*other.x - this->x*other.z,
                    this->x*other.y - this->y*other.x
            );
        }

        void invert() {
            x = -x;
            y = -y;
            z = -z;
        }

        real magnitude() const {
            return real_sqrt(x*x + y*y + z*z);
        }

        real squareMagnitude() const {
            return x*x + y*y + z*z;
        }

        void normalize() {
            if (const real len = magnitude(); len > 0) {
                *this = *this * static_cast<real>(1 / len);
            }
        }

    };
}

#endif //INERTIA_VECTOR3_H