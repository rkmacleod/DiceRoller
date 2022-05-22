#include <iostream>     //std::cout
#include <cstdlib>      //std::srand, std::rand
#include <ctime>        //std::time
#include "Dice.hpp"

//Constructor #0: Default Constructor
Dice::Dice() : Dice(6, 1, 0) {}

//Constructor #1
Dice::Dice(int s) : Dice(s, 1, 0) {}

//Constructor #2
Dice::Dice(int s, int n) : Dice(s, n, 0) {}

//Constructor #3: Delegated Constructor
Dice::Dice(int s, int n, int m) 
    : m_sides(s), m_num(n), m_mod(m)
{
    //Exception Handling
    if(m_sides < 2)
        m_sides = 2;
    if(m_num < 1)
        m_num = 1;

    //Initialize random seed
    std::srand(std::time(NULL));

    //Generate roll value
    roll();
}

void Dice::roll()
{
    //for adding dice rolls
    int sumRoll = 0;

    //Generate value for dice rolls
    for(int i = 0; i < m_num; i++)
    {
        sumRoll += (std::rand() % m_sides + m_MIN_SIDES);
    }

    //Add rolls and modifiers to value
    m_val = sumRoll + m_mod;
}


//Setters
void Dice::setSides(int s)
{
    if(s < 2)
        m_sides = 2;            //set to minimum # of sides
    else m_sides = s;     //set if value is >= 2
}

void Dice::setNumber(int n)
{
    if(n < 1)
        m_num = 1;            //set to minimum # of sides
    else m_num = n;     //set if value is >= 2
}