//
// Created by satyamedh on 31/01/26.
//

#include "ParticleContact.h"

void iNertia::ParticleContact::resolve(real dt) {
    this->resolveVelocity(dt);
    this->resolveInterpenetration(dt);
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

    Vector3 accCausedVel = this->particle[0]->getAcceleration(); // velocity due to acceleration
    if (this->particle[1]) {
        accCausedVel -= this->particle[1]->getAcceleration();
    }
    real accCausedSepVel = accCausedVel * this->contactNormal * dt;

    if (accCausedSepVel < 0) {
        newSepVel += this->restitution * accCausedSepVel;
        if (newSepVel < 0) {
            newSepVel = 0;
        }
    }

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

void iNertia::ParticleContact::resolveInterpenetration(real dt) {
    if (this->penetration <= 0) {
        return; // no penetration to resolve
    }

    real totalInverseMass = this->particle[0]->getInverseMass();
    if (this->particle[1]) {
        totalInverseMass += this->particle[1]->getInverseMass();
    }

    if (totalInverseMass <= 0) {
        return; // infinite mass! do nothing
    }

    Vector3 movePerIMass = this->contactNormal * (-this->penetration / totalInverseMass);

    particle[0]->setPosition(particle[0]->getPosition() + movePerIMass * particle[0]->getInverseMass());

    if (this->particle[1]) {
        particle[1]->setPosition(particle[1]->getPosition() + movePerIMass * particle[1]->getInverseMass());
    }
}
