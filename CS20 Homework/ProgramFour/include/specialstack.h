#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include<stack>
#include<exception>
#include<iostream>

using namespace std;

class SpecialStack
{
    public:
            //ctor
        SpecialStack();
            //Basic Operations
        void push(int value);
        void pop();
        int peek();
        bool isEmpty();
        void printStack();
            //New Operations
        void popOdd();
        void popEven();

    protected:

    private:
        stack<int> m_nums;
};

#endif // SPECIALSTACK_H
