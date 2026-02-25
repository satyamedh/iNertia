//
// Created by satyamedh on 25/02/26.
//

#ifndef INERTIA_PARTICLELINKS_H
#define INERTIA_PARTICLELINKS_H
#include "../ParticleContact.h"
#include "../../../objects/particle.h"

namespace iNertia {
    class ParticleLink {
    public:
        Particle* particle[2]; // particles connected by this link.

    protected:
        real currentLength() const; // current length of the cable

    public:
        virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const = 0;
    };
} // iNertia

#endif //INERTIA_PARTICLELINKS_H