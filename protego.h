#ifndef PROTEGO_H
#define PROTEGO_H

#include "spell.h"
#include "gui.h"


class protego : public spell
{
public:
	protego(std::string aName, float aDamage);
	void castSpell(wizard* castOn, wizard* caster, gui* terminal);
	~protego();
};

#endif