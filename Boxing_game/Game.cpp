#include "Game.hpp"
#include "Player.hpp"
#include "Opponent.hpp"
using namespace std;

const string Game::attacks[4] = 
{"Swing", "Hook", "Uppercut", "Jab"};

const int Game::attackDamage[4] = {15, 10, 20, 5};

const int Game::specialDamage[4] = {20, 15, 25, 10}; 

const string Game::opponents[7] = {"Mike Tyson", "Donkey Kong", "Manny Pacquiao", "Muhammad Ali", "Floyd Mayweather", "Jake Paul", "Rocky"}; 

const string Game::quotes[7] = {"GG bro", "*Pounds Chest*", "Yuh", "I am the greatest!", " Get clapped! *Dabs*", "It's everyday bro!", "Yo Adrien, I did it!"};

Game::Game()
{
  rounds = 1; 
}
void Game::displayIntro(Opponent& enemy)
{
  this_thread::sleep_for(chrono::seconds(2));
  cout << "\033[2J\033[1;1H";
  string userChoice; 
  cout << "\t\t\t===== Welcome to the Boxing tournament!! =====" << endl;
  cout << "\t\t\t        🥊Let's get ready to rumble!!!!🥊" << endl; 
  cout << "\tWould you like to go over the game rules and basics?(yes or no)" << endl;
  cin >> userChoice; 
  for (int i = 0; i < userChoice.length(); i++)
    {
      userChoice[i] = tolower(userChoice[i]);
    }
  if (userChoice  == "yes" || userChoice == "y")
    {
      cout << "Focus up. Your opponent is getting ready as we speak. This is a turn based game so when it is your turn choose a move. When you're in the ring, you have 4 moves to choose from:\n1. Full Swing\n2. Hook\n3. Uppercut\n4. Jab\n"; 
      cout << "There will be three rounds and you can choose to forfeit at anytime by typing 'forfeit' instead of a move. Your special move has an increased damage of +5.\n";
      enemy.displayEnemy(); 
      this_thread::sleep_for(chrono::seconds(15));
      cout << "\033[2J\033[1;1H";
  
    }
  else if (userChoice == "no" || userChoice == "n")
    {
      cout << "Alright, I hope you are ready.\n";
      cout << "Moves: \n1. Swing\n2. Hook\n3. Uppercut\n4. Jab\n"; 
      enemy.displayEnemy();
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\033[2J\033[1;1H";
    }
  else 
    {
      cout << "No idea what you just said man but get ready to fight!\n"; 
      cout << "Moves: \n1. Swing\n2. Hook\n3. Uppercut\n4. Jab\n"; 
      enemy.displayEnemy();
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\033[2J\033[1;1H";
    }
}
void Game::displayRound()
{
  if (rounds == 1)
  {
      cout << "--------------------\n";
      cout << "|      Round       |\n";
      cout << "|        1         |\n";
      cout << "|__________________|\n"; 
      cout <<      "     ¯\\_(ツ)_/¯\n";
   }
  else if (rounds == 2)
  {
      cout << "--------------------\n";
      cout << "|      Round       |\n";
      cout << "|        2         |\n";
      cout << "|__________________|\n"; 
      cout <<      "     ¯\\_(ツ)_/¯\n";

  }
  else if (rounds == 3)
  {
      cout << "--------------------\n";
      cout << "|      FINAL       |\n";
      cout << "|      ROUND       |\n";
      cout << "|__________________|\n"; 
      cout <<      "     ¯\\_(ツ)_/¯\n";
  }
  else if (rounds > 3)
  {
      cout << "--------------------\n";
      cout << "|      OVER        |\n";
      cout << "|      TIME        |\n";
      cout << "|__________________|\n"; 
      cout <<      "     ¯\\_(ツ)_/¯\n";
  }
}
void Game::hitOrMissPlayer(Player& user, Opponent& enemy)
{
  user.setMove();
  int index = 0;
  int x = rand() % 2; 
  if (x == 0 && user.getMove() != "Forfeit")
  {
    cout << user.getName() << " tried to throw a " << user.getMove() << " but missed!\n"; 
  }
  else if (x == 1 && user.getMove() != "Forfeit") 
  {
    cout << "\a";
    cout <<  user.getName() << " threw a " << user.getMove() <<  "!\n" << "\x1B[32m" << "It hit! " << "\033[0m";
  for (int i = 0; i < 4; i++)
    {
      if(user.getMove() == attacks[i])
      { 
        index = i;  
      }
    }
    if(user.getMove() == user.getSpeciality())
    {
      int temp; 
      int newHealth; 
      temp = enemy.getEnemyHealth(); 
      newHealth = (temp - specialDamage[index]);
      if(newHealth <= 0)
      {
        enemy.setEnemyHealth(0);
      }
      if(newHealth > 0)
      {
        enemy.setEnemyHealth(newHealth);
      }
      cout << "\x1B[32m" << "It did " << specialDamage[index] << " damage!" << "\033[0m\t\t\n" << endl; 
    }
    if(user.getMove() != user.getSpeciality())
    {
      int temp; 
      int newHealth;
      temp = enemy.getEnemyHealth(); 
      newHealth = (temp - attackDamage[index]); 
      if(newHealth <= 0)
      {
        enemy.setEnemyHealth(0);
      }
      if(newHealth > 0)
      {
        enemy.setEnemyHealth(newHealth);
      }
      cout << "\x1B[32m" << "It did " << attackDamage[index] << " damage!" << "\033[0m\t\t\n"; 
    }
  }
}
void Game::hitOrMissOpponent(Player& user, Opponent& enemy)
{
  int index; 
  int x; 
  enemy.setEnemyAttack();
  for (int i = 0; i < 4; i++)
  {
    if(enemy.getEnemyAttack() == attacks[i])
      index = i;
  }
  x = rand() % 2; 
  cout << enemy.getEnemy() << " threw out a " << enemy.getEnemyAttack() << "!\n";
  if (x == 0)
  {
    cout << enemy.getEnemy() <<" missed!\n"; 
  }
  else if (x == 1) 
  {
    cout << "\a";
    cout << "\x1B[31m" << "It hit! " << "\033[0m";
    if(enemy.getEnemyAttack() == enemy.getEnemySpecial())
    {
      int newHealth; 
      int temp;
      temp = user.getPlayerHP();
      newHealth = (temp - (specialDamage[index]));
      if(newHealth <= 0)
      {
        user.setPlayerHP(0);
      }
      if(newHealth > 0)
      {
        user.setPlayerHP(newHealth);
      }
      cout << "\x1B[31m" << "It did " << specialDamage[index] << " damage!" <<"\033[0m" << endl; 
    }
    if(enemy.getEnemyAttack() != enemy.getEnemySpecial())
    {
      int newHealth;
      int temp;
      temp = user.getPlayerHP();
      newHealth = (temp - attackDamage[index]);
      if(newHealth <= 0)
      {
        user.setPlayerHP(0);
      }
      if(newHealth > 0)
      {
        user.setPlayerHP(newHealth);
      }
      cout << "\x1B[31m" << "It did " << attackDamage[index] << " damage!" << "\033[0m" << endl; 
    }
  }
}
void Game::continueChoice()
{ 
  string forfeitChoice; 
  cout << "Do you want to throw in the towel? (yes or no)\n";
  cin >> forfeitChoice;
   for (int i = 0; i < forfeitChoice.length(); i++)
    {
      forfeitChoice[i] = tolower(forfeitChoice[i]);
    }
  if (forfeitChoice == "yes" || forfeitChoice == "y")
    {
      cout << "(opponent name) wins by forfeit!\n";
    }
  else 
    {
      cout << "LET'S GO\n"; 
    }
}
void Game::setRounds()
{
  rounds += 1; 
}

void Game::gameOver()
{
  cout << "Game OVER!\n";
}
