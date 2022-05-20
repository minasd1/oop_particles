#ifndef FERMION_H
#define FERMION_H

#include <iostream>
#include "particle.h"
#include "myfunctions.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class fermion: public particle{
	public:
		fermion(const char*, double, float, short int, unsigned short int);
		~fermion();
};


class proton: public fermion{
	public:
		proton();
		~proton();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
		void print_info();
};

class neutron: public fermion{
	public:
		neutron();
		~neutron();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
};

class electron: public fermion{
	public:
		electron();
		~electron();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
	
};

class positron: public fermion{
	public:
		positron();
		~positron();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);

};

class neutrino: public fermion{
	public:
		neutrino();
		~neutrino();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
		
};

class antineutrino: public fermion{
	public:
		antineutrino();
		~antineutrino();
		void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
		
};


#endif
