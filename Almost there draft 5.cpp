#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

// Global Variables
bool plyrMotion = false;                        				// false is clockwise player motion and vis versa
int reverse = 0;
bool skip = false;														// skip used for action cards to skip player's turns
int skipBool = 0;
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
	string WhatCardIsThis(){
		string cardName;
		if(this->GetColor() == RED){									// interperet card's values
			cardName = "red ";
		}	else if(this->GetColor() == YELLOW){
    			cardName = "yellow ";
		}	else if(this->GetColor() == BLUE){
    			cardName = "blue ";
		}	else if(this->GetColor() == GREEN){
    			cardName = "green ";
  		}
		
		if(this->GetValue() == REVERSE & this->GetAction() == Act_Reverse){
			cardName += "reverse";
		}	else if(this->GetValue() == SKIP & this->GetAction() == Act_Skip){
				cardName += "skip";
		}	else if(this->GetValue() == DRAWTWO & this->GetAction() == Act_Draw2){
				cardName += "draw 2";
		}	else if(this->GetValue() == DRAWFOUR & this->GetAction() == Act_WildDraw4){
				cardName = "draw 4";
		}	else if(this->GetValue() == WILDCARD & this->GetAction() == Act_Wild){
				cardName = "wildcard";
		}	else{
				cardName += to_string(this->GetValue());
  }
  return cardName;														// return a string with card name
}
	bool CanCardBePlayed(Card topCard, Card playedCard){
		if ((playedCard.GetColor() == topCard.GetColor()) || ((playedCard.GetValue() == topCard.GetValue()) && playedCard.GetAction() == topCard.GetAction()) || (topCard.GetColor() == WILD)){
			// if you play a card that has the same color/number OR is a wild card 
			return true;																	// then the card CAN be played
		}
		else {
			cout << "You cannot play that card, try again (check your spelling and use all lowercase letters)" ;
		// card is not a valid card
			return false;																// card cannot be played	
		}
	}
};

class Player{
	private:
	  vector<Card> hand;										// player's hand
	  int points;												// player's points
	  string plyrName;											// player's name
	
	public:
  Player(string name){
    plyrName = name;
    points = 0;
  }
	
  vector<Card> GetHand(){																// creates object holding hand vectors
		return hand;
	} 

	int GetPoints(){																// creates object holding player points
		return points;												// create a vector the size of player amount
	}								                        // players are offset (playerPoints.at(0) is the first player and so on)

	void CalculatePoints() {
		// For loop removing top card from hand, add card's points to "points".
		// This will clear the player hand and keep track of points.
	}

  string GetName(){
    return plyrName;
  }

  void AddCard(Card add){
    hand.push_back(add);
  }
};

vector<Card> discardPile;												// where discardPile.at(0) is the top card
	
class Deck{

	private:
		vector<Card> cards;

	public:
	Deck(){																// Create cards and put in deck (constructor is constructing object "Deck")
		int h = 0;
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
			for (int i = 1; i <= 9; ++i){
				cards.push_back(Card(RED,(Value)i,Act_None)); 			// red 1 through red 9
			}
			for (int i = 1; i <= 9; ++i){
				cards.push_back(Card(YELLOW,(Value)i, Act_None));		// yellow 1 through yellow 9
			}
			for (int i = 1; i <= 9; ++i){
				cards.push_back(Card(GREEN,(Value)i, Act_None));		// green 1 through green 9
			}
			for (int i = 1; i <= 9; ++i){
				cards.push_back(Card(BLUE,(Value)i, Act_None));			// blue 1 through blue 9
			} ++j;
		}	
		for (int i = 0; i < 4; ++i){
				cards.push_back(Card(WILD, WILDCARD, Act_Wild));		// wild cards
			}
		for (int i = 0; i < 4; ++i){
				cards.push_back(Card(WILD, DRAWFOUR, Act_WildDraw4));	// wild draw 4
			}
  }

	void shuffle() {													// a function to shuffle the deck
		
		vector<Card> shuffled;
		for (int i = 1; i <= 108; ++i){
			int index = rand() % cards.size();								// Get a random card from the deck (program component: random number generator)

			shuffled.push_back(cards.at(index));
			cards.erase(cards.begin() + index);								// remove the card from the deck once it's been chosen by erasing card from deck
		}
		cards = shuffled;													// set cards vector equal to shuffled deck vector
	}
	Card Draw(){														// draw the top card off the now shuffled cards deck
		if (cards.size() == 0){										// if there are no cards left in the deck 
			Card topCard = discardPile.back();							// sans top card
			discardPile.pop_back();									// shuffle and use discard pile as deck to draw from
			int numCards = discardPile.size();
				for (int i = 0; i < numCards ; ++i){
				int index = rand() % discardPile.size();								

				cards.push_back(discardPile.at(index));
				discardPile.erase(discardPile.begin() + index);
				}
		// discard pile should now be empty, except the top card we kept.
			discardPile.push_back(topCard);
		}
		Card n = cards.back();
		cards.pop_back();													// card is removed from deck vector
		return n;														// return card value
	}
	vector<Card> GetDeck(){
		return cards;
	}
	void DrawMulti(Player temp, int drawAmount){					// pass the player being drawn to and the amount of cards drawn
		for (int i = drawAmount; i > 0; --i){						// everytime you want to draw a card
			temp.AddCard(Draw());
		}
	}
};

