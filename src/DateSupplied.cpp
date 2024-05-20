/*
 * DateSupplied.cpp
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//



#include "DateSupplied.h"



void DateSupplied(int &_year, int &_month, int &_day, bool _verbose) //, int _hour, int _minute, float _second, bool _verbose)
{
	if(_verbose)
		cout << "Date not supplied, using system date..." << endl;

	time_t current = time(NULL);
	struct tm* current_s = localtime(&current);

	_day	= current_s->tm_mday;
	_month	= ++current_s->tm_mon;
	_year	= 1900 + current_s->tm_year;

	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	//cout.setf(ios::fixed);
	if(_verbose){
		cout << "Day: " << setw(2) << setfill('0') << _day
			 << ", month: " << setw(2) << setfill('0') << _month
			 << ", year: " << setw(4) << setfill('0')<< _year << endl;
	}

	return;
}
