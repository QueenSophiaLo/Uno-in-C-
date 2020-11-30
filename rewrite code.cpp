#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// global variables
bool reverse = true;													// reverse = true is clockwise player motion and vis versa
bool skip = false;														// skip used for action cards to skip player's turns
int playerTurn;															// is incremented or decremented to show player's turn
int playerAmount;														// amount of players playing the game

// output for rules of the game
void OutputRules(){
  cout << "Welcome to UNO!\nTo start, lets go over the rules..." << endl;
  cout << "The game UNO is meant for 2 to 10 players, and the goal of the game is to be the first person to reach 500 points." << endl;
  cout << "Each player starts out with 7 cards. Each card will have a specific color like red, yellow, blue, or green, and a number" << endl;
  cout << "that is from 0-9 unless it is a special card. There are 5 different special cards that can be played. A skip card can only"<< endl;
  cout << "be one color and when played, it will skip the turn of the next player. A reverse card reverses the direction of play." << endl;
  cout << "This card can only be played on a matching color or another reverse card. The draw 2 card causes the next person to draw 2" << endl;
  cout << "cards from the deck and forfeit his/her turn. A wild card allows the player to change the  color of play. This card can be" << endl;
  cout << "played at any time during your turn, even if you have another playable card. Likewise, the wild draw 4 card allows you to pick" << endl;
  cout << "the color and the next player must draw 4 cards and forfeit his/her turn. To play, match the top card on the discard pile by either" << endl;
  cout << "number, color, or word. If you don't have anything that matches, you must pick a card from the draw pile. If you draw a card that" << endl;
  cout << "can be played, play it. Otherwise, play moves on to the next player. When a player has only one card left, they must say \"UNO\"." << endl;
  cout << "The first player to discard all of his/her cards gets the points. The points come from the sum of each card in every players hand." << endl << endl;
  cout << "The points are as follows:" << endl;
  cout << "All Number Cards (0-9):\tFace Value" << endl;
  cout << "Draw 2 Cards:\t\t20 Points" << endl;
  cout << "Reverse Cards:\t\t20 Points" << endl;
  cout << "Skip Cards:\t\t20 Points" << endl;
  cout << "Wild Cards:\t\t50 Points" << endl;
  cout << "Wild Draw 4 Cards:\t50 Points" << endl;
  cout << "Now have fun!" << endl << endl;
}
/*   numbers 0-9 are red cards 0-9; 10-12 are red skip, red reverse, and red draw 2 in that order
     numbers 14-23 are yellow cards 0-9; 24-26 are yellow skip, yellow reverse, and yellow draw 2 in that order
     numbers 28-37 are green cards 0-9; 38-40 are green skip, green reverse, and green draw 2 in that order
     numbers 42-51 are blue cards 0-9; 52-54 are blue skip, blue reverse, and blue draw 2 in that order
     numbers 56-64 are red cards 1-9; 65-67 are red skip, red reverse, and red draw 2 in that order
     numbers 69-77 are yellow cards 1-9; 78-80 are yellow skip, yellow reverse, and yellow draw 2 in that order
     numbers 82-90 are green cards 1-9; 91-93 are green skip, green reverse, and green draw 2 in that order
     numbers 95-103 are blue cards 1-9; 104-106 are blue skip, blue reverse, and blue draw 2 in that order
     numbers 13, 27, 41, and 55 are wild cards
     numbers 68, 81, 94, and 107 are wild draw 4 cards
*/
// making cards as objects
enum Color {RED, YELLOW, GREEN, BLUE, WILD};
enum Value {
ZERO = 0,																// zero cards are zero points
ONE = 1,																// one cards are one point
TWO = 2,																// two cards are two points 
THREE = 3,																// three cards are three points
FOUR = 4,																// four cards are four points
FIVE = 5,																// five cards are five points
SIX = 6,																// six cards are six points
SEVEN = 7,																// seven card are seven points
EIGHT = 8,																// eight cards are eight points
NINE = 9,																// nine cards are nine points
REVERSE,				// any action cards are 20 points
SKIP,					// can't be set to 20 for comparison reasons
DRAWTWO,
WILDCARD = 50,															// wild cards are 50 points
DRAWFOUR = 50															// wild draw 4's are 50 points
};
class Card {
    //FIELDS
    private:
        Value value;
        Color color;
    
    public:
        Card(Value temp, Color hold){
            value = temp;
            color = hold;
        };
        Value GetValue(){
            return value;
        };
        Color GetColor(){
            return color;
        };
};
// wild card


// getting input for number of players
void InputForPlayerAmount(int playerAmount){ 
	cout << "How many players will be playing: ";
	cin >> playerAmount;
			while ((playerAmount < 2) || (playerAmount > 10)){
			cout << "\nOnly 2-10 players are allowed to play." << endl;
			cout << "How many players will be playing: ";
			cin >> playerAmount;
			}
}

int main(){
// output for rules of the game
	OutputRules();

// getting input for number of players
	int playerAmount;
	InputForPlayerAmount(playerAmount);

// getting input for names of players
  vector<string> playerName(playerAmount);								//vector made to store names
  string plyrName;
  for (int i = 1; i <= playerAmount; ++i){
      cout << "Please enter player " << i << "'s name: ";				//ask user for their name
      cin >> plyrName;													//get user input
      playerName.at(i - 1) = plyrName;									//each name entered goes into the vector (element 0 is player 1)
    }
	
// playable card
	// if value or color is the same then it is playable

// turn increments/decrements	
	if ((reverse == "true") && (skip == "false")){
	playerTurn = (playerTurn - 1) % playerAmount;						// counterclockwise player movement (next valid player)
	}	else if ((reverse == "true") && (skip == "true")) {
		playerTurn = (playerTurn - 2) % playerAmount;
		}	else if ((reverse == "false") && (skip == "false")){
			playerTurn = (playerTurn + 1) % playerAmount;				// clockwise player movement (next valid player)
			}	else if ((reverse == "false") && (skip == "true")){
				playerTurn = (playerTurn + 2) % playerAmount;
				}
	
// ending parameters
	cout << "Game Over";
	return 0;
}