#include "myfunctions.h"


unsigned short int interaction(vector<particle*>& newMyVector, const char* neighbor, unsigned int previous, unsigned int current, unsigned int next){
	short int flag_interaction = -1;
	unsigned int interact_particle = 0;
	if(strcmp(newMyVector.at(previous)->get_type(), neighbor) == 0){	//TO PROHGOUMENO SWMATIDIO EINAI 
		interact_particle = previous;							//KATALLHLO GIA ANTIDRASH
		flag_interaction = 1;
	}
	else if(strcmp(newMyVector.at(next)->get_type(), neighbor) == 0){
		interact_particle = next;								//TO EPOMENO EINAI KATALLHLO
		flag_interaction = 1;
	}
	
	if(flag_interaction == -1){			//KANENA APO TA DYO DEN EINAI KATALLHLO
		return 0;						
	}
	else{
		unsigned int current_new_position = 0; 	 
		delete newMyVector.at(interact_particle);		//DIAGRAFH TOU SWMATIDIOU POU THA GINEI ANTIDRASH
		newMyVector.erase(newMyVector.begin() + interact_particle);	
		
		if(interact_particle == previous && interact_particle == current - 1){
			current_new_position = current - 1;		//MIA THESH PISW STO VECTOR META THN PROHGOUMENH DIAGRAFH
		}
		else if(interact_particle == next && interact_particle == current + 1){
			current_new_position = current;		
		}
		else if(interact_particle == previous && interact_particle != current - 1){
			current_new_position = 0;
		}
		else if(interact_particle == next && interact_particle != current + 1){
			current_new_position = current - 1;
		}
		
		delete newMyVector.at(current_new_position);	//DIAGRAFH TOU TREXONTOS SWMTADIOU STH NEA TOY THESH
		newMyVector.erase(newMyVector.begin() + current_new_position);	//STH DOMH
		return 1;
	}
}

void decay_particle(vector<particle*>& newMyVector, unsigned int current){
	delete newMyVector.at(current);		//DIAGRAFH TREXONTOS SWMTATIDIOU
	newMyVector.erase(newMyVector.begin() + current);
}


