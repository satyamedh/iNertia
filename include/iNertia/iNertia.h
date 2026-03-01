#ifndef INERTIA_LIBRARY_H
#define INERTIA_LIBRARY_H

// Core math types
#include "../src/core/precision.h"
#include "../src/core/Vector3.h"

// Particle physics
#include "../src/particle/Particle.h"

// Particle force generators
#include "../src/particle/forces/ParticleForceGen.h"
#include "../src/particle/forces/ParticleForceRegistry.h"
#include "../src/particle/forces/ParticleGravity.h"
#include "../src/particle/forces/ParticleDrag.h"
#include "../src/particle/forces/ParticleSpring.h"
#include "../src/particle/forces/ParticleAnchoredSpring.h"
#include "../src/particle/forces/ParticleBungee.h"
#include "../src/particle/forces/ParticleBuoyancy.h"

// Particle contacts
#include "../src/particle/contacts/ParticleContact.h"
#include "../src/particle/contacts/ParticleContactResolver.h"
#include "../src/particle/contacts/ParticleLink.h"
#include "../src/particle/contacts/ParticleCable.h"
#include "../src/particle/contacts/ParticleRod.h"

#endif // INERTIA_LIBRARY_H
