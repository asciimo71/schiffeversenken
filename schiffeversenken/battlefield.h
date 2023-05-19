#ifndef _battlefield_h
#define _battlefield_h

#ifdef C_LION

#include <cstdint>

#endif

#include "ship.h"

#define SHIP_COUNT 5

class Battlefield {
public:
    Battlefield();

    explicit Battlefield(uint8_t size);

    ~Battlefield();

    bool setShip(Ship &ship);

    uint8_t *battleground();
    bool isComplete() const;

    char *string();

private:
    Ship *_ships[SHIP_COUNT];
    uint8_t *_battleground;
    const uint16_t _positions;
    const uint8_t _size;
    uint8_t _placedShips;

    bool shipMatchesHorizontal(Ship &ship);
    bool shipMatchesVertical(Ship &ship);

    bool placeShipHorizontal(Ship &ship);
    bool placeShipVertical(Ship &ship);
};

#endif