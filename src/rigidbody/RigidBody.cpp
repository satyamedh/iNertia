//
// Created by satyamedh on 18-09-2026.
//

#include "RigidBody.h"


using namespace iNertia;

static inline void _calculateTransformMatrix(Matrix4 &tm, const Vector3 &pos, const Quaternion &orientation) {
    tm.data[0] = 1-2*orientation.j*orientation.j - 2*orientation.k*orientation.k;
    tm.data[1] = 2*orientation.i*orientation.j - 2*orientation.r*orientation.k;
    tm.data[2] = 2*orientation.i*orientation.k + 2*orientation.r*orientation.j;
    tm.data[3] = pos.x;

    tm.data[4] = 2*orientation.i*orientation.j + 2*orientation.r*orientation.k;
    tm.data[5] = 1-2*orientation.i*orientation.i - 2*orientation.k*orientation.k;
    tm.data[6] = 2*orientation.j*orientation.k - 2*orientation.r*orientation.i;
    tm.data[7] = pos.y;

    tm.data[8] = 2*orientation.i*orientation.k - 2*orientation.r*orientation.j;
    tm.data[9] = 2*orientation.j*orientation.k + 2*orientation.r*orientation.i;
    tm.data[10] = 1-2*orientation.i*orientation.i - 2*orientation.j*orientation.j;
    tm.data[11] = pos.z;
}


void RigidBody::calculateDerivedData() {
    _calculateTransformMatrix(this->transformMatrix, this->position, this->orientation);
}

