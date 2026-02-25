//
// Created by satyamedh on 25/02/26.
//

#ifndef INERTIA_PARTICLECABLE_H
#define INERTIA_PARTICLECABLE_H
#include "../ParticleLink.h"

namespace iNertia {
    class ParticleCable : public ParticleLink{
    public:
        real maxLength; // maximum length of the cable
        real restitution; // bounciness of the cable

        virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const;
    };
} // iNertia

#endif //INERTIA_PARTICLECABLE_H