bool ReverseCardPlayed(Player currentPlayer, Card topCard){
	if (topCard.GetValue() == REVERSE){										// a reverse card was played (if true is returned, !reverse;)
		return true;
	}
	else {																// a reverse card was not played
		return false;
	}
}

bool SkipCardPlayed(Player currentPlayer, Card topCard){
	if (topCard.GetValue() == SKIP){											// a skip card was played
		return true;
	}
	else {																// a skip card was not played
		return false;
	}
}

void DrawTwoCards(Player nextPlater, int index, Card topCard){
	if (topCard.GetValue() == DRAWTWO){
		// FIXME draw two cards
		// add them to next players hand
	}
}

void WildCardPlayed(Card topCard){
	string cardColorPlayed;
	bool colorWrong = true;
	if (topCard.GetColor() == WILD){		// regular wildcard is played
		while (colorWrong == true){
			cout << "What color would you like to change to (red, green, yellow, or blue): ";
			cin >> cardColorPlayed;
			if ((cardColorPlayed == "red") || (cardColorPlayed == "green") || (cardColorPlayed == "yellow") || (cardColorPlayed == "blue")){
				colorWrong = false;
			}
			else{
				cout << endl << "Please choose a valid color (red, green, yellow, or blue), make sure the color is spelled right " ;
				cout << "and is in all lowercase letters." << endl;
			}			
		}
	}
	if (topCard.GetValue() == DRAWFOUR){
		// FIXME draw four cards
		// add them to next player's hand
		// FIXME change deck to allow that card color to be played
		// FIXME increment player turn
	}
}

// What are the player's names
void GetPlayerNames(vector<Player>& players){
	string plyrName;
  cout << "How many players are playing? " << endl;
	cin >> playerAmount;
	while ((playerAmount < 2) || (playerAmount > 10)){
		cout << "There must be 2 or more players to play UNO. Player number cannot exceed 10 players." << endl << endl << "How many players are playing? ";
		cin >> playerAmount;
	}
	if ((playerAmount >= 2) || (playerAmount <= 10)){
		for (int i = 0; i <  playerAmount; ++i){									// playerAmount is number of players
			cout << "Please enter player " << i + 1 << "'s name: ";					//ask user for their name
			cin >> plyrName;													//get user input
			players.push_back(Player(plyrName));								//each name entered goes into the vector (element 0 is player 1)
		}
	}
}

// draw cards function
void DrawMulti(Player temp, int drawAmount){
	for (int drawAmount; drawAmount > 0 ; --drawAmount){
		temp.at(playerTurn).AddCard(Draw());
	}
}

// ending parameters
void PlayerHasZeroCards(Player currentPlayer, Card topCard){
	string checkUno;
  // if currentplayers hand.size == 0
      cout << "You have no more cards, type \"UNO\" : ";
      cin >> checkUno;
      if ((checkUno == "UNO") || (checkUno == "uno") || (checkUno == "Uno")){
	  cout << currentPlayer.GetName() << " has UNO!" << endl;				// Winner's name is output
			// look at points notes, all of the cards in each players hand are made into points and added to the round winner's points- the game continues  
		}
		else{
			cout << "You did not say \"UNO\", 2 cards have been added to your hand."<< endl;
			//FIXME add two cards to players hand
		}
}

int PlayerHas500Points(){
	for (int i = 0; i < players.size(); ++i){
		if (players.at(i).GetPoints() >= 500){
			return 1;
		}
	}
	return 0;
}

