//
// Created by satyamedh on 31/01/26.
//

#ifndef INERTIA_PARTICLECONTACTS_H
#define INERTIA_PARTICLECONTACTS_H
#include "../../../maths/precision.h"
#include "../../../maths/Vector3.h"
#include "../../objects/particle.h"

namespace iNertia {
    class ParticleContact {
    public:
        Particle* particle[2]; // involved particles; 1 null if immovable
        real restitution; // coefficient of restitution
        Vector3 contactNormal; // direction of contact

        real penetration; // depth of penetration

    protected:
        void resolve(real dt);
        real calculateSeparatingVelocity() const;

    private:
        void resolveVelocity(real dt);
        void resolveInterpenetration(real dt);
    };
}


#endif //INERTIA_PARTICLECONTACTS_H
