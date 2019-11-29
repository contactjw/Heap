/*
 * Planet.hpp
 *
 *  Created on: Nov 24, 2019
 *      Author: johnwest
 */

#ifndef PLANET_HPP_
#define PLANET_HPP_
#include <string>
using namespace std;

class Planet {
public:
	Planet();
	int value;
	string name;
	string url;
	virtual ~Planet();
};

#endif /* PLANET_HPP_ */
