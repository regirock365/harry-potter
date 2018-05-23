#include "spell.h"
#include <string>
#include <iostream>
//#include "wizard.h"
using namespace std;

//implementation of constructor

spell::spell(string aName, float aDamage){
	spellName= aName;
	description= "";
	Damage= aDamage;
	// Speed;
	// Accuracy;
	// Power;
}

void spell::castSpell(wizard* castOn, wizard* caster){
	
}

//setters
void spell::set_name(std::string aName){
	spellName=aName;
}
void spell::set_description(std::string aDescription){
	description= aDescription;
}
void spell::set_power(float aPower){
	Power=aPower;
}
void spell::set_speed(float aSpeed){
	Speed=aSpeed;
}
void spell::set_accuracy(float aAccuracy){
	Accuracy=aAccuracy;
}

//getters
float spell::get_power(){
	return Power;
}
float spell::get_speed(){
	return Speed;
}
float spell::get_accuracy(){
	return Accuracy;
}
std::string spell::get_name(){
	return spellName;
}
std::string spell::get_description(){
	return description;
}

//deconstructor
spell::~spell(){}