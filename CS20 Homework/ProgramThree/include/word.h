#ifndef WORD_H
#define WORD_H

#include<string>
#include<list>

using namespace std;

class Word
{
    public:
        Word(string);           //ctor

        string getWord();       //returns the list

        void addLetter(char);   //replaces the underscore with the char where appropriate
        bool findLetter(char);  //returns true if the guessed letter is present

        bool solved();

    protected:

    private:
        list<char> m_currentWord;
        string m_word;
};

#endif // WORD_H
