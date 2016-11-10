//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Implementation file for the Game class
//to manipulate user interaction and game status.

#include "Game.h"

const string Game::WEST = "west";
const string Game::EAST = "east";
const string Game::BRIDGE = "bridge";
const string Game::GAME_PIECES = {"intern", "assistant", "janitor", "professor", "lantern", "zombies"};
const int Game::INTERN = 1;
const int Game::LAB = 2;
const int Game::JANITOR = 5;
const int Game::PROFESSOR = 10;
	
//Des: Constructor for the Game class.
Game::Game() {
		
}

//Des: Status of the game being won or not.
bool Game::IsWon() const {
	
}

//Des: Status of the game being won or not.
bool Game::IsLost(const linked_list<string> &east) {
	
}

//Des: Status of whether a Game is being played or not.
bool Game::IsPlaying() const {
		
}

//Des: Sets up gorges and light location for a game.
void SetUp() {
	//clear west bank
	//clear east bank
	//put four people in west linked list
}

//Des: Prints the game instructions for the user.
void DisplayInstructions() const {
	//print all instructions so player knows what game is about and the point
}

//Des: Displays game current statuses.
void DisplayStat() const {
	//Who is on west bank
	//Who is on east bank
	//Who is on bridge
	//Who has lantern
	//Time used
	//Time remaining
	
}

//Des: Moves people from one gorge to the other and updates the lantern status.
void TransportPeople(linked_list<string> &fromGorge, linked_list<string> &toGorge) {
	//Ask number to cross bridge
	//Menu  from game pieces - don't print lantern or zombies
	//Ask who to move
	//Get those people out of the appropriate gorge linked list
	
	//Store as strings, not a number from the array
	
	//print stats
	//put people in appropriate gorge linked list
}

//Des: Plays the game.
void Play() {
	//Set Up
	//Display State
	
	//While not won or lost
	//{
		//If lantern is on west bank
		
		//Move people from west to east
		
		//else if lantern is on east bank
		
		//Move people east to west
		
		//Display stats
		
	//}
	
}
	
/*private:
	const string WEST; //constant for west
	const string EAST; //constant for east
	const string BRIDGE; //constant for bridge
	const int INTERN; //constant for intern time (1)
	const int LAB; //constant for lab assistant time (2)
	const int JANITOR; //constant for janitor time (5)
	const int PROFESSOR; //constant for professor time (10)
	
	static const int GAME_PIECES = 5; //number of pieces
	static const string GAME_PIECES[GAME_PIECES]; //What is on the bridge
	
	linked_list <string> westGorge; //west of the gorge
	linked_list <string> eastGorge; //east of the gorge
	linked_list <string> bridge; //over of the gorge
	
	string lightLocation; //light location
	string whoIsHoldingLight; //who holds the light when crossing
	int runningTime;*/