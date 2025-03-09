#ifndef RPG_H
#define RPG_H
#include <string>

using namespace std;

const int SKILL_SIZE = 2;
class RPG
{
    private:
    //complete the rest
    string type; //warrior, mage, theif, archer
    string skills[SKILL_SIZE];
    string name; //name of the character
    int health; //health of the character
    int strength; //strength of the character
    int defense; //defense of the character

    public:
    //Constructors
    RPG();
    RPG(string name, int health, int strngth, int defense, string type);

    //Mutator functions
    void setskills();
    void printAction(string skill , RPG opponent);
    void updateHealth(int New_Health);
    void attack(RPG & target);
    void useSkill(RPG & target);

    //Accessor functions
    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
};

#endif