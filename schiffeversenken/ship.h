#ifndef _ship_h
#define _ship_h

#include "point.h"

#ifdef C_LION

#include <cstdint>
#include <algorithm>

#else

#include <Arduino.h>

#endif

enum Direction {
    HORIZONTAL, VERTICAL
};

// this is a ship game object
class Ship {
private:
    const uint8_t _col;
    const uint8_t _row;
    const uint8_t _size;
    const Direction _direction;
    const uint8_t _maxSize;
    bool destroyed;
    bool *damaged;
    int _id;
    Point *_boundingBox;
    Point *_shipBox;

    void initBoundingBox();

    Ship(uint8_t row, uint8_t col, uint8_t size, Direction direction, uint8_t maxSize);

public:
    static Ship *create(uint8_t row, uint8_t col, uint8_t size, Direction direction, uint8_t maxSize);

    uint8_t id() const;
    void setId(uint8_t id);
    bool isHit(uint8_t row, uint8_t col);

    bool isHorizontal();
    bool isVertical();

    Direction orientation() const;

    uint8_t size() const;
    uint8_t row() const;
    uint8_t col() const;

    /**
     * compares, if the other ship's shipbox overlaps this ships bounding box.
     *
     * @param other the other ship
     * @return true, if the shipboxes overlap
     */
    bool overlaps(Ship *other);

    /**
     * returns top,left and bottom, right points of ship-box.
     *
     * the ship box is the bounding box of the ship + a border of 1. It marks the space that
     * this ship occupies on the battlefield.
     *
     * @return Point[2] [(Top.Left), (Bottom, Right)]
     */
    Point *shipBox();

    bool damageAt(uint8_t col, uint8_t row);
};


#endif