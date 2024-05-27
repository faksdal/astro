/*
 * Tellus.cpp
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include <iostream>


#include "Tellus.h"



Tellus::Tellus(int _year, short _month, float _day, short _hour, short _minute, double _second, short _tz, bool _verbose) :
        JulianDay(_year, _month, _day, _hour, _minute, _second, _tz, _verbose)
{

	if(_verbose)
		std::cout << "Year: " << JDGetJDYear() << std::endl;


	return;

}
