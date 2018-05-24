#include "expelliarmus.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

expelliarmus::expelliarmus(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void expelliarmus::castSpell(wizard* castOn, wizard* caster, gui* terminal){
//creating a somewhat true random number generator based on time
srand(time(0));
	//creating a random number between 0-11, hence 12 possible choices
	int x = rand()%11;
	if(x<8){
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-Damage/d;
		castOn->setHealth(h);
		terminal->print(14, "Successful Attack", "right");
		terminal->clearLine(14);

	}
	else{
		terminal->print(14, "Attack Missed", "right");
	}
	// clear the line after we're done with it
	terminal->clearLine(14);


	if (castOn->getName() == "Harry") {
		terminal->print(25, "Harry's Health: " + std::to_string(castOn->getHealth()), "right");
	} else {
		terminal->print(26, "Draco's Health: " + std::to_string(castOn->getHealth()), "right");
	}
}

expelliarmus::~expelliarmus(){

}