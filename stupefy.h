#ifndef STUPEFY_H
#define STUPEFY_H

#include "spell.h"
#include "gui.h"


class stupefy : public spell
{
public:
	stupefy(std::string aName, float aDamage);
	void castSpell(wizard* castOn, wizard* caster, gui* terminal);
	~stupefy();
};

#endif