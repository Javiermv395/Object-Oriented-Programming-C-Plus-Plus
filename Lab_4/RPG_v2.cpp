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
        skills[0] = "fire";       //make fire 25 damage 
        skills[1] = "thunder";    //make thunder 35 damage
    }
    else if(type == "thief")
    {
        skills[0] = "pilfer";     //dodges move
        skills[1] = "jab";        //make jab 15 damage
    }
    else if(type == "archer")
    {
        skills[0] = "parry";            //make function so if being attacked, whoever is using parry will take no damage and the attacker will take the damage
        skills[1] = "crossbow_attack";  //make crossbow attack 30 damage
    }
    else
    {
        skills[0] = "slash";    //make slash 25 damage
        skills[1] = "parry";    //make function so if being attacked, whoever is using parry will take no damage and the attacker will take the damage
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

void RPG::attack(RPG * target)
{
    int damage = strength - target->getDefense();
    if (damage < 0)
    {
        damage = 0;
    }
    target->updateHealth(target->getHealth() - damage);
}

void RPG::useSkill(RPG * target, int skill_choice, int used_parry)
{
    if(used_parry == 1)//A player used parry
    {
        int damage = (target->strength * 2) - target->getDefense(); 
        if (damage < 0)
        {
            damage = 0;
        }
        target->updateHealth(target->getHealth() - damage); 
        printAction(skills[skill_choice], *target);
    }
    else if(used_parry == 0) //players didnt use parry
    {
        int damage = (strength * 2) - target->getDefense(); 
        if (damage < 0)
        {
            damage = 0;
        }
        target->updateHealth(target->getHealth() - damage); 
        printAction(skills[skill_choice], *target); 
    }
}

void RPG::printSkills() const
{
    cout << name << "'s skills are:\n";
    for (int i = 0; i < SKILL_SIZE; i++) {
        cout << i << ".)" << skills[i] << endl;
    }
}

string RPG::getSkill(int index) const
{
    return skills[index];
}
