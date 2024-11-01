#include "gamestate.h"
#include <iostream>

GameState::GameState()          //ctor
{
    m_nextState = 0;

    m_allStates.push_back("PLATFORM ");
    m_allStates.push_back("HEAD ");
    m_allStates.push_back("BODY ");
    m_allStates.push_back("LEFT ARM ");
    m_allStates.push_back("RIGHT ARM ");
    m_allStates.push_back("LEFT LEG ");
    m_allStates.push_back("RIGHT LEG ");
}

string GameState::getState()    //returns the list
{
    string s = "";
    for (auto it = m_state.begin();
        it != m_state.end(); ++it){
            s += *it;
            s += " ";
    }
    return s;
}

void GameState::addState()      //add next state to the list
{
    m_state.push_back(m_allStates[m_nextState++]);
}

bool GameState::gameOver()      //returns true if hung
{
    if(m_nextState == 7)
        return(true);
    else
        return(false);
}
