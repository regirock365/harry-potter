#ifndef WIZARD_H
#define WIZARD_H

#include <string>

class wizard{
	
	public:
		wizard(std::string aName, std::string aHouse);
		void getName();
		void getHouse();
		virtual int castSpell(std::string spellName);
		int setAttributes(std::string house);


	protected:
		int power;
		int speed;
		int intelligence;
		int defense;
		std::string name;
		std::string house;
		std::string spellName;
};
#endif // "WIZARD.H"