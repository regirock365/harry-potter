#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include "gui.h"
#include <iostream>
#include <unistd.h>
#include <ctype.h>


/*
validMove tests to see if the user has inputted the character inputs. The values we are taking
are integers between 1 and 4 inclusively. If any other values are inputted we are skipping their attack,
similar to making a mistake in a real duel. 
We are also using sleep to delay inputs to simulate a more natural flowing game.
*/
bool validMove(int move){
	if(move <1 || move > 5 || std::cin.fail() ){ //logical statement checking for invalid inputs
		std::cin.clear(); //forcing non-int inputs to not infintely loop in a while loop
   		std::cin.ignore(1000,'\n');
   		sleep(1);
		std::cout << "There is no room for mistakes in a duel and";
		std::cout << " your move has been skipped" << std::endl;
		std::cout << std::endl;
		sleep(1);
		return false;
	}
	else{
		sleep(1);
		return true;
	}
}

/*
playerAttack is where we simulate the damage and healing attributes of our game. We test to see which move
was inputted and correspond that to its respect spell. i.e. move 1 is mapped to spell1 etc.
We also test for the player; if player == 1 we use a spell on player 2 and vice verse.
*/
bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3){
	if(player == 1 & move>0 && move <4){
		if(move == 1){
			spell1.castSpell(player2, player1);
		}
		else if(move == 2){
			spell2.castSpell(player2, player1);			
		}
		else if(move == 3){
			spell3.castSpell(player2, player1); 
		}
		return true;
	}
	else if(player == 2 & move>0 && move<4){
				if(move == 1){
			spell1.castSpell(player1, player2);
		}
		else if(move == 2){
			spell2.castSpell(player1, player2);
		}
		else if(move == 3){
			spell3.castSpell(player1, player2);
		}
		return true;
	}
	else{
		return false; //entered exit condition 5 (or last number)
		//ends game
	}
}

/*
endGame checks for an exit input of 4, or for either wizard to reach health 0 or below.
this ends this game with a message output. of harry/draco resigns and harry/draco was no match 
for draco/harry
*/
bool endGame(wizard obj, int move, int player){
	if(player == 1 && obj.getHealth()<=0){
		sleep(2);
		std::cout << obj.getName() <<  " has fainted!" << std::endl;
		sleep(1);
		std::cout << "Draco was no match for Harry!" << std::endl;
		return false;
	}
	else if(player == 2 && obj.getHealth()<=0){
		sleep(2);
		std::cout << obj.getName() << " has fainted!" << std::endl;
		sleep(1);
		std::cout << "Harry was no match for Draco!" << std::endl;
		return false;
	}
	else if(move == 4 && player == 1){
		sleep(2);
		std::cout << "Harry has for resigned!" << std::endl;
		sleep(1);
		std::cout << "Harry was no match for Draco!" << std::endl;
		return false;
	}
	else if(move == 4 && player == 2){
				sleep(3);
		std::cout << "Draco has for resigned!" << std::endl;
		sleep(1);
		std::cout << "Draco was no match for Harry!" << std::endl;
		return false;
	}
	else{
		return true;
	}
}

/*
playGame uses the logic from the above 3 functions to simulate a working game, in combination with
initialising spell and wizard objets to be used in the duel.
*/

void playGame(){

	int move = 0;
	//initialising wizards and their spells
	wizard player1 = wizard("Harry");
	wizard player2 = wizard("Draco");
	expelliarmus spell1 = expelliarmus("expelliarmus",25);
	protego spell2 = protego("protego",0.1);
	stupefy spell3 = stupefy("stupefy",75);

	std::cout << player1.getName() << " Vs. " << player2.getName() << std::endl;
	std::cout << std::endl;

	sleep(1);
	bool gameRunning = 1;
	bool isValid = 1;
	int player = 2; //2 makes it start on player 1 at the beginning of the loop
	while(gameRunning == true){
	 	if(player == 2){
	 		player = 1;
	 	}
	 	else{
	 		player = 2;
	 	}
	 	sleep(1);
	 	if(player == 1){
	 	 	std::cout << player1.getName() << " it is your turn to attack" << std::endl;	
	 	}
	 	else{
	 		std::cout << player2.getName() << " it is your turn to attack" << std::endl;
	 	}

	 	//character input and then testing whether the input was valid
		std::cin >> move;
		//tests for valid input, and uses the inputted spell on the oponent, or itself. Skips if invalid
		isValid = validMove(move);
		if(isValid == 1){
			if(player == 1){

				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3);
				if(player2.getHealth()<0){
					
					std::cout << player2.getName() << "'s remaining health: 0" << std::endl;
					std::cout << std::endl;				
				}				
				else{
					std::cout << player2.getName() << "'s remaining health: " <<  player2.getHealth() << std::endl;
					std::cout << std::endl;
				}
			}
			else{
				
				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3);
				if(player2.getHealth()<0){
					std::cout << player1.getName() << "'s remaining health: 0"  << std::endl;
				}	
				else{
					std::cout << player1.getName() <<"'s remaining health: " <<  player1.getHealth() << std::endl;
					std::cout << std::endl;
				}
			}
		}
		else{
			isValid = false; //skips the players turn if they entered invalid input
		}
	//checking to see whether the game has been terminated or finished. Then breaks the while loop to finish the game	
	gameRunning = endGame(player2, move, player);
	if(gameRunning == false){
		break;
	}
	gameRunning = endGame(player1, move, player);
	if(gameRunning == false){
		break;
	}

	}
}

/*
initGame creates a box user-interface using the gui class to dislpay a welcome screen and display the rules of the game
*/
void initGame(){
	gui* terminal = new gui(20,80);

	terminal -> print(1, "Welcome to the Harry Potter duelling club", "middle");
	terminal -> print(2, "Rules:", "left");
	terminal -> print(4, "Press 1 to use Expelliarmus", "left");
	terminal -> print(5, "Expelliarmus does 25 damage and has a 3/4 chance of hitting","left");
	terminal -> print(7, "Press 2 to use Protego","left");
	terminal -> print(8, "Protego increases defense by 0.1 and health by 10 ", "left");
	terminal -> print(9, "A higher defense makes the opponents attack less powerful", "middle");
	terminal -> print(11, "Press 3 to use Stupefy","left");
	terminal -> print(12, "Stupefy deals 75 damage and has a 1/5 chance of hitting","left");
	terminal -> print(14, "Press 4 to resign","left");
	terminal -> print(15, "Press 'Any Key' to be taken to the terminal to play the game","middle");

	delete terminal;
}

