
#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include <string>

class wizard{
	
	public:
		wizard(std::string aName, std::string aHouse);
		void getName();
		void getHouse();
		float getHealth();
		void setHealth(float health);
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
		
		std::string name;
		std::string house;
		std::string spellName;
//		bool disabled;
};
#endif // "WIZARD.H"