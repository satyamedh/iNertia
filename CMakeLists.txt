cmake_minimum_required(VERSION 4.1)
project(iNertia)

set(CMAKE_CXX_STANDARD 20)

add_library(iNertia STATIC iNertia.cpp
        maths/fix.h
        maths/precision.h
        maths/Vector3.h
        phsyics/objects/particle.cpp
        phsyics/objects/particle.h
        phsyics/helpers/particleForceGen.h
        phsyics/helpers/particleForceRegistry/particleForceRegistry.cpp
        phsyics/helpers/particleForceRegistry/particleForceRegistry.h
        phsyics/helpers/ForceTypes/Particle/ParticleGravity.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleGravity.h
        phsyics/helpers/ForceTypes/Particle/ParticleDrag.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleDrag.h
        phsyics/helpers/ForceTypes/Particle/ParticleSpring.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleSpring.h
        phsyics/helpers/ForceTypes/Particle/ParticleAnchoredSpring.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleAnchoredSpring.h
        phsyics/helpers/ForceTypes/Particle/ParticleBungee.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleBungee.h
        phsyics/helpers/ForceTypes/Particle/ParticleBuoyancy.cpp
        phsyics/helpers/ForceTypes/Particle/ParticleBuoyancy.h
        phsyics/helpers/Contacts/ParticleContact.cpp
        phsyics/helpers/Contacts/ParticleContact.h
)
