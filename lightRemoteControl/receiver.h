#ifndef INCLUDED_RECEIVER_H
#define INCLUDED_RECEIVER_H

#include<iostream>
using namespace std;

class Light
{
    private:
        string state;
    public:
        string getState();
        void execute(string option);
};

#endif