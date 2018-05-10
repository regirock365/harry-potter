#ifndef DRACO_H
#define DRACO_H

#include "wizard.h"
#include <string>

class draco : public wizard{
	
	public:
		draco(std::string aName, std::string aHouse);
		int castSpell(std::string spellName);
		~draco();

};
#endif // "DRACO.H"