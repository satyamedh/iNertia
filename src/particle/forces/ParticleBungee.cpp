//
// Created by satyamedh on 28/01/26.
//

#include "ParticleBungee.h"

iNertia::ParticleBungee::ParticleBungee(Particle *other, real springConstant, real restLength) {
    this->other = other;
    this->springConstant = springConstant;
    this->restLength = restLength;
}

void iNertia::ParticleBungee::updateForce(Particle *particle, real duration) {
    Vector3 force = particle->getPosition();
    force -= other->getPosition();

    real magnitude = force.magnitude();
    if (magnitude <= restLength) {
        return; // No force if bungee is not stretched
    }

    magnitude = magnitude - restLength;
    magnitude *= -springConstant; // Hooke's law

    force.normalize();
    force *= magnitude;
    particle->addForce(force);
}
