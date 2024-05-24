/*
 * JulianDay.cpp
 *
 *  Created on: 18 May 2024
 *      Author: jole
 */

#include "JulianDay.h"



JulianDay::JulianDay(int _year, short _month, short _day, short _hour, short _minute, double _second, short _tz, bool _verbose)
{

	//	copy parameters into the class data members
	JDYear		= _year;
	JDMonth		= _month;
	JDDay		= _day;

	JDHour		= _hour;
	JDMinute	= _minute;
	JDSecond	= _second;

	JDTz		= _tz;


	//	This is a fixed value used to calculate Julian century.
	//	See Meeus, Jean Astronomical Algorithms second edition p.163 (25.1)
	JDJ2000	= 2451545.0;



	// The Julian day number (JDN) is the integer assigned to a whole solar day in the
	// Julian day count starting from noon Universal Time, with Julian day number 0 assigned
	// to the day starting at noon on Monday, January 1 4713 proleptic Julian calendar
	// https://en.wikipedia.org/wiki/Julian_day
	JDJulianDayNumber	= 0.;

	// The Julian day is the continuous count of days since the beginning of the Julian period,
	// and is used primarily by astronomers, and in software for easily calculating elapsed
	// days between two events (e.g. food production date and sell by date).
	// https://en.wikipedia.org/wiki/Julian_day
	JDJulianDay			= 0.;

	JDJulianCentury		= 0.;
	JDJulianCenturyNoon	= 0.;


	JDVerbose			= _verbose;
	JDFLOATWIDTH		= 25;
	JDFLOATPRECISION	= 15;

	//	Parsing the date supplied, taking the appropriate action...
	JDParseDate();

	//	Calculating the JDN for the supplied date
	JDCalculateJDN();

	//
	//	Calculate the day number of the year
	//
	//int K = jdnIsLeap==true ? 1 : 2;
	//cout << "K = " << K << endl;
	//jdDayOfTheYear = int((275 * jdnMonth) / 9) - ((jdnIsLeap ? 1 : 2) * int((jdnMonth + 9) / 12)) + jdnDay - 30;

	//dayOfWeek = Wednesday;
	//cout << "Day: " << dayOfWeek << endl;


} // JulianDay::JulianDay()



JulianDay::~JulianDay() {

}
