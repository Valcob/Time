/* DateStrings.cpp
 * Definitions for date strings for use with the Time library
 *
 * Updated for Arduino 1.5.7 18 July 2014
 *
 * No memory is consumed in the sketch if your code does not call any of the string methods
 * You can change the text of the strings, make sure the short strings are each exactly 3 characters 
 * the long strings can be any length up to the constant dt_MAX_STRING_LEN defined in TimeLib.h
 * 
 */
#ifndef _DateStrings_Tlib_h
#define _DateStrings_Tlib_h

#if defined(__AVR__)
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif

#include <string.h> // for strcpy_P or strcpy
#include "TimeLib.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


// the short strings for each day or month must be exactly dt_SHORT_STR_LEN
#define dt_SHORT_STR_LEN  3 // the length of short strings

static char buffer[dt_MAX_STRING_LEN+1];  // must be big enough for longest string and the terminating null

PROGMEM const char monthStr0[] = "";
PROGMEM const char monthStr1[] = "January";
PROGMEM const char monthStr2[] = "February";
PROGMEM const char monthStr3[] = "March";
PROGMEM const char monthStr4[] = "April";
PROGMEM const char monthStr5[] = "May";
PROGMEM const char monthStr6[] = "June";
PROGMEM const char monthStr7[] = "July";
PROGMEM const char monthStr8[] = "August";
PROGMEM const char monthStr9[] = "September";
PROGMEM const char monthStr10[] = "October";
PROGMEM const char monthStr11[] = "November";
PROGMEM const char monthStr12[] = "December";

PROGMEM const char * const monthNames_P[] =
{
    monthStr0, monthStr1, monthStr2, monthStr3, monthStr4, monthStr5, monthStr6,
    monthStr7, monthStr8, monthStr9, monthStr10, monthStr11, monthStr12
};

PROGMEM const char monthShortNames_P[] = "ErrJanFebMarAprMayJunJulAugSepOctNovDec";

PROGMEM const char dayStr0[] = "Err";
PROGMEM const char dayStr1[] = "Sunday";
PROGMEM const char dayStr2[] = "Monday";
PROGMEM const char dayStr3[] = "Tuesday";
PROGMEM const char dayStr4[] = "Wednesday";
PROGMEM const char dayStr5[] = "Thursday";
PROGMEM const char dayStr6[] = "Friday";
PROGMEM const char dayStr7[] = "Saturday";

PROGMEM const char * const dayNames_P[] =
{
    dayStr0, dayStr1, dayStr2, dayStr3, dayStr4, dayStr5, dayStr6, dayStr7
};

PROGMEM const char dayShortNames_P[] = "ErrSunMonTueWedThuFriSat";

/* functions to return date strings */

char* monthStr(uint8_t month);

char* monthShortStr(uint8_t month);

char* dayStr(uint8_t day);

char* dayShortStr(uint8_t day);

/**
* Convert a time in UNIX format to a String representing time.
* @param[out] String constructed from current time.
* @param[in] time_t object to convert to extract time.
* TODO: Add internationalization support
*/
String getTimeStr (time_t moment);

/**
* Convert current time to a String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeStr ();

/**
* Convert a time in UNIX format to a String representing its date.
* @param[out] String constructed from current date.
* @param[in] time_t object to convert to extract date.
* TODO: Add internationalization support
*/
String getDateStr (time_t moment);


/**
* Convert current date to a String.
* @param[out] String constructed from current date.
* TODO: Add internationalization support
*/
String getDateStr ();

/**
* Convert current time and date to a String.
* @param[in] time_t object to convert to String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeDateString (time_t moment);

/**
* Convert current time and date to a String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeDateString ();

#endif