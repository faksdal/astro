/*
 * TimeSupplied.h
 *
 *  Created on: 20 May 2024
 *      Author: jole
 */

#ifndef INC_TIMESUPPLIED_H_
#define INC_TIMESUPPLIED_H_

#include <time.h>
#include <iomanip>
#include <iostream>
#include <sys/time.h>

using namespace std;

void	TimeSupplied(int &_hour, int &_minute, double &_second, bool _verbose);
void	PrintTime(int _hour, int _minute, double _second);

#endif /* INC_TIMESUPPLIED_H_ */
