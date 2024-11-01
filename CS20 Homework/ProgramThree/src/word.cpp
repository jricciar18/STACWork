#include "word.h"

Word::Word(string word)             //ctor
{
    m_word = word;
    for (int i=0; i<word.length(); i++)
        m_currentWord.push_back('_');
}

string Word::getWord()              //returns the list
{
    string w = "";
    for (auto it = m_currentWord.begin();
        it != m_currentWord.end(); ++it){
            w += *it;
            w += " ";
    }
    return w;
}

void Word::addLetter(char c)        //replaces the underscore with the char where appropriate
{
    for (size_t pos = 0; pos < m_word.length(); ++pos) {
        if (m_word[pos] == c) {
            auto it = std::next(m_currentWord.begin(), pos);
            if (it != m_currentWord.end() && *it == '_')
                *it = c;
        }
    }
}

bool Word::findLetter(char c)       //returns true if the guessed letter is present
{
    size_t pos = m_word.find(c);

    if (pos != m_word.npos)
        return true;
    else
        return false;
}

bool Word::solved()                 //returns if the word is guessed
{
    string currentWordString;
    for (auto it = m_currentWord.begin();
        it != m_currentWord.end(); ++it)
            currentWordString += *it;

    if(currentWordString == m_word)
        return(true);
    else
        return(false);

}

