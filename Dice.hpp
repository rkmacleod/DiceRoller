#pragma once

class Dice
{
private:
    int m_sides;                    //Number of sides on dice
    int m_num;                      //Number of dice rolled
    int m_mod;                      //Modifiers that add/sub to overall value
    int m_val;                      //The die's value when rolled
    const int m_MIN_SIDES = 1;      //Constant for minimum value of dice sides

public:
    Dice();                         //Constructor #0: Default Constructor
    Dice(int);                      //Constructor #1
    Dice(int, int);                 //Constructor #2
    Dice(int, int, int);            //Constructor #3: Delegated Constructor
    void roll();
    void setSides(int);
    void setNumber(int);
    void setModifier(int m) {m_mod = m;}
    int getSides() const    {return m_sides;}
    int getNumber() const   {return m_num;}
    int getModifier() const {return m_mod;}
    int getValue() const    {return m_val;}
};