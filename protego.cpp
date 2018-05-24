#include "protego.h"
#include "spell.h"
#include "wizard.h"
#include "gui.h"

#include <string>
using namespace std;

protego::protego(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

void protego::castSpell(wizard* castOn, wizard* caster, gui* terminal){
	float c = caster->getDefense();
	float h = caster->getHealth();
	c=c+0.2;
	if (!(h >= 100)) {
		if (h >= 91) {
			h=100;
		} else {
			h=h+10;
		}
		caster->setHealth(h);
		terminal->print(20, caster->getName() + "'s health increased to: " + std::to_string(caster->getHealth()), "left");
	} else {
		terminal->print(20, caster->getName() + "'s health couldn't be increased", "left");
	}

	//check if defense has gotten too strong
	if(c<=2){
		caster->setDefense(c);
		terminal->print(20, caster->getName() + "'s defense has risen to: " + std::to_string(caster->getDefense()), "left");
	}

	if (caster->getName() == "Harry") {
		terminal->print(25, "Harry's Health: " + std::to_string(caster->getHealth()), "right");
	} else {
		terminal->print(26, "Draco's Health: " + std::to_string(caster->getHealth()), "right");
	}
	// terminal->print(25, "Health: " + std::to_string(caster->getHealth()), "right");
	terminal->clearLine(20);

	//return caster;
}

protego::~protego(){

}