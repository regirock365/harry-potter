#include "expelliarmus.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

expelliarmus::expelliarmus(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void expelliarmus::castSpell(wizard* castOn, wizard* caster){
srand(time(0));
	int x = rand()%11;
	if(x<8){
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-d*Damage;
		castOn->setHealth(h);
		std::cout << "Successful Attack." << std::endl;

	}
	else{
		std::cout << "Attack missed" << std::endl;
	}
}

expelliarmus::~expelliarmus(){

}