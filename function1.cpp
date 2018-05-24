#include "wizard.h"
#include "spell.h"
#include "expelliarmus.h"
#include "protego.h"
#include "stupefy.h"
#include <iostream>
#include <unistd.h>
#include "gui.h"
#include <ctype.h>



bool validMove(int move, gui* terminal){
	if(move <1 || move > 5 /*|| std::cin.fail()*/ ){
		    // std::cin.clear();
   			// std::cin.ignore(1000,'\n');
   			// sleep(1);
   		terminal->print(20, "There is no room for mistakes in a duel and...", "left");
   		terminal->print(21, "your move has been skipped", "middle");
   		terminal->clearLine(20);
   		terminal->clearLine(21);
		// std::cout << "There is no room for mistakes in a duel and";
		// std::cout << " your move has been skipped" << std::endl;
		// sleep(1);
		return false;
	}
	else if(move == 4){
		// sleep(1);
		// std::cout << "lmao really kid?? " << std::endl;
		return true;
	}

	else{
		// sleep(1);
		//std::cout << "Successful attack" << std::endl;
		return true;
	}
}

bool playerAttack(int move, int player, wizard* player1, wizard* player2, expelliarmus spell1, protego spell2, stupefy spell3, gui* terminal){
	if(player == 1 & move>0 && move <4){
		if(move == 1){
			terminal->print(13, "EXPELLIARMUS", "left");
			terminal->clearLine(13);
			spell1.castSpell(player2, player1, terminal);
		}
		else if(move == 2){
			terminal->print(13, "PROTEGO", "left");
			terminal->clearLine(13);
			spell2.castSpell(player2, player1, terminal);
		}
		else if(move == 3){
			terminal->print(13, "STUPEFY", "left");
			terminal->clearLine(13);
			spell3.castSpell(player2, player1, terminal); 
		}
		return true;
	}
	else if(player == 2 & move>0 && move<4){
		if(move == 1){
			terminal->print(13, "EXPELLIARMUS", "left");
			terminal->clearLine(13);
			spell1.castSpell(player1, player2, terminal);
		}
		else if(move == 2){
			terminal->print(13, "PROTEGO", "left");
			terminal->clearLine(13);
			spell2.castSpell(player1, player2, terminal);
		}
		else if(move == 3){
			terminal->print(13, "STUPEFY", "left");
			terminal->clearLine(13);
			spell3.castSpell(player1, player2, terminal);
		}
		return true;
	}
	else{
		return false; //entered exit condition 5 (or last number)
		//ends game
	}
}

bool endGame(wizard obj, int move, int player, gui* terminal){
	if(player == 1 && obj.getHealth()<=0){
		// sleep(3);
		terminal->print(17, "Draco has fainted!", "left");
		terminal->print(18, "Harry is victorious!", "left");
		terminal->get();
		// std::cout << "Player " << 2 << " has fainted!" << std::endl;
		return false;
	}
	else if(player == 2 && obj.getHealth()<=0){
		// sleep(3);
		terminal->print(17, "Harry has fainted!", "right");
		terminal->print(18, "Draco is victorious!", "left");
		terminal->get();
		// std::cout << "Player " << 1 << " has fainted!" << std::endl;
		return false;
	}
	else if(move == 4 && player == 1){
		// sleep(3);
		terminal->print(17, "Harry has resigned!", "right");
		terminal->print(18, "Draco is victorious!", "left");
		terminal->get();
		// std::cout << "Player " << player << " has for resigned!" << std::endl;
		return false;
	} else if(move == 4 && player == 2){
		// sleep(3);
		terminal->print(17, "Draco has resigned!", "left");
		terminal->print(18, "Harry is victorious!", "left");
		terminal->get();
		// std::cout << "Player " << player << " has for resigned!" << std::endl;
		return false;
	}
	else{
		return true;
	}
}

void playGame(gui* terminal){

	int move = 0;
	wizard player1 = wizard("Harry","Gryff");
	wizard player2 = wizard("Draco","sl");
	expelliarmus spell1 = expelliarmus("expelliarmus",25);
	protego spell2 = protego("protego",0.1);
	stupefy spell3 = stupefy("stupefy",75);

	terminal->print(10,  "Harry Vs. Draco", "middle");
	// std::cout << player1.getName() << " Vs. " << player2.getName() << std::endl;
	// std::cout << std::endl;

	// sleep(1);
	bool gameRunning = 1;
	bool isValid = 1;
	int player = 2; //2 makes it start on player 1
	while(gameRunning == true){
	 	if(player == 2){
	 		player = 1;
	 	}
	 	else{
	 		player = 2;
	 	}
	 	// sleep(1);
	 	if(player == 1){
	 	 	terminal->print(11, "Harry it is your turn to attack", "left");	
	 	 	// std::cout << player1.getName() << " it is your turn to attack" << std::endl;	
	 	}
	 	else{
	 	 	terminal->print(11, "Draco it is your turn to attack", "left");	
	 		// std::cout << player2.getName() << " it is your turn to attack" << std::endl;
	 	}

	 
	 	terminal->print(12, "Choose your move: 1, 2, 3, or 4", "left");
	 	move = terminal->get();
		// std::cin >> move;
	 	terminal->clearLine(12);
		isValid = validMove(move, terminal);
		if(isValid == 1){
			if(player == 1){

				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3, terminal);
				if(player2.getHealth()<0){
					
					terminal->print(25, "Draco's remaining health: 0", "left");
					// std::cout << player2.getName() << "'s remaining health: 0" << std::endl;
					// std::cout << std::endl;
				}
				else{
					terminal->print(25, "Draco's remaining health: " + std::to_string(player2.getHealth()), "left");
					// std::cout << player2.getName() << "'s remaining health: " <<  player2.getHealth() << std::endl;
					// std::cout << std::endl;
				}
			}
			else{
				
				gameRunning = playerAttack(move, player, &player1, &player2, spell1, spell2, spell3, terminal);
				if(player2.getHealth()<0){
					terminal->print(26, "Harry's remaining health: 0", "left");
					// std::cout << player1.getName() << "'s remaining health: 0"  << std::endl;
				}	
				else{
					terminal->print(26, "Harry's remaining health: " + std::to_string(player1.getHealth()), "left");
					// std::cout << player1.getName() <<"'s remaining health: " <<  player1.getHealth() << std::endl;
					// std::cout << std::endl;
				}
			}
		}
		else{
			isValid = false;
		}
	gameRunning = endGame(player2, move, player, terminal);
	if(gameRunning == false){
		break;
	}
	gameRunning = endGame(player1, move, player, terminal);
	if(gameRunning == false){
		break;
	}

	}
}

