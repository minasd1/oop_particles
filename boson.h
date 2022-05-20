#ifndef BOSON_H
#define BOSON_H

#include <iostream>
#include "particle.h"
#include <stdlib.h>
#include <vector>
#include "myfunctions.h"

using namespace std;


class boson: public particle{
	public:
		boson(const char*, double, float, short int, unsigned short int);
		~boson();
};


class photon: public boson{
	public:
		photon();
		~photon();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
		
};


#endif
