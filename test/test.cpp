#include <iostream>
#include "../dice/Dice.hpp"

int main()
{
    const int CLASS_LEVEL = 5;
    const int MOD_DEXTERITY = 3;
    const int MOD_INTELLIGENCE = -1;
    const int PROFICIENCY = 2;
    const int INIT = 3;
    int rolls;

    Dice initiative(20,1,INIT);
    Dice attack_rayOfFrost(20,1,MOD_INTELLIGENCE + PROFICIENCY);
    Dice attack_shortsword(20,1,MOD_DEXTERITY + PROFICIENCY);
    Dice attack_dagger(20,1,MOD_DEXTERITY + PROFICIENCY);

    Dice damage_rayOfFrost(8,2);
    Dice damage_shortsword(6,1,MOD_DEXTERITY);
    Dice damage_dagger(4,1,MOD_DEXTERITY);
    Dice damage_sneak;

    Dice seven_d10(7,10);
    Dice d8(8);
    
    std::cout << "This is a test use-case of the Dice class\n";

    std::cout << "The die d8 has "  << d8.getSides() << " sides.\n";
    std::cout << "The die d8 has " << d8.getModifier() << " modifiers.\n";
    std::cout << "The initial roll of d8 is " << d8.getValue() << std::endl;
    std::cout << "How many times would you like to reroll the die?\n";
    std::cin >> rolls; 

    for(int i = 0; i < rolls; i++)
    {
        d8.roll();
        std::cout << "Roll #" << i+1 << " = " << d8.getValue() << std::endl;
    }

    std::cout << "\n\nSimulating DnD Combat now...\n";
    std::cout << "Attemping to attack with Ray of Frost spell\n";
    if(attack_rayOfFrost.getValue() > 10)
    {
        std::cout << "The attack landed with a roll of " << attack_rayOfFrost.getValue() << "!\n";
        std::cout << "Calculating damage...\n";
        std::cout << damage_rayOfFrost.getValue() << " of damage was dealt!\n";
    }
    else
        std::cout << "You rolled a " << attack_rayOfFrost.getValue() << " so the attack did not land.\n";

    return 0;
}