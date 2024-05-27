/******************************************************************************
 * main.cpp
 *
 *  Created on: 2 May 2024
 *      Author: jole
 *
 *      Program for testing my astro functions
 *
 * 
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

#include "PrintUsage.h"
#include "ParseOptarg.h"
#include "DateSupplied.h"
#include "TimeSupplied.h"

#include "JulianDay.h"
#include "Tellus.h"



int main(int argc, char *argv[])
{

	bool	verbose			= false;
	bool	timeSupplied	= false;
	bool	dateSupplied	= false;
	bool	printDoy		= false;
	bool	printJD			= false;
	bool	printAll		= false;

	int		year, month, day, hour, minute, timezone, dst;
	double	second = 0.00000000000;
	//double	lat, lon;



	timezone	= 0;
	dst			= 0;



	//
	//	getopt variables
	//
	int		c, optionIndex;
	//float	input = 0L, output;

	//
	//	TODO Add proper switches as the projects goes along
	//
	char	*shortOptions = (char*)"d:t:vh";
	struct option	longOptions[] = {
					{"date",		required_argument,	NULL,	'd'},
					{"time",		required_argument,	NULL,	't'},
					{"tz",			required_argument,	NULL,	3},
					{"lat",			required_argument,	NULL,	4},
					{"lon",			required_argument,	NULL,	5},
					{"dst",			required_argument,	NULL,	6},
					{"printdoy",	no_argument,		NULL,	7},
					{"printjd",		no_argument,		NULL,	8},
					{"printall",	no_argument,		NULL,	9},
					{"verbose",		no_argument,		NULL,	'v'},
					{"help",		no_argument,		NULL,	'h'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	/*
	timezone	= 1;
	lat			= 78.92927;	//	Ny-Ålesund
	lon			= 11.86778;	//	Ny-Ålesund
	//lat			= 64.6806667;	//	Oppi Leite
	//lon			= 11.2914444;	//	Oppi Leite
	dst			= 0;
	*/



	//	getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 'd':	{
								year = atoi(optarg);
								//cout << "optarg: " << optarg << endl;
								//cout << "Year: " << year << endl;
								ParseOptarg(&optarg);
								month = atoi(optarg);
								//cout << "Month: " << month << endl;
								ParseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg
								dateSupplied = true;

								break;
							}
				case 't':	{
								hour = atoi(optarg);
								ParseOptarg(&optarg);
								minute = atoi(optarg);
								ParseOptarg(&optarg);
								second = atof(optarg);
								// end of parsing optarg
								timeSupplied = true;


								break;
							}
				case 3:		{
								timezone = atoi(optarg);

								break;
							}
				case 4:		{
								//lat = atof(optarg);

								break;
				}
				case 5:		{
								//lon = atof(optarg);

								break;
							}
				case 6:		{
								//dst = atoi(optarg);

								break;
							}
				case 7:		{
								printDoy = true;
								cout << "printDoy" << endl;
								break;
							}
				case 8:		{
								printJD = true;
								break;
							}
				case 9:		{
								printAll = true;
								break;
							}
				case 'v':	{
								verbose = true;
								break;
							}
				case 'h':	{
								PrintUsage();
								exit(1);
							}
				default:	{
								cout << "Switch default\n" << endl;
								break;
							}
			} //end of getopt() switch statement
		} // end of while-loop

	dateSupplied ? PrintDate(year, month, day) : DateSupplied(year, month, day, verbose);
	timeSupplied ? PrintTime(hour, minute, second) : TimeSupplied(hour, minute, second, verbose);

	Tellus *earth = new Tellus(year, month, day, hour, minute, second, timezone, verbose);

	if(printAll){
		cout << "printall is true" << endl;
		earth->te_print( (int)earth->printFlags::JD_ALL);
	}
	if(printDoy){
		cout << "printdoy is true" << endl;
		earth->te_print( (int)earth->printFlags::JD_DOY);
	}


	//earth->te_print( (int)earth->printFlags::JD_ALL );




	return 0;

} // int main(int argc, char *argv[])
;
