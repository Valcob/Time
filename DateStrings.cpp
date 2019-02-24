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
#include "DateStrings.h"

/* functions to return date strings */

char* monthStr(uint8_t month)
{
   strcpy_P(buffer, monthNames_P[month]);
   return buffer;
}

char* monthShortStr(uint8_t month)
{
   for (int i=0; i < dt_SHORT_STR_LEN; i++)
      buffer[i] = pgm_read_byte(&(monthShortNames_P[i+ (month*dt_SHORT_STR_LEN)]));
   buffer[dt_SHORT_STR_LEN] = 0;
   return buffer;
}

char* dayStr(uint8_t day)
{
   strcpy_P(buffer, dayNames_P[day]);
   return buffer;
}

char* dayShortStr(uint8_t day)
{
   uint8_t index = day*dt_SHORT_STR_LEN;
   for (int i=0; i < dt_SHORT_STR_LEN; i++)
      buffer[i] = pgm_read_byte(&(dayShortNames_P[index + i]));
   buffer[dt_SHORT_STR_LEN] = 0;
   return buffer;
}

/**
* Convert a time in UNIX format to a String representing time.
* @param[out] String constructed from current time.
* @param[in] time_t object to convert to extract time.
* TODO: Add internationalization support
*/
String getTimeStr (time_t moment) {
   char timeStr[10];
   sprintf_P (timeStr, PSTR("%02d:%02d:%02d"), hour (moment), minute (moment), second (moment));

   return timeStr;
}

/**
* Convert current time to a String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeStr () { return getTimeStr (now ()); }

/**
* Convert a time in UNIX format to a String representing its date.
* @param[out] String constructed from current date.
* @param[in] time_t object to convert to extract date.
* TODO: Add internationalization support
*/
String getDateStr (time_t moment) {
   char dateStr[12];
   sprintf_P (dateStr, PSTR("%02d/%02d/%4d"), day (moment), month (moment), year (moment));

   return dateStr;
}


/**
* Convert current date to a String.
* @param[out] String constructed from current date.
* TODO: Add internationalization support
*/
String getDateStr () { return getDateStr (now ()); }

/**
* Convert current time and date to a String.
* @param[in] time_t object to convert to String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeDateString (time_t moment) {
   return getTimeStr (moment) + " " + getDateStr (moment);
}

/**
* Convert current time and date to a String.
* @param[out] String constructed from current time.
* TODO: Add internationalization support
*/
String getTimeDateString () { return getTimeDateString (now ()); }
