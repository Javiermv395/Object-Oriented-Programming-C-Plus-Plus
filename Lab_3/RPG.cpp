#include "RPG.h"
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>


RPG::RPG()
{
    name = "NPC";
    health = 100;
    strength = 7;
    defense = 2;
    type = "Goblin";
    skills[0] = "slash";
    skills[1] = "Pilfer";
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this -> name = name;
    this -> health = health;
    this -> strength = strength;
    this -> defense = defense;
    this -> type = type;

    setskills();
}

string RPG::getName() const
{
    return name;
}

int RPG::getHealth() const
{
    return health;
}

int RPG::getStrength() const
{
    return strength;
}

int RPG::getDefense() const 
{
    return defense;
}

void RPG::setskills()
{
    if (type == "mage")
    {
        skills[0] = "fire";        
        skills[1] = "thunder";      
    }
    else if(type == "theif")
    {
        skills[0] = "pilfer";   
        skills[1] = "jab";      
    }
    else if(type == "archer")
    {
        skills[0] = "parry";    
        skills[1] = "crossbow_attack";      
    }
    else
    {
        skills[0] = "slash";    
        skills[1] = "parry";    
    }
}

void RPG::printAction(string skill, RPG opponent)
{
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

void RPG::updateHealth(int New_Health)
{
    health = New_Health;
}

bool RPG::isAlive() const
{
    return health > 0;
}

void RPG::attack(RPG & target)
{
    int damage = strength - target.getDefense();
    if (damage < 0)
    {
        damage = 0;
    }
    target.updateHealth(target.getHealth() - damage);
    printAction("attack", target);
}

void RPG::useSkill(RPG & target)
{
    srand(time(0));
    int skill_choice = 0;
    int damage = (strength * 2) - target.getDefense();
    if (damage < 0)
    {
        damage = 0;
    }
    skill_choice = rand() % 2;
    target.updateHealth(target.getHealth() - damage);
    printAction(skills[skill_choice], target);
}









