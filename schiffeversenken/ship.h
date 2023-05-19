#ifndef _ship_h
#define _ship_h

#ifdef C_LION

#include <cstdint>

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
    bool destroyed;
    bool *damaged;
    int _id;

public:
    Ship(uint8_t row, uint8_t col, uint8_t size, Direction direction);

    uint8_t id() const;
    void setId(uint8_t id);
    bool isHit(uint8_t row, uint8_t col);

    bool isHorizontal();
    bool isVertical();

    Direction orientation() const;

    uint8_t size() const;
    uint8_t row() const;
    uint8_t col() const;

};


#endif