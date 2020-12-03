#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//Global Variables
string currCardColor;
string currCardNum;
string playerCardColor;
string playerCardNum;
string cardColorPlayed;
string cardNumPlayed;
string cardNumberPlayed;
int cardPlayed1;
int cardPlayed2;
int cardPlayed3;
int cardPlayed4;
int discardPosition = 0;
int currDeckPosition;
bool draw4;
bool skip;
bool reverse;
bool draw2;
bool playerIsOut = false;
bool player1Out;
bool player2Out;
bool player3Out;
bool player4Out;
bool player5Out;
bool player6Out;
bool player7Out;
bool player8Out;
bool player9Out;
bool player10Out;
bool playerSkip;

void WhatIsPlayerCard (vector < int >& currPlayer, int i) 
{ //function called to declare what the player card is in string format
  int Card = currPlayer.at (i); //sets an integer to the current card being played in the current players vectors 

  if (((Card >= 0) && (Card <= 12)) || ((Card >= 56) && (Card <= 67)))
    {	//checks for red cards and then checks for which specific red card it is
      playerCardColor = "red";
      if (Card == 0)
	{
	  playerCardNum = "0";
	}
      else if ((Card == 1) || (Card == 56))
	{
	  playerCardNum = "1";
	}
      else if ((Card == 2) || (Card == 57))
	{
	  playerCardNum = "2";
	}
      else if ((Card == 3) || (Card == 58))
	{
	  playerCardNum = "3";
	}
      else if ((Card == 4) || (Card == 59))
	{
	  playerCardNum = "4";
	}
      else if ((Card == 5) || (Card == 60))
	{
	  playerCardNum = "5";
	}
      else if ((Card == 6) || (Card == 61))
	{
	  playerCardNum = "6";
	}
      else if ((Card == 7) || (Card == 62))
	{
	  playerCardNum = "7";
	}
      else if ((Card == 8) || (Card == 63))
	{
	  playerCardNum = "8";
	}
      else if ((Card == 9) || (Card == 64))
	{
	  playerCardNum = "9";
	}
      else if ((Card == 10) || (Card == 65))
	{
	  playerCardNum = "skip";
	}
      else if ((Card == 11) || (Card == 66))
	{
	  playerCardNum = "reverse";
	}
      else if ((Card == 12) || (Card == 67))
	{
	  playerCardNum = "draw 2";
	}
    }
  else if (((Card >= 14) && (Card <= 26)) || ((Card >= 69) && (Card <= 80)))
    {	//checks for yellow cards and then checks for which specific yellow card it is
      playerCardColor = "yellow";
      if (Card == 14)
	{
	  playerCardNum = "0";
	}
      else if ((Card == 15) || (Card == 69))
	{
	  playerCardNum = "1";
	}
      else if ((Card == 16) || (Card == 70))
	{
	  playerCardNum = "2";
	}
      else if ((Card == 17) || (Card == 71))
	{
	  playerCardNum = "3";
	}
      else if ((Card == 18) || (Card == 72))
	{
	  playerCardNum = "4";
	}
      else if ((Card == 19) || (Card == 73))
	{
	  playerCardNum = "5";
	}
      else if ((Card == 20) || (Card == 74))
	{
	  playerCardNum = "6";
	}
      else if ((Card == 21) || (Card == 75))
	{
	  playerCardNum = "7";
	}
      else if ((Card == 22) || (Card == 76))
	{
	  playerCardNum = "8";
	}
      else if ((Card == 23) || (Card == 77))
	{
	  playerCardNum = "9";
	}
      else if ((Card == 24) || (Card == 78))
	{
	  playerCardNum = "skip";
	}
      else if ((Card == 25) || (Card == 79))
	{
	  playerCardNum = "reverse";
	}
      else if ((Card == 26) || (Card == 80))
	{
	  playerCardNum = "draw 2";
	}
    }
  else if (((Card >= 28) && (Card <= 40)) || ((Card >= 82) && (Card <= 93)))
    {	//checks for green cards and then checks for which specific green card it is
      playerCardColor = "green";
      if (Card == 28)
	{
	  playerCardNum = "0";
	}
      else if ((Card == 29) || (Card == 82))
	{
	  playerCardNum = "1";
	}
      else if ((Card == 30) || (Card == 83))
	{
	  playerCardNum = "2";
	}
      else if ((Card == 31) || (Card == 84))
	{
	  playerCardNum = "3";
	}
      else if ((Card == 32) || (Card == 85))
	{
	  playerCardNum = "4";
	}
      else if ((Card == 33) || (Card == 86))
	{
	  playerCardNum = "5";
	}
      else if ((Card == 34) || (Card == 87))
	{
	  playerCardNum = "6";
	}
      else if ((Card == 35) || (Card == 88))
	{
	  playerCardNum = "7";
	}
      else if ((Card == 36) || (Card == 89))
	{
	  playerCardNum = "8";
	}
      else if ((Card == 37) || (Card == 90))
	{
	  playerCardNum = "9";
	}
      else if ((Card == 38) || (Card == 91))
	{
	  playerCardNum = "skip";
	}
      else if ((Card == 39) || (Card == 92))
	{
	  playerCardNum = "reverse";
	}
      else if ((Card == 40) || (Card == 93))
	{
	  playerCardNum = "draw 2";
	}
    }
  else if (((Card >= 42) && (Card <= 54)) || ((Card >= 95) && (Card <= 106)))
    {	//checks for blue cards and then checks for which specific blue card it is
      playerCardColor = "blue";
      if (Card == 42)
	{
	  playerCardNum = "0";
	}
      else if ((Card == 43) || (Card == 95))
	{
	  playerCardNum = "1";
	}
      else if ((Card == 44) || (Card == 96))
	{
	  playerCardNum = "2";
	}
      else if ((Card == 45) || (Card == 97))
	{
	  playerCardNum = "3";
	}
      else if ((Card == 46) || (Card == 98))
	{
	  playerCardNum = "4";
	}
      else if ((Card == 47) || (Card == 99))
	{
	  playerCardNum = "5";
	}
      else if ((Card == 48) || (Card == 100))
	{
	  playerCardNum = "6";
	}
      else if ((Card == 49) || (Card == 101))
	{
	  playerCardNum = "7";
	}
      else if ((Card == 50) || (Card == 102))
	{
	  playerCardNum = "8";
	}
      else if ((Card == 51) || (Card == 103))
	{
	  playerCardNum = "9";
	}
      else if ((Card == 52) || (Card == 104))
	{
	  playerCardNum = "skip";
	}
      else if ((Card == 53) || (Card == 105))
	{
	  playerCardNum = "reverse";
	}
      else if ((Card == 54) || (Card == 106))
	{
	  playerCardNum = "draw 2";
	}
    }
  else if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55)
	   || (Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
    {	//checks for wild cards and then checks for which specific wild card it is
      playerCardColor = "wild";
      if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55))
	{
	  playerCardNum = "card";
	}
      else if ((Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
	{
	  playerCardNum = "draw 4";
	}
    }
}

void DrawTwo (int& i, int playerAmount, vector < int >& player1, vector < int >& nextPlayer, vector < int >& Deck)
{    //function called if a draw two card was played while play is going in clockwise direction
     //i is set equal to the players turn
  if (i == playerAmount)
    { /* if i is equal to how many players are playing then the cards are given to player 1 
      and a boolean expression is set true to skip player 1 at the start */
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      playerSkip = true;
      draw2 = false;
    }
    if(i == playerAmount - 1)   {
        /* if i is 1 less than the number of players in the game then it gives the cards to the next player but changes the value of
        i so that i is not out of bounds */
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = 0;
      draw2 = false;
    }
  else
    {
        /* if neither of the above are true then the 2 cards are given to the next player, 1 is added to is
        and the boolean draw 2 is reset to false */
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = i + 1;
      draw2 = false;
    }
}

