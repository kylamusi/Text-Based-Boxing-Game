#ifndef OPPONENT_HPP_INCLUDED
#define OPPONENT_HPP_INCLUDED
#include <string>
#include <iostream>
#include <ctime>
#include "Player.hpp"
using namespace std;

class Opponent 
{
  public:
    Opponent();
    void setEnemyName(string enemyName);
    void setEnemyHealth(unsigned int enemyHealth);
    void setSpecial(string specialMove);
    void setEnemyAttack();
    int getEnemyHealth() {return enemyHealth;}
    string getEnemy()const {return enemyName;}
    string getEnemyAttack()const {return enemyAttack;}
    string getEnemySpecial()const {return specialMove;}
    int getEnemyDamage()const {cout << "It dealt " << enemyDamage << "damage!\n";}
    //void enemyHitOrMiss(Player user);
    void displayEnemy(); 
    int num;
  protected:
    unsigned int enemyHealth;
    unsigned int enemyDamage; 
    string enemyName;
    string enemyAttack;
    string specialMove;
};

#endif //OPPONENT_INCLUDED
