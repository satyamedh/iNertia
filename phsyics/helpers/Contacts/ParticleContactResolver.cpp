//
// Created by satyamedh on 24/02/26.
//

#include "ParticleContactResolver.h"

void iNertia::ParticleContactResolver::setIterations(unsigned i) {
    this->maxIterations = i;
}

void iNertia::ParticleContactResolver::resolveContacts(ParticleContact *contactArray, unsigned numContacts, real dt) {
    iterationsUsed = 0;

    while (iterationsUsed < maxIterations) {
        // find largest closingVel
        // TODO: Maybe sort and get 0th element?
        real max = 0;
        unsigned maxIndex = numContacts;
        for (unsigned i = 0; i < numContacts; i++) {
            real sepVel = contactArray[i].calculateSeparatingVelocity();
            if (sepVel < max) {
                max = sepVel;
                maxIndex = i;
            }
        }
        contactArray[maxIndex].resolve(dt);
        iterationsUsed++;
    }
}


