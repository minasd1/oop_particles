#include "boson.h"

//class boson
	
	boson::boson(const char* t, double m, float s, short int c, unsigned short int i)
	:particle(t, m, s, c, i, "Bose-Einstein")
	{
	}
	boson::~boson(){
	}	


	
//class photon

	photon::photon()
	:boson("photon", 0, 1, 0, 6)
	{}
	photon::~photon(){
		
	}
	
	void photon::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "photon", previous, current, next)){ 	//INTERACTION WITH PHOTON
			newMyVector.push_back(new electron());
			newMyVector.push_back(new positron());
		}
		
	}
