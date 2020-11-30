#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Global Variables
bool reverse = false;													// reverse = false is clockwise player motion and vis versa
bool skip = false;														// skip used for action cards to skip player's turns
int currDeckSize = 108;													// 108 cards in the deck (starts with 108 cards)
int playerAmount;														// amount of players playing the game
int playerTurn;															// is incremented or decremented to show player's turn

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
REVERSE = 20,															// any action cards are 20 points
SKIP = 20,					
DRAWTWO = 20,
WILDCARD = 50,															// wild cards are 50 points
DRAWFOUR = 50															// wild draw 4's are 50 points
};
enum Action {Act_None, Act_Reverse, Act_Skip, Act_Draw2, Act_Wild, Act_WildDraw4};

bool ReverseCardPlayed(FIXME current player, Card topCard){
	if (topCard.value == REVERSE){										// a reverse card was played
		return true;
	}
	else {																// a reverse card was not played
		return false;
	}
}

bool SkipCardPlayed(FIXME current player, Card topCard){
	if (topCard.value == SKIP){											// a skip card was played
		return true;
	}
	else {																// a skip card was not played
		return false;
	}
}

void DrawTwoCards(FIXME next players hand, Card topCard, bool skip = false){
	if (topcard.value == DRAWTWO){
		// FIXME draw two cards
		// add them to next players hand
		skip = true
		// after one player's turn is skipped (bc they just drew cards) turn the skip bool into false	
	}
}

void WildCardPlayed(Card topcard){
	string cardcolorPlayed;
	if ((topcard.color == WILD) && (topcard.value == WILDCARD)){		// regular wildcard is played
		cout << "What color would you like to change to (red, green, yellow, or blue): ";
		cin >> cardColorPlayed;
		// FIXME change deck to allow that card color to be played
	}
	else if ((topcard.color == WILD) && (topcard.value == DRAWFOUR)){
		// FIXME draw four cards
		// add them to next player's hand
		cout << "What color would you like to change to (red, green, yellow, or blue): ";
		cin >> cardColorPlayed;
		// FIXME change deck to allow that card color to be played
		// FIXME increment player turn
	}
}



// Act_None continues to increment/decrement player turns

// Act_Reverse switches "bool reverse" value to increment turns in the opposite direction

// Act_Skip sets "bool skip" to true, skips player's turn, and turns "bool skip" back to false

// Act_Draw2 puts two more cards in the next player's hand, sets "bool skip" to true, skips next player's turn, and turns "bool skip" back to false

// Act_Wild asks the player which color they would like to chage the deck to and changes playable cards to that color

// Act_WildDraw4 asks the player which color they would like to chage the deck to and changes playable cards to that color
			// Act_WildDraw4 then puts four more cards in the next player's hand, sets "bool skip" to true, skips next player's turn


class Card {
    //FIELDS
    private:
        Color color;
        Value value;
    	Action action;
    public:
        Card(Color hold, Value temp, Action act){
            value = temp;
            color = hold;
			action = act;
        };
        Value GetValue(){												// note to self** getter method- returns private data stored in an object's member variables
            return value;
        };
        Color GetColor(){
            return color;												// if color is the same or is WILD, continue
        };
		Action GetAction(){
			return action;
		};
	bool CanCardBePlayed(Card topCard){
		if ((topCard.color == color) || (topCard.value == value) || (color == WILD)){		// if you play a card that has the same color/number OR is a wild card 
			return true;																	// then the card CAN be played
		}
		else {
			string tryAgain = "You cannot play that card, try again";
		//FIXME cout the try again statement
		// card is not a valid card
		// you don't have that card in your hand or maybe you mispelled the card name
			return tryAgain;																// card cannot be played	
		}
	}
};

class Deck{

	private:
		std::vector<Card> cards;

