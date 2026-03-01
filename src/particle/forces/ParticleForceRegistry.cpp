//
// Created by satyamedh on 26/01/26.
//

#include "ParticleForceRegistry.h"

void iNertia::ParticleForceRegistry::add(Particle *p, ParticleForceGen *fg) {
    ParticleForceRegistration registration{};
    registration.particle = p;
    registration.pfg = fg;
    this->pf_registrations.push_back(registration);
}

void iNertia::ParticleForceRegistry::remove(const Particle *p, const ParticleForceGen *fg) {
    for (auto it = this->pf_registrations.begin(); it != this->pf_registrations.end(); ++it) {
        if (it->particle == p && it->pfg == fg) {
            this->pf_registrations.erase(it);
            return;
        }
    }
}

void iNertia::ParticleForceRegistry::clear() {
    this->pf_registrations.clear();
}

void iNertia::ParticleForceRegistry::updateForces(const real dt) {
    for (auto &[particle, pfg] : this->pf_registrations) {
        pfg->updateForce(particle, dt);
    }
}
