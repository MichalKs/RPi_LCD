/**
 * @file    HD44780.h
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
#ifndef HD44780_H_
#define HD44780_H_

#include "GPIO.h"

class HD44780 {
public:
  HD44780(int rs, int rw, int e, int d0, int d1, int d2, int d3);
  virtual ~HD44780();

  void home(void);
  void clear(void);
  void changePosition(void);
  void setCursor(int onOff, int blink);
  void putc(char c);
  void puts(char* c);

private:

  GPIO rs;
  GPIO rw;
  GPIO e;

  GPIO d4, d5, d6, d7;

  void sendData(unsigned char);
  void sendCommand(unsigned char);
  int readFlag(void);
  void write(unsigned char data);
  unsigned char read(void);

};

#endif /* HD44780_H_ */