	public:
	Deck(){																// Create cards and put in deck (constructor is constructing object "Deck")
		int h = 0
		int i;
		int j = 0;			
			cards.push_back(Card(RED, ZERO,Act_None)); 					// red 0 (only one zero card of each color)
			cards.push_back(Card(YELLOW, ZERO, Act_None));				// yellow 0
			cards.push_back(Card(GREEN, ZERO, Act_None));				// green 0
			cards.push_back(Card(BLUE, ZERO, Act_None));				// blue 0

		while (h < 2){													// creates two versions of each card
			cards.push_back(Card(RED, REVERSE, Act_Reverse)); 			// red 0
			cards.push_back(Card(YELLOW, REVERSE, Act_Reverse));		// yellow 0
			cards.push_back(Card(GREEN, REVERSE, Act_Reverse));			// green 0
			cards.push_back(Card(BLUE, REVERSE, Act_Reverse));			// blue 0

			cards.push_back(Card(RED, SKIP, Act_Skip)); 				// red skip
			cards.push_back(Card(YELLOW, SKIP, Act_Skip));				// yellow skip
			cards.push_back(Card(GREEN, SKIP, Act_Skip));				// green skip
			cards.push_back(Card(BLUE, SKIP, Act_Skip));				// blue skip

			cards.push_back(Card(RED, DRAWTWO, Act_Draw2)); 			// red draw 2
			cards.push_back(Card(YELLOW, DRAWTWO, Act_Draw2));			// yellow draw 2
			cards.push_back(Card(GREEN, DRAWTWO, Act_Draw2));			// green draw 2
			cards.push_back(Card(BLUE, DRAWTWO, Act_Draw2));			// blue draw 2
			++h;
		}	

		while (j < 2){													// creates two versions of each card
			for (i = 1; i <= 9; ++i){
				cards.push_back(Card(RED,(Value)i,Act_None)); 			// red 1 through red 9
			}
			for (i = 1; i <= 9; ++i){
				cards.push_back(Card(YELLOW,(Value)i, Act_None));		// yellow 1 through yellow 9
			}
			for (i = 1; i <= 9; ++i){
				cards.push_back(Card(GREEN,(Value)i, Act_None));		// green 1 through green 9
			}
			for (i = 1; i <= 9; ++i){
				cards.push_back(Card(BLUE,(Value)i, Act_None));			// blue 1 through blue 9
			} ++j;
		}	
		for (i = 0; i < 4; ++i){
				cards.push_back(Card(WILD, WILDCARD, Act_Wild));		// wild cards
			}
		for (i = 0; i < 4; ++i){
				cards.push_back(Card(WILD, DRAWFOUR, Act_WildDraw4));	// wild draw 4
			}
	void Shuffle() { 													// shuffle algorithm here
	const Card& Draw() {  												// Get a random card (program component: random number generator)
		int cardIndex = (std::rand() % currDeckSize);					// get a random index to pull the card from
		Card temp = cards[cardIndex];									// pull the card from the deck
		--currDeckSize;													// decrement current deck size
		cards.erase(cardIndex);											// remove the card from the deck once it's been chosen by erasing card from deck array
		return temp;													// return the card value
	}
	}
}
	/* 
	
	vector<Cards> shuffled;					// shuffled cards is a local variable
	for (i = 1; i <= 108; ++i){
		select a random card from the deck
		int index = rand() % cards.size;
		
		shuffled.push_back(cards.at(index)				// put that card that you got out into the "shuffled deck"
		cards.erase(index);						// erase card you got from the regular deck index
	}
		cards = shuffled
		
	Card& Draw()
		draw the top card
		Card c = cards.at(0);
		cards.erase(0);
		return c;
		
	
	*/

class Player{
	private:
	vector<Card> hand;
	int points;
	string plyrName;
	
	public:

