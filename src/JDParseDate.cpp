/*
 * jdnParseDate.cpp
 *
 *	Created on: 20 Nov 2022
 *	Author: jole
 *
 *
 *	This function takes care of checking the user inputs a valid date, and also that we use the
 *	correct algorithm whether we're using the Julian or Gregorian calendar.
 *      
 *
 */

//#include <iostream>
#include "JulianDay.h"

using namespace std;



void JulianDay::JDParseDate(void)
{
	//	We assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statements
	JDValidDate		= true;
	JDGregorianDate	= true;


	//	Default is no leap year
	JDIsLeap			= false;
	if(JDYear > 1582){
		if( ((JDYear % 4) == 0) && (((JDYear % 100) != 0) || ((JDYear % 400) == 0))){
			if(JDVerbose)
				cout << JDYear << " is a Leap year :-)" << endl;

			JDIsLeap	= true;
		}
		else{
			if(JDVerbose)
				cout << JDYear << " is not Leap year!" << endl;

			JDIsLeap	= false;
		}
	}


	//	If we're in 1582, check for valid date. There are ten missing dates this year as we went from
	//	using the Julian calendar to be using the Gregorian calendar.
	if(JDYear == 1582 && JDMonth == 10){
		switch(JDDay){
		case 1:
		case 2:
		case 3:
		case 4:		JDGregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	cout << endl << "No such date!\n Exiting..." << endl;
					//JDValidDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(JDYear == 1582 && JDMonth < 10){
		JDGregorianDate = false;

		if(JDVerbose)
			cout << endl << "Year == 1582 and month is less than 10." << endl;
	}
	else if(JDYear < 1582){
		JDGregorianDate = false;

		if(JDVerbose)
			cout << endl << "Year is less than 1582." << endl;
	}
}
