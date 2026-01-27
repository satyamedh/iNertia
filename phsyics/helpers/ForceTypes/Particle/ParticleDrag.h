//
// Created by satyamedh on 27/01/26.
//

#ifndef INERTIA_PARTICLEDRAG_H
#define INERTIA_PARTICLEDRAG_H
#include "../../particleForceGen.h"

namespace iNertia {
    class ParticleDrag : public ParticleForceGen {
        real k1; // linear part
        real k2; // quadratic part

    public:
        ParticleDrag(real k1, real k2);
        virtual void updateForce(Particle *particle, real dt) override;
    };
}
#endif //INERTIA_PARTICLEDRAG_H