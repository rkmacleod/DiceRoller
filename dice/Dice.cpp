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
    try
    {
        if(m_sides < 2)
            throw "Exception: sides must be an integer >= 2";
        if(m_num < 1)
            throw "Exception: number of dice must be an integer >= 1";
    }
    catch(const char* ex)
    {
        std::cout << ex << std::endl;
    }

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
    //Exception Handling
    try
    {
        if(s < 2)
            throw "Exception: sides of dice must be an integer >= 2";
        else m_sides = s;     //set if value is >= 2
    }
    catch(const char* ex)
    {
        std::cout << ex << std::endl;
    }
}

void Dice::setNumber(int n)
{
    //Exception Handling
    try
    {
        if(n < 1)
            throw "Exception: number of dice must be an integer >= 1";
        else m_num = n;     //set if value is >= 1
    }
    catch(const char* ex)
    {
        std::cout << ex << std::endl;
    }
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