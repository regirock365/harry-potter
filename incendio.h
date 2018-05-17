#ifndef INCENDIO_H
#define INCENDIO_H

#include "spell.h"


class incendio : public spell
{
public:
	incendio(std::string aName, float aDamage);
	wizard castSpell(wizard obj1);
	~incendio();
};

#endif