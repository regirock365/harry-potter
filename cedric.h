#ifndef CEDRIC_H
#define CEDRIC_H

#include "wizard.h"
#include <string>

class cedric : public wizard{
	
	public:
		cedric(std::string aName, std::string aHouse);
		int castSpell(std::string spellName);
		~cedric();

};
#endif // "cedric.H"