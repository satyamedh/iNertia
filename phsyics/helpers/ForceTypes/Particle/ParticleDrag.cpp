//
// Created by satyamedh on 27/01/26.
//

#include "ParticleDrag.h"

iNertia::ParticleDrag::ParticleDrag(const real k1, const real k2) {
    this->k1 = k1;
    this->k2 = k2;
}

void iNertia::ParticleDrag::updateForce(Particle *particle, real dt) {
    Vector3 f = particle->getVelocity();

    real dragCoeff = f.magnitude();
    dragCoeff = (this->k1 * dragCoeff) + (this->k2 * dragCoeff * dragCoeff); // k1 * v + k2 * v^2

    f.normalize();
    f *= -dragCoeff; // drag opposes motion
    particle->addForce(f);
}