void DrawFour (int& i, int playerAmount, vector < int >& player1, vector < int >& nextPlayer, vector < int >& Deck)
{
    /* DrawFour is a function called when draw 4 card is played while play is going in the clockwise direction. 
       Also, i is set equal to the players turn*/
  if (i == playerAmount)
    {
        /* if play is currently on the last players turn than the 4 cards are given to player 1
           and the boolean expression to skip the first players turn is set to true */
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      playerSkip = true;
      draw4 = false;
    }
  if (i == playerAmount - 1){
      /* if play is currently on the second to last player than the next player still gets the 4 cards but
         the value of i is changed so that an out of bounds error is not recieved */
       nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = 0;
      draw4 = false;  
    }
  else
    {
        /* if it is not close to the last players turn than the 4 cards are given to the next player,
           the value of i is increased by 1, and the boolean expression draw4 is reset to false */
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = i + 1;
      draw4 = false;
    }
}

int Points (vector < int >currPlayer)
{
    /* This function is called in order to add up all the point values in a specific players hand */
    
  int points = 0;

    /* for loop that runs for the size of the current players hand thats points
           are being added up */
  for (int j = 0; j < currPlayer.size (); ++j)
    {
      if ((currPlayer.at (j) == 1) || (currPlayer.at (j) == 15)
	  || (currPlayer.at (j) == 29) || (currPlayer.at (j) == 43)
	  || (currPlayer.at (j) == 56) || (currPlayer.at (j) == 69)
	  || (currPlayer.at (j) == 82) || (currPlayer.at (j) == 95))
	{
	    /* if statement that checks for all values of 1 in the players hand */
	  points = points + 1;
	}
      else if ((currPlayer.at (j) == 2) || (currPlayer.at (j) == 16)
	       || (currPlayer.at (j) == 30) || (currPlayer.at (j) == 44)
	       || (currPlayer.at (j) == 57) || (currPlayer.at (j) == 70)
	       || (currPlayer.at (j) == 83) || (currPlayer.at (j) == 96))
	{
	    /* if statement that checks for all values of 2 in the players hand */
	  points = points + 2;
	}
      else if ((currPlayer.at (j) == 3) || (currPlayer.at (j) == 17)
	       || (currPlayer.at (j) == 31) || (currPlayer.at (j) == 45)
	       || (currPlayer.at (j) == 58) || (currPlayer.at (j) == 71)
	       || (currPlayer.at (j) == 84) || (currPlayer.at (j) == 97))
	{
	    /* if statement that checks for all values of 3 in the players hand */
	  points = points + 3;
	}
      else if ((currPlayer.at (j) == 4) || (currPlayer.at (j) == 18)
	       || (currPlayer.at (j) == 32) || (currPlayer.at (j) == 46)
	       || (currPlayer.at (j) == 59) || (currPlayer.at (j) == 72)
	       || (currPlayer.at (j) == 85) || (currPlayer.at (j) == 98))
	{
	    /* if statement that checks for all values of 4 in the players hand */
	  points = points + 4;
	}
      else if ((currPlayer.at (j) == 5) || (currPlayer.at (j) == 19)
	       || (currPlayer.at (j) == 33) || (currPlayer.at (j) == 47)
	       || (currPlayer.at (j) == 60) || (currPlayer.at (j) == 73)
	       || (currPlayer.at (j) == 86) || (currPlayer.at (j) == 99))
	{
	    /* if statement that checks for all values of 5 in the players hand */
	  points = points + 5;
	}
      else if ((currPlayer.at (j) == 6) || (currPlayer.at (j) == 20)
	       || (currPlayer.at (j) == 34) || (currPlayer.at (j) == 48)
	       || (currPlayer.at (j) == 61) || (currPlayer.at (j) == 74)
	       || (currPlayer.at (j) == 87) || (currPlayer.at (j) == 100))
	{
	    /* if statement that checks for all values of 6 in the players hand */
	  points = points + 6;
	}
      else if ((currPlayer.at (j) == 7) || (currPlayer.at (j) == 21)
	       || (currPlayer.at (j) == 35) || (currPlayer.at (j) == 49)
	       || (currPlayer.at (j) == 62) || (currPlayer.at (j) == 75)
	       || (currPlayer.at (j) == 88) || (currPlayer.at (j) == 101))
	{
	    /* if statement that checks for all values of 7 in the players hand */
	  points = points + 7;
	}
      else if ((currPlayer.at (j) == 8) || (currPlayer.at (j) == 22)
	       || (currPlayer.at (j) == 36) || (currPlayer.at (j) == 50)
	       || (currPlayer.at (j) == 63) || (currPlayer.at (j) == 76)
	       || (currPlayer.at (j) == 89) || (currPlayer.at (j) == 102))
	{
	    /* if statement that checks for all values of 8 in the players hand */
	  points = points + 8;
	}
      else if ((currPlayer.at (j) == 9) || (currPlayer.at (j) == 23)
	       || (currPlayer.at (j) == 37) || (currPlayer.at (j) == 51)
	       || (currPlayer.at (j) == 64) || (currPlayer.at (j) == 77)
	       || (currPlayer.at (j) == 90) || (currPlayer.at (j) == 103))
	{
	    /* if statement that checks for all values of 9 in the players hand */
	  points = points + 9;
	}
      else if (((currPlayer.at (j) >= 10) && (currPlayer.at (j) <= 12))
	       || ((currPlayer.at (j) >= 24) && (currPlayer.at (j) <= 26))
	       || ((currPlayer.at (j) >= 38) && (currPlayer.at (j) <= 40))
	       || ((currPlayer.at (j) >= 52) && (currPlayer.at (j) <= 54))
	       || ((currPlayer.at (j) >= 65) && (currPlayer.at (j) <= 67))
	       || ((currPlayer.at (j) >= 78) && (currPlayer.at (j) <= 80))
	       || ((currPlayer.at (j) >= 91) && (currPlayer.at (j) <= 93))
	       || ((currPlayer.at (j) >= 104) && (currPlayer.at (j) <= 106)))
	{
	    /* if statement that checks for all reverse cards, skip cards, or draw 2 cards in the players hand */
	  points = points + 20; //all special cards such as skips, reverses, and draw 2 cards are worth 20 points
	}
      else if ((currPlayer.at (j) == 13) || (currPlayer.at (j) == 27)
	       || (currPlayer.at (j) == 41) || (currPlayer.at (j) == 55)
	       || (currPlayer.at (j) == 68) || (currPlayer.at (j) == 81)
	       || (currPlayer.at (j) == 94) || (currPlayer.at (j) == 107))
	{
	    /* if statement that checks for all wild cards in the players hand */
	  points = points + 50; //wild cards are worth 50 points
	}
    }

  return points;
}

bool PlayableCard (vector < int >&currPlayer, vector < int >&Discard)
{
    /* function called to check the hand of the current players turn for a playable card */
  bool playableCard;

    // for loop to run the size of the current players hand
  for (int i = 0; i < currPlayer.size (); ++i)
    {
        /* calls the function WhatIsPlayerCard in order to get a string value from the corresponding integer value */
      WhatIsPlayerCard (currPlayer, i);
      
      /* if statement to check if the current card in the players hand is equal to the top card on the discard pile
         in terms of checking the same color, number, and checking if its a wild card */
      if ((playerCardColor == currCardColor) || (playerCardNum == currCardNum)
	  || (playerCardColor == "wild"))
	{
	  playableCard = true; //if one of the above is true then the player has a playable card
	}
    }

  return playableCard;
}

