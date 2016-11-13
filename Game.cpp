//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Implementation file for the Game class
//to manipulate user interaction and game status.
#include <iostream>
#include <string>
#include "linked_list.h"
#include "Game.h"

using namespace std;

const string Game::WEST = "west";
const string Game::EAST = "east";
const string Game::BRIDGE = "bridge";
const string Game::GAME_PIECES[GAME_PIECES_NUM] = {"intern", "assistant", "janitor", "professor", "lantern", "zombies"};
const int Game::INTERN = 1;
const int Game::LAB = 2;
const int Game::JANITOR = 5;
const int Game::PROFESSOR = 10;

//Des: Constructor for the Game class.
Game::Game() {
	runningTime = 0;
	westGorge.initList();
	eastGorge.initList();
	bridge.initList();
}

//Des: Status of the game being won or not.
bool Game::IsWon() {
	if (runningTime <= 17 && eastGorge.length() == 5) {
		return true;
	} else {
		return false;
	}
}

//Des: Status of the game being lost or not.
bool Game::IsLost(linked_list<string> &east) {
	bool count = east.length();
	if (runningTime > 17 && (count < 5)) {
		return true;
	} else {
		return false;
	}
}

//Des: Status of whether a Game is being played or not.
bool Game::IsPlaying() {
	if (runningTime > 0 && !IsWon() && !IsLost(eastGorge)) {
		return true;
	} else {
		return false;
	}
}

//Des: Sets up gorges and light location for a game.
void Game::SetUp() {
	runningTime = 0;
	//clear west bank
	westGorge.initList();
	//clear east bank
	eastGorge.initList();
	//clear bridge
	bridge.initList();
	//put four people in west linked list
	westGorge.InsertInOrder(GAME_PIECES[0]); //intern
	westGorge.InsertInOrder(GAME_PIECES[1]); //assistant
	westGorge.InsertInOrder(GAME_PIECES[2]); //janitor
	westGorge.InsertInOrder(GAME_PIECES[3]); //professor
	westGorge.InsertInOrder(GAME_PIECES[4]); //lantern
	lightLocation = WEST;
	whoIsHoldingLight = GAME_PIECES[0];
}

//Des: Prints the game instructions for the user.
void Game::DisplayInstructions() {
	//print all instructions so player knows what game is about and the point
	cout<<"Zombie Bridge Problem Rules"<<endl;
	cout<<"Help the party cross the bridge before the zombies arrive in 17 minutes."<<endl;
	cout<<"Decide who crosses the gorge each trip and who holds the light."<<endl;
	cout<<"Travel times: "<<endl;
	cout<<"Intern: 1 minute, Lab Assistant: 2 minutes, Janitor 5 minutes, Professor: 10 minutes."<<endl;
	cout<<"Remember: "<<endl;
	cout<<"- Up to two people may corss the bridge at one time, one of which must hold the lantern."<<endl;
	cout<<"- Everyone else may wait on either side of the gorge in the dark."<<endl;
	cout<<"- If the zombies arrive when people are on the bridge or on the west side of the gorge, you lose."<<endl;
	cout<<"- If a person is on the bridge without the lantern, you lose."<<endl;
}

//Des: Displays game current statuses.
void Game::DisplayStats() {
	cout<<endl;
	cout<<"\t--- GAME STATS ---"<<endl;
	//Who is on west bank
	if (!westGorge.IsEmpty()) {
		cout<<"\tWest Gorge: "<<endl;
		westGorge.PrintAll();
	} else {
		cout<<"\tWest Gorge is empty."<<endl;
	}
	cout<<endl;
	//Who is on east bank
	if (!eastGorge.IsEmpty()) {
		cout<<"\tEast Gorge: "<<endl;
		eastGorge.PrintAll();
	} else {
		cout<<"\tEast Gorge is empty."<<endl;
	}
	cout<<endl;
	//Who is on bridge
	if (!bridge.IsEmpty()) {
		cout<<"\tBridge: "<<endl;
		bridge.PrintAll();
	} else {
		cout<<"\tNo one is on the bridge."<<endl;
	}
	cout<<endl;
	//Who has lantern
	cout<<"\tThe "<<whoIsHoldingLight<<" has the lantern."<<endl;
	//Time used
	cout<<"\tTime used: "<<runningTime<<endl;
	//Time remaining
	cout<<"\tTime remaining: "<<17-runningTime<<endl;
	cout<<"\t--- END STATS ---"<<endl;
	cout<<endl;
}

