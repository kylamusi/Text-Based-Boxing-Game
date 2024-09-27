#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <string>
#include <iostream>

using namespace std;


class Player {
  public:
      Player();
      Player(string name, string specialty_move);
      void setName(string name);
      void setSpeciality(string specialty_move);
      void setPlayerHP(unsigned int playerHP);
      void setMove();
      void createCharacter();
      string getName() {return name;}
      string getMove() {return move;}
      int getPlayerHP(){return playerHP;}
      string getSpeciality() {return specialty_move;}
  
  protected:
      string name, specialty_move, move;
      unsigned int playerHP, damage;  
      
  
};

#endif // PLAYER_HPP_INCLUDED

//Good Job!
