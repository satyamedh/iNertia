//
// Created by satyamedh on 24/01/26.
//

#include "particle.h"

#include <cassert>
#include <stdexcept>

namespace iNertia {
    void Particle::clearAccumulator() {
        this->forceAccum.clear();
    }

    void Particle::addForce(const Vector3 &force) {
        this->forceAccum += force;
    }

    void Particle::setMass(const real mass) {
        if (mass != 0) {
            this->inverseMass = static_cast<real>(1.0f) / mass; // static cast may be redundant now, but if switching to fixed-point later, will be needed
        } else {
            throw std::runtime_error("Particle::setMass(): mass cannot be zero");
        }
    }

    void Particle::setInverseMass(const real inverse_mass) {
        this->inverseMass = inverse_mass;
    }

    real Particle::getMass() const {
        if (this->inverseMass == 0) {
            throw std::runtime_error("Particle::getMass(): infinite mass (inverse mass is zero)");
        }
        return static_cast<real>(1.0f) / this->inverseMass;
    }

    real Particle::getInverseMass() const {
        return this->inverseMass;
    }

    void Particle::integrate(const real dt) {
        assert(dt > static_cast<real>(0)); // no going back in time :D

        this->position.addScaledVector(this->velocity, dt); // s1 = s0 + ut

        Vector3 resultingAcc = acceleration;
        resultingAcc.addScaledVector(this->forceAccum, this->inverseMass); // a = F/m

        this->velocity.addScaledVector(resultingAcc, dt); // v1 = v0 + at

        velocity *= real_pow(damping, dt); // apply damping/drag/friction


    }
}
