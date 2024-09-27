#include "Opponent.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

Opponent:: Opponent()
{
  setEnemyHealth(100);
  setEnemyName(enemyName);
  setSpecial(specialMove);
}
void Opponent::setEnemyHealth(unsigned int enemyHealth)
{
  this -> enemyHealth = enemyHealth;
}
void Opponent::setEnemyName(string enemyName)
{
  srand(time(NULL));
  int num = rand() % 7;
  enemyName = Game::opponents[num];
  this -> enemyName = enemyName;
}
void Opponent:: setSpecial(string specialMove)
{
  srand(time(NULL));
  int num = rand() % 4;
  specialMove = Game::attacks[num];
  this -> specialMove = specialMove;
}
void Opponent:: setEnemyAttack()
{
  srand(time(NULL));
  num = rand() % 4;
  enemyAttack = Game:: attacks[num];
  if (enemyAttack == specialMove)
    enemyDamage = Game:: specialDamage[num];
  else
    enemyDamage = Game:: attackDamage[num];
}
void Opponent:: displayEnemy()
{
  cout << "Your opponent is " << enemyName << ". His special move is " << specialMove << "." << endl;
}
