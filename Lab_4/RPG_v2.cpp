#include "RPG.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



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
    else if(type == "thief")
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

void RPG::attack(RPG * target, int skill_choice, int used_parry)
{
    if(used_parry == 1)//this executes when NPC uses parry
    {
        int damage = target->strength - target->getDefense();
        if (damage < 0)
        {
            damage = 0;
        }
        target->updateHealth(target->getHealth() - damage);
        printAction(skills[skill_choice], *target);
    }
    else if(used_parry == 0)//this executes when NPC doesnt use parry
    {
        int damage = strength - target->getDefense();
        if (damage < 0)
        {
            damage = 0;
        }
        target->updateHealth(target->getHealth() - damage);
        printAction(skills[skill_choice], *target);
    }
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

void RPG::displayEnd(RPG player1, RPG player2) const
{
    if(player1.getHealth() > 0)
    {
        cout<<player1.getName()<<" wins! Good game"<<endl;
    }
    else if(player2.getHealth() > 0)
    {
        cout<<player2.getName()<<" wins! Good game"<<endl;
    }
}

void RPG::displayStats( RPG player1, RPG player2) const
{
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"Player's health: "<<player1.getHealth()<<"      NPC's health: "<<player2.getHealth()<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}

void RPG::gameLoop(RPG * player1, RPG * player2) const
{
    int player_choice = 0; //dictates which move the player will use
    int NPC_choice = 0; //dictates which move the NPC will use
    int round_count = 1;
    int used_Parry = 0;
    int player_health = 100, player_strength = 0, player_defense = 0;
    string player_name, player_type;

    RPG NPC("NPC", 100, 20, 10, "archer");

    cout<<"Hello and welcome to my RPG game"<<endl;
    cout<<"what is your name?"<<endl;
    cin>>player_name;
    
    cout<<"Please choose a character between (1) mage, (2) thief, (3) archer, (4) and warrior"<<endl;
    cout<<"Please enter a number for the character"<<endl;
    cin>>player_choice;
    
    
    switch (player_choice)
    {
    case 1:
        player_type = "mage";
        player_strength = 30;
        player_defense = 15;
        break;
    case 2:
        player_type = "thief";
        player_strength = 25;
        player_defense = 10;
        break; 
    case 3:
        player_type = "archer";
        player_strength = 30;
        player_defense = 15;
        break;
    case 4:
        player_type = "warrior";
        player_strength = 35;
        player_defense = 15;
        break;
    }

    RPG player(player_name, player_health, player_strength, player_defense, player_type);

    cout<<"okay let the battle begin"<<endl;

    while(player.isAlive() && NPC.isAlive())
    {
        cout<<"Round "<<round_count<<endl;
        cout<<"Player's turn"<<endl;
        cout<<"Would you like to (1) regular attack or (2) use skill"<<endl;
        cin>>player_choice;
        
        switch (player_choice) 
        {
            case 1:
                if(NPC.getSkill(NPC_choice) == "parry")
                {
                    used_Parry = 1;
                    NPC.useSkill(&player, NPC_choice, used_Parry);
                }
                else
                {
                    used_Parry = 0;
                    player.attack(&NPC, player_choice, used_Parry);
                    NPC.useSkill(&player, NPC_choice, used_Parry);
                }
                displayStats(player, NPC);
                round_count++;
            break;
                case 2: 
                cout<<"Please choose a skill"<<endl;
                player.printSkills();
                cin>>player_choice;
              
                cout<<"NPC's turn"<<endl;
                NPC_choice = rand () % 2;
    
                if(player.getSkill(player_choice) == "parry" && NPC.getSkill(NPC_choice) == "parry") //when both players use parry
                {
                    cout<<"Both players used parry, no damage was taken"<<endl;
                }
                else if(player.getSkill(player_choice) == "parry" && NPC.getSkill(NPC_choice) != "parry") //when the player uses parry
                {
                    used_Parry = 1;
                    player.useSkill(&NPC, player_choice, used_Parry);
                }
                else if(player.getSkill(player_choice) != "parry" && NPC.getSkill(NPC_choice) == "parry") //when the NPC uses parry
                {
                    used_Parry = 1;
                    NPC.useSkill(&player, NPC_choice, used_Parry);
                }
                else //When both players dont use parry
                {
                    used_Parry = 0;
                    player.useSkill(&NPC, player_choice, used_Parry);
                    NPC.useSkill(&player, NPC_choice, used_Parry);
                }
                displayStats(player, NPC);
                round_count++;
            break;
            default:
                cout<<"Invalid input turn skipped"<<endl;
            break;
        }   
    }
    displayEnd(player, NPC);
}
