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

	enum class printFlags{
		JD_NULL,
		JD_DATE,
		JD_TIME,
		JD_JULIANDAY,
		JD_TZ,
		JD_ISLEAP,
		JD_DOY,
		JD_ALL
	};



	//Use the bitwise OR operator (|) to set a bit.
	int set_bit(int _number, int _bit) { return(_number |= 1 << (_bit)); }

	// Function to clear the _bitth bit of _number
	int clear_bit(int _number, int _bit) { return(_number & (~(1 << (_bit)))); }


	Tellus(int _year, short _month, float _day, short _hour, short _minute, double _second, short _tz, bool _verbose);

	void	te_print(int _flags);

	// inline functions for retreiving data members


};



#endif /* INC_TELLUS_H_ */
