#include <iostream>
#include <string>
#include "RPG.h"
using namespace std;

int main()
{
    int round_count = 0;
    int player_health = 100, player_strength = 0, player_defense = 0;
    int choice; //players choice when its therir turn
    string player_name, player_type;

    RPG NPC("NPC", 100, 7, 5, "theif");

    cout<<"Hello and welcome to my RPG game"<<endl;
    cout<<"what is your name?"<<endl;
    cin>>player_name;
    
    cout<<"Please choose a character between (1) mage, (2) theif, (3) warrior, (4) and archer"<<endl;
    cout<<"Please enter the actual name of the character"<<endl;
    cin>>player_type;

    if(player_type == "mage")
    {
        player_strength = 8;
        player_defense = 2;
    } 
    if(player_type == "thief")
    {
        player_strength = 7;
        player_defense = 0;
    }
    if(player_type == "warrior")
    {
        player_strength = 9;
        player_defense = 3;
    }
    if(player_type == "archer")
    {
        player_strength = 9;
        player_defense = 1;
    }

    RPG player(player_name, player_health, player_strength, player_defense, player_type);

    cout<<"okay let the battle begin"<<endl;

    while(player.isAlive() && NPC.isAlive())
    {
        if(round_count % 2 == 0)
        {
            cout<<"Player's turn"<<endl;
            cout<<"Do you want to regular (1) attack or use a (2) skill?"<<endl;
            cin>>choice;

            if(choice == 1)
            {
                player.attack(NPC);
            }
            else if(choice == 2)
            {
                player.useSkill(NPC);
            }     
        }
        else
        {
            cout<<"NPC's turn"<<endl;
            NPC.attack(player);
        }
        cout<<"----------------------"<<endl;
        cout<<"Player's health is now: "<<player.getHealth()<<endl;
        cout<<"NPC's health is now: "<<NPC.getHealth()<<endl;
        cout<<"----------------------"<<endl;
        round_count++;
    }
    if(player.isAlive())
    {
        cout<<player.getName()<<" is the winner"<<endl;
    }
    else
    {
        cout<<NPC.getName()<<" is the winner"<<endl;
    }

}