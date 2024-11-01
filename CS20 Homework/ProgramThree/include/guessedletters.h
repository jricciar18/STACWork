#ifndef GUESSEDLETTERS_H
#define GUESSEDLETTERS_H

#include<string>
#include<list>

using namespace std;

class GuessedLetters
{
    public:
        GuessedLetters();       //ctor

        string getLetters();    //returns the list

        void addLetter(char);   //add the to list of guessed letters

    protected:

    private:
        list<char> m_guessed;
};

#endif // GUESSEDLETTERS_H
