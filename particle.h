#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>


using namespace std;

class particle{
	public:
		particle();
		particle(const char*, double, float, short int, unsigned short int, string); 
		~particle();
		
		short int get_charge();
		const char* get_type();
		unsigned short int get_id();
		double get_mass();
		float get_spin();
		virtual void react(vector<particle*>&, unsigned int, unsigned int, unsigned int);
	
	private:
		const char* type;
		double mass;
		float spin;
		short int charge;
		string statistics; 
		unsigned short int id;
};



#endif