//Des: Moves people from one gorge to the other and updates the lantern status.
void Game::TransportPeople(linked_list<string> &fromGorge, linked_list<string> &toGorge) {
	cout<<"--- BEGIN TURN ---"<<endl;
	char input = ' ';
	//Ask number to cross bridge
	cout<<"How many people should cross the bridge now (1 or 2): ";
	cin.get(input);
	cin.ignore(80, '\n');
	while (input != '1' && input != '2') {
		cout<<"Invalid Answer. 1 or 2: ";
		cin.get(input);
		cin.ignore(80, '\n');
	}
	cout<<endl;
	//Menu  from game pieces - don't print lantern or zombies
	cout<<"Game Piece Menu:"<<endl;
	for (int i = 0; i < GAME_PIECES_NUM - 2; i++) {
		cout<<i<<" "<<GAME_PIECES[i]<<endl;
	}
	cout<<endl;
	//Ask who to move
	int p1 = -1;
	int p2 = -1;
	bool p1Good = false;
	bool p2Good = false;
	bool validSelections = false;
	string piece1 = "";
	string piece2 = "";
	string lantern = "lantern";

	while (!validSelections) {
		//Get the first input
		while (!p1Good) {
			cout<<"Select your first person to move by number (this person will hold the lantern): ";
			while (cin.peek() >= '0' && cin.peek() <= '3') {
				cin>>p1;
			}
			if (p1 >= 0 && p1 <= 3) {
				p1Good = true;
			} else {
				cout<<"Selection #1 not vaild. Try again."<<endl;
			}
			cin.ignore(80, '\n');
		}
		//Get second input
		while (input == '2' && !p2Good) {
			cout<<"Select your second person to move by number: ";
			while (cin.peek() >= '0' && cin.peek() <= '3') {
				cin>>p2;
			}
			if (p2 >= 0 && p2 <= 3 && p1 != p2) {
				p2Good = true;
			} else if (p2 >= 0 && p2 <= '3' && p1 == p2) {
				cout<<"You picked the same person twice! Pick someone else."<<endl;
			} else {
				cout<<"Selection #2 not valid. Try again."<<endl;
			}
			cin.ignore(80, '\n');
		}

		//Convert player input for game piece selection from int to strings of the piecess
		piece1 = GAME_PIECES[p1];
		if (p2 != -1) {
			piece2 = GAME_PIECES[p2];
		}

		//verify selections from fromGorge exist there
		bool piece1Search = fromGorge.Search(piece1);
		bool piece2Search = false;
		if (piece2 != "") {
			piece2Search = fromGorge.Search(piece2);
		}
		if (piece1Search && (piece2 != "" ? piece2Search : true)) {
			validSelections = true;
		} else {
			cout<<"Your selections are not found in that list. Try again."<<endl;
			p1 = -1;
			p2 = -1;
			p1Good = p2Good = false;
		}
	} //end while (!validSelections)
	string message = piece1 + (piece2 == "" ? "" : (" and " + piece2));
	cout<<"You selected "<<message<<"."<<endl;
	//Get those people out of the appropriate gorge linked list
	//Store as strings, not a number from the array
	bool remove1 = fromGorge.Remove(piece1);
	bool remove2 = false;
	if (piece2 != "") {
		remove2 = fromGorge.Remove(piece2);
	}
	bool remove3 = fromGorge.Remove(lantern);
	if (!remove1 && !(piece2 != "" ? remove2 : true) && !remove3) {
		cout<<"Removing from gorge failed."<<endl;
	}

	//Move pawns to bridge and update tracking variables
	bool bridge1 = bridge.InsertInOrder(piece1);
	bool bridge2 = false;
	if (piece2 != "") {
		bridge2 = bridge.InsertInOrder(piece2);
	}
	bool bridge3 = bridge.InsertInOrder(lantern);

	if (!bridge1 && !(piece2 !="" ? bridge2 : true) && !bridge3) {
		cout<<"Moving to the bridge failed."<<endl;
	}
	whoIsHoldingLight = piece1;
	lightLocation = BRIDGE;

	if (piece1 == "professor" || piece2 == "professor") {
		runningTime += PROFESSOR;
	} else if (piece1 == "janitor" || piece2 == "janitor") {
		runningTime += JANITOR;
	} else if (piece1 == "assistant" || piece2 == "assistant") {
		runningTime += LAB;
	} else {
		runningTime += INTERN;
	}

	//print stats
	DisplayStats();

	//put people in appropriate gorge linked list
	remove1 = bridge.Remove(piece1);
	bool insert1 = toGorge.InsertInOrder(piece1);
	bool insert2 = false;
	if (piece2 != "") {
		remove2 = bridge.Remove(piece2);
		insert2 = toGorge.InsertInOrder(piece2);
	}
	remove3 = bridge.Remove(lantern);
	bool insert3 = toGorge.InsertInOrder(lantern);
	if (!remove1 && !(piece2 != "" ? remove2 : true) && !remove3) {
		cout<<"Removing from bridge failed."<<endl;
	}
	if (!insert1 && !(piece2 != "" ? insert2 : true) && !insert3) {
		cout<<"Insert to gorge failed."<<endl;
	}
	cout<<"--- END TURN ---"<<endl;
} //End transportPeople function

//Des: Plays the game.
void Game::Play() {
	//Set Up
	SetUp();
	//Display State
	DisplayStats();
	//while not won or lost
	while (!(IsWon()) && !(IsLost(eastGorge))) {
		//If lantern is on west bank
		if (lightLocation == "west") {
			cout<<"Travel: west ---> east"<<endl;
			//Move people from west to east
			TransportPeople(westGorge, eastGorge);
			lightLocation = "east";
		} else {
			//else if lantern is on east bank
			//Move people east to west
			cout<<"Travel: west <--- east"<<endl;
			TransportPeople(eastGorge, westGorge);
			lightLocation = "west";
		}
		//Display stats
		DisplayStats();
	}
	if (IsWon()) {
		cout<<"You get the last member of the party across, "<<endl;
		cout<<"cut the ropes of the bridge, and contain the mutant zombies!"<<endl;
	} else {
		cout<<"You ran out of time!"<<endl;
		cout<<"The zombies caught up to your party before you could cut the ropes!"<<endl;
	}
}
