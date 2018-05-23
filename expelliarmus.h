#ifndef EXPELLIARMUS_H
#define EXPELLIARMUS_H

#include "spell.h"


class expelliarmus : public spell
{
public:
	expelliarmus(std::string aName, float aDamage);
	void castSpell(wizard* castOn, wizard* caster);
	~expelliarmus();
};

#endif