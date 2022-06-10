#include <iostream>
#include <random>
#include "DiceRoll.hpp"

int main()
{
    std::random_device rd;          //Static random seed
    std::mt19937 mt(rd());          //Static random number generator engine (mt19937) seeded with std::random_device

    const int MOD_INTELLIGENCE = -1;
    const int PROFICIENCY = 2;
    const int INIT = 3;
    int rolls;

    DiceRoll attack_rayOfFrost{20,1,MOD_INTELLIGENCE + PROFICIENCY};
    DiceRoll damage_rayOfFrost{8,2};
    DiceRoll damage_sneak;
    DiceRoll d8{8};
    
    std::cout << "This is a test of the DiceRoll struct\n";

    std::cout << "The die d8 has "  << d8.m_sides << " sides.\n";
    std::cout << "The die d8 has " << d8.m_number << " dice.\n";
    std::cout << "The die d8 has " << d8.m_modifier << " modifiers.\n";
    std::cout << "The initial roll of d8 is " << roll_dice(mt, d8);
    std::cout << "\n-----------------------------------------\n";

    std::cout << "The die damage_sneak has "  << damage_sneak.m_sides << " sides.\n";
    std::cout << "The die damage_sneak has " << damage_sneak.m_number << " dice.\n";
    std::cout << "The die damage_sneak has " << damage_sneak.m_modifier << " modifiers.\n";
    std::cout << "The initial roll of damage_sneak is " << roll_dice(mt, damage_sneak);
    std::cout << "\n-----------------------------------------\n";

    std::cout << "The die damage_rayOfFrost has "  << damage_rayOfFrost.m_sides << " sides.\n";
    std::cout << "The die damage_rayOfFrost has " << damage_rayOfFrost.m_number << " dice.\n";
    std::cout << "The die damage_rayOfFrost has " << damage_rayOfFrost.m_modifier << " modifiers.\n";
    std::cout << "The initial roll of damage_rayOfFrost is " << roll_dice(mt, damage_rayOfFrost);
    std::cout << "\n-----------------------------------------\n";

    std::cout << "The die attack_rayOfFrost has "  << attack_rayOfFrost.m_sides << " sides.\n";
    std::cout << "The die attack_rayOfFrost has " << attack_rayOfFrost.m_number << " dice.\n";
    std::cout << "The die attack_rayOfFrost has " << attack_rayOfFrost.m_modifier << " modifiers.\n";
    std::cout << "The initial roll of attack_rayOfFrost is " << roll_dice(mt, attack_rayOfFrost);
    std::cout << "\n-----------------------------------------\n";



    std::cout << "How many times would you like to roll a normal 1d6 die?\n";
    std::cin >> rolls; 
    for(int i = 0; i < rolls; i++)
    {
        std::cout << "Roll #" << i+1 << " = " << roll_die(mt, 6) << std::endl;
    }

    std::cout << "How many times would you like to roll the damage_rayOfFrost dice?\n";
    std::cin >> rolls; 
    for(int i = 0; i < rolls; i++)
    {
        std::cout << "Roll #" << i+1 << " = " << roll_dice(mt, damage_rayOfFrost) << std::endl;
    }



    std::cout << "\n\nSimulating DnD Combat now...\n";
    std::cout << "Attemping to attack with Ray of Frost spell\n";
    int initiative = roll_dice(mt, attack_rayOfFrost);
    while(initiative <= 15)
    {
        std::cout << "You rolled a " << initiative << " so the attack did not land.\nRerolling...\n";
        initiative = roll_dice(mt, attack_rayOfFrost);
    }

    std::cout << "The attack landed with a roll of " << initiative << "!\n";
    std::cout << "Calculating damage...\n";
    std::cout << roll_dice(mt, damage_rayOfFrost) << " points of damage were dealt!\n\n";



    DiceRoll badSides{-1};
    DiceRoll badNum{6,-2};
    //std::cout << "Rolling die with -1 sides...\n";
    //int bad1 = roll_dice(mt, badSides);

    std::cout << "Rolling -2 number of dice...\n";
    int bad2 = roll_dice(mt, badNum);

}