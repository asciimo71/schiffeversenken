#include <iostream>
#define C_LION 1
#include "battlefield.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Battlefield bf = Battlefield(10);
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
    std::cout << std::endl;
    return 0;
}