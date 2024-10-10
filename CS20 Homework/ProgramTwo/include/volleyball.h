#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include <athlete.h>
#include <string>

using namespace std;

class VolleyBall
{
    public:
        VolleyBall();
        VolleyBall(string, float);

        string getPosition();
        void setPosition(string);

        float getReactionTime();
        void setReactionTime(float);

    protected:

    private:
        string m_position;
        float m_reactionTime;
};

#endif // VOLLEYBALL_H
