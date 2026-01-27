//
// Created by satyamedh on 28/01/26.
//

#ifndef INERTIA_PARTICLEANCHOREDSPRING_H
#define INERTIA_PARTICLEANCHOREDSPRING_H
#include "../../particleForceGen.h"

namespace iNertia {
    class ParticleAnchoredSpring : public ParticleForceGen {
        Vector3 anchor;
        real springConstant; // k in Hooke's law
        real restLength; // rest length of the spring, i.e., length at which no

    public:
        ParticleAnchoredSpring(const Vector3& anchor, real springConstant, real restLength);
        void updateForce(Particle* particle, real duration) override;

    };
}

#endif //INERTIA_PARTICLEANCHOREDSPRING_H