#ifndef EXPELLIARMUS_H
#define EXPELLIARMUS_H

#include "spell.h"


class expelliarmus : public spell
{
public:
	expelliarmus(std::string aName, float aDamage);
	wizard castSpell(wizard castOn, wizard caster);
	~expelliarmus();
};

#endif