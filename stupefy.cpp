#include "stupefy.h"
#include "spell.h"
#include "wizard.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <string>
using namespace std;

stupefy::stupefy(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void stupefy::castSpell(wizard* castOn, wizard* caster, gui* terminal){
	srand(time(0));
	int x = rand()%10;
	if(x<2){
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-Damage/d;
		castOn->setHealth(h);
		terminal->print(14, "Successful Attack", "right");
		terminal->clearLine(14);
		// std::cout << "Successful Attack." << std::endl;

	}
	else{
		terminal->print(14, "Attack Missed", "right");
		// std::cout << "Attack missed" << std::endl;
	}
	terminal->clearLine(14);

	//return castOn;
}

stupefy::~stupefy(){

}

