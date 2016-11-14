/*
  MD_AButton.h - Arduino library to handle multiple buttons on one analog input.
  Copyright (C) 2013 Marco Colli
  All rights reserved.
	
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
#ifndef _MD_ABUTTON_H
#define _MD_ABUTTON_H

#include <Arduino.h>

// Miscellaneous defines
#define	KEY_ADC_PORT	A0
#define	KEY_NONE		'\0'
#define	ARRAY_SIZE(x)	(sizeof(x)/sizeof(x[0]))

// MD_AButton class to one analog input button stream
class MD_AButton 
{
  public:
    MD_AButton(uint8_t keyPin);
    ~MD_AButton(void);

	// Data handling
	void	setKeyId(uint8_t id, char c);	// set the return value for key with id
	void	setDetectTime(uint16_t t);		// set the detect time for a key
	void	setRepeatTime(uint16_t t);		// set the repeat time for a key
	char	getKey(void);					// read value and determine the key pressed
											// returns KEY_NONE if no key found
  protected:
	uint8_t		_keyPin;		// analog input port
	uint32_t	_lastReadTime;	// last time the pin was read
	uint32_t	_lastKeyTime;	// last time a key was returned
	char	  	_lastKey;		// last key value read
	uint16_t	_timeDetect;	// time between keys detected
	uint16_t	_timeRepeat;	// time for auto-repeat
};

#endif
