#ifndef INCLUDED_INVOKER_H
#define INCLUDED_INVOKER_H

#include<iostream>
#include "command.h"
using namespace std;

class Invoker{
    private:
        ICommand *onCommand;
        ICommand *offCommand;
        ICommand *upCommand;
        ICommand *downCommand;
    public:
        Invoker( ICommand *on, ICommand *off,  ICommand *up,  ICommand *down);
        ~Invoker();
        void setOnCommand();
        void unsetOnCommand();
        void setOffCommand();
        void unsetOffCommand();
        void setUpCommand();
        void unsetUpCommand();
        void setDownCommand();
        void unsetDownCommand();
};

#endif