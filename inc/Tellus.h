/*
 * Tellus.h
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

#ifndef INC_TELLUS_H_
#define INC_TELLUS_H_

#include "JulianDay.h"



class Tellus : public JulianDay{

public:
	Tellus(int _year, short _month, short _day, short _hour, short _minute, double _second, short _tz, bool _verbose);
};



#endif /* INC_TELLUS_H_ */
