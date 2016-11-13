//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Contains main function to run the program.
// Run scenarios of zombies chasing people across a gorge 
//aka time management and resource allocation.
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

//Des: Creates an instance of the zombie bridge game until the user doesn't want to play any more.
//Input: None, execpt the user interaction.
//Output: The interactions of the game.
int main() {
	//Create an instance of the game;
	Game game;
	cout<<"Welcome to the Zombie Bridge problem!"<<endl<<endl;	
	game.DisplayInstructions();
	char again = 'y';
	do {
		//Play the game
		game.Play();	
		//Play again?
		cout<<endl<<"Play again? (y/n): ";
		cin>>again;
		if (again != 'y' && again != 'n') {
			cout<<"You did not answer correctly. Play again."<<endl;
		}
	//Reset to play again
	} while (again != 'n');
	return 0;
}
