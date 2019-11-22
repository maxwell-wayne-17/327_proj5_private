//
/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */
#include <iostream>
#include <memory>
#include <vector>
#include <time.h>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers.  Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	std::vector<std::unique_ptr<Smalltalk>> talks;

	for (int i = 1; i <= numBrit; i++){
		std::unique_ptr<Smalltalk> pBrit(new Smalltalk_Brit(i));
		talks.push_back(std::move(pBrit));
	}

	for (int i = 1; i <= numAmerican; i++){
		std::unique_ptr<Smalltalk> pAmerican(new Smalltalk_American(i));
		talks.push_back(std::move(pAmerican));
	}

	for (int i = 1; i <= numbAmericanDonutEnthusiest; i++){
		std::unique_ptr<Smalltalk> pUSDE(new ST_American_DonutEnthusiest);
		talks.push_back(std::move(pUSDE));
	}

	for (unsigned int i = 0; numWatches > 0 && i < talks.size(); i++){
		std::unique_ptr<Watch> pWatch(new Watch());
		if(talks[i]->giveWatch(pWatch)){
			numWatches--;
		}

	}

	return talks;
}
