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

    {
        Battlefield bf = Battlefield(12);
        std::cout << "place ship HORIZONTALLY " << 0 << ", " << 0 << " size 5: (true) == "
                  << bf.setShip(Ship::create(0, 0, 5, HORIZONTAL, 12)) << std::endl << bf.string();
        std::cout << "place ship HORIZONTALLY " << 0 << ", " << 6 << " size 5: (true) == "
                  << bf.setShip(Ship::create(0, 6, 5, HORIZONTAL, 12)) << std::endl << bf.string();
        std::cout << "place ship HORIZONTALLY " << 2 << ", " << 8 << " size 5: (false) == "
                  << bf.setShip(Ship::create(2, 8, 5, HORIZONTAL, 12)) << std::endl << bf.string();
        std::cout << "place ship HORIZONTALLY " << 0 << ", " << 5 << " size 5: (false) == "
                  << bf.setShip(Ship::create(0, 5, 5, HORIZONTAL, 12)) << std::endl << bf.string();

        std::cout << "place ship VERTICALLY " << 0 << ", " << 0 << " size 5: (false) == "
                  << bf.setShip(Ship::create(0, 0, 5, VERTICAL, 12)) << std::endl << bf.string();
        std::cout << "place ship VERTICALLY " << 2 << ", " << 0 << " size 5: (true) == "
                  << bf.setShip(Ship::create(2, 0, 5, VERTICAL, 12)) << std::endl << bf.string();
        std::cout << "place ship VERTICALLY " << 5 << ", " << 2 << " size 5: (true) == "
                  << bf.setShip(Ship::create(5, 2, 5, VERTICAL, 12)) << std::endl << bf.string();
        std::cout << "place ship VERTICALLY " << 2 << ", " << 2 << " size 2: (true) == "
                  << bf.setShip(Ship::create(2, 2, 2, VERTICAL, 12)) << std::endl << bf.string();
        std::cout << "place ship VERTICALLY " << 6 << ", " << 3 << " size 2: (false) == "
                  << bf.setShip(Ship::create(6, 3, 2, VERTICAL, 12)) <<
                  " too many ships, complete is true " << bf.isComplete() << std::endl << bf.string();

        auto area = bf.battleground();
        for (auto i = 0; i < 100; i++) {
            std::cout << (char) (area[i] ? area[i] : '_');
        }
    }

    {
        Battlefield bf = Battlefield(12);

        for(int col = 0; col < 12; col++) {
            for(int row = 0; row < 12; row++) {
                std::cout << bf.setShip(Ship::create(row, col, 2, HORIZONTAL, 12)) << std::endl << bf.string();
            }
        }

        for(int col = 0; col < 12; col++) {
            for(int row = 0; row < 12; row++) {
                std::cout << bf.setShip(Ship::create(row, col, 2, VERTICAL, 12)) << std::endl << bf.string();
            }
        }
    }

    {
        Battlefield bf = Battlefield(12);

        for(int col = 0; col < 12; col++) {
            for(int row = 0; row < 12; row++) {
                std::cout << bf.setShip(Ship::create(row, col, 2, VERTICAL, 12)) << std::endl << bf.string();
            }
        }

        for(int col = 0; col < 12; col++) {
            for(int row = 0; row < 12; row++) {
                std::cout << bf.setShip(Ship::create(row, col, 2, HORIZONTAL, 12)) << std::endl << bf.string();
            }
        }
    }

    {
        Battlefield bf = Battlefield(12);

        bool shipSet;
        do {
            shipSet = false;
            for (int col = 0; col < 12; col++) {
                for (int row = 0; row < 12; row++) {
                    auto direction = RAND(2) ? HORIZONTAL : VERTICAL;
                    shipSet |= bf.setShip(Ship::create(row, col, 5, direction, 12));
                    std::cout << std::endl << bf.string();
                }
            }
        } while (shipSet);
    }

    return 0;
}