void WhatIsTopCard (vector < int >&Discard)
{
    /* function that is called in order to get the corresponding string value from an integer value based from 0 to 108 */
  
  // sets and integer value with the current top card in the discard pile
  int Card = Discard.at (discardPosition);
  
    /* if statement that checks for all red cards */
  if (((Card >= 0) && (Card <= 12)) || ((Card >= 56) && (Card <= 67)))
    {
        // sets the current card color string value to "red"
      currCardColor = "red";
      
      /* the following if statements check for certain integer values that have a corresponding
         string value and then sets that string value equal to the current card number */
      if (Card == 0)
	{
	  currCardNum = "0";
	}
      else if ((Card == 1) || (Card == 56))
	{
	  currCardNum = "1";
	}
      else if ((Card == 2) || (Card == 57))
	{
	  currCardNum = "2";
	}
      else if ((Card == 3) || (Card == 58))
	{
	  currCardNum = "3";
	}
      else if ((Card == 4) || (Card == 59))
	{
	  currCardNum = "4";
	}
      else if ((Card == 5) || (Card == 60))
	{
	  currCardNum = "5";
	}
      else if ((Card == 6) || (Card == 61))
	{
	  currCardNum = "6";
	}
      else if ((Card == 7) || (Card == 62))
	{
	  currCardNum = "7";
	}
      else if ((Card == 8) || (Card == 63))
	{
	  currCardNum = "8";
	}
      else if ((Card == 9) || (Card == 64))
	{
	  currCardNum = "9";
	}
      else if ((Card == 10) || (Card == 65))
	{
	  currCardNum = "skip";
	}
      else if ((Card == 11) || (Card == 66))
	{
	  currCardNum = "reverse";
	}
      else if ((Card == 12) || (Card == 67))
	{
	  currCardNum = "draw 2";
	}
    }
    
    /* if statement that checks for all yellow cards */
  else if (((Card >= 14) && (Card <= 26)) || ((Card >= 69) && (Card <= 80)))
    {
        // sets the current card color string value to "yellow"
      currCardColor = "yellow";
      
      /* the following if statements check for certain integer values that have a corresponding
         string value and then sets that string value equal to the current card number */
      if (Card == 14)
	{
	  currCardNum = "0";
	}
      else if ((Card == 15) || (Card == 69))
	{
	  currCardNum = "1";
	}
      else if ((Card == 16) || (Card == 70))
	{
	  currCardNum = "2";
	}
      else if ((Card == 17) || (Card == 71))
	{
	  currCardNum = "3";
	}
      else if ((Card == 18) || (Card == 72))
	{
	  currCardNum = "4";
	}
      else if ((Card == 19) || (Card == 73))
	{
	  currCardNum = "5";
	}
      else if ((Card == 20) || (Card == 74))
	{
	  currCardNum = "6";
	}
      else if ((Card == 21) || (Card == 75))
	{
	  currCardNum = "7";
	}
      else if ((Card == 22) || (Card == 76))
	{
	  currCardNum = "8";
	}
      else if ((Card == 23) || (Card == 77))
	{
	  currCardNum = "9";
	}
      else if ((Card == 24) || (Card == 78))
	{
	  currCardNum = "skip";
	}
      else if ((Card == 25) || (Card == 79))
	{
	  currCardNum = "reverse";
	}
      else if ((Card == 26) || (Card == 80))
	{
	  currCardNum = "draw 2";
	}
    }
    
    /* if statement that checks for all green cards */
  else if (((Card >= 28) && (Card <= 40)) || ((Card >= 82) && (Card <= 93)))
    {
        // sets the current card color string value to "green"
      currCardColor = "green";
      
      /* the following if statements check for certain integer values that have a corresponding
         string value and then sets that string value equal to the current card number */
      if (Card == 28)
	{
	  currCardNum = "0";
	}
      else if ((Card == 29) || (Card == 82))
	{
	  currCardNum = "1";
	}
      else if ((Card == 30) || (Card == 83))
	{
	  currCardNum = "2";
	}
      else if ((Card == 31) || (Card == 84))
	{
	  currCardNum = "3";
	}
      else if ((Card == 32) || (Card == 85))
	{
	  currCardNum = "4";
	}
      else if ((Card == 33) || (Card == 86))
	{
	  currCardNum = "5";
	}
      else if ((Card == 34) || (Card == 87))
	{
	  currCardNum = "6";
	}
      else if ((Card == 35) || (Card == 88))
	{
	  currCardNum = "7";
	}
      else if ((Card == 36) || (Card == 89))
	{
	  currCardNum = "8";
	}
      else if ((Card == 37) || (Card == 90))
	{
	  currCardNum = "9";
	}
      else if ((Card == 38) || (Card == 91))
	{
	  currCardNum = "skip";
	}
      else if ((Card == 39) || (Card == 92))
	{
	  currCardNum = "reverse";
	}
      else if ((Card == 40) || (Card == 93))
	{
	  currCardNum = "draw 2";
	}
    }
    
    /* if statement that checks for all blue cards */
  else if (((Card >= 42) && (Card <= 54)) || ((Card >= 95) && (Card <= 106)))
    {
        // sets the current card color string value to "blue"
      currCardColor = "blue";
      
      /* the following if statements check for certain integer values that have a corresponding
         string value and then sets that string value equal to the current card number */
      if (Card == 42)
	{
	  currCardNum = "0";
	}
      else if ((Card == 43) || (Card == 95))
	{
	  currCardNum = "1";
	}
      else if ((Card == 44) || (Card == 96))
	{
	  currCardNum = "2";
	}
      else if ((Card == 45) || (Card == 97))
	{
	  currCardNum = "3";
	}
      else if ((Card == 46) || (Card == 98))
	{
	  currCardNum = "4";
	}
      else if ((Card == 47) || (Card == 99))
	{
	  currCardNum = "5";
	}
      else if ((Card == 48) || (Card == 100))
	{
	  currCardNum = "6";
	}
      else if ((Card == 49) || (Card == 101))
	{
	  currCardNum = "7";
	}
      else if ((Card == 50) || (Card == 102))
	{
	  currCardNum = "8";
	}
      else if ((Card == 51) || (Card == 103))
	{
	  currCardNum = "9";
	}
      else if ((Card == 52) || (Card == 104))
	{
	  currCardNum = "skip";
	}
      else if ((Card == 53) || (Card == 105))
	{
	  currCardNum = "reverse";
	}
      else if ((Card == 54) || (Card == 106))
	{
	  currCardNum = "draw 2";
	}
    }
    
    /* if statement that checks for all wild cards */
  else if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55)
	   || (Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
    {
      //sets the current cards color equal to the card color that was played
      currCardColor = cardColorPlayed;
      
      /* if statement that checks for a normal wild card that only changes the color being played */
      if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55))
	{
	  currCardNum = "card";
	}
	  /* if statement that checks for a wild draw 4 card that changes the color and causes the next player to draw 4 cards */
      else if ((Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
	{
	  currCardNum = "draw 4";
	}
    }
    
  ++discardPosition; //adds one to the discard position
}

