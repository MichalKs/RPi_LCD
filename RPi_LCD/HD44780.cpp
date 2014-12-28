/**
 * @file    HD44780.cpp
 * @brief	  
 * @date    28 gru 2014
 * @author  Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */
#include "HD44780.h"

HD44780::HD44780(int rsPin, int rwPin, int ePin,
    int d4Pin, int d5Pin, int d6Pin, int d7Pin):
    rs(rsPin, GPIO::DIR_OUTPUT), rw(rwPin, GPIO::DIR_OUTPUT),
    e(ePin, GPIO::DIR_OUTPUT), d4(d4Pin, GPIO::DIR_OUTPUT),
    d5(d5Pin, GPIO::DIR_OUTPUT), d6(d6Pin, GPIO::DIR_OUTPUT),
    d7(d7Pin, GPIO::DIR_OUTPUT) {


}

HD44780::~HD44780() {
  // TODO Auto-generated destructor stub
}

void HD44780::home(void) {
}

void HD44780::clear(void) {
}

void HD44780::changePosition(void) {
}

void HD44780::setCursor(int onOff, int blink) {
}

void HD44780::putc(char c) {
}

void HD44780::puts(char* c) {
}

void HD44780::sendData(unsigned char data) {

}

void HD44780::sendCommand(unsigned char data) {

  rw.set(0);
  rs.set(0);

  d4.changeDirection(GPIO::DIR_OUTPUT);
  d5.changeDirection(GPIO::DIR_OUTPUT);
  d6.changeDirection(GPIO::DIR_OUTPUT);
  d7.changeDirection(GPIO::DIR_OUTPUT);

  // write higher bits first
  e.set(1);

  e.set(0);

  e.set(1);

  e.set(0);

}

int HD44780::readFlag(void) {

  return 0;
}

void HD44780::write(unsigned char data) {
  if (data & (1<<3))
    d7.set(1);
  else
    d7.set(0);

  if (data & (1<<2))
    d6.set(1);
  else
    d6.set(0);

  if (data & (1<<1))
    d5.set(1);
  else
    d5.set(0);

  if (data & (1<<0))
    d4.set(1);
  else
    d4.set(0);
}

unsigned char HD44780::read(void) {

  return 0;
}
