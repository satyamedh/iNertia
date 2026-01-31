//
// Created by satyamedh on 31/01/26.
//

#include "ParticleContact.h"

void iNertia::ParticleContact::resolve(real dt) {
    this->resolveVelocity(dt);
}

iNertia::real iNertia::ParticleContact::calculateSeparatingVelocity() const {
    Vector3 relVel = this->particle[0]->getVelocity();
    if (this->particle[1]) {
        relVel -= this->particle[1]->getVelocity();
    }
    return relVel * this->contactNormal;
}

void iNertia::ParticleContact::resolveVelocity(real dt) {

    real sepVel = this->calculateSeparatingVelocity();

    if (sepVel > 0) {
        return; // they are already separating, no need to resolve
    }

    real newSepVel = -sepVel * this->restitution;

    real dv = newSepVel - sepVel;

    real totalInverseMass = this->particle[0]->getInverseMass();
    if (this->particle[1]) {
        totalInverseMass += this->particle[1]->getInverseMass();
    }

    if (totalInverseMass <= 0) {
        return; // infinite mass! do nothing
    }

    real impulse = dv / totalInverseMass;

    Vector3 impulsePerIMass = this->contactNormal * impulse;

    particle[0]->setVelocity(particle[0]->getVelocity() + impulsePerIMass * particle[0]->getInverseMass());

    if (this->particle[1]) {
        particle[1]->setVelocity(particle[1]->getVelocity() + impulsePerIMass * -particle[1]->getInverseMass());
    }

}
