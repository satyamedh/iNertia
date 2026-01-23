//
// Created by satyamedh on 23/01/26.
//

#ifndef INERTIA_PRECISION_H
#define INERTIA_PRECISION_H
#include "fix.h"

#define real_sqrt std::sqrtf // will need to fixed-point sqrt implementation later when *optimizing*

namespace iNertia {
    typedef float real; // switch to Fix<8, int32_t> if and when vog allows
}
#endif //INERTIA_PRECISION_H
