#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <iostream>
#include <vector>
#include "particle.h"
#include "fermion.h"
#include "boson.h"
#include <stdlib.h>
#include <cstring>

using namespace std;

unsigned short int interaction(vector<particle*>&, const char*, unsigned int, unsigned int, unsigned int);
void decay_particle(vector<particle*>&, unsigned int);






#endif
