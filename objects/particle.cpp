//
// Created by satyamedh on 24/01/26.
//

#include "particle.h"

#include <cassert>
#include <stdexcept>

namespace iNertia {
    void particle::setMass(const real mass) {
        if (mass != 0) {
            this->inverseMass = static_cast<real>(1.0f) / mass; // static cast may be redundant now, but if switching to fixed-point later, will be needed
        } else {
            throw std::runtime_error("particle::setMass(): mass cannot be zero");
        }
    }

    void particle::setInverseMass(const real inverse_mass) {
        this->inverseMass = inverse_mass;
    }

    real particle::getMass() const {
        if (this->inverseMass == 0) {
            throw std::runtime_error("particle::getMass(): infinite mass (inverse mass is zero)");
        }
        return static_cast<real>(1.0f) / this->inverseMass;
    }

    real particle::getInverseMass() const {
        return this->inverseMass;
    }

    void particle::integrate(real dt) {
        assert(dt > static_cast<real>(0)); // no going back in time :D

        this->position.addScaledVector(this->velocity, dt); // s1 = s0 + ut

        Vector3 resultingAcc = acceleration;
        resultingAcc.addScaledVector(this->forceAccum, this->inverseMass); // a = F/m

        this->velocity.addScaledVector(resultingAcc, dt); // v1 = v0 + at

        velocity *= real_pow(damping, dt); // apply damping/drag/friction


    }
}
