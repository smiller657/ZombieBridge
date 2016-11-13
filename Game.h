//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Header file for the Game class
//to manipulate user interaction and game status.
#include <string>
#include "linked_list.h"

using namespace std;

class Game {
	
	public:
	
		//Des: Constructor for the Game class.
		//Input: None.
		//Output: A Game object.
		Game();
		
		//Des: Status of the game being won or not.
		//Input: None.
		//Output: True for a won game, false if it is not yet won.
		bool IsWon();
		
		//Des: Status of the game being lost or not.
		//Input: The members of the team on the east side of the gorge.
		//Output: True for a lost game, false still going.
		bool IsLost(linked_list<string> &east);
		
		//Des: Status of whether a Game is being played or not.
		//Input: None.
		//Output: True for playing currently, or false for the game is off.
		bool IsPlaying();
		
		//Des: Sets up gorges and light location for a game.
		//Input: None.
		//Output: None, but instantiates the game.
		void SetUp();
		
		//Des: Prints the game instructions for the user.
		//Input: None.
		//Output: None, but prints game instructions to the console.
		void DisplayInstructions();
		
		//Des: Displays game current statuses.
		//Input: None.
		//Output: None, but prints people on east and west gorges, time used, time remaining, who has the lantern. 
		void DisplayStats();
		
		//Des: Moves people from one gorge to the other and updates the lantern status.
		//Input: A list of those moving from one gorge to another, using a linked list string.
		//Output: None, but updates statuses.
		void TransportPeople(linked_list<string> &fromGorge, linked_list<string> &toGorge);
		
		//Des: Plays the game.
		//Input: None.
		//Output: None, but controls a game played.
		void Play();
	
	private:
		static const string WEST; //constant for west
		static const string EAST; //constant for east
		static const string BRIDGE; //constant for bridge
		static const int INTERN; //constant for intern time (1)
		static const int LAB; //constant for lab assistant time (2)
		static const int JANITOR; //constant for janitor time (5)
		static const int PROFESSOR; //constant for professor time (10)
		
		static const int GAME_PIECES_NUM = 6; //number of pieces
		static const string GAME_PIECES[GAME_PIECES_NUM]; //What is on the bridge
		
		linked_list <string> westGorge; //west of the gorge
		linked_list <string> eastGorge; //east of the gorge
		linked_list <string> bridge; //over of the gorge
		
		string lightLocation; //light location
		string whoIsHoldingLight; //who holds the light when crossing
		int runningTime;
};
