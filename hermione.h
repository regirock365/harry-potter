#ifndef HERMIONE_H
#define HERMIONE_H

#include "wizard.h"
#include <string>

class hermione : public wizard{
	
	public:
		hermione(std::string aName, std::string aHouse);
		int castSpell(std::string spellName);
		~hermione();

};
#endif // "HERMIONE.H"