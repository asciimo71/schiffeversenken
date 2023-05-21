//
// Created by Thomas Strauß on 21.05.23.
//

#include "Point.h"

Point *newPoint(uint8_t row, uint8_t col) {
    auto p = new Point;
    p->col = col;
    p->row = row;
    return p;
}