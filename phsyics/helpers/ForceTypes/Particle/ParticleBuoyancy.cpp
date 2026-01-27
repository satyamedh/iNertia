//
// Created by satyamedh on 28/01/26.
//

#include "ParticleBuoyancy.h"

iNertia::ParticleBuoyancy::ParticleBuoyancy(const real maxDepth, const real volume, const real waterHeight, const real liquidDensity) {
    this->maxDepth = maxDepth;
    this->volume = volume;
    this->waterHeight = waterHeight;
    this->liquidDensity = liquidDensity;
}

void iNertia::ParticleBuoyancy::updateForce(Particle *particle, real duration) {
    real depth = particle->getPosition().y;

    if (depth >= waterHeight + maxDepth) {
        return; // Out of the water
    }

    Vector3 force;

    if (depth <= waterHeight - maxDepth) {
        // Completely submerged
        force.y = liquidDensity * volume;
        particle->addForce(force);
        return;
    }

    force.y = liquidDensity * volume * (depth - waterHeight - maxDepth) / (2 * maxDepth);
    particle->addForce(force);

}