	Hand GetHand(){																// creates object holding hand vectors
		// FIXME how would I access all my player's hands?
	}
	Points GetPoint(){																// creates object holding player points
		playerPoints(playerAmount);												// create a vector the size of player amount
	}																			// players are offset (playerPoints.at(0) is the first player and so on)
}		//FIXME

// What are the player's names
void GetPlayerNames(vector<Player> playerNames, int playerNum){
	string plyrname;
	cout << "How many players are playing? " << endl;
	cin >> playernum;
	for (int i = 0; i < playerNum ; ++i){									// playerNum is number of players
		cout << "Please enter player " << i << "'s name: ";					//ask user for their name
		cin >> plyrName;													//get user input
		playerNames.at(i).name = (plyrName);								//each name entered goes into the vector (element 0 is player 1)
	}
}
	/*
	class Player {
	
	public:
		string name;
		vector hand;
		int points;
		
	};
	
	vector<Player> players(number of player);		// when you create the class you don't really need the function so delete it afterwards
	string player names;
	
	for (int i = 1; i <= num of players ; ++i){
		cout << "enter name " ;
		cin >> player names;
		players.at(i).name = (name);
	}
	
	Deal cards
	for (i = 1; i <= 7; ++i){


 make an object that holds player names AND hand vectors
 employ getter methods 
 method to push to the vector stored within

 define the two variables (string name, card vector) for player hands	
 end up constructing an empty hand and push items into that hand
 functions needed; constructor, getter for player name, getter for player hand, push to hand function (it will take a card variable and add it to the card card vector that is in your object (hand vector))
 make sure you give your constructor the variables it needs (just a player name)
	*/

	
vector<string> winningOrder = {"The Winner is: ", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth", "Last"};

// ending parameters
void PlayerHasZeroCards(FIXME current players hand, current players name, Card topCard){
	// if currentplayers hand.size == 0
      cout << "You have no more cards, type \"UNO\" : ";
      cin >> checkUno;
      if ((checkUno == "UNO") || (checkUno == "uno") || (checkUno == "Uno")){
	  cout << current players name << " has UNO!" << endl;				// Winner's name is output
			// look at points notes, all of the cards in each players hand are scored and the game continues  
		}
		else{
			cout << "You did not say \"UNO\", 2 cards have been added to your hand."<< endl;
			FIXME add two cards to players hand
		}
}
/* points are kinda weird tbh
"At the end of an Uno hand the losing players must total the cards left in their hand.
The sum total is recorded and the game is over when the first player reaches 500 points.
At the point a player hits 500 points, the overall winner is the player who has the lowest score
- since avoiding scoring points is the name of the game here."
*/
void PlayerHas500Points(vector<int> playerpoints, int playerNum){
	for (int i = 0; i < playerNum; ++i){
		if (playerpoints.at(i) <= 500){
			cout << "Game over!" << endl;
			//FIXME output winners in order of least amount of points
			cout << winningOrder.at(0) << FIXME winning player << endl;
			for (int i = 1; i < playerNum; ++i){
				cout << winningOrder.at(i) << " place is: " << FIXME playername << endl;
			}
		}
		else{
		// keep playing the game
		}
	}
}
	
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
	
int main(){

// variables
Card topCard;											// the card on top of the stack
vector<Player> plyrNames;								// the vector containing all the player's names

	
// output for rules of the game
OutputRules();
	
// shuffle the deck
Shuffle(); FIXME										// shuffle deck
								// one card is chosen as top card
									// top card is output (each turn increment will remind player's of the topcard)
								// seven cards are delt to each players's hand
/*	
	Deck deck_of_cards;
	deck_of_cards.Shuffle();
*/
	
// What are the player's names and how many players are playing
	GetPlayerNames(plyrNames, playerAmount);
		
// player 1 starts
	CanCardBePlayed(topCard);		// FIXME needs to check to see if player has a playable card
	ReverseCardPlayed(FIXME current player.at(playerTurn), topCard);
	SkipCardPlayed(FIXME current player.at(playerTurn), topCard);
	DrawTwoCards(FIXME next players hand, topCard, bool skip = false);
	WildCardPlayed(topcard);
	// if player has no playable cards in their hand, draw ONE card then go to the next player
	// else if - the player can play a card
// check to see if card is valid
	
// winning parameters
	PlayerHasZeroCards(FIXME current players hand, current players name, topCard);
	PlayerHas500Points(vector<int> playerpoints);
	
vector<Card> player_1;	
	
	for (i = 0; i <= 7 ; ++i){								// draw 7 cards
	Card   deck_of_cards.Draw();							// make filling player hands a seperate function (don't put it in main)
	}
	
// turn increments/decrements	
	if ((reverse == true) && (skip == false)){
	playerTurn = (playerTurn - 1) % playerAmount;						// counterclockwise player movement (next valid player)
	}	else if ((reverse == true) && (skip == true)) {
		playerTurn = (playerTurn - 2) % playerAmount;
		}	else if ((reverse == false) && (skip == false)){
			playerTurn = (playerTurn + 1) % playerAmount;				// clockwise player movement (next valid player)
			}	else if ((reverse == false) && (skip == true)){
				playerTurn = (playerTurn + 2) % playerAmount;
				}
	return 0;	
}