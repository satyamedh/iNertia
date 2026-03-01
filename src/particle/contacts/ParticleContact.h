//
// Created by satyamedh on 31/01/26.
//

#ifndef INERTIA_PARTICLECONTACT_H
#define INERTIA_PARTICLECONTACT_H
#include "core/precision.h"
#include "core/Vector3.h"
#include "particle/Particle.h"

namespace iNertia {
    class ParticleContact {
    public:
        Particle* particle[2]; // involved particles; 1 null if immovable
        real restitution; // coefficient of restitution
        Vector3 contactNormal; // direction of contact

        real penetration; // depth of penetration

        real calculateSeparatingVelocity() const;
        void resolve(real dt);

    private:
        void resolveVelocity(real dt);
        void resolveInterpenetration(real dt);
    };
}


#endif //INERTIA_PARTICLECONTACT_H
