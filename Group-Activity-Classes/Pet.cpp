#include "pet.h"

Pet::Pet()
{
    age = 0;
    name = "Frijol";
    owner = "Javier";
    isHosueTrained = true;
}

Pet::Pet(int age, string name, string owner, bool isHouseTrained)
{
    this->name = name;
    this->age = age;
    this->owner = owner;
    this->isHosueTrained = isHouseTrained;
}

void Pet::updatename(string name)
{
    this->name = name;
}

void Pet::updateOwner(string owner)
{
    this->owner = owner;
}

void Pet::updateAge(int age)
{
    this->age = age;
}

void Pet::updateIsHouseTrained(bool isHouseTrained)
{
    this->isHosueTrained = isHouseTrained;
}

