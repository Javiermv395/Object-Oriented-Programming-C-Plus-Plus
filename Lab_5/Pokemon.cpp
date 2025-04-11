#include <iostream> 
#include "Pokemon.h"

/* 
 * @brief Construct a  New Pokemon :: Pokemon Object
 *
 * 
*/

Pokemon::Pokemon()
{
    name = "unidentified";
    hp = 0;
    attack = 0;
    defense = 0;
    cout<<"Default Constructor (Pokemon)\n";
}

/*
    * @brief Construct a Pokemon Object with parameters
    *
    * @param name The name of the Pokemon
    * @param hp The health points of the Pokemon
    * @param att The attack points of the Pokemon
    * @param def The defense points of the Pokemon
    * @param type The type of the Pokemon
*/

Pokemon::Pokemon(string name, int hp, int att, int def, vector<string> type)
{
    this->name = name;
    this->hp = hp;
    attack = att;
    defense = def;
    type = type;
    cout<<"Overloaded Constructor (Pokemon)\n";
}

/*
 * @brief says whatever this pokemon normally says
 *
*/
void Pokemon::speak()
{
    cout<< "....\n";
}

void Pokemon::printStats()
{
    printf("Name:%s\t HP:%d\t ATT:%d\t DEF:%d\n", name.c_str(), hp, attack, defense);
    cout<<"Type: ";
    for (int i = 0; i < type.size(); i++)
    {
        cout<<type[i]<<" ";
    }
    cout<<endl;
}