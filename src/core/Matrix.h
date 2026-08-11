//
// Created by Satyamedh on 8/10/2026.
//

#ifndef INERTIA_MATRIX3_H
#define INERTIA_MATRIX3_H

#include "precision.h"
#include "Quaternion.h"
#include "Vector3.h"

namespace iNertia {
    class Matrix3 {
    public:
        real data[9]; // 3x3

        Matrix3 operator*(const Matrix3 &m) const {
            return {
                data[0]*m.data[0] + data[1]*m.data[3] + data[2]*m.data[6],
                data[0]*m.data[1] + data[1]*m.data[4] + data[2]*m.data[7],
                data[0]*m.data[2] + data[1]*m.data[5] + data[2]*m.data[8],

                data[3]*m.data[0] + data[4]*m.data[3] + data[5]*m.data[6],
                data[3]*m.data[1] + data[4]*m.data[4] + data[5]*m.data[7],
                data[3]*m.data[2] + data[4]*m.data[5] + data[5]*m.data[8],

                data[6]*m.data[0] + data[7]*m.data[3] + data[8]*m.data[6],
                data[6]*m.data[1] + data[7]*m.data[4] + data[8]*m.data[7],
                data[6]*m.data[2] + data[7]*m.data[5] + data[8]*m.data[8]
            };
        }

        // sets THIS matrix to be the inverse of the given matrix
        void setInverse(const Matrix3 &m) {
            real t4 = m.data[0]*m.data[4];
            real t6 = m.data[0]*m.data[5];
            real t8 = m.data[1]*m.data[3];
            real t10 = m.data[2]*m.data[3];
            real t12 = m.data[1]*m.data[6];
            real t14 = m.data[2]*m.data[6];

            // Calculate the determinant
            real t16 = (t4*m.data[8] - t6*m.data[7] - t8*m.data[8] + t10*m.data[7] + t12*m.data[5] - t14*m.data[4]);

            // Make sure the determinant is non-zero
            if (t16 == static_cast<real>(0.0)) return;
            real invDet = 1.0f/t16;

            data[0] = (m.data[4]*m.data[8] - m.data[5]*m.data[7])*invDet;
            data[1] = -(m.data[1]*m.data[8] - m.data[2]*m.data[7])*invDet;
            data[2] = (m.data[1]*m.data[5] - m.data[2]*m.data[4])*invDet;
            data[3] = -(m.data[3]*m.data[8] - m.data[5]*m.data[6])*invDet;
            data[4] = (m.data[0]*m.data[8] - t14)*invDet;
            data[5] = -(t6 - t10)*invDet;
            data[6] = (m.data[3]*m.data[7] - m.data[4]*m.data[6])*invDet;
            data[7] = -(m.data[0]*m.data[7] - t12)*invDet;
            data[8] = (t4 - t8)*invDet;
        }

        // returns a NEW matrix, inverse of THIS
        Matrix3 inverse() const {
            Matrix3 result{};
            result.setInverse(*this);
            return result;
        }

        // Inverses this in place
        void invert() {
            setInverse(*this);
        }

        void setTranspose(const Matrix3 &m) {
            data[0] = m.data[0];
            data[1] = m.data[3];
            data[2] = m.data[6];
            data[3] = m.data[1];
            data[4] = m.data[4];
            data[5] = m.data[7];
            data[6] = m.data[2];
            data[7] = m.data[5];
            data[8] = m.data[8];
        }

        Matrix3 transpose() const {
            Matrix3 result{};
            result.setTranspose(*this);
            return result;
        }

        void transpose() {
            setTranspose(*this);
        }

        void setOrientation(const Quaternion &q) {
            data[0] = 1 - (2 * q.y * q.y + 2 * q.z * q.z);
            data[1] = 2 * q.x * q.y + 2 * q.z * q.w;
            data[2] = 2 * q.x * q.z - 2 * q.y * q.w;

            data[3] = 2 * q.x * q.y - 2 * q.z * q.w;
            data[4] = 1 - (2 * q.x * q.x + 2 * q.z * q.z);
            data[5] = 2 * q.y * q.z + 2 * q.x * q.w;

            data[6] = 2 * q.x * q.z + 2 * q.y * q.w;
            data[7] = 2 * q.y * q.z - 2 * q.x * q.w;
            data[8] = 1 - (2 * q.x * q.x + 2 * q.y * q.y);
        }

    };

    class Matrix4 {
    public:
        real data[12]; // 3x4

        Vector3 operator*(const Vector3 &v) const {
            return {
                v.x * data[0] + v.y * data[1] + v.z * data[2] + data[3],
                v.x * data[4] + v.y * data[5] + v.z * data[6] + data[7],
                v.x * data[8] + v.y * data[9] + v.z * data[10] + data[11]
            };
        }

