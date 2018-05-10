#ifndef HARRY_H
#define HARRY_H

#include "wizard.h"
#include <string>

class harry : public wizard{
	
	public:
		harry(std::string aName, std::string aHouse);
		int castSpell(std::string spellName);
		~harry();

};
#endif // "HARRY.H"