#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

// Global Variables
bool plyrMotion = false;						// false is clockwise player motion and vis versa
int reverse = 0;
bool skip = false;								// skip used for action cards to skip player's turns
int skipBool = 0;
int currDeckSize = 108;							// 108 cards in the deck (starts with 108 cards)
int playerAmount;								// amount of players playing the game
int playerTurn;									// is incremented or decremented to show player's turn

enum Color {RED, YELLOW, GREEN, BLUE, WILD};
enum Value {
ZERO = 0,				// zero cards are zero points
ONE = 1,				// one cards are one point
TWO = 2,				// two cards are two points 
THREE = 3,				// three cards are three points
FOUR = 4,				// four cards are four points
FIVE = 5,				// five cards are five points
SIX = 6,				// six cards are six points
SEVEN = 7,				// seven card are seven points
EIGHT = 8,				// eight cards are eight points
NINE = 9,				// nine cards are nine points
REVERSE = 20,			// any action cards are 20 points
SKIP = 20,
DRAWTWO = 20,
WILDCARD = 50,			// wild cards are 50 points
DRAWFOUR = 50			// wild draw 4's are 50 points
};
enum Action {Act_None, Act_Reverse, Act_Skip, Act_Draw2, Act_Wild, Act_WildDraw4};	
	/*	differentiates different cards (in the "Value" object, there are multiple cards that have
		the same value, the program would read them as the same card because they have the same
		point value, hence, a new enummeration "Action" is created)
	*/
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
        Value GetValue(){							// getter method- returns private data stored in an object's member variables
            return value;
        };
        Color GetColor(){
            return color;							// if color is the same or is WILD, continue
        };
		Action GetAction(){
			return action;
		};
	string WhatCardIsThis(){
		string cardName;
		if(this->GetColor() == RED){				// interperet card's values
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
  return cardName;												// return a string with card name
}
	bool CanCardBePlayed(Card topCard, bool Played){
		// if you play a card that has the same color/number OR is a wild card 
		if ((this->GetColor() == topCard.GetColor()) || ((this->GetValue() == topCard.GetValue()) && this->GetAction() == topCard.GetAction()) || (this->GetColor() == WILD)){
			return true;										// then the card CAN be played
		}
    else if(Played == true){
			cout << "You cannot play that card, try again (check your spelling and use all lowercase letters)" ;
		// card is not a valid card
			return false;										// card cannot be played	
		}else{
      return false;
    }
	}
};

class Player{
	private:
	  vector<Card> hand;		// player's hand
	  int points;				// player's points
	  string plyrName;			// player's name
	
	public:
	Player(string name){
    plyrName = name;
    points = 0;
  }
	
  vector<Card> GetHand(){		// creates object holding hand vectors
		return hand;
	} 

	int GetPoints(){			// creates object holding player points
		return points;			// create a vector the size of player amount
	}							// reminder** players are offset (playerPoints.at(0) is the first player and so on)
	void AddPoints(int num) {
		points += num;
	}
	int CalculatePoints(Player currentPlayer) {
		int total = 0;
		int numCards = currentPlayer.GetHand().size();
		for (int i = 0; i < numCards; ++i){								// For loop removing top card from hand, add card's points to "points"
			total += currentPlayer.GetHand().back().GetValue();	// This will clear the player's hand and keep track of points
			currentPlayer.GetHand().pop_back();
		}
		return total;
	}
	void PlayCard(int index) {
		cout << "Play card at index: " << index << endl;
		hand.erase(hand.begin() + index);
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
			int index = rand() % cards.size();							// Get a random card from the deck (program component: random number generator)

			shuffled.push_back(cards.at(index));
			cards.erase(cards.begin() + index);							// remove the card from the deck once it's been chosen by erasing card from deck
		}
		cards = shuffled;												// set cards vector equal to shuffled deck vector
	}
	Card Draw(){														// draw the top card off the now shuffled cards deck
		if (cards.size() == 0){											// if there are no cards left in the deck 
			Card topCard = discardPile.back();							// sans top card
			discardPile.pop_back();										// shuffle and use discard pile as deck to draw from
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
		cards.pop_back();												// card is removed from deck vector
		return n;														// return card value
	}
	vector<Card> GetDeck(){
		return cards;
	}
	void DrawMulti(Player& temp, int drawAmount){						// pass the player being drawn to and the amount of cards drawn
		for (int i = drawAmount; i > 0; --i){							// everytime you want to draw a card
			temp.AddCard(Draw());
		}
	}
};

bool ReverseCardPlayed(Player currentPlayer, Card topCard){
	if (topCard.GetValue() == REVERSE){									// a reverse card was played (if true is returned, !reverse;)
		return true;
	}
	else {																// a reverse card was not played
		return false;
	}
}

