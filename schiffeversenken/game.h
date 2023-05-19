#ifndef _game_h
#define _game_h

#include "ship.h"
#include "battlefield.h"

// returns a 
typedef struct {
  bool hit;
  Ship ship;
} FireResult;

typedef struct {
  uint8_t row;
  uint8_t col;
} Location;

enum MapType {
  OWN, ENEMY
};

class Game {
public:
  Game(uint8_t width);

  void randomizeShips();

  MapType changeBattlefield(MapType map);
  MapType currentBattlefield();
  MapType switchBattlefield();

  Location moveLeft();
  Location moveUp();
  Location moveRight();
  Location moveDown();

  // fire against enemy
  FireResult fire();

  /* returns the current battlefield area */
  uint8_t *battlefield();

  /* returns true, if all ships in the area are destroyed */
  bool defeated();
private:
  Battlefield *battlefields[2];
  Location cursor;
  MapType current;
};

#endif