/*
 * JulianDay.h
 *
 *  Created on: 18 May 2024
 *      Author: jole
 *
 *
 *
 *	References:
 *		https://isbnsearch.org/isbn/0943396611
 *		https://observablehq.com/@danleesmith/meeus-solar-position-calculations
 *
 *
 *
 *
 *	Constructor parameters:
 * 		JDYear:		the year as an integer, i.e. 2022 or -1
 * 		JDMonth:	the month as a short, 1 = January, 2 = February and so forth
 * 		JDDay:		the day number of the month
 *		JDHour:		the hour of the day, 0-23, local time
 *		JDMinute:	the minute of the hour 0-59, local time
 *		JDSecond:	the second of the minute, 0-59 with fractions, local time
 *		JDTz:		the timezone
 *		JDVerbose:	if true, prints out extra info during calculation
 *
 *
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 *
 */

#ifndef INC_JULIANDAY_H_
#define INC_JULIANDAY_H_

#include <iostream>

using namespace std;



class JulianDay{



	// True for dates in the Gregorian calendar, false otherwise
	bool	JDGregorianDate;

	// Some dates in our history doesn't exist; 5th - 14th of October 1582 were skipped during the
	// transition from the Julian to the Gregorian Calendar.
	// True for any other date
	bool	JDValidDate;

	// Set this to true if you want the calculation process to be verbose
	bool	JDVerbose;

	// True for leap years
	bool	JDIsLeap;

	// These holds values for the date to be converted into Julian Day Number (JDN)
	float	JDDay;
	short	JDMonth, JDHour, JDMinute, JDTz;
	double	JDSecond;

	//	Precision formatters for terminal printing
	short	JDFLOATWIDTH, JDFLOATPRECISION;

	// Day number of the year
	int		JDDayOfTheYear;

	//	Value of the year being converted to JDN
	int		JDYear;



	// The Julian day number (JDN) is the integer assigned to a whole solar day in the
	// Julian day count starting from noon Universal Time, with Julian day number 0 assigned
	// to the day starting at noon on Monday, January 1 4713 proleptic Julian calendar
	// https://en.wikipedia.org/wiki/Julian_day
	long double	JDJulianDayNumber;

	// The Julian day is the continuous count of days since the beginning of the Julian period,
	// and is used primarily by astronomers, and in software for easily calculating elapsed
	// days between two events (e.g. food production date and sell by date).
	// https://en.wikipedia.org/wiki/Julian_day
	long double	JDJulianDay;

	long double	JDJulianCentury;
	long double	JDJulianCenturyNoon;
	long double	JDJ2000;
	long double	JDJulianMillennia;
	long double	JDJulianMillenniaNoon;

	//enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
	//Days	dayOfWeek;
	//const char	*dayOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


	void	JDParseDate(void);
	void	JDCalculateJDN(void);


public:

	JulianDay(int _year, short _month, float _day, short _hour, short _minute, double _second, short _tz, bool _verbose);

	virtual ~JulianDay();

	// inline public functions providing data member values

	inline int			JDGetJDYear(void)				{ return JDYear; }
	inline int			JDGetJDDayOfTheYear(void)		{ return JDDayOfTheYear; }
	inline short		JDGetJDMonth(void)				{ return JDMonth; }
	inline short		JDGetJDDay(void)				{ return JDDay; }
	inline short		JDGetJDHour(void)				{ return JDHour; }
	inline short		JDGetJDMinute(void)				{ return JDMinute; }
	inline short		JDGetJDSecond(void)				{ return JDSecond; }
	inline short		JDGetJDTz(void)					{ return JDTz; }
	inline long double	JDGetJDJulianDay(void)			{ return JDJulianDay; }
	//inline long double	JDGetJDoon(void)				{ return JDJulianDayNumber; }
	//inline long double	JDGetJDJulianCentury(void)		{ return JDJulianCentury; }
	//inline long double	JDGetJDJulianCenturyNoon(void)	{ return JDJulianCenturyNoon; }
	//inline long double	JDGetJDJulianMillenia(void)		{ return JDJulianMillennia; }
	//inline long double	JDGetJDJulianMilleniaNoon(void)	{ return JDJulianMillenniaNoon; }
	inline bool			JDGetIsLeap(void)				{ return JDIsLeap; }


	//


	//const char*	jdGetDayName(void);

}; // class JulianDay


#endif /* INC_JULIANDAY_H_ */
