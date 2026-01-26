cmake_minimum_required(VERSION 4.1)
project(iNertia)

set(CMAKE_CXX_STANDARD 20)

add_library(iNertia STATIC iNertia.cpp
        maths/fix.h
        maths/precision.h
        maths/Vector3.h
        phsyics/objects/particle.cpp
        phsyics/objects/particle.h
)
