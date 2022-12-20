//
// Created by evag on 15/12/22.
//

#ifndef SINGE_RANGE_H
#define SINGE_RANGE_H

#include "types_const.h"

struct Range {
    uint start;
    uint end;
};

uint get_range(const Range &range);

#endif //SINGE_RANGE_H
