#ifndef ATHLETE_H
#define ATHLETE_H

using namespace std;

class Athlete
{
    public:
        Athlete();
        Athlete(int, int, char);

        int getHeight();
        void setHeight(int);

        int getWeight();
        void setWeight(int);

        char getGender();
        void setGender(char);

    protected:

    private:
        int m_height;
        int m_weight;
        char m_gender;
};

#endif // ATHLETE_H
