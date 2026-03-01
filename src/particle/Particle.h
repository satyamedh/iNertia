//
// Created by satyamedh on 24/01/26.
//

#ifndef INERTIA_PARTICLE_H
#define INERTIA_PARTICLE_H
#include "core/Vector3.h"

namespace iNertia {
    class Particle {
    public:
        Particle () : damping(1.0f) {}

        void setPosition(const Vector3& newPosition);
        Vector3 getPosition() const;

        void setVelocity(const Vector3& newVelocity);
        Vector3 getVelocity() const;

        void setAcceleration(const Vector3& newAcceleration);
        Vector3 getAcceleration() const;

        Vector3 forceAccum; // total accumulated force for this update
        void clearAccumulator();

        void addForce(const Vector3& force);

        real damping;

        void setMass(real mass);
        void setInverseMass(real inverse_mass);

        real getMass() const;
        real getInverseMass() const;

        bool hasFiniteMass() const { return inverseMass > 0; }


        void integrate(real dt);
    protected:

        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;

        real inverseMass = 0;
    };
}


#endif //INERTIA_PARTICLE_H
