#include <iostream>
#include "Die.hpp"

int main()
{
    const int CLASS_LEVEL = 5;
    const int MOD_DEXTERITY = 3;
    const int MOD_INTELLIGENCE = -1;
    const int PROFICIENCY = 2;
    const int INIT = 3;
    int rolls;

    Die initiative(20,1,INIT);
    Die attack_rayOfFrost(20,1,MOD_INTELLIGENCE + PROFICIENCY);
    Die attack_shortsword(20,1,MOD_DEXTERITY + PROFICIENCY);
    Die attack_dagger(20,1,MOD_DEXTERITY + PROFICIENCY);

    Die damage_rayOfFrost(8,2);
    Die damage_shortsword(6,1,MOD_DEXTERITY);
    Die damage_dagger(4,1,MOD_DEXTERITY);
    Die damage_sneak;

    Die seven_d10(7,10);
    
    Die d8(8);
    
    std::cout << "This is a test use-case of the Die class\n";

    std::cout << "The die d8 has "  << d8.getSides() << " sides.\n";
    std::cout << "The die d8 has " << d8.getModifier() << " modifiers.\n";
    std::cout << "The die d8 has " << d8.getNumber() << " dice.\n";
    std::cout << "The initial roll of d8 is " << d8.roll() << std::endl;
    std::cout << "How many times would you like to reroll the die?\n";
    std::cin >> rolls; 

    for(int i = 0; i < rolls; i++)
    {
        std::cout << "Roll #" << i+1 << " = " << d8.roll() << std::endl;
    }


    std::cout << "\n\nSimulating DnD Combat now...\n";
    std::cout << "Attemping to attack with Ray of Frost spell\n";
    if(attack_rayOfFrost.roll() > 10)
    {
        std::cout << "The attack landed with a roll of " << attack_rayOfFrost.roll() << "!\n";
        std::cout << "Calculating damage...\n";
        std::cout << damage_rayOfFrost.roll() << " of damage was dealt!\n";
    }
    else
        std::cout << "You rolled a " << attack_rayOfFrost.roll() << " so the attack did not land.\n";

}