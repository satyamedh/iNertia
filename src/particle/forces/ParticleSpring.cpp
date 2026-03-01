//
// Created by satyamedh on 28/01/26.
//

#include "ParticleSpring.h"

iNertia::ParticleSpring::ParticleSpring(Particle *other, real springConstant, real restLength) {
    this->other = other;
    this->springConstant = springConstant;
    this->restLength = restLength;
}

void iNertia::ParticleSpring::updateForce(Particle *particle, real duration) {
    Vector3 force = particle->getPosition();
    force -= other->getPosition();

    real magnitude = force.magnitude();
    magnitude = real_abs(magnitude - restLength);
    magnitude *= -springConstant; // Hooke's law

    force.normalize();
    force *= magnitude;
    particle->addForce(force);
}
