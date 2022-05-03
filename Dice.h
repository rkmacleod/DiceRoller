#pragma once

class Dice
{
    private:
        int sides;                  //Number of sides on dice
        int num;                    //Number of dice rolled
        int mod;                    //Modifiers that add/sub to overall value
        int val;                    //The die's value when rolled
        const int MIN_SIDES = 1;    //Constant for minimum value of dice sides

    public:
        Dice();
        Dice(int);
        Dice(int, int);
        Dice(int, int, int);
        void roll();
        void setSides(int);
        void setNumber(int);
        void setModifier(int);
        int getSides();
        int getNumber();
        int getModifier();
        int getValue();
};