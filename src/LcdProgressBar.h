/*
  LcdProgressBar.h - LcdProgressBar library v1.0.1 - 2017-02-02

  LcdProgressBar is an Arduino library for displaying a progress bar in LCD display,
  which is previously initialized. This library uses LiquidCrystal library for displaying.

  Copyright (c) Wilfried Loche.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/
#ifndef LcdProgressBar_h
#define LcdProgressBar_h

#include "Arduino.h"
#include <LiquidCrystal.h>

/**
 * Version
 * (Major:non-compatible changes) . (Minor:backwards compatible changes) . (Patch:bugfix releases)
 * @refer http://semver.org/
 */
#define LCDPROGRESSBAR_VERSION  "1.0.1"

/**
 * Debug mode?
 * - Uncomment to debug (verbose on Serial monitor)
 * - Comment it to avoid debug messages
 */
//#define LCDPROGRESSBAR_DEBUG true

class LcdProgressBar
{
  public:
    /**
     * Contructor
     * @param lcd     LiquidCrystal instance (must pass the pointer via prefix &, e.g. &lcd)
     * @param row     Which row to display. 0 is the 1st row, 1 is the second, ...
     * @param numCols Number of columns your LCD has (16, 8, ...)
     */
    LcdProgressBar(LiquidCrystal* lcd, int row = 0, int numCols = 16);

    /**
     * Set the starting value of your progress bar (0 by default)
     * @param minValue Starting value
     */
    void setMinValue(unsigned long minValue);

    /**
     * Set the finishing value of your progress bar (must be provided)
     * @param minValue Finishing value
     */
    void setMaxValue(unsigned long maxValue);

    /**
     * Draw the progress bar on the LCD
     * @param value Value to draw
     */
    void draw(unsigned long value);

    /**
     * Alias on draw() (LcdBarGraph style :))
     */
    void drawValue(unsigned long value);

  private:
    //-- LiquidCrystal instance
    LiquidCrystal* _lcd;

    //-- Starting value
    unsigned long _minValue = 0;
    //-- Finishing value
    unsigned long _maxValue;
    //-- Computed finishing value (optimization purpose only, to avoid some repetitive maths)
    unsigned long _computedMaxValue;

    //-- Number of columns your LCD has (16, 8, ...)
    int _numCols = 0;
    //-- Computed number of columns (optimization purpose only, to avoid some repetitive maths)
    int _computedNumCols = 0;
    //-- Which row to display. 0 is the 1st row, 1 is the second, ...
    int _row = 0;
    //-- Which position is the progress bar: optimization purpose only; refresh LCD only on change
    byte _previousProgressPos = -1;
};

#endif
