/*
 * TimeSupplied.cpp
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "TimeSupplied.h"



void TimeSupplied(int &_hour, int &_minute, double &_second, bool _verbose)
{
	if(_verbose)
		cout << "Time not supplied, using system time..." << endl;

	time_t current = time(NULL);
	struct tm* current_s = localtime(&current);

	_hour	= current_s->tm_hour;
	_minute	= current_s->tm_min;
	_second	= current_s->tm_sec;

	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	//cout.setf(ios::fixed);
	if(_verbose){
		cout << "Time: " << setprecision(2) << _hour
			 << ":" << setprecision(2) << _minute
			 << ":" << setw(2) << setprecision(9) << _second << endl;
	}

	return;
}
