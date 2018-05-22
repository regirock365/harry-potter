
#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include <string>

class wizard{
	
	public:
		wizard(std::string aName, std::string aHouse);
		std::string getName();
		std::string getHouse();
		float getHealth();
		void setHealth(float health);
		float getDefense();
		void setDefense(float defense);
		//virtual int castSpell(std::string aName);
		//virtual bool isDisabled();
		//virtual void funFacts();
		//virtual int setAttributes(std::string house);
		float health;


	protected:
		//int power;
		//int speed;
		//int intelligence;
		//int defense;
		float defense;
		std::string name;
		std::string house;
		std::string spellName;
//		bool disabled;
};
#endif // "WIZARD.H"