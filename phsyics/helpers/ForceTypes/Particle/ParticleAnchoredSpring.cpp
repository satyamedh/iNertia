//
// Created by satyamedh on 28/01/26.
//

#include "ParticleAnchoredSpring.h"


iNertia::ParticleAnchoredSpring::ParticleAnchoredSpring(const Vector3 &anchor, real springConstant, real restLength) {
    this->anchor = anchor;
    this->springConstant = springConstant;
    this->restLength = restLength;
}

void iNertia::ParticleAnchoredSpring::updateForce(Particle *particle, real duration) {
    Vector3 force = particle->getPosition();
    force -= anchor;

    real magnitude = force.magnitude();
    magnitude = real_abs(magnitude - restLength);
    magnitude *= -springConstant; // Hooke's law

    force.normalize();
    force *= magnitude;
    particle->addForce(force);
}


