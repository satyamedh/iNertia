//
// Created by satyamedh on 28/01/26.
//

#ifndef INERTIA_PARTICLESPRING_H
#define INERTIA_PARTICLESPRING_H
#include "../../particleForceGen.h"

namespace iNertia {
    class ParticleSpring : public ParticleForceGen {
        Particle* other; // particle at the other end of the spring
        real springConstant; // k in Hooke's law
        real restLength; // rest length of the spring, i.e., length at which no force is applied

    public:
        ParticleSpring(Particle* other, real springConstant, real restLength);
        void updateForce(Particle* particle, real duration) override;

    };
}

#endif //INERTIA_PARTICLESPRING_H
