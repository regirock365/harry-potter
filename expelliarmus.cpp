#include "expelliarmus.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

void expelliarmus::castSpell(wizard obj1){
	float c = obj1.getHealth();
	c=c-10;
	obj1.setHealth(c);
}

expelliarmus::~expelliarmus(){

}