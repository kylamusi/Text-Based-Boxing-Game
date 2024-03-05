#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

Player::Player()
{
  name="";
  specialty_move="";
}
Player::Player(string name, string specialty_movey){
  setName(name);
  setSpeciality(specialty_move);
  setPlayerHP(100);
}
void Player::setPlayerHP(unsigned int playerHP)
{
  this -> playerHP = playerHP; 
}
void Player::setName(string name){
  this->name=name;
}
void Player::setSpeciality(string specialty_move){
  this->specialty_move=specialty_move;
}
void Player::setMove()
{
  
  bool moveFound = false;
  cout<<getName()<<", what are you gonna throw?"<<endl;
  moveFound = false;
  int index;//might not need this code anymore 
  // Checking if it is a valid move in the array
  while(moveFound == false && move != "Forfeit")
  { 
    cin >> move;
    move[0] = toupper(move[0]);
    for (int i = 0; i < 4; i++)
    {
        if(move == Game::attacks[i])
        { 
          index = i; 
          moveFound = true; 
        }
    }
    if(move == "Forfeit")
    {
      Game::gameOver(); 
    }
     else if (moveFound == false && move != "Forfeit")
        {
          cout << "That is not a valid move please input another.\n";
        }
  }
  cout << endl; 
}

void Player::createCharacter()
{
  string name, specialty_move;
  cout << "Alright, what's your name kid?\n";
  cin >> name; 
  setName(name);
  cout << "Okay " << getName() << ", now tell me what's the best move you got?\nIs it a ";
  for(int i = 0; i < 4; i++)
  {
    if(i == 3)
      cout<<Game::attacks[i]<<"?\n";
  
    if(i != 3)
      cout<<Game::attacks[i]<<", a ";
  }
  bool moveFound = false; 
  while(moveFound == false)
  {
    cin >> specialty_move;
    specialty_move[0] = toupper(specialty_move[0]);
    for (int i = 0; i < 4; i++)
    {
        if (specialty_move == Game::attacks[i])
        {
          specialty_move = Game::attacks[i];
          cout << "Good choice!\n";
          moveFound = true; 
          setSpeciality(specialty_move);
        }
    }
     if (moveFound == false)
        {
          cout << "That is not a valid move please input another.\n";
        }
  }
}