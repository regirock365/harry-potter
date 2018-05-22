#include "expelliarmus.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

expelliarmus::expelliarmus(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

wizard expelliarmus::castSpell(wizard castOn, wizard caster){
	float h = castOn.getHealth();
	float d = castOn.getDefense();
	h=h-d*Damage;
	castOn.setHealth(h);
	return castOn;
}

expelliarmus::~expelliarmus(){

}