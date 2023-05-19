#include <Arduino.h>
#include "battlefield.h"

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "colors.h"


Adafruit_NeoMatrix *matrix;
Battlefield *bf;

void setup() {
  // put your setup code here, to run once:
  bf = new Battlefield(16);

  matrix = new Adafruit_NeoMatrix(16, 16,
                                  1, 1,
                                  6,
                                  NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG + NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ZIGZAG,
                                  NEO_GRB + NEO_KHZ800);

  matrix->begin();
  matrix->clear();
  matrix->setBrightness(40);
  matrix->setTextWrap(false);

  /*
  matrix->print(bf->setShip(*new Ship(2, 2, 5, HORIZONTAL)));
  matrix->print(bf->setShip(*new Ship(6, 15, 4, VERTICAL)));
  matrix->println(bf->setShip(*new Ship(10, 12, 3, HORIZONTAL)));
  matrix->print(bf->setShip(*new Ship(1, 8, 3, VERTICAL)));
  matrix->print(bf->setShip(*new Ship(15, 4, 2, HORIZONTAL)));
  */

  bf->setRandomShips();

  matrix->show();

  //delay(1000);

  dumpBoard();
}

void dumpBoard() {
  auto area = bf->battleground();

  for (auto row = 0; row < 16; row++) {
    for (auto col = 0; col < 16; col++) {

      auto value = area[row * 16 + col];
      uint16_t color;

      if (value == '0') color = LED_RED_MEDIUM;
      else if (value == '0' + 1) color = LED_GREEN_LOW;
      else if (value == '0' + 2) color = LED_BLUE_MEDIUM;
      else if (value == '0' + 3) color = LED_PURPLE_MEDIUM;
      else if (value == '0' + 4) color = LED_ORANGE_MEDIUM;
      else color = LED_BLACK;

      matrix->drawPixel(col, row, color);
    }
  }

  delete[] area;

  matrix->show();
}

void loop() {
}
