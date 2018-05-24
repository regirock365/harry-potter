#ifndef EXPELLIARMUS_H
#define EXPELLIARMUS_H

#include "spell.h"
#include "gui.h"


class expelliarmus : public spell
{
public:
	expelliarmus(std::string aName, float aDamage);
	void castSpell(wizard* castOn, wizard* caster, gui* terminal);
	~expelliarmus();
};

#endif