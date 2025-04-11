#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Charmander : public Pokemon
{
    public:
        //------------- Constructors -------------
        Charmander();
        Charmander(string name, int hp, int att, int def, vector<string> type, vector<string> s);
        // ------------ Mutator Functions --------
        void speak()/*override*/; 
        void printStats()/*override*/;
        //------------- Accessor Functions -------

        protected:
        vector<string>skills;
        /*name, hp, attack, defense*/
};
#endif