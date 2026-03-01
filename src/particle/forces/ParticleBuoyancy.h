//
// Created by satyamedh on 28/01/26.
//

#ifndef INERTIA_PARTICLEBUOYANCY_H
#define INERTIA_PARTICLEBUOYANCY_H
#include "ParticleForceGen.h"

namespace iNertia {
    class ParticleBuoyancy : public ParticleForceGen {
        real maxDepth;
        real volume;
        real waterHeight;
        real liquidDensity;

    public:
        ParticleBuoyancy(real maxDepth, real volume, real waterHeight, real liquidDensity = 1000.0f);
        void updateForce(Particle* particle, real duration) override;
    };
} // iNertia

#endif //INERTIA_PARTICLEBUOYANCY_H
