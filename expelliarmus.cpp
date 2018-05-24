#include "expelliarmus.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

expelliarmus::expelliarmus(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void expelliarmus::castSpell(wizard* castOn, wizard* caster){
	//creating a somewhat true random number generator based on time
	srand(time(0));
	int x = rand()%11; //creating a random number between 0-11, hence 12 possible choices
	std::cout << "\e[1mEXPELLIARMUS\e[0m" << std::endl;
	if(x<9){ //conditional statement forcing 75% of our attacks to miss
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-Damage/d; //health is replaced by their health minus a proportion of their damage and defense
		castOn->setHealth(h);
		std::cout << "Successful Attack." << std::endl;

	}
	else{
		std::cout << "Attack missed" << std::endl;
	}
}

expelliarmus::~expelliarmus(){

}