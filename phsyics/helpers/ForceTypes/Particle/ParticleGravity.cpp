//
// Created by satyamedh on 26/01/26.
//

#include "ParticleGravity.h"

using namespace iNertia;

void ParticleGravity::updateForce(Particle *particle, real dt) {
    // ensure finite mass
    if (!particle->hasFiniteMass()) return;

    particle->addForce(gravity * particle->getMass());
}
