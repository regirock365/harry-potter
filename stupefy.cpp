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

void stupefy::castSpell(wizard* castOn, wizard* caster){
	srand(time(0));
	int x = rand()%11;
	if(x<3){
		float h = castOn->getHealth();
		float d = castOn -> getDefense();
		h=h-d*Damage;
		castOn->setHealth(h);
		std::cout << "Successful Attack." << std::endl;

	}
	else{
		std::cout << "Attack missed" << std::endl;
	}

	//return castOn;
}

stupefy::~stupefy(){

}

