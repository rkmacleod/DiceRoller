#pragma once

#include <random>       //std::random_device, std::mt19937, std::uniform_real_distribution

class Die
{
private:
    int m_sides;                                        //Number of sides on dice
    int m_num;                                          //Number of dice to roll
    int m_mod;                                          //Modifiers that add/sub to overall value
    int m_val;                                          //The die's value when rolled
    static const int s_MIN_VAL = 1;                     //Static constant for minimum value of a die roll
    static const int s_MIN_SIDES = 2;                   //Static constant for minimum sides of a die, 2 sides = coinflip
    static const int s_MIN_NUM = 1;                     //Static constant for minimum number of dice, must be >= 1
    inline static std::random_device m_rd;              //Static random seed
    inline static std::mt19937 m_engine;                //Static random number generator engine (mt19937) seeded with std::random_device
    std::uniform_int_distribution<int> dist;    //Uniform int distribution for each die instance, based on number of sides

public:
    Die();                                      //Constructor #0: Default Constructor, no parameters
    Die(int);                                   //Constructor #1: Dice(sides)
    Die(int, int);                              //Constructor #2: Dice(sides, number of dice)
    Die(int, int, int);                         //Constructor #3: Delegated Constructor - Dice(sides, number of dice, modifiers)
    int roll();                                 //Perform a random dice roll with mt19937 engine, return m_val value of roll
    void setSides(int);                         //Change the number of sides of the die  
    void setNumber(int);                        //Change the number of dice rolled
    void setModifier(int m) {m_mod = m;}        //Change modifier added to the dice roll
    int getSides() const    {return m_sides;}   //Returns number of sides of the die
    int getNumber() const   {return m_num;}     //Returns number of dice being rolled at once
    int getModifier() const {return m_mod;}     //Returns modifier being added to dice roll value
};