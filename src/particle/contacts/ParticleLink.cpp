//
// Created by satyamedh on 25/02/26.
//

#include "ParticleLink.h"


iNertia::real iNertia::ParticleLink::currentLength() const {
    Vector3 relPos = particle[0]->getPosition() - particle[1]->getPosition();
    return relPos.magnitude();
}
