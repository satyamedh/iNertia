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

        void invert() {
            x = -x;
            y = -y;
            z = -z;
        }

    };
}

#endif //INERTIA_VECTOR3_H