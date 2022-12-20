//
// Created by evag on 15/12/22.
//

#include "range.h"

uint get_range(const Range &range)
{
    return range.end - range.start+1;
}