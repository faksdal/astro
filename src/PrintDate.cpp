/*
 * PrintTime.cpp
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "TimeSupplied.h"



void PrintDate(int _year, int _month, double _day)
{
	cout << "Date: " <<  _year
	     << "-" << setw(2) << setfill('0')<< _month
	     << "-" << setw(2) << setfill('0') << _day << endl;
}
