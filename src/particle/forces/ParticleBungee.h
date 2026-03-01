//
// Created by satyamedh on 28/01/26.
//

#ifndef INERTIA_PARTICLEBUNGEE_H
#define INERTIA_PARTICLEBUNGEE_H
#include "ParticleForceGen.h"

namespace iNertia {
    class ParticleBungee : public ParticleForceGen{
        Particle* other; // particle at the other end of the bungee
        real springConstant; // k in Hooke's law
        real restLength; // rest length of the bungee, i.e., length at which no force is applied

    public:
        ParticleBungee(Particle* other, real springConstant, real restLength);
        void updateForce(Particle* particle, real duration) override;

    };
}

#endif //INERTIA_PARTICLEBUNGEE_H