void StrToNum ()
{
    /* function that is called to find the corresponding integer value for the string value that needs to be found */
    
    /* if statement that checks if the card color is a red card */
  if (cardColorPlayed == "red")
    {
        /* the following if statements check for string values of "0" to "9" and
           also checks for the special cards "skip", "reverse", and "draw 2". once 
           of the following string values is true then the variable is set with the 
           corresponding integer value */
      if (cardNumPlayed == "0")
	{
	  cardPlayed1 = 0;
	}
      else if (cardNumPlayed == "1")
	{
	  cardPlayed1 = 1;
	  cardPlayed2 = 56;
	}
      else if (cardNumPlayed == "2")
	{
	  cardPlayed1 = 2;
	  cardPlayed2 = 57;
	}
      else if (cardNumPlayed == "3")
	{
	  cardPlayed1 = 3;
	  cardPlayed2 = 58;
	}
      else if (cardNumPlayed == "4")
	{
	  cardPlayed1 = 4;
	  cardPlayed2 = 59;
	}
      else if (cardNumPlayed == "5")
	{
	  cardPlayed1 = 5;
	  cardPlayed2 = 60;
	}
      else if (cardNumPlayed == "6")
	{
	  cardPlayed1 = 6;
	  cardPlayed2 = 61;
	}
      else if (cardNumPlayed == "7")
	{
	  cardPlayed1 = 7;
	  cardPlayed2 = 62;
	}
      else if (cardNumPlayed == "8")
	{
	  cardPlayed1 = 8;
	  cardPlayed2 = 63;
	}
      else if (cardNumPlayed == "9")
	{
	  cardPlayed1 = 9;
	  cardPlayed2 = 64;
	}
      else if (cardNumPlayed == "skip")
	{
	  cardPlayed1 = 10;
	  cardPlayed2 = 65;
	}
      else if (cardNumPlayed == "reverse")
	{
	  cardPlayed1 = 11;
	  cardPlayed2 = 66;
	}
      else if (cardNumPlayed == "draw")
	{
	      cardPlayed1 = 12;
	      cardPlayed2 = 67;
	}
      else if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
    }
    
    /* if statement that checks if the card color is a yellow card */
  else if (cardColorPlayed == "yellow")
    {
        /* the following if statements check for string values of "0" to "9" and
           also checks for the special cards "skip", "reverse", and "draw 2". once 
           of the following string values is true then the variable is set with the 
           corresponding integer value */
      if (cardNumPlayed == "0")
	{
	  cardPlayed1 = 14;
	}
      else if (cardNumPlayed == "1")
	{
	  cardPlayed1 = 15;
	  cardPlayed2 = 69;
	}
      else if (cardNumPlayed == "2")
	{
	  cardPlayed1 = 16;
	  cardPlayed2 = 70;
	}
      else if (cardNumPlayed == "3")
	{
	  cardPlayed1 = 17;
	  cardPlayed2 = 71;
	}
      else if (cardNumPlayed == "4")
	{
	  cardPlayed1 = 18;
	  cardPlayed2 = 72;
	}
      else if (cardNumPlayed == "5")
	{
	  cardPlayed1 = 19;
	  cardPlayed2 = 73;
	}
      else if (cardNumPlayed == "6")
	{
	  cardPlayed1 = 20;
	  cardPlayed2 = 74;
	}
      else if (cardNumPlayed == "7")
	{
	  cardPlayed1 = 21;
	  cardPlayed2 = 75;
	}
      else if (cardNumPlayed == "8")
	{
	  cardPlayed1 = 22;
	  cardPlayed2 = 76;
	}
      else if (cardNumPlayed == "9")
	{
	  cardPlayed1 = 23;
	  cardPlayed2 = 77;
	}
      else if (cardNumPlayed == "skip")
	{
	  cardPlayed1 = 24;
	  cardPlayed2 = 78;
	}
      else if (cardNumPlayed == "reverse")
	{
	  cardPlayed1 = 25;
	  cardPlayed2 = 79;
	}
      else if (cardNumPlayed == "draw")
	{
	  cardPlayed1 = 26;
	  cardPlayed2 = 80;
	}
      else if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
    }
    
    /* if statement that checks if the card color is a green card */
  else if (cardColorPlayed == "green")
    {
        /* the following if statements check for string values of "0" to "9" and
           also checks for the special cards "skip", "reverse", and "draw 2". once 
           of the following string values is true then the variable is set with the 
           corresponding integer value */
      if (cardNumPlayed == "0")
	{
	  cardPlayed1 = 28;
	}
      else if (cardNumPlayed == "1")
	{
	  cardPlayed1 = 29;
	  cardPlayed2 = 82;
	}
      else if (cardNumPlayed == "2")
	{
	  cardPlayed1 = 30;
	  cardPlayed2 = 83;
	}
      else if (cardNumPlayed == "3")
	{
	  cardPlayed1 = 31;
	  cardPlayed2 = 84;
	}
      else if (cardNumPlayed == "4")
	{
	  cardPlayed1 = 32;
	  cardPlayed2 = 85;
	}
      else if (cardNumPlayed == "5")
	{
	  cardPlayed1 = 33;
	  cardPlayed2 = 86;
	}
      else if (cardNumPlayed == "6")
	{
	  cardPlayed1 = 34;
	  cardPlayed2 = 87;
	}
      else if (cardNumPlayed == "7")
	{
	  cardPlayed1 = 35;
	  cardPlayed2 = 88;
	}
      else if (cardNumPlayed == "8")
	{
	  cardPlayed1 = 36;
	  cardPlayed2 = 89;
	}
      else if (cardNumPlayed == "9")
	{
	  cardPlayed1 = 37;
	  cardPlayed2 = 90;
	}
      else if (cardNumPlayed == "skip")
	{
	  cardPlayed1 = 38;
	  cardPlayed2 = 91;
	}
      else if (cardNumPlayed == "reverse")
	{
	  cardPlayed1 = 39;
	  cardPlayed2 = 92;
	}
      else if (cardNumPlayed == "draw")
	{
	      cardPlayed1 = 40;
	      cardPlayed2 = 93;
	}
      else if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
    }
    
    /* if statement that checks if the card color is a blue card */
  else if (cardColorPlayed == "blue")
    {
        /* the following if statements check for string values of "0" to "9" and
           also checks for the special cards "skip", "reverse", and "draw 2". once 
           of the following string values is true then the variable is set with the 
           corresponding integer value */
      if (cardNumPlayed == "0")
	{
	  cardPlayed1 = 42;
	}
      else if (cardNumPlayed == "1")
	{
	  cardPlayed1 = 43;
	  cardPlayed2 = 95;
	}
      else if (cardNumPlayed == "2")
	{
	  cardPlayed1 = 44;
	  cardPlayed2 = 96;
	}
      else if (cardNumPlayed == "3")
	{
	  cardPlayed1 = 45;
	  cardPlayed2 = 97;
	}
      else if (cardNumPlayed == "4")
	{
	  cardPlayed1 = 46;
	  cardPlayed2 = 98;
	}
      else if (cardNumPlayed == "5")
	{
	  cardPlayed1 = 47;
	  cardPlayed2 = 99;
	}
      else if (cardNumPlayed == "6")
	{
	  cardPlayed1 = 48;
	  cardPlayed2 = 100;
	}
      else if (cardNumPlayed == "7")
	{
	  cardPlayed1 = 49;
	  cardPlayed2 = 101;
	}
      else if (cardNumPlayed == "8")
	{
	  cardPlayed1 = 50;
	  cardPlayed2 = 102;
	}
      else if (cardNumPlayed == "9")
	{
	  cardPlayed1 = 51;
	  cardPlayed2 = 103;
	}
      else if (cardNumPlayed == "skip")
	{
	  cardPlayed1 = 52;
	  cardPlayed2 = 104;
	}
      else if (cardNumPlayed == "reverse")
	{
	  cardPlayed1 = 53;
	  cardPlayed2 = 105;
	}
      else if (cardNumPlayed == "draw")
	{
	      cardPlayed1 = 54;
	      cardPlayed2 = 106;
	}
      else if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
    }
    
    /* checks if the card that was played was a wild card */
  else if (cardColorPlayed == "wild")
    {
        /* if statement that checks if the card was a normal wild card */
      if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
	
	    /* if statement that checks if the card was a wild draw 4 */
      else if (cardNumPlayed == "draw")
	{
	  cardPlayed1 = 68;
	  cardPlayed2 = 81;
	  cardPlayed3 = 94;
	  cardPlayed4 = 107;
	}
    }
}

