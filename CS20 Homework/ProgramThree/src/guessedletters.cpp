#include "guessedletters.h"

GuessedLetters::GuessedLetters()        //ctor
{

}

string GuessedLetters::getLetters()     //returns the list
{
    string letters = "";
    for (auto it = m_guessed.begin();
        it != m_guessed.end(); ++it)
        {
            letters += *it;
            letters += " ";
        }
    return letters;
}

void GuessedLetters::addLetter(char c)  //add the to list of guessed letters
{
    m_guessed.push_back(c);
}