bool SkipCardPlayed(Player currentPlayer, Card topCard){
	if (topCard.GetValue() == SKIP){									// a skip card was played
		return true;
	}
	else {																// a skip card was not played
		return false;
	}
}

void DrawTwoCards(vector<Player> Players, int index, Card topCard, bool skipPlayer, Deck& deck){
	if (topCard.GetValue() == DRAWTWO){
		int drawAmount = 2;										//	make draw amount 2 (draw 2)
		deck.DrawMulti(Players.at(index +1), drawAmount);		// draw 2 cards and put them in the next player's hand
		bool skipPlayer = true;									// you now want to skip the next player's turn								
	}
}

void WildCardPlayed(Card topCard, bool skipPlayer, Deck& deck, vector<Player> Players, int index){
	string cardColorPlayed;
	bool colorWrong = true;
	if (topCard.GetColor() == WILD){	// regular wildcard is played
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
		if (topCard.GetValue() == DRAWFOUR){
		int drawAmount = 4;										// make draw amount 4 (draw 4)
		deck.DrawMulti(Players.at(index +1), drawAmount);		// draw 4 cards and put them in the next player's hand
		bool skipPlayer = true;									// you now want to skip the next player's turn								
		}
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
		for (int i = 0; i <  playerAmount; ++i){							// playerAmount is number of players
			cout << "Please enter player " << i + 1 << "'s name: ";			// ask user for their name
			cin >> plyrName;												// get user input
			players.push_back(Player(plyrName));							// each name entered goes into the vector (element 0 is player 1)
		}
	}
}

// ending parameters
bool PlyrsHaveCardsRemaining(Player currentPlayer, int playerAmount){
	for (int i = 0; i < playerAmount; ++i){
		if (currentPlayer.GetHand().size() == 0){	// if current player's hand size is 0
			return 0;							
		}
  }
	return true;
}


void PlayerHasZeroCards(Player currentPlayer, Card topCard, Deck& deck){
	if (currentPlayer.GetHand().size() == 0){		// checks to see if player has zero cards (not the loop that checks if all players
	string checkUno;								// have zero cards becuase there is a possibility that two cards can be added to that player's hand
	cout << "You have no more cards, type \"UNO\" : ";
	cin >> checkUno;
		if ((checkUno == "UNO") || (checkUno == "uno") || (checkUno == "Uno")){
			cout << currentPlayer.GetName() << " has UNO!" << endl;			// Winner's name is output
		// reminder** all of the cards in each players hand are made into points and added to the round winner's points- the game continues  
		}
		else{
			cout << "You did not say \"UNO\", 2 cards have been added to your hand."<< endl;
			int add2Cards = 2;
			deck.DrawMulti(currentPlayer, add2Cards);
		}
	}
}

int PlayerHas500Points(vector<Player> players){
	for (int i = 0; i < players.size(); ++i){
		if (players.at(i).GetPoints() >= 500){
			return 1;
		}
	}
	return 0;
}

