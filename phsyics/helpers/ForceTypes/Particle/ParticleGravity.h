//
// Created by satyamedh on 26/01/26.
//

#ifndef INERTIA_PARTICLEGRAVITY_H
#define INERTIA_PARTICLEGRAVITY_H
#include "../../particleForceGen.h"

namespace iNertia {
    class ParticleGravity : public ParticleForceGen {
    public:
        Vector3 gravity;
        ParticleGravity(Vector3 gravity);

        void updateForce(Particle *particle, real dt) override;
    };
}

#endif //INERTIA_PARTICLEGRAVITY_H