#include <iostream>
#include <string>
#include "RPG.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int player_choice = 0; //dictates which move the player will use
    int NPC_choice = 0; //dictates which move the NPC will use
    int round_count = 1;
    int used_Parry = 0;
    int player_health = 100, player_strength = 0, player_defense = 0;
    string player_name, player_type;

    RPG NPC("NPC", 100, 20, 10, "thief");

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
                    player.attack(&NPC);
                    NPC.useSkill(&player, NPC_choice, used_Parry);
                }
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"Player's health: "<<player.getHealth()<<"      NPC's health: "<<NPC.getHealth()<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                round_count++;
            break;
                case 2: 
                cout<<"Please choose a skill"<<endl;
                player.printSkills();
                cin>>player_choice;
              
                //Players choose their skill as a number to be used to determine who takes damage due to some characters having parry as a skill
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
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"Player's health: "<<player.getHealth()<<"      NPC's health: "<<NPC.getHealth()<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                round_count++;
            break;
            default:
                cout<<"Invalid input turn skipped"<<endl;
            break;
        }       
    }
    if(player.isAlive())
    {
        cout<<player.getName()<<" is the winner"<<endl;
    }
    else
    {
        cout<<NPC.getName()<<" is the winner"<<endl;
    }
    return 0;
}
