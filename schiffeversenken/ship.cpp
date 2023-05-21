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
    const int shipWidth = _direction == HORIZONTAL ? _size : 0;
    const int shipHeight = _direction == VERTICAL ? _size : 0;
    uint8_t top = 0 > _col - 1 ? 0 : _col - 1;
    uint8_t left = 0 > _row - 1 ? 0 : _row - 1;
    uint8_t bottom = _maxSize > shipHeight + 1 ? _maxSize : shipHeight + 1;
    uint8_t right = _maxSize > shipWidth + 1 ? 0 : shipWidth + 1;

    _boundingBox = new Point[]{
            {left,  top},
            {right, bottom}
    };
    _shipBox = new Point[]{
            {_col,                            _row},
            {static_cast<uint8_t>(shipWidth), static_cast<uint8_t>(shipHeight)}
    };
}

bool Ship::overlaps(Ship *other) {
    return other->_shipBox[BotRight].row >= _boundingBox[TopLeft].row
           && other->_shipBox[BotRight].col >= _boundingBox[TopLeft].col
           && other->_shipBox[TopLeft].row <= _boundingBox[BotRight].row
           && other->_shipBox[TopLeft].col <= _boundingBox[BotRight].col;
}