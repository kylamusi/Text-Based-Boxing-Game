#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream> 
#include <string> 
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Opponent.hpp"
#include "Player.hpp"

using namespace std; 

class Game
{
  public:
    Game();
    void displayIntro(Opponent& enemy); 
    void hitOrMissPlayer(Player& user, Opponent& enemy); 
    void hitOrMissOpponent(Player& user, Opponent& enemy);
    void continueChoice();   
    void displayRound(); 
    void updateScreen(); 
    void setRounds();
    int getRounds() {return rounds;}
    
    
    static void gameOver(); 
    static const string attacks[4];
    static const int attackDamage[4];
    static const int specialDamage[4];
    static const string opponents[7];
    static const string quotes[7];

  protected: 
    int rounds;
    Player user; 
    Opponent enemy; 

};

#endif // GAME_HPP_INCLUDED
