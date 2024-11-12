#include "specialstack.h"

SpecialStack::SpecialStack()
{
    //ctor
}

void SpecialStack::push(int value)
{
    m_nums.push(value);
}

void SpecialStack::pop()
{
    if (m_nums.empty()) {
        throw(-1);
    }
    m_nums.pop();
}

int SpecialStack::peek()
{
    if(!m_nums.empty())
        return m_nums.top();
    else
        throw(-1);
}

bool SpecialStack::isEmpty()
{
    return m_nums.empty();
}

void SpecialStack::printStack()
{
        //Uses a copy of m_nums to print
    stack<int> tempStack = m_nums;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

void SpecialStack::popOdd()
{
    stack<int> tempStack;
    bool found = false;

        //Find odd value in stack
    while (!m_nums.empty())
    {
        int top = m_nums.top();
        m_nums.pop();

        if(!found && top % 2 != 0)
        {
            found = true;
        }
        else
        {
            tempStack.push(top);
        }
    }
        //Restore the stack
    while (!tempStack.empty())
    {
        m_nums.push(tempStack.top());
        tempStack.pop();
    }
        //Exception
    if (!found)
    {
        throw(-1);
    }
}

void SpecialStack::popEven()
{
    stack<int> tempStack;
    bool found = false;

        //Find even value in stack
    while (!m_nums.empty())
    {
        int top = m_nums.top();
        m_nums.pop();

        if(!found && top % 2 == 0)
        {
            found = true;
        }
        else
        {
            tempStack.push(top);
        }
    }
        //Restore the stack
    while (!tempStack.empty())
    {
        m_nums.push(tempStack.top());
        tempStack.pop();
    }
        //Exception
    if (!found)
    {
        throw(-1);
    }
}
