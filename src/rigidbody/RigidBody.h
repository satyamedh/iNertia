//
// Created by satyamedh on 18-09-2026.
//

#ifndef INERTIA_RIGIDBODY_H
#define INERTIA_RIGIDBODY_H
#include <iNertia/iNertia.h>

namespace iNertia {
    class RigidBody {
    public:
        real inverseMass{};
        Vector3 position;
        Quaternion orientation;
        Vector3 velocity;
        Vector3 rotation; // angular velocity

        Matrix4 transformMatrix{};

        void calculateDerivedData();

    };
}

#endif //INERTIA_RIGIDBODY_H
