#include "athlete.h"

Athlete::Athlete()
{
    //ctor
}
Athlete::Athlete(int height, int weight, char gender)
{
    m_height = height;
    m_weight = weight;
    m_gender = gender;
}

int Athlete::getHeight() //returns the height of the athlete
{
    return m_height;
}
void Athlete::setHeight(int height) //sets the height of the athlete
{
    m_height = height;
}

int Athlete::getWeight() //returns the weight of the athlete
{
    return m_weight;
}
void Athlete::setWeight(int weight) //sets the weight of the athlete
{
    m_weight = weight;
}

char Athlete::getGender()
{
    return m_gender;
}
void Athlete::setGender(char gender)
{
    m_gender = gender;
}
