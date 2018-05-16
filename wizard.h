#ifndef WIZARD_H
#define WIZARD_H

#include <string>

class wizard{
	
	public:
		wizard(std::string aName, std::string aHouse);
		void getName();
		void getHouse();
		void getHealth();
		//virtual float setHealth(flot health);
		//virtual int castSpell(std::string aName);
		//virtual bool isDisabled();
		//virtual void funFacts();
		//virtual int setAttributes(std::string house);


	protected:
		//int power;
		//int speed;
		//int intelligence;
		//int defense;
		float health;
		std::string name;
		std::string house;
		std::string spellName;
//		bool disabled;
};
#endif // "WIZARD.H"

