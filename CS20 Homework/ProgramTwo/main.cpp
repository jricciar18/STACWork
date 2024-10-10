#include <iostream>
#include <athlete.h>
#include <tennis.h>
#include <volleyball.h>

using namespace std;

int main()
{
    Athlete sport(72, 140, 'M');
    cout << "Athlete: " << sport.getHeight() << " "
         << sport.getWeight() << " "
         << sport.getGender() << endl;

    Tennis martina = Tennis();
    martina.setServeSpeed(100);
    martina.setGender('F');
    Tennis bjorn(150,false);
    bjorn.setGender('M');
    if  (martina.getGender() == 'F')
       cout << "Martina serve speed: " << martina.getServeSpeed() << endl;

    VolleyBall kerri = VolleyBall();
    kerri.setGender('F');
    kerri.setPosition("Opposite Hitter");
    VolleyBall giba("Outside Hitter",23.2);
    giba.setGender('M');
    if  (kerri.getGender() == 'F')
       cout << "Kerri is an " << kerri.getPosition() << endl;

    return 0;
}
