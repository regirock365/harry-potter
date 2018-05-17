#include "protego.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

protego::protego(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

wizard protego::castSpell(wizard obj1){
	float c = obj1.getHealth();
	c=c-Damage;
	obj1.setHealth(c);
	return obj1;
}

protego::~protego(){

}