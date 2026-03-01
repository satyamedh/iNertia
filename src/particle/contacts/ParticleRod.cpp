//
// Created by satyamedh on 25/02/26.
//

#include "ParticleRod.h"

iNertia::real iNertia::ParticleRod::currentLength() const {
    Vector3 relPos = particle[0]->getPosition() - particle[1]->getPosition();
    return relPos.magnitude();
}

unsigned iNertia::ParticleRod::fillContact(ParticleContact *contact, unsigned limit) const {
    real currLen = this->currentLength();
    if (currLen == length) {
        return 0; // perfectly balanced, as all things should be.
    }

    contact->particle[0] = this->particle[0];
    contact->particle[1] = this->particle[1];

    Vector3 normal = particle[1]->getPosition() - particle[0]->getPosition();
    normal.normalize();
    if (currLen > length) {
        contact->contactNormal = normal;
        contact->penetration = currLen - length;
    } else {
        contact->contactNormal = normal * -1;
        contact->penetration = length - currLen;
    }

    contact->restitution = 0; // no bounciness, it's a rod!
    return 1;
}
