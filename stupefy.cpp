#include "stupefy.h"
#include "spell.h"
#include "wizard.h"

#include <string>
using namespace std;

stupefy::stupefy(std::string aName, float aDamage) : spell(aName, aDamage) {
	
}

wizard stupefy::castSpell(wizard castOn, wizard caster){
	float h = castOn.getHealth();
	float d = castOn.getDefense();
	h=h-d*Damage;
	castOn.setHealth(c);
	return castOn;
}

stupefy::~stupefy(){

}