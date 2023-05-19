#include "game.h"

Game::Game(uint8_t width) {
  cursor.col = 0;
  cursor.row = 0;
  battlefields[0] = new Battlefield(width);
  battlefields[1] = new Battlefield(width);
  changeBattlefield(OWN);
}

MapType Game::changeBattlefield(MapType map) {
  MapType old = current;
  current = map;
  return old;
}

MapType Game::switchBattlefield() {
  current = (current == OWN) ? ENEMY : OWN;
  return current;
}

MapType Game::currentBattlefield() {
  return current;
}

byte *Game::battlefield() {
  battlefields[current]->battleground();
}