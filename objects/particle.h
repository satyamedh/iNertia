//
// Created by satyamedh on 24/01/26.
//

#ifndef INERTIA_PARTICLE_H
#define INERTIA_PARTICLE_H
#include "../maths/Vector3.h"

namespace iNertia {
    class particle {
    public:
        particle () : damping(1.0f) {}

        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;

        real damping;

        void setMass(real mass);
        void setInverseMass(real inverse_mass);

        real getMass() const;
        real getInverseMass() const;
    protected:
        real inverseMass = 0;
    };
}


#endif //INERTIA_PARTICLE_H