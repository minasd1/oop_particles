#include "fermion.h"


//class fermion
	
	fermion::fermion(const char* t, double m, float sp, short int c, unsigned short int i)
	:particle(t, m, sp, c, i, "Fermi-Dirac")
	{
	}
	fermion::~fermion(){
	}
	

	
//class proton

	proton::proton()
	:fermion("proton", 938272080, 0.5, 1, 0)
	{	
	}
	proton::~proton(){
	}
	
	void proton::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "antineutrino", previous, current, next)){	//RETURNS 1 IF INTERACTION CAN BE DONE
			newMyVector.push_back(new neutron());								
			newMyVector.push_back(new positron());
		}
		else if(interaction(newMyVector, "electron", previous, current, next)){
			newMyVector.push_back(new neutron());
			newMyVector.push_back(new neutrino());
		}
		else{									//IF AN INTERACTION IS NOT FEASIBLE, THE PARTICLE IS DACAYED
			decay_particle(newMyVector, current);
			newMyVector.push_back(new neutron());	
			newMyVector.push_back(new positron());
			newMyVector.push_back(new neutrino());
				
		}
		
	}
	

	
	
//class neutron

neutron::neutron()
	:fermion("neutron", 939565410, 0.5, 0, 1)
	{
	}
	neutron::~neutron(){
	}
	void neutron::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "neutrino", previous, current, next)){	//INTERACTION WITH NEUTRINO
			newMyVector.push_back(new proton());
			newMyVector.push_back(new electron());
		}
		else{
			decay_particle(newMyVector, current);		//DECAY
			newMyVector.push_back(new proton());
			newMyVector.push_back(new electron());
			newMyVector.push_back(new antineutrino());
				
		}
		
	}

	
//class electron

	electron::electron()
	:fermion("electron", 510998.946, 0.5, -1, 2)
	{
	}
	electron::~electron(){
	}
	
	void electron::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "proton", previous, current, next)){	//LIKEWISE
			newMyVector.push_back(new neutron());
			newMyVector.push_back(new neutrino());
		}	
		else if(interaction(newMyVector, "positron", previous, current, next)){
			newMyVector.push_back(new photon());
			newMyVector.push_back(new photon());
		}
		
	}
	
//class positron

	positron::positron()
	:fermion("positron", 510998.946, 0.5, 1, 3)
	{
	}
	positron::~positron(){
	}
	
	void positron::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "electron", previous, current, next)){
			newMyVector.push_back(new photon());
			newMyVector.push_back(new photon());
		}
		
	}
	
//class neutrino

	neutrino::neutrino()
	:fermion("neutrino", 0.320, 0.5, 0, 4)
	{
	}
	neutrino::~neutrino(){
	}
	
	void neutrino::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "neutron", previous, current, next)){
			newMyVector.push_back(new proton());
			newMyVector.push_back(new electron());
		}
		
	}
	
//class antineutrino

	antineutrino::antineutrino()
	:fermion("antineutrino", 0.320, 0.5, 0, 5)
	{
	}
	antineutrino::~antineutrino(){	
	}
	
	void antineutrino::react(vector<particle*>& newMyVector, unsigned int previous, unsigned int current, unsigned int next){
		if(interaction(newMyVector, "proton", previous, current, next)){
			newMyVector.push_back(new neutron());
			newMyVector.push_back(new positron());
		}
		
	}
	
