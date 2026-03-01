//
// Created by satyamedh on 26/01/26.
//

#ifndef INERTIA_PARTICLEFORCEGEN_H
#define INERTIA_PARTICLEFORCEGEN_H

#include <vector>

#include "core/precision.h"
#include "particle/Particle.h"

namespace iNertia {
    class ParticleForceGen {
        public:
            virtual void updateForce(Particle* particle, real dt) = 0;
    };
}


#endif //INERTIA_PARTICLEFORCEGEN_H
