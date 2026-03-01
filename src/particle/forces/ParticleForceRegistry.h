//
// Created by satyamedh on 26/01/26.
//

#ifndef INERTIA_PARTICLEFORCEREGISTRY_H
#define INERTIA_PARTICLEFORCEREGISTRY_H
#include <vector>

#include "core/precision.h"
#include "particle/Particle.h"
#include "ParticleForceGen.h"


namespace iNertia {
    class ParticleForceRegistry {
    protected:
        struct ParticleForceRegistration {
            Particle* particle;
            ParticleForceGen* pfg;
        };

        typedef std::vector<ParticleForceRegistration> PFRegistry;
        PFRegistry pf_registrations;

    public:
        void add(Particle* p, ParticleForceGen* fg); // why is register a keyword??
        void remove(const Particle* p, const ParticleForceGen* fg);

        void clear();

        void updateForces(real dt);
    };
}


#endif //INERTIA_PARTICLEFORCEREGISTRY_H
