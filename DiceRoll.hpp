#pragma once

#include <random>       //std::random_device, std::mt19937, std::uniform_real_distribution
#include <assert.h>     //std::assert

struct DiceRoll
{
    int m_sides = 6;                                //Number of sides on dice
    int m_number = 1;                               //Number of dice to roll
    int m_modifier = 0;                             //Modifiers that add/sub to overall value
};

int roll_die(std::mt19937& engine, int num_sides)
{
    assert(num_sides >= 1);

    return std::uniform_int_distribution<int>{1, num_sides}(engine);
}

int roll_dice(std::mt19937& engine, int num_sides, int num_dice, int modifier = 0)
{
    assert(num_sides >= 1);
    assert(num_dice >= 1);

    int total = 0;

    for(int i = 0; i < num_dice; i++)
        total += roll_die(engine, num_sides);
    
    return total + modifier;
}

int roll_dice(std::mt19937& engine, DiceRoll roller)
{
    return roll_dice(engine, roller.m_sides, roller.m_number, roller.m_modifier);
}
