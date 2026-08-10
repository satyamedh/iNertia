//
// Created by satyamedh on 23/01/26.
//

#ifndef INERTIA_PRECISION_H
#define INERTIA_PRECISION_H
#include "fix.h"
#include <cmath>

#define real_sqrt std::sqrt // will need to fixed-point sqrt implementation later when *optimizing*
#define real_pow std::pow // same as above
#define real_abs std::fabs // same as above

namespace iNertia {
    typedef float real; // switch to Fix<8, int32_t> after implementing LUT-based sqrt and fast pow.
}
#endif //INERTIA_PRECISION_H
