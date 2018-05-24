#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include <string>

class wizard{
	
	public:
		wizard(std::string aName); //constructur that takes in name of wizard
		std::string getName();  //retrieves the name of a wizard
		float getHealth(); //retrieves the health of a wizard
		void setHealth(float health); //change the health of a wizard
		float getDefense(); //retrieves the defense of a wizard
		void setDefense(float defense); //change the defense of a wizard
		float health;


	protected:
		float defense;
		std::string name;
};
#endif // "WIZARD.H"