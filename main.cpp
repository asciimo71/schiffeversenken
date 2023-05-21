#include <iostream>

#define C_LION 1

#include "battlefield.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    SRAND();

    {
        Battlefield bf = Battlefield(16);
        std::cout << bf.setShip(Ship::create(0, 0, 5, HORIZONTAL, 16)) << std::endl
                  << bf.string()
                  << bf.setShip(Ship::create(0, 0, 5, HORIZONTAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(15, 15, 5, HORIZONTAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(15, 15, 5, VERTICAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(1, 1, 5, VERTICAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(1, 0, 5, HORIZONTAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(2, 0, 5, HORIZONTAL, 16)) << std::endl // true
                  << bf.string()
                  << bf.setShip(Ship::create(1, 3, 3, VERTICAL, 16)) << std::endl // false
                  << bf.string()
                  << bf.setShip(Ship::create(4, 3, 3, VERTICAL, 16)) << std::endl // true
                  << bf.string()
                  << bf.setShip(Ship::create(5, 0, 5, HORIZONTAL, 16)) << std::endl // true
                  << bf.string()
                  << bf.setShip(Ship::create(0, 6, 3, VERTICAL, 16)) << std::endl // true
                  << bf.string()
                  << std::endl;

        std::cout << bf.fireAt(0, 0) << std::endl
                  << bf.string()
                  << bf.fireAt(1, 0) << std::endl
                  << bf.string()
                  << bf.fireAt(2, 0) << std::endl
                  << bf.string()
                  << bf.fireAt(3, 0) << std::endl
                  << bf.string()
                  << bf.fireAt(4, 0) << std::endl
                  << bf.string()
                  << bf.fireAt(0, 2) << std::endl
                  << bf.string()
                  << bf.fireAt(1, 2) << std::endl
                  << bf.string()
                  << bf.fireAt(2, 2) << std::endl
                  << bf.string()
                  << bf.fireAt(3, 2) << std::endl
                  << bf.string()
                  << bf.fireAt(4, 2) << std::endl
                  << bf.string()
                  << bf.fireAt(0, 4) << std::endl
                  << bf.string()
                  << bf.fireAt(1, 3) << std::endl
                  << bf.string()
                  << bf.fireAt(2, 3) << std::endl
                  << bf.string()
                  << bf.fireAt(3, 4) << std::endl
                  << bf.string()  
                  << bf.fireAt(4, 3) << std::endl
                  << bf.string()
                  << std::endl;

    }


    for (auto i = 0; i < 10; i++) {
        Battlefield bf = Battlefield(16);
        bf.setRandomShips();
        std::cout << bf.string();
        std::cout << std::endl;
    }

/*
    bf = Battlefield(12);
    std::cout << "place ship HORIZONTALLY " << 0 << ", " << 0 << " size 5: (true) == "
    << bf.setShip(*new Ship(0, 0, 5, HORIZONTAL)) << std::endl << bf.string();
    std::cout << "place ship HORIZONTALLY " << 0 << ", " << 5 << " size 5: (true) == "
    << bf.setShip(*new Ship(0, 5, 5, HORIZONTAL)) << std::endl << bf.string();
    std::cout << "place ship HORIZONTALLY " << 0 << ", " << 6 << " size 5: (false) == "
    << bf.setShip(*new Ship(0, 6, 5, HORIZONTAL)) << std::endl << bf.string();
    std::cout << "place ship HORIZONTALLY " << 0 << ", " << 5 << " size 5: (false) == "
    << bf.setShip(*new Ship(0, 5, 5, HORIZONTAL)) << std::endl << bf.string();

    std::cout << "place ship VERTICALLY " << 0 << ", " << 0 << " size 5: (false) == "
    << bf.setShip(*new Ship(0, 0, 5, VERTICAL)) << std::endl << bf.string();
    std::cout << "place ship VERTICALLY " << 1 << ", " << 0 << " size 5: (true) == "
    << bf.setShip(*new Ship(1, 0, 5, VERTICAL)) << std::endl << bf.string();
    std::cout << "place ship VERTICALLY " << 5 << ", " << 2 << " size 5: (true) == "
    << bf.setShip(*new Ship(5, 2, 5, VERTICAL)) << std::endl << bf.string();
    std::cout << "place ship VERTICALLY " << 6 << ", " << 1 << " size 4: (true) == "
    << bf.setShip(*new Ship(6, 1, 4, VERTICAL)) << std::endl << bf.string();
    std::cout << "place ship VERTICALLY " << 6 << ", " << 3 << " size 2: (false) == "
    << bf.setShip(*new Ship(6, 3, 2, VERTICAL)) <<
    " too many ships, complete is true " << bf.isComplete() << std::endl << bf.string();

    auto area = bf.battleground();
    for(auto i=0; i<100; i++) {
        std::cout << (char)(area[i] ? area[i] : '_');
    }
*/
    return 0;
}