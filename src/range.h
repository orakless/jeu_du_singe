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

/**
 * @brief Gets the range between the two extremes of the variable
 * @param range
 * @return the range
 */
uint get_range(const Range &range);

#endif //SINGE_RANGE_H
