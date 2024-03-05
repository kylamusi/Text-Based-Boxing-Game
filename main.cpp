/*
  Authors: Kyla U., Saul M. Cristobal E.
  Date: 5/11/23
  Description: This is a turn based boxing game where your opponent is randomized each time. The user is able to put their name and their best move that will do +5 more damage if it is hit. When making a move, the user has a 50/50 chance of hitting or missing their throw. There are 3 rounds that will continue until someone gets knocked out or if the user chooses to forfeit. The program also displays the player and the enemy's health after each move. 
*/
#include <iostream>
#include "Game.hpp"
#include "Opponent.hpp"
#include "Player.hpp"
#include <chrono>
#include <thread>

using namespace std; 
string replay;
string player[12]={"[","=","=","=","=","=","=","=","=","=","=","]"};
string opponent[12]={"[","=","=","=","=","=","=","=","=","=","=","]"};

void displayhealthbar(){
  for(int i=0;i<12;i++){
    cout<<player[i];
  }
}
void displayhealthbar1(){
  for(int i=0;i<12;i++){
    cout<<opponent[i];
  }
}

int main() 
{
  do{
      Game match;
      Opponent enemy; 
      Player user; 
      user.setPlayerHP(100); 
      int player1hp; 
      int enemy1hp; 
      user.createCharacter();
      Opponent();
      match.displayIntro(enemy);
  
      //Countdown
      for(int i = 3; i > 0; i--)
      {
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
      }
      this_thread::sleep_for(chrono::seconds(1));
      cout << "\033[2J\033[1;1H";
      do{
        match.displayRound();
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\033[2J\033[1;1H";
      
        int counter = 10;
        // cout << "Moves: Swing Hook Uppercut Jab\n\n";
        do{ 
          cout << "Moves: Swing\tHook\tUppercut\tJab\n\n";

          // Displays Health Bar
          cout << user.getName()<<"\t\t\t\t\t\t\t\t\t"<<enemy.getEnemy() << endl;
          cout <<"(";
          displayhealthbar();
          cout <<")" << user.getPlayerHP()<< "\t\t\t\t" << enemy.getEnemyHealth() <<"(";
          displayhealthbar1();
          cout <<")" << endl << endl;
          
          match.hitOrMissPlayer(user,enemy);
          this_thread::sleep_for(chrono::seconds(1));
          cout << endl;
          counter -= 1;
          this_thread::sleep_for(chrono::seconds(1));
          if(user.getMove() != "Forfeit" && user.getPlayerHP() > 0 && enemy.getEnemyHealth() > 0)
          {
            match.hitOrMissOpponent(user, enemy);
            cout << endl;
            counter -= 1; 
          }
          player1hp = (user.getPlayerHP()/10);
          enemy1hp = (100-enemy.getEnemyHealth())/10;
            if(player1hp!=10)
          {
              player[player1hp+1] ="]";
              player1hp = player1hp + 2;
            for(int i = player1hp; i <= 11; i++) 
            {
              player[i]=" ";
            }
          }
            if(enemy1hp!=10)
            {
              opponent[enemy1hp]="[";
              enemy1hp=enemy1hp-1;
              for(int i=enemy1hp; i>=0; i--) 
              {
                opponent[i]=" ";
              }
            }
      this_thread::sleep_for(chrono::seconds(3));
      cout << "\033[2J\033[1;1H";
         
        }while(user.getPlayerHP() > 0 && enemy.getEnemyHealth() > 0 && user.getMove() != "Forfeit" && counter > 0);
        match.setRounds();
        if(user.getMove() != "Forfeit")
        {
          player1hp = (user.getPlayerHP()/10);
          enemy1hp = (100-enemy.getEnemyHealth())/10;
            if(player1hp!=10)
          {
              player[player1hp+1] ="]";
              player1hp = player1hp + 2;
            for(int i = player1hp; i <= 11; i++) 
            {
              player[i]=" ";
            }
          }
            if(enemy1hp!=0)
            {
              opponent[enemy1hp]="[";
              enemy1hp=enemy1hp-1;
              for(int i=enemy1hp; i>=0; i--) 
              {
                opponent[i]=" ";
              }
          }
          cout << user.getName()<<"\t\t\t\t\t\t\t\t\t"<<enemy.getEnemy() << endl;
          cout <<"(";
          displayhealthbar();
          cout <<")" << user.getPlayerHP()<< "\t\t\t\t" << enemy.getEnemyHealth() <<"(";
          displayhealthbar1();
          cout <<")" << endl << endl;
          cout << "Round Over!!\n";
        }
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\033[2J\033[1;1H";
      }while(user.getPlayerHP() > 0 && enemy.getEnemyHealth() > 0 && user.getMove() != "Forfeit");
      if (user.getMove() == "Forfeit")
      { 
        cout << user.getName() << " forfeited! LOSER!!!\n" << enemy.getEnemy() << " wins by default!\n";
      }
      else if(user.getPlayerHP() <= 0 || user.getPlayerHP() < enemy.getEnemyHealth())
      {
        int index; 
        for(int i = 0; i < 7; i++)
        {
          if(enemy.getEnemy() == Game::opponents[i])
          {
            index = i; 
          }
        }
        cout << "K.O! You lost bozo!\n"; 
        cout << user.getName() << " is a goner.\n" << enemy.getEnemy() << ": " << Game::quotes[index] << endl;
      }
      else if(enemy.getEnemyHealth() <= 0 || user.getPlayerHP() > enemy.getEnemyHealth())
      {
        cout << "You won!! Great job " << user.getName() << "!\n";
      }
      cout << "Do you want to play again?(yes or no)\n";
      cin >> replay; 
      for (int i = 0; i < replay.length(); i++)
        {
          replay[i] = tolower(replay[i]);
        }
      if(replay == "yes" || replay == "y")
      {
        cout << "Let's go again!\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\033[2J\033[1;1H";
      }
      else if(replay == "no" || replay == "n")
      {
        cout << "Thanks for playing!\n";
        return 0; 
      }
      else
      {
        cout << "No idea what you said dude, see ya!\n";
        return 0; 
      }
    }while(replay == "yes" || "y"); 
  }