//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Contains main function to run the program.
// Run scenarios of zombies chasing people across a gorge 
//aka time management and resource allocation.
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main() {
	bool playAgain = true;
	//Create an instance of the game;
	Game game;
	cout<<"Welcome to the Zombie Bridge problem!"<<endl<<endl;	
	//do {
//	game.DisplayInstructions();	
	//Play the game
	game.Play();	
	//Play again?
	
	//Reset to play again
	//} while (playAgain);
	return 0;
}
