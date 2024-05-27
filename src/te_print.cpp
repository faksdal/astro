/*
 * print.cpp
 *
 *  Created on: May 27, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include <iomanip>
#include "JulianDay.h"
#include "Tellus.h"





void Tellus::te_print(int _flags)
{
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	cout << "_flags: " << _flags << endl;


	if(_flags & (int)printFlags::JD_DATE || _flags & (int)printFlags::JD_TIME || _flags & (int)printFlags::JD_ALL){
		cout	<< "Date/time: " /*<< JDGetDayName()*/
				<< " " << JDGetJDDay()
				<< "/" <<  JDGetJDMonth()
				<< "/" << JDGetJDYear()
				<< " @ " << setw(2) << setfill('0') << JDGetJDHour()
				<<":" << setw(2) << setfill('0') << JDGetJDMinute()
				<< ":" << setw(2) << setfill('0') << JDGetJDSecond() << endl;
	}
	if(_flags & (int)printFlags::JD_TZ || _flags & (int)printFlags::JD_ALL){
		cout << " Timezone: " << JDGetJDTz() << endl;
	}
	if(_flags & (int)printFlags::JD_DOY || _flags & (int)printFlags::JD_ALL){
			cout << " DOY: " << JDGetJDDayOfTheYear() << endl;
	}



	//cout	<< "      DST: " << aSunDst << endl;

	//cout	<< "  Lat/Lon: " << setw(12) << setprecision(8) << aSunLat << "°/" << setw(12) << setprecision(8) << aSunLon << "°" << endl;
	cout << endl;


		//
		// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
		//
		struct my_numpunct : std::numpunct<char> {
			// We want to group in numbers of three
			std::string do_grouping() const {return "\03";}
		};
		std::locale loc (std::cout.getloc(),new my_numpunct);
		std::cout.imbue(loc);
		// *************************************************************************************************

}
