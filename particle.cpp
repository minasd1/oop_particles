#include <iostream>
#include "particle.h"

using namespace std;

//class particle

	particle::particle(){
			mass = 0;
			spin = 0;
			charge = 0;
	}
	particle::particle(const char* t, double m, float sp, short int c, unsigned short int i, string st){ 
			type = t;
			mass = m;
			spin = sp;
			charge = c;
			statistics = st;
			id = i;
			cout << "A " << type << " has been constructed" << endl;
			cout << "statistics: " << statistics << endl;
	}
	
	particle::~particle(){
		cout << "A " << type << " will be destroyed" << endl;
	}
	
	short int particle::get_charge(){
		return charge;
	}
	
	const char* particle::get_type(){
		return type;
	}
	
	unsigned short int particle::get_id(){
		return id;
	}
	
	void particle::react(vector<particle*>&, unsigned int, unsigned int, unsigned int){
		
	}
	
	double particle::get_mass(){
		return mass;
	}
	
	float particle::get_spin(){
		return spin;
	}
	

