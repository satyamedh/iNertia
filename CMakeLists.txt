cmake_minimum_required(VERSION 4.1)
project(iNertia)

set(CMAKE_CXX_STANDARD 20)

add_library(iNertia STATIC
        iNertia.cpp

        # Core math types
        src/core/fix.h
        src/core/precision.h
        src/core/Vector3.h

        # Particle
        src/particle/Particle.cpp
        src/particle/Particle.h

        # Particle forces
        src/particle/forces/ParticleForceGen.h
        src/particle/forces/ParticleForceRegistry.cpp
        src/particle/forces/ParticleForceRegistry.h
        src/particle/forces/ParticleGravity.cpp
        src/particle/forces/ParticleGravity.h
        src/particle/forces/ParticleDrag.cpp
        src/particle/forces/ParticleDrag.h
        src/particle/forces/ParticleSpring.cpp
        src/particle/forces/ParticleSpring.h
        src/particle/forces/ParticleAnchoredSpring.cpp
        src/particle/forces/ParticleAnchoredSpring.h
        src/particle/forces/ParticleBungee.cpp
        src/particle/forces/ParticleBungee.h
        src/particle/forces/ParticleBuoyancy.cpp
        src/particle/forces/ParticleBuoyancy.h

        # Particle contacts
        src/particle/contacts/ParticleContact.cpp
        src/particle/contacts/ParticleContact.h
        src/particle/contacts/ParticleContactResolver.cpp
        src/particle/contacts/ParticleContactResolver.h
        src/particle/contacts/ParticleLink.cpp
        src/particle/contacts/ParticleLink.h
        src/particle/contacts/ParticleCable.cpp
        src/particle/contacts/ParticleCable.h
        src/particle/contacts/ParticleRod.cpp
        src/particle/contacts/ParticleRod.h
)

target_include_directories(iNertia
        PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
