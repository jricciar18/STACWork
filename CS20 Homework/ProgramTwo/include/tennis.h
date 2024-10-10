#ifndef TENNIS_H
#define TENNIS_H

#include <athlete.h>

using namespace std;

class Tennis
{
    public:
        Tennis();
        Tennis(int, bool);

        int getServeSpeed();
        void setServeSpeed(int);

        bool getServeAndVolley();
        void setServeAndVolley(bool);


    protected:

    private:
        int m_serveSpeed;
        bool m_serveAndVolley;
};

#endif // TENNIS_H
