#include "ship.h"

Ship::Ship(const uint8_t row, const uint8_t col, const uint8_t size, const Direction direction) :
        _row(row), _col(col),
        _size(size),
        _direction(direction),
        _id(-1) {
    damaged = new bool[_size];
    destroyed = false;
}

/*
 * check if the target col/row are inside the ship area, sets the destroyed flag
 */
bool Ship::isHit(const uint8_t targetRow, const uint8_t targetCol) {
    auto hitCol = targetCol - _col;
    auto hitRow = targetRow - _row;
    int hitPos;
    bool hit;
    if (_direction == HORIZONTAL) {
        // 0 <= hitCol < size --> hit
        hit = hitRow && 0 <= hitCol && hitCol < _size;
        hitPos = hitCol;
    } else {  // VERTICAL
        hit = hitCol && 0 <= hitRow && hitRow < _size;
        hitPos = hitRow;
    }

    if (hit) {
        damaged[hitPos] = true;
        destroyed = true;
        for (auto i = 0; i < _size; i++) {
            destroyed = destroyed && damaged[i];
        }
    }

    return hit;
}

bool Ship::isHorizontal() {
    return _direction == HORIZONTAL;
}

Direction Ship::orientation() const {
    return _direction;
}

bool Ship::isVertical() {
    return !isHorizontal();
}

uint8_t Ship::size() const {
    return _size;
}

uint8_t Ship::row() const {
    return _row;
}

uint8_t Ship::col() const {
    return _col;
}

void Ship::setId(uint8_t id) {
    if(_id >= 0) return;
    _id = id;
}

uint8_t Ship::id() const {
    return _id;
}
