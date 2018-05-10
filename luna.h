#ifndef LUNA_H
#define LUNA_H

#include "wizard.h"
#include <string>

class luna : public wizard{
	
	public:
		luna(std::string aName, std::string aHouse);
		int castSpell(std::string spellName);
		~luna();

};
#endif // "LUNA.H"