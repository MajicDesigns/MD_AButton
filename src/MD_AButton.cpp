/*
  MD_AButton.cpp - Arduino library to handle multiple buttons on one analog input.
  Copyright (C) 2013 Marco Colli
  All rights reserved.

  See MD_AButton.h for complete comments

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <MD_AButton.h>

typedef struct
{
  int	adcThreshold;		// Average analog value (PULLUP and no PULLUP)
  int	adcTolerance;		// Valid range will be Average +/- Tolerance
  char	value;				// value returned to the caller
} TKEYDEF;

TKEYDEF keyDefTable[] =
{
  { 10, 10, 'R' },	// Right
  {139, 15, 'U' },	// Up
  {315, 15, 'D' },	// Down
  {489, 15, 'L' },	// Left
  {726, 15, 'S' }	  // Select
};

MD_AButton::MD_AButton(uint8_t keyPin)
{
	_keyPin = keyPin;
	_lastReadTime = 0;
	_lastKeyTime = 0;
	_lastKey = KEY_NONE;
	_timeDetect = 100;
	_timeRepeat = 300;
}

MD_AButton::~MD_AButton(void)
{
}

void MD_AButton::setKeyId(uint8_t id, char c)
{
	if ((id >= 0) && (id < ARRAY_SIZE(keyDefTable)))
	{
		keyDefTable[id].value = c;
	}
}

void MD_AButton::setDetectTime(uint16_t t)
{
	_timeDetect = t;
}

void MD_AButton::setRepeatTime(uint16_t t)
{
	_timeRepeat = t;
}

char MD_AButton::getKey(void)
// Convert ADC value to character
// return the key code defined in the keyDefTable
// Only read a key every 100ms. Effectively debounces.
// If a key is kept pressed, auto repeat every 300 milliseconds.
{
  int	input = analogRead(_keyPin);
  char	key = KEY_NONE;
  
  if (millis()-_lastReadTime > _timeDetect)
  {
	  _lastReadTime = millis();

	  // get the analog value and work out what key it is
	  for (int k = 0; k < ARRAY_SIZE(keyDefTable); k++)
	  {
			if ((input >= (keyDefTable[k].adcThreshold - keyDefTable[k].adcTolerance)) &&
				(input <= (keyDefTable[k].adcThreshold + keyDefTable[k].adcTolerance)))
			{
				key = keyDefTable[k].value;
				break;
			}
	  }

	  // check if this is the same as before and do auto repeat if timing is right
	  if ((key == _lastKey) && (_lastKey != KEY_NONE))
	  {
		  if (millis() - _lastKeyTime < _timeRepeat)
			  // don't repeat yet
			  key = KEY_NONE;
		  else
			  // remember this repeat time for next time
			  _lastKeyTime = millis();
	  }
	  else
	  {
			// save the key for next time
			_lastKey = key;
			_lastKeyTime = millis();
	  }
  }
  
  return(key);
}