int GetPoints (vector < int >&player1, vector < int >&player2, vector < int >&player3, vector < int >&player4, vector < int >&player5, vector < int >&player6, vector < int >&player7, vector < int >&player8, vector < int >&player9, vector < int >&player10, int playerAmount)
{
    /* function that is called in order to get the total points for all the point values in each players hand */
    
  int totalPoints = 0;

    /* the following for loop will run for the number of players currently playing in the game */
  for (int i = 1; i <= playerAmount; ++i)
    {
        /* the following if statements check for value of i in terms of the current players points that is being
           totaled up */ 
      if (i == 1)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player1.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player1Out = true; 
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player1);
	    }
	}
      else if (i == 2)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player2.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player2Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player2);
	    }
	}
      else if (i == 3)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player3.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player3Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player3);
	    }
	}
      else if (i == 4)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player4.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player4Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player4);
	    }
	}
      else if (i == 5)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player5.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player5Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player5);
	    }
	}
      else if (i == 6)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player6.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player6Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player6);
	    }
	}
      else if (i == 7)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player7.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player7Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player7);
	    }
	}
      else if (i == 8)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player8.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player8Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player8);
	    }
	}
      else if (i == 9)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player9.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player9Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player9);
	    }
	}
      else if (i == 10)
	{
	    /* if statement that checks if the player went out by checking the size of the vector that represent his/her hand */
	  if (player10.size () == 0)
	    {
	        //if the current player did lay down all their cards than the following boolean expression is set to true
	      player10Out = true;
	    }
	  else
	    {
	        /* if the current player did not lay down all of their cards than the Points function is called to add up 
	           their points and then adds that current players total points to the groups total points */
	      totalPoints = totalPoints + Points (player10);
	    }
	}
    }

  return totalPoints; //returns the total points for all the players back to int main()
}

