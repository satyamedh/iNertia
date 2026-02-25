//
// Created by satyamedh on 25/02/26.
//

#ifndef INERTIA_PARTICLEROD_H
#define INERTIA_PARTICLEROD_H
#include "../ParticleLink.h"

namespace iNertia {
    class ParticleRod : public ParticleLink {
    public:
        real length; // length of the rod

        real currentLength() const; // current length of the rod

        virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const;
    };
}


#endif //INERTIA_PARTICLEROD_H