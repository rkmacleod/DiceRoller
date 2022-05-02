#include <cstdlib>
#include <ctime>
#include "Dice.h"

//Default Constructor #0
Dice::Dice()
{
    sides = 6;
    num = 1;
    mod = 0;
}

//Constructor #1
Dice::Dice(int s)
{
    //Initial values
    sides = s;
    num = 1;
    mod = 0;

    //Initialize random seed
    srand(time(NULL));

    //Generate roll value
    roll();
}

//Constructor #2
Dice::Dice(int s, int n)
{
    //Initial values
    sides = s;
    num = n;
    mod = 0;

    //Initialize random seed
    srand(time(NULL));

    //Generate roll value
    roll();
}

//Constructor #3
Dice::Dice(int s, int n, int m)
{
    //Initial values
    sides = s;
    num = n;
    mod = m;

    //Initialize random seed
    srand(time(NULL));

    //Generate roll value
    roll();
}

void Dice::roll()
{
    int sum = 0;    //for adding dice rolls

    //Generate value for dice rolls
    for(int i = 0; i < num; i++)
    {
        sum += (rand() % sides + MIN_SIDES);
    }

    //Add rolls and modifiers to value
    val = sum + mod;
}

void Dice::setSides(int s)
{
    if(s >= 1)
        sides = s;
}

void Dice::setNumber(int n)
{
    if(n >= 1)
        num = n;
}

void Dice::setModifier(int m)
{
    mod = m;
}

int Dice::getSides()
{
    return sides;
}

int Dice::getNumber()
{
    return num;
}

int Dice::getModifier()
{
    return mod;
}

int Dice::getValue()
{
    return val;
}