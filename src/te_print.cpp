/*
 * print.cpp
 *
 *  Created on: May 27, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include "JulianDay.h"
#include "Tellus.h"




void Tellus::te_print(int _flags)
{
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	cout << "_flags: " << _flags << endl;




}
