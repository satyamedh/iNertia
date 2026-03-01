//
// Created by satyamedh on 25/02/26.
//

#include "ParticleCable.h"

unsigned iNertia::ParticleCable::fillContact(ParticleContact *contact, unsigned limit) const {
    // find the length of the cable
    real len = this->currentLength();

    if (len < maxLength) {
        return 0; // not overextended
    }

    // STRECHY! RETURN CONTACT!
    contact->particle[0] = this->particle[0];
    contact->particle[1] = this->particle[1];

    Vector3 normal = particle[1]->getPosition() - particle[0]->getPosition();
    normal.normalize();
    contact->contactNormal = normal;

    contact->penetration = len - maxLength;
    contact->restitution = restitution;

    return 1;
}
