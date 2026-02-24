//
// Created by satyamedh on 24/02/26.
//

#ifndef INERTIA_PARTICLECONTACTRESOLVER_H
#define INERTIA_PARTICLECONTACTRESOLVER_H
#include "ParticleContact.h"

namespace iNertia {
    class ParticleContactResolver {
    protected:
        unsigned maxIterations;
        unsigned iterationsUsed;
    public:
        ParticleContactResolver(const unsigned i) : maxIterations(i), iterationsUsed(0) {}
        void setIterations(unsigned i);

        void resolveContacts(ParticleContact *contactArray, unsigned numContacts, real dt);

    };
}

#endif //INERTIA_PARTICLECONTACTRESOLVER_H