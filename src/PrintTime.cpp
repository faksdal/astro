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



void PrintTime(int _hour, int _minute, double _second)
{

	cout << "Time: " << setprecision(2) << _hour
	     << ":" << setprecision(2) << _minute
	     << ":" << setprecision(9) << _second << endl;
}
