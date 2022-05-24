#include "Die.hpp"

//Random Number Generator
std::random_device m_rd;
std::mt19937 m_engine(m_rd());

//Constructor #0: Default Constructor
Die::Die() : Die(6, 1, 0) {}

//Constructor #1
Die::Die(int s) : Die(s, 1, 0) {}

//Constructor #2
Die::Die(int s, int n) : Die(s, n, 0) {}

//Constructor #3: Delegated Constructor
Die::Die(int s, int n, int m) 
    : m_sides(s), m_num(n), m_mod(m), dist(s_MIN_VAL, s)
{
    //Exception Handling
    if(m_sides < s_MIN_SIDES)
        m_sides = s_MIN_SIDES;
    if(m_num < s_MIN_NUM)
        m_num = s_MIN_NUM;
}

int Die::roll()
{
    //reset m_val to hold new roll value
    m_val = 0;

    //Generate value for dice rolls
    for(int i = 0; i < m_num; i++)
    {
        m_val += dist(m_engine);
    }

    //Add modifiers to value, then return m_val
    m_val += m_mod;
    return m_val;
}

//Setters
void Die::setSides(int s)
{
    if(s < s_MIN_SIDES)
        m_sides = s_MIN_SIDES;   //set to minimum # of sides
    else m_sides = s;           //set if value is >= 2

    //Update distribution for random num generator, so that it doesn't become stale
    std::uniform_int_distribution<int>::param_type p(s_MIN_VAL, m_sides);
    dist.param(p);
}

void Die::setNumber(int n)
{
    if(n < s_MIN_NUM)
        m_num = s_MIN_NUM;      //set to minimum # of sides
    else m_num = n;             //set if value is >= 2
}