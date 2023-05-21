#include "ship.h"

#define TopLeft 0
#define BotRight 1

Ship::Ship(const uint8_t row, const uint8_t col, const uint8_t size, const Direction direction, const uint8_t maxSize) :
        _row(row), _col(col),
        _size(size),
        _direction(direction),
        _id(-1),
        _maxSize(maxSize) {
    damaged = new bool[_size];
    destroyed = false;
    initBoundingBox();
}

/*
 * check if the target col/row are inside the ship area, sets the destroyed flag
 */
bool Ship::isHit(const uint8_t targetRow, const uint8_t targetCol) {
    Point target = {targetCol, targetRow};
    bool hit = _shipBox[TopLeft].col <= target.col
               && target.col <= _shipBox[BotRight].col      // l <= x <= r
               && _shipBox[TopLeft].row <= target.row
               && target.row <= _shipBox[BotRight].row;      // t <= y <= b

    if (hit) {
        auto hitCol = targetCol - _col;
        auto hitRow = targetRow - _row;
        int hitPos;

        if (_direction == HORIZONTAL) {
            hitPos = hitCol;
        } else {  // VERTICAL
            hitPos = hitRow;
        }

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
    if (_id >= 0) return;
    _id = id;
}

uint8_t Ship::id() const {
    return _id;
}

void Ship::initBoundingBox() {
    const int shipRight = _col + (_direction == HORIZONTAL ? _size - 1 : 0);
    const int shipBottom = _row + (_direction == VERTICAL ? _size - 1 : 0);
    uint8_t left = (_col - 1 < 0) ? 0 : _col - 1;
    uint8_t top = (_row - 1 < 0) ? 0 : _row - 1;
    uint8_t right = shipRight + 1 >= _maxSize ? _maxSize - 1 : shipRight + 1;
    uint8_t bottom = shipBottom + 1 >= _maxSize ? _maxSize - 1 : shipBottom + 1;

    _boundingBox = new Point[]{
            {left,  top},
            {right, bottom}
    };
    _shipBox = new Point[]{
            {_col,                            _row},
            {static_cast<uint8_t>(shipRight), static_cast<uint8_t>(shipBottom)}
    };
}

bool Ship::overlaps(Ship *other) {
    auto overlap = other->_shipBox[BotRight].row >= _boundingBox[TopLeft].row
                   && other->_shipBox[BotRight].col >= _boundingBox[TopLeft].col
                   && other->_shipBox[TopLeft].row <= _boundingBox[BotRight].row
                   && other->_shipBox[TopLeft].col <= _boundingBox[BotRight].col;

    return overlap;
}

Ship *Ship::create(uint8_t row, uint8_t col, uint8_t size, Direction direction, uint8_t maxSize) {
    auto optShip = new Ship(row, col, size, direction, maxSize);
    if (optShip->_shipBox[BotRight].row >= maxSize || optShip->_shipBox[BotRight].col >= maxSize)
        return nullptr;
    else
        return optShip;
}

Point *Ship::shipBox() {
    return new Point[2]{
            {_shipBox[0].col, _shipBox[0].row},
            {_shipBox[1].col, _shipBox[1].row}
    };
}

bool Ship::damageAt(uint8_t col, uint8_t row) {
    uint8_t dIdx;
    if(isVertical()) {
        dIdx = row - _row;
    }
    else {
        dIdx = col - _col;
    }
    return damaged[dIdx];
}
