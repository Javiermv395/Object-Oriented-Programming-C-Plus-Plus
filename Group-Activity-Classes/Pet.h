#ifndef PET_H
#define PET_H
#include <string>
using namespace std;

class Pet
{
    private:
        int age;
        string name;
        string owner;
        bool isHosueTrained;
        
    public:
    // -----------Constructors------------
    Pet();
    Pet(int age, string name, string owner, bool isHouseTrained);

    // -----------Mutators---------------
    void updatename(string name);
    void updateOwner(string owner);
    void updateAge(int age);            //increments age by 1
    void updateIsHouseTrained(bool isHouseTrained); //set house trained to true

    // -----------Accessors--------------
    string getname() const;
    string getOwner() const;
    int getAge() const;
    bool getIsHouseTrained() const;
};
#endif