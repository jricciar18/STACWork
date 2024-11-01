#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<string>
#include<list>
#include<vector>

using namespace std;

class GameState
{
    public:
        GameState();        //ctor

        string getState();  //returns the list

        void addState();    //add next state to the list

        bool gameOver();    //returns true if hung


    protected:

    private:
        list<string> m_state;
        vector<string> m_allStates;
        int m_nextState;
};

#endif // GAMESTATE_H
