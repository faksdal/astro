/*
 * astro.h
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

#ifndef INC_DATESUPPLIED_H_
#define INC_DATESUPPLIED_H_

#include <time.h>
#include <iomanip>
#include <iostream>
#include <sys/time.h>

using namespace std;

void	DateSupplied(int &_year, int &_month, int &_day, bool _verbose);
void	PrintDate(int _year, int _month, double _day);


#endif /* INC_DATESUPPLIED_H_ */
