#include <cstdlib>
#include <ctime>
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
    //Initialize random seed
    srand(time(NULL));

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
        sumRoll += (rand() % m_sides + m_MIN_SIDES);
    }

    //Add rolls and modifiers to value
    m_val = sumRoll + m_mod;
}


//Setters
void Dice::setSides(int s)
{
    if(s >= 1)
        m_sides = s;
}

void Dice::setNumber(int n)
{
    if(n >= 1)
        m_num = n;
}

void Dice::setModifier(int m)
{
    m_mod = m;
}


//Getters
int Dice::getSides() const
{
    return m_sides;
}

int Dice::getNumber() const
{
    return m_num;
}

int Dice::getModifier() const
{
    return m_mod;
}

int Dice::getValue() const
{
    return m_val;
}