void WhoWins(vector<Player> players){
	int highScore = players.at(0).GetPoints();				// get first player points value
	cout << "Game over!" << endl << endl;
	for (int i = 0; i < players.size(); ++i){				// output all player's points
		cout << players.at(i).GetName() << "'s points: " << players.at(i).GetPoints() << endl;
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

// variables
vector<Player> players;
Deck deck_of_cards;
int cardsDrawn = 0;										// 1 2 4
bool playerWins = false;
srand(time(NULL));										// shuffled deck contains a random seed based off time of day (to ensure completely random cards every game)
bool goodCard = false;
bool goodHand = false;
int incrOrDecr = 0;										// increment or decrement value (set later in the code)
int ind;

// output for rules of the game
OutputRules();
// What are the player's names and how many players are playing
GetPlayerNames(players);
	
// Gameplay while loop
	while (PlayerHas500Points(players) == 0){					// if function returns zero, game is not over
// shuffle the deck
		deck_of_cards.shuffle();
			// deal cards to players
    for(int i=0;i<players.size();++i){
      deck_of_cards.DrawMulti(players.at(i), 7);
    }
			// todo
    discardPile.push_back(deck_of_cards.Draw());
	int firstloop = 1;
		while (PlyrsHaveCardsRemaining(players.at(playerTurn), playerAmount) == true){
			
      //for (int playerTurn = 0; playerTurn < players.size(); ++playerTurn){
cout << "turn: " << playerTurn << endl;
goodHand = false;
goodCard = false;
				cout << "It is " << players.at(playerTurn).GetName() << "'s turn" << endl;
				cout << "Top card is " << discardPile.at(0).WhatCardIsThis() << " ." << endl << "Player Hand contains: ";
			  for (int j = 0; j < players.at(playerTurn).GetHand().size(); ++j){
					cout << players.at(playerTurn).GetHand().at(j).WhatCardIsThis() << ", ";	// display player's hand
				}
				for (int i = 0; i < players.at(playerTurn).GetHand().size(); ++i){							// checks to see if player has any playable cards
					if (players.at(playerTurn).GetHand().at(i).CanCardBePlayed(discardPile.at(0), false) == true){
						goodHand = true;
					}
				}
				if (goodHand == true){												// player has at least one valid card in their hand	
					cout << "You have at least one playable card in your hand, what card would you like to play?" << endl;
					while (goodCard == false){                                      // if card can be played, put it in discard pile vector
            string playedCard;
            //cin >> playedCard;                                            // player plays card 
	// for some reason this does not work the first loop and it needs two getlines
	 if (firstloop == 1) {
 		firstloop = 0;
            getline(cin, playedCard);
	}

            getline(cin, playedCard);
            //cout << "test1";
            //cout << "[" << playedCard << "]" << endl;
            for(ind = 0; ind < players.at(playerTurn).GetHand().size(); ind++){
              //cout << "test2";
              //cout << "[" << players.at(playerTurn).GetHand().at(ind).WhatCardIsThis() << "]" << endl;
              if(players.at(playerTurn).GetHand().at(ind).WhatCardIsThis() == playedCard){
                //cout << "test3";
                //ind = players.at(playerTurn).GetHand().size();
		break;
              }
            }
      
            // debug
            if (ind >= players.at(playerTurn).GetHand().size()) {
			cout << "Card not found" << endl;
			continue;
	}         														// if card cant be played try again
            	goodCard = players.at(playerTurn).GetHand().at(ind).CanCardBePlayed(discardPile.at(0), true);
		if (goodCard == false)
			continue;
		
          	cout << "Playing the card";
		discardPile.insert(discardPile.begin(), players.at(playerTurn).GetHand().at(ind));			// put played card on top of discard pile
          	//players.at(playerTurn).GetHand().erase(players.at(playerTurn).GetHand().begin() + ind);
          	players.at(playerTurn).PlayCard(ind);

			// reverse card function		
					if ( (ReverseCardPlayed(players.at(playerTurn), discardPile.at(0))) == true){
						plyrMotion = !plyrMotion;
					}
					
			// skip card function		
					if ((SkipCardPlayed(players.at(playerTurn), discardPile.at(0))) == true){
						skip = true;
					}
			// draw 2 function
					DrawTwoCards(players, playerTurn, discardPile.at(0), skip, deck_of_cards);
			// wildcard function
					WildCardPlayed(discardPile.at(0), skip, deck_of_cards, players, playerTurn);
			}
			}
			else{			// player has no playable cards
				cout << "You have no playable cards in your hand." << endl << "A card has automatically been drawn for you and your turn will be skipped." << endl; 
				cardsDrawn = 1; // sets amount of cards to be drawn equal to 1
				deck_of_cards.DrawMulti(players.at(playerTurn), cardsDrawn);
				//skip = true; 	// skip that player's turn after they draw a card
			}	
			// winning parameter functions called
				PlayerHasZeroCards(players.at(playerTurn), discardPile.at(0), deck_of_cards);			
			// turn increments/decrements	
cout << "player turn: " << playerTurn << endl;
cout << "player amt: " << playerAmount<< endl;
				if ((plyrMotion == true) && (skip == false)){
					playerTurn = (playerTurn - 1) % playerAmount;			// counterclockwise player movement (next valid player)
						if (playerTurn < 0) 
							playerTurn += playerAmount;;
cout << "player turn1: " << playerTurn << endl;
				}			
				else if ((plyrMotion == false) && (skip == false)){
						playerTurn = (playerTurn + 1) % playerAmount;		// clockwise player movement (next valid player)
cout << "player turn2: " << playerTurn << endl;
				}
				else if ((plyrMotion == true) && (skip == true)) {
						playerTurn = (playerTurn - 2) % playerAmount;
						if (playerTurn < 0) 
							playerTurn += playerAmount;;
						skip = false;										//	set skip back to false
cout << "player turn3: " << playerTurn << endl;
				}	
				else if ((plyrMotion == false) && (skip == true)){
						playerTurn = (playerTurn + 2) % playerAmount;
						skip = false;										// set skip back to false
cout << "player turn4: " << playerTurn << endl;
				}			
			//}	
		}
		//todo: calculate points, add points to players, 
	}	// end of while loop code
// print out scores and winners	
	WhoWins(players);										
	return 0;
}	// end of int main 															   