        Matrix4 operator*(const Matrix4 &m) const {
            Matrix4 result{};
            result.data[0] = data[0]*m.data[0] + data[1]*m.data[4] + data[2]*m.data[8];
            result.data[4] = data[4]*m.data[0] + data[5]*m.data[4] + data[6]*m.data[8];
            result.data[8] = data[8]*m.data[0] + data[9]*m.data[4] + data[10]*m.data[8];

            result.data[1] = data[0]*m.data[1] + data[1]*m.data[5] + data[2]*m.data[9];
            result.data[5] = data[4]*m.data[1] + data[5]*m.data[5] + data[6]*m.data[9];
            result.data[9] = data[8]*m.data[1] + data[9]*m.data[5] + data[10]*m.data[9];

            result.data[2] = data[0]*m.data[2] + data[1]*m.data[6] + data[2]*m.data[10];
            result.data[6] = data[4]*m.data[2] + data[5]*m.data[6] + data[6]*m.data[10];
            result.data[10] = data[8]*m.data[2] + data[9]*m.data[6] + data[10]*m.data[10];

            return result;
        }

        real getDeterminant() const {
            return data[8] * data[5] * data[2] +
                     data[4] * data[9] * data[2] +
                     data[8] * data[1] * data[6] -
                     data[0] * data[9] * data[6] -
                     data[4] * data[1] * data[10] -
                     data[0] * data[5] * data[10];
        }

        void setInverse(const Matrix4 &m) {
            real det = getDeterminant();
            if (det == 0) return;
            det = static_cast<real>(1.0)/det;

            data[0] = (-m.data[9]*m.data[6]+m.data[5]*m.data[10])*det;
            data[4] = (m.data[8]*m.data[6]-m.data[4]*m.data[10])*det;
            data[8] = (-m.data[8]*m.data[5]+m.data[4]*m.data[9])*det;

            data[1] = (m.data[9]*m.data[2]-m.data[1]*m.data[10])*det;
            data[5] = (-m.data[8]*m.data[2]+m.data[0]*m.data[10])*det;
            data[9] = (m.data[8]*m.data[1]-m.data[0]*m.data[9])*det;

            data[2] = (-m.data[5]*m.data[2]+m.data[1]*m.data[6])*det;
            data[6] = (+m.data[4]*m.data[2]-m.data[0]*m.data[6])*det;
            data[10] = (-m.data[4]*m.data[1]+m.data[0]*m.data[5])*det;

            data[3] = (m.data[9]*m.data[6]*m.data[3]
                       -m.data[5]*m.data[10]*m.data[3]
                       -m.data[9]*m.data[2]*m.data[7]
                       +m.data[1]*m.data[10]*m.data[7]
                       +m.data[5]*m.data[2]*m.data[11]
                       -m.data[1]*m.data[6]*m.data[11])*det;
            data[7] = (-m.data[8]*m.data[6]*m.data[3]
                       +m.data[4]*m.data[10]*m.data[3]
                       +m.data[8]*m.data[2]*m.data[7]
                       -m.data[0]*m.data[10]*m.data[7]
                       -m.data[4]*m.data[2]*m.data[11]
                       +m.data[0]*m.data[6]*m.data[11])*det;
            data[11] =(m.data[8]*m.data[5]*m.data[3]
                       -m.data[4]*m.data[9]*m.data[3]
                       -m.data[8]*m.data[1]*m.data[7]
                       +m.data[0]*m.data[9]*m.data[7]
                       +m.data[4]*m.data[1]*m.data[11]
                       -m.data[0]*m.data[5]*m.data[11])*det;
        }

        Matrix4 inverse() const {
            Matrix4 result{};
            result.setInverse(*this);
            return result;
        }

        void invert() {
            setInverse(*this);
        }

        void setOrientationAndPosition(const Quaternion &q, const Vector3 &pos) {
            data[0] = 1 - (2 * q.y * q.y + 2 * q.z * q.z);
            data[1] = 2 * q.x * q.y + 2 * q.z * q.w;
            data[2] = 2 * q.x * q.z - 2 * q.y * q.w;
            data[3] = pos.x;

            data[4] = 2 * q.x * q.y - 2 * q.z * q.w;
            data[5] = 1 - (2 * q.x * q.x + 2 * q.z * q.z);
            data[6] = 2 * q.y * q.z + 2 * q.x * q.w;
            data[7] = pos.y;

            data[8] = 2 * q.x * q.z + 2 * q.y * q.w;
            data[9] = 2 * q.y * q.z - 2 * q.x * q.w;
            data[10] = 1 - (2 * q.x * q.x + 2 * q.y * q.y);
            data[11] = pos.z;
        }
    };

}
#endif //INERTIA_MATRIX3_H
