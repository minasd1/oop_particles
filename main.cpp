#include <iostream>
#include "fermion.h"
#include "boson.h"
#include "particle.h"
#include "myfunctions.h"
#include <stdlib.h>
#include <time.h>
#include <vector>


using namespace std;


int main(int argc, char** argv) {
	
	srand(time(NULL));
	unsigned int M = atoi(argv[1]);								
	unsigned int N = atoi(argv[2]);
	unsigned short int type;
	float number_of_particles[7];
	int initial_total_charge = 0;
	int percentage_change[7];
	double initial_total_mass = 0;
	float initial_total_spin = 0;
	double mass_difference;
	float spin_difference;
	
	vector<particle*> myVector;
	for(unsigned int k = 0; k < 7; k++){
		number_of_particles[k] = 0;
	}
	
	for(unsigned short int i = 0; i < M; i++){
		type = rand() % 7;
		switch(type){
			case 0:		//PROTON
				myVector.push_back(new proton());
				number_of_particles[0]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
			case 1:		//NEUTRON
				myVector.push_back(new neutron());
				number_of_particles[1]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
			case 2:		//ELECTRON
				myVector.push_back(new electron());
				number_of_particles[2]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;	
			case 3:		//POSITRON
				myVector.push_back(new positron());
				number_of_particles[3]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
			case 4:		//NEUTRINO
				myVector.push_back(new neutrino());
				number_of_particles[4]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
			case 5:		//ANTINEUTRINO
				myVector.push_back(new antineutrino());
				number_of_particles[5]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
			case 6:		//PHOTON
				myVector.push_back(new photon());
				number_of_particles[6]++;
				initial_total_charge += myVector.at(i)->get_charge();
				initial_total_mass += myVector.at(i)->get_mass();
				initial_total_spin += myVector.at(i)->get_spin();
				break;
		}
	}
	
	unsigned int size;
	unsigned int random_particle = 0;
	unsigned int previous = 0;
	unsigned int next = 0;
	
	
	for(unsigned int count = 0; count < N; count++){
		size = myVector.size();
		random_particle = rand() % size;		//THE PARTICLE THAT WILL INTERACT
		
		if(random_particle == 0){				//FIRST IN SEQUENCE
			previous = size - 1;
			next = 1;
		}
		else if(random_particle == size - 1){	//LAST IN SEQUENCE
			next = 0;
			previous = size - 2;
		}
		else{
			next = random_particle + 1;			//IN EVERY OTHER CASE
			previous = random_particle - 1;
		}
		//REACTION
		myVector.at(random_particle)->react(myVector, previous, random_particle, next);
	}
	
	unsigned int new_size = myVector.size();
	int new_total_charge = 0;
	float new_number_of_particles[7];
	unsigned int fermion_count = 0;
	unsigned int boson_count = 0;
	unsigned int thesi[7];
	double new_total_mass = 0;
	float new_total_spin = 0;
	
	for(unsigned int count2 = 0; count2 < 7; count2++){
		new_number_of_particles[count2] = 0;
	}
	
	for(unsigned int k = 0; k < new_size; k++){		//CONCLUSIONS AFTER INTERACTIONS
		unsigned short int id = myVector.at(k)->get_id();
		switch(id){
			case 0:		//PROTON
				new_number_of_particles[0]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[0] = k;
				break;
			case 1:		//NEUTRON
				new_number_of_particles[1]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[1] = k;
				break;
			case 2:		//ELECTRON
				new_number_of_particles[2]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[2] = k;
				break;	
			case 3:		//POSITRON
				new_number_of_particles[3]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[3] = k;
				break;
			case 4:		//NEUTRINO
				new_number_of_particles[4]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[4] = k;
				break;
			case 5:		//ANTINEUTRINO
				new_number_of_particles[5]++;
				new_total_charge += myVector.at(k)->get_charge();
				fermion_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[5] = k;
				break;
			case 6:		//PHOTON
				new_number_of_particles[6]++;
				new_total_charge += myVector.at(k)->get_charge();
				boson_count++;
				new_total_spin += myVector.at(k)->get_spin();
				new_total_mass += myVector.at(k)->get_mass();
				thesi[6] = k;
				break;
		}
	}
	
	for(unsigned int count3 = 0; count3 < 7; count3++){
		percentage_change[count3] = (new_number_of_particles[count3] - number_of_particles[count3])/number_of_particles[count3] * 100;
	}
	
	for(unsigned int count4 = 0; count4 < 7; count4++){
		cout << "Initial " << myVector.at(thesi[count4])->get_type() << " number is: " 
		<< number_of_particles[count4] << endl;
		cout << "New " << myVector.at(thesi[count4])->get_type() << " number is: " 
		<< new_number_of_particles[count4] << endl;
		cout << "Percentage change = " << percentage_change[count4] << "%" << endl << endl;
	}

	if(fermion_count > boson_count){
		cout << "Living in a material world!" << endl << endl;
	}
	else if(fermion_count < boson_count){
		cout << "Radiation prevails!" << endl << endl;
	}
	else{
		cout << "Equilibrium?" << endl << endl;
	}
	
	cout << "Initial total charge is " << initial_total_charge << endl;
	cout << "New total charge is " << new_total_charge << endl;
	
	if(initial_total_charge == new_total_charge){
		cout << "Conservation verified!" << endl << endl;
	}
	
	mass_difference = new_total_mass - initial_total_mass;
	spin_difference = new_total_spin - initial_total_spin;
	
	cout << "Mass difference is " << mass_difference << "eV/c^2" << endl;
	cout << "Spin difference is " << spin_difference << endl;
	
	if(mass_difference != 0 || spin_difference != 0){
		cout << "How it comes!" << endl;
	}
	
	for(unsigned int a = 0; a < new_size; a++){	//FREE MEMORY
		delete myVector.at(a);
	}		
	myVector.clear();
	
	return 0;
}
