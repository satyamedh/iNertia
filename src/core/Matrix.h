//
// Created by Satyamedh on 8/10/2026.
//

#ifndef INERTIA_MATRIX3_H
#define INERTIA_MATRIX3_H

#include "precision.h"
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

            result.data[3] = data[0]*m.data[3] + data[1]*m.data[7] + data[2]*m.data[11] + data[3];
            result.data[7] = data[4]*m.data[3] + data[5]*m.data[7] + data[6]*m.data[11] + data[7];
            result.data[11] = data[8]*m.data[3] + data[9]*m.data[7] + data[10]*m.data[11] + data[11];

            return result;
        }
    };

}
#endif //INERTIA_MATRIX3_H