void PlayerTurn (vector < string >& playerName, vector < int >& currPlayer, vector < int >& Deck, vector < int >& Discard, int& playerTurn)
{
    /* The following function is called for each players turn and does a variety of things such as displaying the current players cards,
       allowing the player to play a card, checking for UNO, etc. */
       
    //variables needed inside the function
  bool cont = false;
  bool haveCard = false;
  bool cardPlayable = false;
  draw4 = false;
  skip = false;
  draw2 = false;
  int temp;
  string checkUno;

    //displays the name of the current players turn
  cout << "It is " << playerName.at (playerTurn - 1) << "'s turn." << endl;
    //calls the function WhatIsTopCard in order to display a string of what the top card is
  WhatIsTopCard (Discard);
    //displays what the top card is
  cout << "The top card is: " << currCardColor << " " << currCardNum << endl;
  
  /* the following if statement calls the PlayableCard function to check if there is a playable card in the players hand */
  if (PlayableCard (currPlayer, Discard) == false)
    {
        /* if there is not a playable card in the players hand than the following while loop will
           run until a playable card is drawn from the deck */
      while (PlayableCard (currPlayer, Discard) == false)
	{
	    //displays the player does not have a playable card and notifies them that a card was drawn
	  cout << "You do not have a playable card, you must draw a card." << endl;
	    //adds the top card in the deck to the current players hand
	  currPlayer.push_back (Deck.at (currDeckPosition));
	    //increases deck position by 1
	  ++currDeckPosition;
	}
    }
    
    /* once a playable card is drawn from the deck the following code displays the players hand by
       running a for loop 1 less than the size of the players hand in order to display all values in
       the player vector */
  cout << "Your cards are:" << endl;
  for (int i = 0; i < currPlayer.size(); ++i)
    {
        //the WhatIsPlayerCard function is called in order to print out a readable string for the user to understand
      WhatIsPlayerCard (currPlayer, i);
      cout << playerCardColor << " " << playerCardNum << "; ";
    }
  cout << endl; //prints out a new line
  
  /* the following while function will run based off of the users input choices
     that will check if the card played was playable and will check if the player has
     that card in their hand */
  while ((haveCard == false) || (cardPlayable == false))
    {
        //displays that the user has a playable card and then gets input from the user involving what card they want to play
      cout << "You have at least one playable card, what card would you like to play (lowercase letters only): ";
      cin >> cardColorPlayed >> cardNumPlayed;
      //the following if statements checks for "draw" meaning that there will be a 2 or 4 after that needs to be inputted as well
      if (cardNumPlayed == "draw")  {
          cin >> cardNumberPlayed;
      }
      //sets cont to false so that the while function will have to run and check things at least once
      cont = false;
      
      /* the following while loop will run until the users input is readable */
      while (cont == false)
	{
	    //if statement that checks the users input for a readable card color
	  if ((cardColorPlayed == "wild") || (cardColorPlayed == "red")
	      || (cardColorPlayed == "green") || (cardColorPlayed == "yellow")
	      || (cardColorPlayed == "blue"))
	    {
	      cont = true;
	    }
	    //if the user does not input a readable card color than the following code runs in order to get a new input from the user
	  else
	    {
	      cout << "Please enter only lowercase letters when selecting a card. What card would you like to play: ";
	      cin >> cardColorPlayed >> cardNumPlayed;
	      if (cardNumPlayed == "draw")  {
	          cin >> cardNumberPlayed;
	      }
	    }
	}
	/* once the user has inputted a card that is readable, the following function is called in oder to convert
	   the users string input to a integer value that can be used to check if the player has the card and checks
	   if the card is playable */
      StrToNum ();
      
      /* the following for loop will run for the current size of the players hand and check for multiple things each iteration */
      for (int i = 0; i < currPlayer.size(); ++i)
	{
	    /* if statement that checks if the card played is equal to the card in the current vector slot.
	       In other words, it is checking to see if the player has the card in their hand first */
	  if (currPlayer.at(i) == cardPlayed1)
	    {
	        /* if statement that checks the current card color and number to the card that was played, ultimately checking if the card that was played was playable */
	      if ((cardColorPlayed == currCardColor) || (cardNumPlayed == currCardNum) || (cardColorPlayed == "wild") || ((currCardNum == "draw 2") && (cardNumPlayed == "draw"))) {
	        /* if statement that will only run if the current player has more than 1 card in their hand */
	        if (currPlayer.size() > 1)  {
	            //sets boolean expressions to true for if the card is in the players hand and for if the card is playable
	            haveCard = true;
	            cardPlayable = true;
	            //sets the top card in the discard pile to the card that was played
	            Discard.push_back (cardPlayed1);
	            //sets a temporary integer value with the last value in the players hand
	            temp = currPlayer.at (currPlayer.size () - 1);
	            //sets the last value in the players hand with the current value being checked
	            currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	            //sets the current vector position with previously the last posistions value
	            currPlayer.at (i) = temp;
	            //takes away the last position in the current players vector which is equal to the card that was played
	            currPlayer.pop_back ();
	            //breaks the loop
	            break;
	        }
	        /* else statement that will run if the player is playing their last card */
	        else    {
	            haveCard = true;
	            cardPlayable = true;
	            currPlayer.resize(0);
	            break;
	        }
	      }
	      /* else statement that will run if the card chose is not a playable card */
	      else  {
	          cout << "The card that you have chosen is not playable." << endl;
	          haveCard = true;
	      }
	    }
	    /* if statement that checks if the card played is equal to the card in the current vector slot */
	  else if (currPlayer.at (i) == cardPlayed2)
	    {
	        /* if statement that checks the current card color and number to the card that was played, ultimately checking if the card that was played was playable */
	      if ((cardColorPlayed == currCardColor) || (cardNumPlayed == currCardNum) || (cardColorPlayed == "wild") || ((currCardNum == "draw 2") && (cardNumPlayed == "draw"))) {
	          /* if statement that will only run if the current player has more than 1 card in their hand */
	        if (currPlayer.size() > 1)  {
	            //sets boolean expressions to true for if the card is in the players hand and for if the card is playable
	            haveCard = true;
	            cardPlayable = true;
	            //sets the top card in the discard pile to the card that was played
	            Discard.push_back (cardPlayed2);
	            //sets a temporary integer value with the last value in the players hand
	            temp = currPlayer.at (currPlayer.size () - 1);
	            //sets the last value in the players hand with the current value being checked
	            currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	            //sets the current vector position with previously the last posistions value
	            currPlayer.at (i) = temp;
	            //takes away the last position in the current players vector which is equal to the card that was played
	            currPlayer.pop_back ();
	            //breaks the loop
	            break;
	        }
	        /* else statement that will run if the player is playing their last card */
	        else    {
	            haveCard = true;
	            cardPlayable = true;
	            currPlayer.resize(0);
	            break;
	        }
	      }
	      /* else statement that will run if the card chose is not a playable card */
	      else  {
	          cout << "The card that you have chosen is not playable." << endl;
	          haveCard = true;
	      }
	    }
	    /* if statement that checks if the card played is equal to the card in the current vector slot */
	  else if (currPlayer.at (i) == cardPlayed3)
	    {
	        /* if statement that checks the current card color and number to the card that was played, ultimately checking if the card that was played was playable */
	      if ((cardColorPlayed == currCardColor) || (cardNumPlayed == currCardNum) || (cardColorPlayed == "wild") || ((currCardNum == "draw 2") && (cardNumPlayed == "draw"))) {
	          /* if statement that will only run if the current player has more than 1 card in their hand */
	        if (currPlayer.size() > 1)  {
	            //sets boolean expressions to true for if the card is in the players hand and for if the card is playable
	            haveCard = true;
	            cardPlayable = true;
	            //sets the top card in the discard pile to the card that was played
	            Discard.push_back (cardPlayed3);
	            //sets a temporary integer value with the last value in the players hand
	            temp = currPlayer.at (currPlayer.size () - 1);
	            //sets the last value in the players hand with the current value being checked
	            currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	            //sets the current vector position with previously the last posistions value
	            currPlayer.at (i) = temp;
	            //takes away the last position in the current players vector which is equal to the card that was played
	            currPlayer.pop_back ();
	            //breaks the loop
	            break;
	        }
	        /* else statement that will run if the player is playing their last card */
	        else    {
	            haveCard = true;
	            cardPlayable = true;
	            currPlayer.resize(0);
	            break;
	        }
	      }
	      /* else statement that will run if the card chose is not a playable card */
	      else  {
	          cout << "The card that you have chosen is not playable." << endl;
	          haveCard = true;
	      }
	    }
	    /* if statement that checks if the card played is equal to the card in the current vector slot */
	  else if (currPlayer.at (i) == cardPlayed4)
	    {
	        /* if statement that checks the current card color and number to the card that was played, ultimately checking if the card that was played was playable */
	      if ((cardColorPlayed == currCardColor) || (cardNumPlayed == currCardNum) || (cardColorPlayed == "wild") || ((currCardNum == "draw 2") && (cardNumPlayed == "draw"))) {
	          /* if statement that will only run if the current player has more than 1 card in their hand */
	        if (currPlayer.size() > 1)  {
	            //sets boolean expressions to true for if the card is in the players hand and for if the card is playable
	            haveCard = true;
	            cardPlayable = true;
	            //sets the top card in the discard pile to the card that was played
	            Discard.push_back (cardPlayed4);
	            //sets a temporary integer value with the last value in the players hand
	            temp = currPlayer.at (currPlayer.size () - 1);
	            //sets the last value in the players hand with the current value being checked
	            currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	            //sets the current vector position with previously the last posistions value
	            currPlayer.at (i) = temp;
	            //takes away the last position in the current players vector which is equal to the card that was played
	            currPlayer.pop_back ();
	            //breaks the loop
	            break;
	        }
	        /* else statement that will run if the player is playing their last card */
	        else    {
	            haveCard = true;
	            cardPlayable = true;
	            currPlayer.resize(0);
	            break;
	        }
	      }
	      /* else statement that will run if the card chose is not a playable card */
	      else  {
	          cout << "The card that you have chosen is not playable." << endl;
	          haveCard = true;
	      }
	    }
	}
	/* if statement that will run if the player does not have the card that they chose to play */
      if (haveCard == false)
	{
	  cout << "You do not have that card to play. Please choose a card in your hand." << endl;
	}
    }
    //once the card has been checked and it is a playable card and the user has that card then the card is displayed to the user
  cout << "You played a " << cardColorPlayed << " " << cardNumPlayed;
  //if statement that will run if a draw 2 or draw 4 is played so that it will display the number as well
  if (cardNumPlayed == "draw")  {
      cout << " " << cardNumberPlayed << "." << endl;
  }
  else  {
      cout << "." << endl;
  }
    /* if statement that will run when a reverse card is played */
 if (cardNumPlayed == "reverse")    {
     /* if statements that makes reverse go from false to true or true to false */
      if (reverse == false)
	{
	  reverse = true;
	}
      else if (reverse == true)
	{
	  reverse = false;
	}
  }
  /* if statement that will run when a wild card or wild draw 4 card is played */
 else if (cardColorPlayed == "wild")
    {
        //asks the user for what color they would like to change to
      cout << "What color would you like to change to (red, green, yellow, or blue): ";
      cin >> cardColorPlayed;
      //sets boolean to false so that the while loop will run at least once
      cont = false;
      //while loop that will run to make sure the user inputs a readable color
      while (cont == false)
	  {
	      //if statement that will run if the user correctly puts in one of the colors
	  if ((cardColorPlayed == "red") || (cardColorPlayed == "green") || (cardColorPlayed == "yellow") || (cardColorPlayed == "blue"))
	    {
	      cont = true;
	    }
	    //if the user does not input a color that is readable then the following is outputted and the while loop restarts
	  else
	    {
	      cout << "Please enter only lowercase letters when selecting a color. What color would you like to change to (red, green, yellow, or blue): ";
	      cin >> cardColorPlayed;
	    }
	  }
	  //if statement that checks if the wild card is a wild draw 4 and if so then sets the boolean variable to true
      if (cardNumPlayed == "draw")
	  {
	    draw4 = true;
	  }
    }
    /* if a skip card is played than the global boolean variable skip is set to true */
 else if (cardNumPlayed == "skip")
    {
        skip = true;
    }
    /* if a draw 2 card is played than the global boolean variable draw2 is set to true */
 else if (cardNumPlayed == "draw")
    {
        draw2 = true;
    }

    /* the following if statement checks for UNO by checking if the size of the current players hand is 1 */
  if (currPlayer.size () == 1)
    {
        //displays that the user has one card and prompts the user to type uno
      cout << "You have only one card, type \"UNO\", or draw 2 cards: ";
      cin >> checkUno;
      //if the user types UNO or uno then the if statement will run that displays the current players name has uno 
      if ((checkUno == "UNO") || (checkUno == "uno"))
	{
	  cout << playerName.at (playerTurn - 1) << " has UNO!" << endl;
	}
	//if the user does not type uno then 2 cards are added to their hand
      else
	{
	  cout << "You did not say \"UNO\", 2 cards have been added to your hand." << endl;
	  currPlayer.push_back (Deck.at (currDeckPosition));
	  ++currDeckPosition;
	  currPlayer.push_back (Deck.at (currDeckPosition));
	  ++currDeckPosition;
	}
    }
    
    /* if the current players size is 0 and they have laid all their cards down then the boolean expressions
       stating that a player is out is set to true and an output shows the player that went out */
  if (currPlayer.size () == 0)
    {
      playerIsOut = true;
      cout << playerName.at (playerTurn - 1) << " has gone out!" << endl;
    }
}

