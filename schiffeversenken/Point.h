//
// Created by Thomas Strauß on 21.05.23.
//

#ifndef SCHIFFEVERSENKEN_POINT_H
#define SCHIFFEVERSENKEN_POINT_H

#ifdef C_LION

#include <cstdint>
#include <cstdlib>

#else

#include <Arduino.h>

#endif

typedef struct {
    uint8_t col, row;
} Point;


#endif //SCHIFFEVERSENKEN_POINT_H
