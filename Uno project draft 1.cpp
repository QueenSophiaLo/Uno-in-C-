#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

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
bool reverse = false;
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

void WhatIsPlayerCard (vector < int >&currPlayer, int i)
{
  int Card = currPlayer.at (i);

  if (((Card >= 0) && (Card <= 12)) || ((Card >= 56) && (Card <= 67)))
    {				//red cards
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
    {				//yellow cards
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
    {				//green cards
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
    {				//blue cards
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
    {				//wild cards
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

void DrawTwo (int &i, int playerAmount, vector < int >&player1, vector < int >&nextPlayer, vector < int >&Deck)
{
  if (i == playerAmount)
    {
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      player1.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      playerSkip = true;
      draw2 = false;
    }
  else
    {
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = i + 2;
      draw2 = false;
    }
}

void DrawFour (int &i, int playerAmount, vector < int >&player1, vector < int >&nextPlayer, vector < int >&Deck)
{
  if (i == playerAmount)
    {
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
  else
    {
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      nextPlayer.push_back (Deck.at (currDeckPosition));
      ++currDeckPosition;
      i = i + 2;
      draw4 = false;
    }
}

int Points (vector < int >currPlayer)
{
  int points = 0;

  for (int j = 0; j < currPlayer.size (); ++j)
    {
      if ((currPlayer.at (j) == 1) || (currPlayer.at (j) == 15)
	  || (currPlayer.at (j) == 29) || (currPlayer.at (j) == 43)
	  || (currPlayer.at (j) == 56) || (currPlayer.at (j) == 69)
	  || (currPlayer.at (j) == 82) || (currPlayer.at (j) == 95))
	{
	  points = points + 1;
	}
      else if ((currPlayer.at (j) == 2) || (currPlayer.at (j) == 16)
	       || (currPlayer.at (j) == 30) || (currPlayer.at (j) == 44)
	       || (currPlayer.at (j) == 57) || (currPlayer.at (j) == 70)
	       || (currPlayer.at (j) == 83) || (currPlayer.at (j) == 96))
	{
	  points = points + 2;
	}
      else if ((currPlayer.at (j) == 3) || (currPlayer.at (j) == 17)
	       || (currPlayer.at (j) == 31) || (currPlayer.at (j) == 45)
	       || (currPlayer.at (j) == 58) || (currPlayer.at (j) == 71)
	       || (currPlayer.at (j) == 84) || (currPlayer.at (j) == 97))
	{
	  points = points + 3;
	}
      else if ((currPlayer.at (j) == 4) || (currPlayer.at (j) == 18)
	       || (currPlayer.at (j) == 32) || (currPlayer.at (j) == 46)
	       || (currPlayer.at (j) == 59) || (currPlayer.at (j) == 72)
	       || (currPlayer.at (j) == 85) || (currPlayer.at (j) == 98))
	{
	  points = points + 4;
	}
      else if ((currPlayer.at (j) == 5) || (currPlayer.at (j) == 19)
	       || (currPlayer.at (j) == 33) || (currPlayer.at (j) == 47)
	       || (currPlayer.at (j) == 60) || (currPlayer.at (j) == 73)
	       || (currPlayer.at (j) == 86) || (currPlayer.at (j) == 99))
	{
	  points = points + 5;
	}
      else if ((currPlayer.at (j) == 6) || (currPlayer.at (j) == 20)
	       || (currPlayer.at (j) == 34) || (currPlayer.at (j) == 48)
	       || (currPlayer.at (j) == 61) || (currPlayer.at (j) == 74)
	       || (currPlayer.at (j) == 87) || (currPlayer.at (j) == 100))
	{
	  points = points + 6;
	}
      else if ((currPlayer.at (j) == 7) || (currPlayer.at (j) == 21)
	       || (currPlayer.at (j) == 35) || (currPlayer.at (j) == 49)
	       || (currPlayer.at (j) == 62) || (currPlayer.at (j) == 75)
	       || (currPlayer.at (j) == 88) || (currPlayer.at (j) == 101))
	{
	  points = points + 7;
	}
      else if ((currPlayer.at (j) == 8) || (currPlayer.at (j) == 22)
	       || (currPlayer.at (j) == 36) || (currPlayer.at (j) == 50)
	       || (currPlayer.at (j) == 63) || (currPlayer.at (j) == 76)
	       || (currPlayer.at (j) == 89) || (currPlayer.at (j) == 102))
	{
	  points = points + 8;
	}
      else if ((currPlayer.at (j) == 9) || (currPlayer.at (j) == 23)
	       || (currPlayer.at (j) == 37) || (currPlayer.at (j) == 51)
	       || (currPlayer.at (j) == 64) || (currPlayer.at (j) == 77)
	       || (currPlayer.at (j) == 90) || (currPlayer.at (j) == 103))
	{
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
	  points = points + 20;
	}
      else if ((currPlayer.at (j) == 13) || (currPlayer.at (j) == 27)
	       || (currPlayer.at (j) == 41) || (currPlayer.at (j) == 55)
	       || (currPlayer.at (j) == 68) || (currPlayer.at (j) == 81)
	       || (currPlayer.at (j) == 94) || (currPlayer.at (j) == 107))
	{
	  points = points + 50;
	}
    }

  return points;
}

bool PlayableCard (vector < int >&currPlayer, vector < int >&Discard)
{
  bool playableCard;

  for (int i = 0; i < currPlayer.size (); ++i)
    {
      WhatIsPlayerCard (currPlayer, i);
      if ((playerCardColor == currCardColor) || (playerCardNum == currCardNum)
	  || (playerCardColor == "wild"))
	{
	  playableCard = true;
	}
    }

  return playableCard;
}

void WhatIsTopCard (vector < int >&Discard)
{
  int Card = Discard.at (discardPosition);

  if (((Card >= 0) && (Card <= 12)) || ((Card >= 56) && (Card <= 67)))
    {				//red cards
      currCardColor = "red";
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
  else if (((Card >= 14) && (Card <= 26)) || ((Card >= 69) && (Card <= 80)))
    {				//yellow cards
      currCardColor = "yellow";
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
  else if (((Card >= 28) && (Card <= 40)) || ((Card >= 82) && (Card <= 93)))
    {				//green cards
      currCardColor = "green";
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
  else if (((Card >= 42) && (Card <= 54)) || ((Card >= 95) && (Card <= 106)))
    {				//blue cards
      currCardColor = "blue";
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
  else if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55)
	   || (Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
    {
      currCardColor = cardColorPlayed;
      if ((Card == 13) || (Card == 27) || (Card == 41) || (Card == 55))
	{
	  currCardNum = "card";
	}
      else if ((Card == 68) || (Card == 81) || (Card == 94) || (Card == 107))
	{
	  currCardNum = "draw 4";
	}
    }
  ++discardPosition;
}

void StrToNum ()
{
  if (cardColorPlayed == "red")
    {
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
  else if (cardColorPlayed == "yellow")
    {
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
  else if (cardColorPlayed == "green")
    {
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
  else if (cardColorPlayed == "blue")
    {
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
  else if (cardColorPlayed == "wild")
    {
      if (cardNumPlayed == "card")
	{
	  cardPlayed1 = 13;
	  cardPlayed2 = 27;
	  cardPlayed3 = 41;
	  cardPlayed4 = 55;
	}
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
  int totalPoints = 0;

  for (int i = 1; i <= playerAmount; ++i)
    {
      if (i == 1)
	{
	  if (player1.size () == 0)
	    {
	      player1Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player1);
	    }
	}
      else if (i == 2)
	{
	  if (player2.size () == 0)
	    {
	      player2Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player2);
	    }
	}
      else if (i == 3)
	{
	  if (player3.size () == 0)
	    {
	      player3Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player3);
	    }
	}
      else if (i == 4)
	{
	  if (player4.size () == 0)
	    {
	      player4Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player4);
	    }
	}
      else if (i == 5)
	{
	  if (player5.size () == 0)
	    {
	      player5Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player5);
	    }
	}
      else if (i == 6)
	{
	  if (player6.size () == 0)
	    {
	      player6Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player6);
	    }
	}
      else if (i == 7)
	{
	  if (player7.size () == 0)
	    {
	      player7Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player7);
	    }
	}
      else if (i == 8)
	{
	  if (player8.size () == 0)
	    {
	      player8Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player8);
	    }
	}
      else if (i == 9)
	{
	  if (player9.size () == 0)
	    {
	      player9Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player9);
	    }
	}
      else if (i == 10)
	{
	  if (player10.size () == 0)
	    {
	      player10Out = true;
	    }
	  else
	    {
	      totalPoints = totalPoints + Points (player10);
	    }
	}
    }

  return totalPoints;
}

void PlayerTurn (vector < string > &playerName, vector < int >&currPlayer, vector < int >&Deck, vector < int >&Discard, int playerTurn)
{
  bool cont = false;
  bool haveCard = false;
  draw4 = false;
  skip = false;
  reverse = false;
  draw2 = false;
  int temp;
  string checkUno;

  cout << "It is " << playerName.at (playerTurn - 1) << "'s turn." << endl;
  WhatIsTopCard (Discard);
  cout << "The top card is: " << currCardColor << " " << currCardNum << endl;
  if (PlayableCard (currPlayer, Discard) == false)
    {
      while (PlayableCard (currPlayer, Discard) == false)
	{
	  cout << "You do not have a playable card, you must draw a card." <<
	    endl;
	  currPlayer.push_back (Deck.at (currDeckPosition));
	  ++currDeckPosition;
	}
    }
  cout << "Your cards are:" << endl;
  for (int i = 0; i < currPlayer.size (); ++i)
    {
      WhatIsPlayerCard (currPlayer, i);
      cout << playerCardColor << " " << playerCardNum << "; ";
    }
  cout << endl;
  while (haveCard == false)
    {
      cout <<
	"You have at least one playable card, what card would you like to play (lowercase letters only): ";
      cin >> cardColorPlayed >> cardNumPlayed;
      if (cardNumPlayed == "draw")  {
          cin >> cardNumberPlayed;
      }
      cont = false;
      while (cont == false)
	{
	  if ((cardColorPlayed == "wild") || (cardColorPlayed == "red")
	      || (cardColorPlayed == "green") || (cardColorPlayed == "yellow")
	      || (cardColorPlayed == "blue"))
	    {
	      cont = true;
	    }
	  else
	    {
	      cout <<
		"Please enter only lowercase letters when selecting a card. What card would you like to play: ";
	      cin >> cardColorPlayed >> cardNumPlayed;
	      if (cardNumPlayed == "draw")  {
	          cin >> cardNumberPlayed;
	      }
	    }
	}
      StrToNum ();
      for (int i = 0; i < currPlayer.size(); ++i)
	{
	  if (currPlayer.at(i) == cardPlayed1)
	    {
	      haveCard = true;
	      Discard.push_back (cardPlayed1);
	      temp = currPlayer.at (currPlayer.size () - 1);
	      currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	      currPlayer.at (i) = temp;
	      currPlayer.pop_back ();
	      break;
	    }
	  else if (currPlayer.at (i) == cardPlayed2)
	    {
	      haveCard = true;
	      Discard.push_back (cardPlayed2);
	      temp = currPlayer.at (currPlayer.size () - 1);
	      currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	      currPlayer.at (i) = temp;
	      currPlayer.pop_back ();
	      break;
	    }
	  else if (currPlayer.at (i) == cardPlayed3)
	    {
	      haveCard = true;
	      Discard.push_back (cardPlayed3);
	      temp = currPlayer.at (currPlayer.size () - 1);
	      currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	      currPlayer.at (i) = temp;
	      currPlayer.pop_back ();
	      break;
	    }
	  else if (currPlayer.at (i) == cardPlayed4)
	    {
	      haveCard = true;
	      Discard.push_back (cardPlayed4);
	      temp = currPlayer.at (currPlayer.size () - 1);
	      currPlayer.at (currPlayer.size () - 1) = currPlayer.at (i);
	      currPlayer.at (i) = temp;
	      currPlayer.pop_back ();
	      break;
	    }
	}
      if (haveCard == false)
	{
	  cout <<
	    "You do not have that card to play. Please choose a card in your hand."
	    << endl;
	}
    }
  cout << "You played a " << cardColorPlayed << " " << cardNumPlayed << "." <<
    endl;
  if (cardColorPlayed == "wild")
    {
      cout <<
	"What color would you like to change to (red, green, yellow, or blue): ";
      cin >> cardColorPlayed;
      cont = false;
      while (cont == false)
	{
	  if ((cardColorPlayed == "red") || (cardColorPlayed == "green")
	      || (cardColorPlayed == "yellow") || (cardColorPlayed == "blue"))
	    {
	      cont = true;
	    }
	  else
	    {
	      cout <<
		"Please enter only lowercase letters when selecting a color. What color would you like to change to (red, green, yellow, or blue): ";
	      cin >> cardColorPlayed;
	    }
	}
      if (cardNumPlayed == "draw")
	{
	  draw4 = true;
	}
    }
  else if (cardNumPlayed == "reverse")
    {
      if (reverse == false)
	{
	  reverse = true;
	}
      else if (reverse == true)
	{
	  reverse = false;
	}
    }
  else if (cardNumPlayed == "skip")
    {
      skip = true;
    }
  else if (cardNumPlayed == "draw")
    {
      draw2 = true;
    }

  if (currPlayer.size () == 1)
    {
      cout << "You have only one card, type \"UNO\", or draw 2 cards: ";
      cin >> checkUno;
      if ((checkUno == "UNO") || (checkUno == "uno"))
	{
	  cout << playerName.at (playerTurn - 1) << " has UNO!" << endl;
	}
      else
	{
	  cout <<
	    "You did not say \"UNO\", 2 cards have been added to your hand."
	    << endl;
	  currPlayer.push_back (Deck.at (currDeckPosition));
	  ++currDeckPosition;
	  currPlayer.push_back (Deck.at (currDeckPosition));
	  ++currDeckPosition;
	}
    }
  if (currPlayer.size () == 0)
    {
      playerIsOut = true;
      cout << playerName.at (playerTurn - 1) << " has gone out!" << endl;
    }
}

int main ()
{
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
  vector < int >player1 (7);	//only use the vectors of the amount of players that will be playing
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
  for (i = 1; i <= playerAmount; ++i)
    {
      cout << "Please enter player " << i << "'s name: ";	//ask user for their name
      cin >> plyrName;		//get user input
      playerName.at (i - 1) = plyrName;	//each name entered goes into the vector (element 0 is player 1)
    }
  while ((player1Points < 500) && (player2Points < 500)
	 && (player3Points < 500) && (player4Points < 500)
	 && (player5Points < 500) && (player6Points < 500)
	 && (player7Points < 500) && (player8Points < 500)
	 && (player9Points < 500) && (player10Points < 500))
    {
      //loops to shuffle the deck that will be drawing from
      while (wildCard == true)
	{
	  for (i = 0; i < Shuffle.size (); ++i)
	    {
	      Shuffle.at (i) = i;
	    }
	  for (i = 0; i < Deck.size (); ++i)
	    {
	      while (Shuffle.at (shuffleDeck) == 108)
		{
		  shuffleDeck = rand () % 108;
		}
	      Deck.at (i) = Shuffle.at (shuffleDeck);
	      Shuffle.at (shuffleDeck) = 108;
	    }
	  if ((Deck.at (0) == 13) || (Deck.at (0) == 27)
	      || (Deck.at (0) == 41) || (Deck.at (0) == 55)
	      || (Deck.at (0) == 68) || (Deck.at (0) == 81)
	      || (Deck.at (0) == 94) || (Deck.at (0) == 107))
	    {
	      wildCard = true;
	    }
	  else
	    {
	      wildCard = false;
	    }
	}

      //fill the vectors for the # of players in the game
      for (i = 1; i <= playerAmount; ++i)
	{
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

      counter = 0;
      if (playerBool1 == true)
	{
	  for (i = 0; i < player1.size (); ++i)
	    {
	      player1.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 1;
      if (playerBool2 == true)
	{
	  for (i = 0; i < player2.size (); ++i)
	    {
	      player2.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 2;
      if (playerBool3 == true)
	{
	  for (i = 0; i < player3.size (); ++i)
	    {
	      player3.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 3;
      if (playerBool4 == true)
	{
	  for (i = 0; i < player4.size (); ++i)
	    {
	      player4.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 4;
      if (playerBool5 == true)
	{
	  for (i = 0; i < player5.size (); ++i)
	    {
	      player5.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 5;
      if (playerBool6 == true)
	{
	  for (i = 0; i < player6.size (); ++i)
	    {
	      player6.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 6;
      if (playerBool7 == true)
	{
	  for (i = 0; i < player7.size (); ++i)
	    {
	      player7.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 7;
      if (playerBool8 == true)
	{
	  for (i = 0; i < player8.size (); ++i)
	    {
	      player8.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 8;
      if (playerBool9 == true)
	{
	  for (i = 0; i < player9.size (); ++i)
	    {
	      player9.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      counter = 9;
      if (playerBool10 == true)
	{
	  for (i = 0; i < player10.size (); ++i)
	    {
	      player10.at (i) = Deck.at (counter);
	      counter += playerAmount;
	    }
	}
      currDeckPosition = playerAmount * 7;
      Discard.at (0) = Deck.at (currDeckPosition);
      cout << endl;

      //begin player turns
      while (playerIsOut == false)
	{
	  if (reverse == false)
	    {
	      if (playerSkip == true)
		{
		  playerTurn = 2;
		  playerSkip = false;
		}
	      for (i = playerTurn; i < playerAmount + 1; ++i)
		{
		    playerTurn = 1;
		    cout << i << endl;
		  if (i == 1)
		    {
		      PlayerTurn (playerName, player1, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = playerAmount - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player2, Deck);
			}
		      if (draw4 == true)
			{
			  DrawFour (i, playerAmount, player1, player2, Deck);
			}
		    }
		  if (i == 2)
		    {
		      PlayerTurn (playerName, player2, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player3, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player3, Deck);
		    }
		  if (i == 3)
		    {
		      PlayerTurn (playerName, player3, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player4, Deck);
			}
		      if (draw4 == true)
			{
			  DrawFour (i, playerAmount, player1, player4, Deck);
		    }
		    }
		  if (i == 4)
		    {
		      PlayerTurn (playerName, player4, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player5, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player5, Deck);
		    }
		    }
		  if (i == 5)
		    {
		      PlayerTurn (playerName, player5, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player6, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player6, Deck);
		    }
		    }
		  if (i == 6)
		    {
		      PlayerTurn (playerName, player6, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player7, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player7, Deck);
		    }
		    }
		  if (i == 7)
		    {
		      PlayerTurn (playerName, player7, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player8, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player8, Deck);
		    }
		    }
		  if (i == 8)
		    {
		      PlayerTurn (playerName, player8, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player9, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player9, Deck);
		    }
		    }
		  if (i == 9)
		    {
		      PlayerTurn (playerName, player9, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player10, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player10, Deck);
		    }
		    }
		  if (i == 10)
		    {
		      PlayerTurn (playerName, player10, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i - 1;
			  break;
			}
		      if (skip == true)
			{
			  if (i == playerAmount)
			    {
			      playerSkip = true;
			      skip = false;
			    }
			  else
			    {
			      i = i + 2;
			      skip = false;
			    }
			}
		      if (draw2 == true)
			{
			  DrawTwo (i, playerAmount, player1, player2, Deck);
			}
		      if (draw4 == true)
			{
			DrawFour (i, playerAmount, player1, player2, Deck);
		    }
		}
	    }
		}
	  if (reverse == true)
	    {
	      if (playerSkip == true)
		{
		  playerTurn = playerAmount - 1;
		  playerSkip = false;
		}
	      for (i = playerTurn; i >= playerAmount; --i)
		{
		  if (i == 1)
		    {
		      PlayerTurn (playerName, player1, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  if (i == 1)
			    {
			      if (playerAmount == 2)
				{
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 3)
				{
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 4)
				{
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 5)
				{
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 6)
				{
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 7)
				{
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 8)
				{
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 9)
				{
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 10)
				{
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				}
			      playerSkip = true;
			      draw2 = false;
			    }
			}
		      if (draw4 == true)
			{
			  if (i == 1)
			    {
			      if (playerAmount == 2)
				{
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player2.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 3)
				{
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player3.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 4)
				{
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player4.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 5)
				{
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player5.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 6)
				{
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player6.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 7)
				{
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player7.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 8)
				{
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player8.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 9)
				{
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				  player9.push_back (Deck.
						     at (currDeckPosition));
				  ++currDeckPosition;
				}
			      else if (playerAmount == 10)
				{
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				  player10.push_back (Deck.
						      at (currDeckPosition));
				  ++currDeckPosition;
				}
			      playerSkip = true;
			      draw4 = false;
			    }
			}
		    }
		  else if (i == 2)
		    {
		      PlayerTurn (playerName, player2, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player1.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
			  i = i - 1;
			  draw4 = false;
			}
		    }
		  else if (i == 3)
		    {
		      PlayerTurn (playerName, player3, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player2.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player4, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player3.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player5, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player4.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player6, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player5.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player7, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player6.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player8, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player7.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player9, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player8.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		      PlayerTurn (playerName, player10, Deck, Discard, i);
		      if (reverse == true)
			{
			  playerTurn = i + 1;
			  break;
			}
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
		      if (draw2 == true)
			{
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  player9.push_back (Deck.at (currDeckPosition));
			  ++currDeckPosition;
			  i = i - 1;
			  draw2 = false;
			}
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
		}
	    }
	}
	    }
      counter =
	GetPoints (player1, player2, player3, player4, player5, player6,
		   player7, player8, player9, player10, playerAmount);
      counter = 0;
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
    }				//bracket for end of while loop

  cout << "Game Over";

  return 0;
}