int main ()
{
    //vectors for the deck and discard pile along with a shuffle vector used to shuffle the cards in the deck
  vector < int >Deck (108);
  vector < int >Shuffle (108);
  vector < int >Discard (1);
  /*
     numbers 0-9 are red cards 0-9; 10-12 are red skip, red reverse, and red draw 2 in that order
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
   
   //vectors for each possible player but only the ones chosen by the user will be used
  vector < int >player1 (7);
  vector < int >player2 (7);
  vector < int >player3 (7);
  vector < int >player4 (7);
  vector < int >player5 (7);
  vector < int >player6 (7);
  vector < int >player7 (7);
  vector < int >player8 (7);
  vector < int >player9 (7);
  vector < int >player10 (7);

  //variables
  int i = 0;
  int counter = 0;
  int playerAmount;
  bool playerNum = false;
  int shuffleDeck = rand () % 108;
  bool playerBool1;
  bool playerBool2;
  bool playerBool3;
  bool playerBool4;
  bool playerBool5;
  bool playerBool6;
  bool playerBool7;
  bool playerBool8;
  bool playerBool9;
  bool playerBool10;
  bool wildCard = true;
  int playerTurn = 1;
  int player1Points = 0;
  int player2Points = 0;
  int player3Points = 0;
  int player4Points = 0;
  int player5Points = 0;
  int player6Points = 0;
  int player7Points = 0;
  int player8Points = 0;
  int player9Points = 0;
  int player10Points = 0;

  //output for rules of the game
  cout << "Welcome to UNO!\nTo start, lets go over the rules..." << endl;
  cout <<
    "The game UNO is meant for 2 to 10 players, and the goal of the game is to be the first person to reach 500 points."
    << endl;
  cout <<
    "Each player starts out with 7 cards. Each card will have a specific color like red, yellow, blue, or green, and a number"
    << endl;
  cout <<
    "that is from 0-9 unless it is a special card. There are 5 different special cards that can be played. A skip card can only"
    << endl;
  cout <<
    "be one color and when played, it will skip the turn of the next player. A reverse card reverses the direction of play."
    << endl;
  cout <<
    "This card can only be played on a matching color or another reverse card. The draw 2 card causes the next person to draw 2"
    << endl;
  cout <<
    "cards from the deck and forfeit his/her turn. A wild card allows the player to change the  color of play. This card can be"
    << endl;
  cout <<
    "played at any time during your turn, even if you have another playable card. Likewise, the wild draw 4 card allows you to pick"
    << endl;
  cout <<
    "the color and the next player must draw 4 cards and forfeit his/her turn. To play, match the top card on the discard pile by either"
    << endl;
  cout <<
    "number, color, or word. If you don't have anything that matches, you must pick a card from the draw pile. If you draw a card that"
    << endl;
  cout <<
    "can be played, play it. Otherwise, play moves on to the next player. When a player has only one card left, they must say \"UNO\"."
    << endl;
  cout <<
    "The first player to discard all of his/her cards gets the points. The points come from the sum of each card in every players hand."
    << endl << endl;
  cout << "The points are as follows:" << endl;
  cout << "All Number Cards (0-9):\tFace Value" << endl;
  cout << "Draw 2 Cards:\t\t20 Points" << endl;
  cout << "Reverse Cards:\t\t20 Points" << endl;
  cout << "Skip Cards:\t\t20 Points" << endl;
  cout << "Wild Cards:\t\t50 Points" << endl;
  cout << "Wild Draw 4 Cards:\t50 Points" << endl;
  cout << "Now have fun!" << endl << endl;

  //getting input for number of players
  cout << "How many players will be playing: ";
  cin >> playerAmount;
  //while loop that checks to make sure the user chooses between 2 and 10 players
  while (playerNum == false)
    {
      if ((playerAmount < 2) || (playerAmount > 10))
	{
	  cout << "\nOnly 2-10 players are allowed to play." << endl;
	  cout << "How many players will be playing: ";
	  cin >> playerAmount;
	}
      else
	{
	  playerNum = true;
	}
    }

  //getting input for names of players
  vector < string > playerName (playerAmount);	//vector made to store names
  string plyrName;
  //for loop that will run for amount of players chosen to play
  for (i = 1; i <= playerAmount; ++i)
    {
      cout << "Please enter player " << i << "'s name: ";	//ask user for their name
      cin >> plyrName;		//get user input
      playerName.at (i - 1) = plyrName;	//each name entered goes into the vector (element 0 is player 1)
    }
    
    /* the following while loop will run a majority of the code until one of the players gets 500 points or more */
  while ((player1Points < 500) && (player2Points < 500)
	 && (player3Points < 500) && (player4Points < 500)
	 && (player5Points < 500) && (player6Points < 500)
	 && (player7Points < 500) && (player8Points < 500)
	 && (player9Points < 500) && (player10Points < 500))
    {
      //while loop that will run if there is a wild card as the top card on the deck
      while (wildCard == true)
	{
	    //for loop that will run 108 times in order to populate the shuffle vector with values from 0-107
	  for (i = 0; i < Shuffle.size (); ++i)
	    {
	      Shuffle.at (i) = i;
	    }
	    //the following for loop will run 108 times in order to populate the vector
	  for (i = 0; i < Deck.size (); ++i)
	    {
	        //the following while loop checks the position of the shuffle vector for the value 108 which means it has already been used
	      while (Shuffle.at (shuffleDeck) == 108)
		{
		    //if the value at the current position of the shuffle vector is 108 then a new value is required and a random number is used
		  shuffleDeck = rand () % 108;
		}
		//once a value is found from the shuffle vector that has not been used yet that value is then added to the deck and the current positon is set to 108
	      Deck.at (i) = Shuffle.at (shuffleDeck);
	      Shuffle.at (shuffleDeck) = 108;
	    }
	    //the if statement checks if a wild card is the top card and if it is then the boolean expression is true and the while loop restarts
	  if ((Deck.at (0) == 13) || (Deck.at (0) == 27)
	      || (Deck.at (0) == 41) || (Deck.at (0) == 55)
	      || (Deck.at (0) == 68) || (Deck.at (0) == 81)
	      || (Deck.at (0) == 94) || (Deck.at (0) == 107))
	    {
	      wildCard = true;
	    }
	    //if the top card in the deck is not a wild card then the boolean is set to false and the code continues
	  else
	    {
	      wildCard = false;
	    }
	}

      //the following for loop runs for the amount of players playing and is used to populate the vectors later on
      for (i = 1; i <= playerAmount; ++i)
	{
	    /* the following if statements will run if that player will be playing */
	  if (i == 1)
	    {
	      playerBool1 = true;
	    }
	  if (i == 2)
	    {
	      playerBool2 = true;
	    }
	  if (i == 3)
	    {
	      playerBool3 = true;
	    }
	  if (i == 4)
	    {
	      playerBool4 = true;
	    }
	  if (i == 5)
	    {
	      playerBool5 = true;
	    }
	  if (i == 6)
	    {
	      playerBool6 = true;
	    }
	  if (i == 7)
	    {
	      playerBool7 = true;
	    }
	  if (i == 8)
	    {
	      playerBool8 = true;
	    }
	  if (i == 9)
	    {
	      playerBool9 = true;
	    }
	  if (i == 10)
	    {
	      playerBool10 = true;
	    }
	}

    /* the following if statements will run for the players that are playing in the game and will only populate those vectors */
      counter = 0;
      if (playerBool1 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player1.size (); ++i)
	    {
	      player1.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 1;
      if (playerBool2 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player2.size (); ++i)
	    {
	      player2.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 2;
      if (playerBool3 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player3.size (); ++i)
	    {
	      player3.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 3;
      if (playerBool4 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player4.size (); ++i)
	    {
	      player4.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 4;
      if (playerBool5 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player5.size (); ++i)
	    {
	      player5.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 5;
      if (playerBool6 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player6.size (); ++i)
	    {
	      player6.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 6;
      if (playerBool7 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player7.size (); ++i)
	    {
	      player7.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 7;
      if (playerBool8 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player8.size (); ++i)
	    {
	      player8.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 8;
      if (playerBool9 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player9.size (); ++i)
	    {
	      player9.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 9;
      if (playerBool10 == true)
	{
	    //the following for loop will run 7 times and will add cards to the vector from the deck
	  for (i = 0; i < player10.size (); ++i)
	    {
	      player10.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
	
	/* the following code sets the current deck position to the last card that was drawn in the deck and then sets
	   the discard to the top card on the deck */
      currDeckPosition = playerAmount * 7;
      Discard.at (0) = Deck.at (currDeckPosition);
      cout << endl;

      //while loop that will run until a player lays down all the cards in their hand
      while (playerIsOut == false)
	{
	    //the following if statement will run if the first player needs to be skipped
	      if (playerSkip == true)
		{
		    //sets playerTurn to 2 and resets the boolean back to false
		    playerTurn = 2;
		    playerSkip = false;
		}
		
		//sets i equal to playerTurn
	      i = playerTurn;
	      
	    /* the following while loop will run while i is less than or equal to the number of players
	       this is for play going in clockwise direction */
	      while(i <= playerAmount)
		{
		    //resets playerTurn to 1
		    playerTurn = 1;
		    cout << endl;
		    //i is equal to current players turn, therfore the following if statements check for whose turn it is
		  if (i == 1)
		    {
		        //the following calls the PlayerTurn function using player 1's hand
		      PlayerTurn (playerName, player1, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = playerAmount;
			  break ;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player2, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			  DrawFour (i, playerAmount, player1, player2, Deck);
			}
		    }
		  else if (i == 2)
		    {
		        //the following calls the PlayerTurn function using player 2's hand
		      PlayerTurn (playerName, player2, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player3, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			  DrawFour (i, playerAmount, player1, player3, Deck);
		    }
		    }
		  else if (i == 3)
		    {
		        //the following calls the PlayerTurn function using player 3's hand
		      PlayerTurn (playerName, player3, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player4, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			  DrawFour (i, playerAmount, player1, player4, Deck);
		    }
		    }
		  else if (i == 4)
		    {
		        //the following calls the PlayerTurn function using player 4's hand
		      PlayerTurn (playerName, player4, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player5, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player5, Deck);
		    }
		    }
		  else if (i == 5)
		    {
		        //the following calls the PlayerTurn function using player 5's hand
		      PlayerTurn (playerName, player5, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player6, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player6, Deck);
		    }
		    }
		  else if (i == 6)
		    {
		        //the following calls the PlayerTurn function using player 6's hand
		      PlayerTurn (playerName, player6, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player7, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player7, Deck);
		    }
		    }
		  else if (i == 7)
		    {
		        //the following calls the PlayerTurn function using player 7's hand
		      PlayerTurn (playerName, player7, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player8, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player8, Deck);
		    }
		    }
		  else if (i == 8)
		    {
		        //the following calls the PlayerTurn function using player 8's hand
		      PlayerTurn (playerName, player8, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player9, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player9, Deck);
		    }
		    }
		  else if (i == 9)
		    {
		        //the following calls the PlayerTurn function using player 9's hand
		      PlayerTurn (playerName, player9, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player10, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player10, Deck);
		    }
		    }
		  else if (i == 10)
		    {
		        //the following calls the PlayerTurn function using player 10's hand
		      PlayerTurn (playerName, player10, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to the number of
		         players and then break out of the while loop */
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the last players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the last players turn then i is increased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 1;
			      skip = false;
			    }
			}
			
			/* the following statement checks if a draw two card was played and if it was then the DrawTwo function is called */
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player2, Deck);
			}
			
			/* the following statement checks if a draw four card was played and if it was then the DrawFour function is called */
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player2, Deck);
		    }
		}
		  ++i; //adds one to i
	    }
	    
	    //the following if statement will run if the last player needs to be skipped  
	      if (playerSkip == true)
		{
		    //sets playerTurn equal to one less than the number of players in the game and then resets the boolean expression
		    playerTurn = playerAmount - 1;
		    playerSkip = false;
		}
		
	  //sets i equal to playerTurn
	    i = playerTurn;
	    
	  /* the following while loop will run while i is greater than or equal to the number of players
	     this is for the play going in counter clockwise direction */
	    while(i >= playerAmount)
		{
		  if (i == 1)
		    {
		        //the following calls the PlayerTurn function using player 1's hand
		      PlayerTurn (playerName, player1, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is true and will set playerturn equal to i plus one 
		      and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//if a draw 2 card was played then the following if statement will run
		      if (draw2 == true)
			{
			    /* the following if statements check and run for the amount of players in the game
			       however many players are playing determines who gets the two cards */
			      if (playerAmount == 2)
				{
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 3)
				{
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 4)
				{
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 5)
				{
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 6)
				{
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 7)
				{
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 8)
				{
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 9)
				{
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 10)
				{
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
				
				//once the cards are given to the last player, player skip is set to true and draw2 is reset to false
			      playerSkip = true;
			      draw2 = false;
			}
			
			//if a draw 4 card was played then the following if statement will run
		      if (draw4 == true)
			{
			    /* the following if statements check and run for the amount of players in the game
			       however many players are playing determines who gets the four cards */
			      if (playerAmount == 2)
				{
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 3)
				{
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 4)
				{
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 5)
				{
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 6)
				{
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 7)
				{
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 8)
				{
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 9)
				{
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 10)
				{
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.at (currDeckPosition));
				  ++currDeckPosition;
				}
				
				//once the cards are given to the last player, player skip is set to true and draw4 is reset to false
			      playerSkip = true;
			      draw4 = false;
			}
		}
		  else if (i == 2)
		    {
		        //the following calls the PlayerTurn function using player 2's hand
		      PlayerTurn (playerName, player2, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = playerAmount + 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = playerAmount + 1;
			  draw4 = false;
			}
		    }
		  else if (i == 3)
		    {
		        //the following calls the PlayerTurn function using player 3's hand
		      PlayerTurn (playerName, player3, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 4)
		    {
		        //the following calls the PlayerTurn function using player 4's hand
		      PlayerTurn (playerName, player4, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 5)
		    {
		        //the following calls the PlayerTurn function using player 5's hand
		      PlayerTurn (playerName, player5, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 6)
		    {
		        //the following calls the PlayerTurn function using player 6's hand
		      PlayerTurn (playerName, player6, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 7)
		    {
		        //the following calls the PlayerTurn function using player 7's hand
		      PlayerTurn (playerName, player7, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 8)
		    {
		        //the following calls the PlayerTurn function using player 8's hand
		      PlayerTurn (playerName, player8, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 9)
		    {
		        //the following calls the PlayerTurn function using player 9's hand
		      PlayerTurn (playerName, player9, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 10)
		    {
		        //the following calls the PlayerTurn function using player 10's hand
		      PlayerTurn (playerName, player10, Deck, Discard, i);
		      
		      /* the following statement checks if reverse is false and will set playerturn equal to i plus one
		         and then break out of the while loop */
		      if (reverse == false)
			{
			  playerTurn = i + 1;
			  break;
			}
			
			/* the following statement checks if skip is true,
			   if skip is true and it is currently the first players turn then playerSkip is set to true and skip is reset to false,
			   if it is not the first players turn then i is decreased by 1 and skip is reset to false */
		      if (skip == true)
			{
			  if (i == 1)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      --i;
			      skip = false;
			    }
			}
			
			//the following if statement checks to see if a draw 2 card was played and if it was then 2 cards is given to the next player and then the player is skipped
		      if (draw2 == true)
			{
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
			
			//the following if statement checks to see if a draw 4 card was played and if it was then 4 cards is given to the next player and then the player is skipped
		      if (draw4 == true)
			{
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  --i; //i is decreased by one
		}
	}
	
	//sets counter equal to the total points gotten from GetPoints and also checks which player went out
      counter = GetPoints (player1, player2, player3, player4, player5, player6,
		   player7, player8, player9, player10, playerAmount);
    //resets the counter to 0
      counter = 0;
    /* the following if statements check to see which player laid down all of his/her cards
       whichever player went out gets the points from the GetPoints function */
      if (player1Out == true)
	{
	  player1Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player2Out == true)
	{
	  player2Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player3Out == true)
	{
	  player3Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player4Out == true)
	{
	  player4Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player5Out == true)
	{
	  player5Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player6Out == true)
	{
	  player6Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player7Out == true)
	{
	  player7Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player8Out == true)
	{
	  player8Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player9Out == true)
	{
	  player9Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
      else if (player10Out == true)
	{
	  player10Points =
	    GetPoints (player1, player2, player3, player4, player5, player6,
		       player7, player8, player9, player10, playerAmount);
	}
    }	//bracket for end of while loop that checks players points

  cout << "Game Over";

  return 0;
}

