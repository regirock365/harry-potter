#ifndef PROTEGO_H
#define PROTEGO_H

#include "spell.h"


class protego : public spell
{
public:
	protego(std::string aName, float aDamage);
	wizard castSpell(wizard castOn, wizard caster);
	~protego();
};

#endif