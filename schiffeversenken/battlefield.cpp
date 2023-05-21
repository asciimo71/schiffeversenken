#include "battlefield.h"

Battlefield::Battlefield() : _positions(12 * 12), _size(12), _placedShips(0) {
    _battleground = new uint8_t[_positions];
    for(auto i=0; i< sizeof(_ships); _ships[i++]=nullptr);
};

Battlefield::Battlefield(uint8_t size) : _positions(size * size), _size(size), _placedShips(0) {
    _battleground = new uint8_t[_positions];
    for(int i=0;i<_positions;_battleground[i++]=0);
    for(auto i=0; i<SHIP_COUNT; _ships[i++]=nullptr);
}

Battlefield::~Battlefield() {
    delete _battleground;
}

/*
 * row / col is top of ship
 * size is amount of elements, the ship covers
 * direction is placement of ship. (horizontal: spans over columns, vertical spans over rows)
 *
 * 0/0 is top left
 * checks if ship fits into battleground
 * checks that space is not occupied (!=0)
 */


bool Battlefield::setShip(Ship *ship) {
    if(ship == nullptr) return false;
    if(isComplete()) return false;
    if (shipDoesOverlap(ship)) return false;

    ship->setId('0' + _placedShips);
    ship->isHorizontal()
           ? placeShipHorizontal(ship)
           : placeShipVertical(ship);

    _ships[_placedShips++] = ship;

    return true;
}

void Battlefield::placeShipHorizontal(Ship *ship) {
    for (uint8_t i = 0; i < ship->size(); i++) {
        _battleground[ship->row() * _size + ship->col() + i] = ship->id();
    }
}

void Battlefield::placeShipVertical(Ship *ship) {
    for (uint8_t i = 0; i < ship->size(); i++) {
        _battleground[(ship->row() + i) * _size + ship->col()] = ship->id();
    }
}

uint8_t *Battlefield::battleground() {
    auto *result = new uint8_t[_positions];
    memcpy(result, _battleground, _positions);
    return result;
}

bool Battlefield::shipDoesOverlap(Ship *ship) {
    for(auto sIdx=0; sIdx < _placedShips; sIdx++) {
        if(_ships[sIdx]->overlaps(ship)) {
            return true;
        }
    }

    return false;
}

__inline bool Battlefield::isComplete() const {
    return _placedShips >= SHIP_COUNT;
}

char *Battlefield::string() {
    auto str = new char[_positions+_size];
    memset(str, '_', _positions+_size); // clear
    for(int i=_size; i<_positions+_size; str[i]='\n',i+=_size+1); // add linebreaks
    for(auto sIdx = 0; sIdx < _placedShips; sIdx ++) {
        auto ship = _ships[sIdx];
        auto points = ship->shipBox();
        for(auto col = points[0].col; col <= points[1].col; col++) {
            for(auto row = points[0].row; row <= points[1].row; row++) {
                str[row * (_size+1) + col] = ship->damageAt(col, row) ? '*' : ship->id();
            }
        }
    }

    return str;
}

void Battlefield::setRandomShips() {
    while(!setShip(Ship::create(RAND(_size), RAND(_size), 5, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(Ship::create(RAND(_size), RAND(_size), 4, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(Ship::create(RAND(_size), RAND(_size), 3, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(Ship::create(RAND(_size), RAND(_size), 3, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(Ship::create(RAND(_size), RAND(_size), 2, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
}

bool Battlefield::fireAt(uint8_t col, uint8_t row) {
    for(auto sIdx = 0; sIdx < _placedShips; sIdx ++) {
        if(_ships[sIdx]->isHit(row, col)) return true;
    }

    return false;
}


