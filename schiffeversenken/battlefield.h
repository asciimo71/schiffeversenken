#ifndef _battlefield_h
#define _battlefield_h

#ifdef C_LION

#include <cstdint>
#include <cstdlib>
#include <ctime>

#define SRAND() std::srand(static_cast<unsigned int>(std::time(nullptr)))
#define RAND(x) (std::rand() % x)

#else

#include <Arduino.h>

#define SRAND() randomSeed(millis() * analogRead(0))
#define RAND(x) random(x)

#endif

#include <string.h>

#include "point.h"
#include "ship.h"

#define SHIP_COUNT 5

class Battlefield {
public:
    Battlefield();

    explicit Battlefield(uint8_t size);

    ~Battlefield();

    void setRandomShips();
    bool setShip(Ship *ship);

    uint8_t *battleground();
    bool isComplete() const;

    bool fireAt(uint8_t col, uint8_t row);

    char *string();

private:
    Ship *_ships[SHIP_COUNT];
    uint8_t *_battleground;
    const uint16_t _positions;
    const uint8_t _size;
    uint8_t _placedShips;

    void placeShipHorizontal(Ship *ship);
    void placeShipVertical(Ship *ship);

    bool shipDoesOverlap(Ship *ship);
};

#endif