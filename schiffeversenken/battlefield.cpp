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


bool Battlefield::setShip(Ship &ship) {
    if(isComplete()) return false;

    bool success = ship.isHorizontal()
           ? placeShipHorizontal(ship)
           : placeShipVertical(ship);

    if( success ) {
        _ships[_placedShips++] = &ship;
    }

    return success;
}

bool Battlefield::placeShipHorizontal(Ship &ship) {
    if (!shipMatchesHorizontal(ship)) return false;
    ship.setId('0' + _placedShips);
    for (uint8_t i = 0; i < ship.size(); i++) {
        _battleground[ship.row() * _size + ship.col() + i] = ship.id();
    }
    return true;
}

bool Battlefield::placeShipVertical(Ship &ship) {
    if (!shipMatchesVertical(ship)) return false;
    ship.setId('0' + _placedShips);
    for (uint8_t i = 0; i < ship.size(); i++) {
        _battleground[(ship.row() + i) * _size + ship.col()] = ship.id();
    }
    return true;
}

uint8_t *Battlefield::battleground() {
    auto *result = new uint8_t[_positions];
    memcpy(result, _battleground, _positions);
    return result;
}

bool Battlefield::shipMatchesHorizontal(Ship &ship) {
    if (ship.col() + ship.size() > _size) return false;
    for (uint8_t i = 0; i < ship.size(); i++) {
        if (_battleground[ship.row() * _size + ship.col() + i]) return false;
    }
    return true;
}

bool Battlefield::shipMatchesVertical(Ship &ship) {
    if (ship.row() + ship.size() > _size) return false;
    if(ship.row())
    if(ship.col()>0) {

    }
    for (uint8_t i = 0; i < ship.size(); i++) {
        if (_battleground[(ship.row() + i) * _size + ship.col()]) return false;
    }
    return true;
}

__inline bool Battlefield::isComplete() const {
    return _placedShips >= SHIP_COUNT;
}

char *Battlefield::string() {
    auto str = new char[_positions+_size];
    for(auto row = 0; row < _size; row++) {
        for(auto col = 0; col < _size; col++) {
            char shipId = static_cast<char>(_battleground[row*_size+col]);
            str[row*(_size+1)+col] = _battleground[row*_size+col] ? shipId : '_';
        }
        str[row*(_size+1)+_size] = '\n';
    }
//    str[_positions] = '\0';
    return str;
}

void Battlefield::setRandomShips() {
    SRAND();

    while(!setShip(*new Ship(RAND(_size), RAND(_size), 5, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(*new Ship(RAND(_size), RAND(_size), 4, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(*new Ship(RAND(_size), RAND(_size), 3, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(*new Ship(RAND(_size), RAND(_size), 3, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
    while(!setShip(*new Ship(RAND(_size), RAND(_size), 2, RAND(2) ? HORIZONTAL : VERTICAL, _size)));
}


