#include "Die.hpp"

//Random Number Generator
std::random_device s_rd;
std::mt19937 s_engine(s_rd());

//Constructor #0: Default Constructor
Die::Die() : Die(6, 1, 0) {}

//Constructor #1
Die::Die(int s) : Die(s, 1, 0) {}

//Constructor #2
Die::Die(int s, int n) : Die(s, n, 0) {}

//Constructor #3: Delegated Constructor
Die::Die(int s, int n, int m) 
    : m_sides(s), m_num(n), m_mod(m), m_dist(sc_MIN_VAL, s)
{
    //Exception Handling
    if(m_sides < sc_MIN_SIDES)
        m_sides = sc_MIN_SIDES;
    if(m_num < sc_MIN_NUM)
        m_num = sc_MIN_NUM;
}

//Main method: returns int value of dice roll sums + modifier
int Die::roll()
{
    //reset m_val to hold new roll value
    m_val = 0;

    //Generate value for dice rolls
    for(int i = 0; i < m_num; i++)
    {
        m_val += m_dist(s_engine);
    }

    //Add modifiers to value, then return m_val
    return m_val += m_mod;
}

//Setters
void Die::setSides(int s)
{
    if(s < sc_MIN_SIDES)        //if sides was set to an impossible value less than 2
        m_sides = sc_MIN_SIDES; //set to minimum # of sides, 2
    else m_sides = s;           //set normally if value is >= 2

    //Update distribution for random num generator, so that it doesn't become stale
    std::uniform_int_distribution<int>::param_type p(sc_MIN_VAL, m_sides);
    m_dist.param(p);
}

void Die::setNumber(int n)
{
    if(n < sc_MIN_NUM)          //if number of dice was set to an impossible value less than 1
        m_num = sc_MIN_NUM;     //set to minimum # of dice, 1
    else m_num = n;             //set normally if value is >= 1
}