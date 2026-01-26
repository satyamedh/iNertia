//
// Created by satyamedh on 26/01/26.
//

#ifndef INERTIA_IFORCEGEN_H
#define INERTIA_IFORCEGEN_H

#include <vector>

#include "../../maths/precision.h"
#include "../objects/particle.h"

namespace iNertia {
    class ParticleForceGen {
        public:
            virtual void updateForce(Particle* particle, real dt) = 0;
    };
}


#endif //INERTIA_IFORCEGEN_H