void WhoWins(){
	int highScore = players.at(0).GetPoints();				// get first player points value
	cout << "Game over!" << endl << endl;
	for (int i = 0; i < players.size(); ++i){				// output all player's points
		cout << players.at(i).GetName() << "'s points: ", players.at(i).GetPoints() << endl;
	}
	for (int j = 1; j < players.size(); ++j){
		if (players.at(j).GetPoints() > highScore){
			highScore = players.at(j).GetPoints();
		}
		for (int h = 0; h < players.size(); ++h){			// if the winners are tied
			cout << endl << "Winning players are: " << endl;
			if (players.at(h).GetPoints() == highScore){
				cout << players.at(h).GetName() << endl;
			}		
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

// variables											// the card on top of the stack has to be drawn at a later point because it cant be defined empty. (Card topCard)
vector<Player> players;
Deck deck_of_cards;
int cardsDrawn = 0;										// 1 2 4
bool playerWins = false;
srand(time(NULL));										// shuffled deck contains a random seed based off time of day (to ensure completely random cards every game)
string playedCard;										// card the user plays
bool goodCard = false;
 
	
// output for rules of the game
OutputRules();
	
// shuffle the deck
	deck_of_cards.shuffle();
	Card topCard = deck_of_cards.GetDeck().at(0);						// card on top of the deck declared
	
	// top card is output (each turn increment will remind player's of the topcard)
								// seven cards are dealt to each players's hand

// What are the player's names and how many players are playing
	GetPlayerNames(players);						// function that allows players to input # of players and player names
	
	for ( int i = 0; i < playerAmount; ++i){
		cout << players.at(i).GetName() << "'s cards are; " ;				// outputs players' names
		for (int j = 0; j < 7 ; ++j){										// draw 7 cards
			players.at(i).AddCard(deck_of_cards.Draw());					// make filling player hands a seperate function (don't put it in main)
			cout << players.at(i).GetHand().at(j).WhatCardIsThis() << ", ";	// output hand 
		} 	
	cout << endl;
	}

	// if player has no playable cards in their hand, draw ONE card then go to the next player
	// else if - the player can play a card


	while (PlayerHas500Points() == 0){							// if function returns zero, game is not over
		for (int playerTurn = 0; playerTurn < players.size(); ++playerTurn){
			cout << "It is " << players.GetName().at(playerTurn) << "'s turn" << endl;
			cout << "Top card is " << discardPile.at(0).GetCard().at(0).WhatCardIsThis() << " ." << endl << "Player Hand contains: " 
				for (int j = 0; j < players.GetHand().size(); ++j){
					cout << players.at(playerTurn).GetHand().at(j).WhatCardIsThis() << ", ";	// display player's hand
				}
			cout << "What card would you like to play?";
			topCard = discardPile.at(0).GetCard().at(0).WhatCardIsThis();		// declare topcard
			while (goodCard == false){                                       // if card can be played, put it in discard pile vector
				cin << playedCard;                                             // player plays card 
		// FIXME	"playedCard" is a string which you need to turn into a card object
				goodCard = (CanCardBePlayed(topCard, playedCard)) ;             // calls function with parameter topCard
            }          						  // if card cant be played try again
			discardPile.push_front(playedCard);					// put played card on top of discard pile

	// reverse card function		
			if ( (ReverseCardPlayed(players.at(playerTurn), topCard)) == true){
				reverse = !reverse;						// reverse card played (1)
			}
			else{
				reverse = reverse;						// reverse card not played (0)
			}

			if (reverse == 1){							
				plyrMotion = true;						// player motion is now counterclockwise
			}
			else {
				plyrMotion = false;
			}	
	// skip card function		
			if ((SkipCardPlayed(players.at(playerTurn), topCard)) == true){
				skip = true;
			}
	// draw 2 function
			
	// wildcard function
			WildCardPlayed(topCard);
	// winning parameter functions called
			PlayerHasZeroCards(players, topCard);			
	// turn increments/decrements								// FIXME increment and decrements to non valid players rn
			if ((plyrMotion == true) && (skip == false)){
				playerTurn = (playerTurn - 1) % playerAmount;					// counterclockwise player movement (next valid player)
			}	else if ((plyrMotion == true) && (skip == true)) {
					playerTurn = (playerTurn - 2) % playerAmount;
					skip = false;												//	set skip back to false
			}	else if ((plyrMotion == false) && (skip == false)){
					playerTurn = (playerTurn + 1) % playerAmount;			// clockwise player movement (next valid player)
			}	else if ((plyrMotion == false) && (skip == true)){
					playerTurn = (playerTurn + 2) % playerAmount;
					skip = false;										// set skip back to false
			}
		}	
	}	// end of while loop code

// print out scores and winners	
	WhoWins();										
	return 0;
}	// end of int main 															   
