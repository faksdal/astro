/*
 * ParseOptarg.cpp
 *
 *	Created on: 13th of November 2022
 *	Author: jole
 */

#include "ParseOptarg.h"



void ParseOptarg(char **_optarg)
{
	//std::cout << "inside ParseOptarg\n";
	while(**_optarg != '.' && **_optarg != '-' && **_optarg != '/' && **_optarg != ':'){
		(*_optarg)++;
	}
	(*_optarg)++;
	return;
}
