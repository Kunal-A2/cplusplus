#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

#include<iostream>
#include "receiver.h"
using namespace std;

class  ICommand
{
public:
    ICommand();
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    ~ICommand();
};

class OnCommand : public ICommand{
    private:
        Light *light;
    public:
        OnCommand(Light*);
        ~OnCommand();
        void execute();
        void unexecute();
};

class OffCommand : public ICommand{
    private:
        Light *light;
    public:
        OffCommand(Light*);
        ~OffCommand();
        void execute();
        void unexecute();
};

class UpCommand : public ICommand{
    private:
        Light *light;
    public:
        UpCommand(Light*);
        ~UpCommand();
        void execute();
        void unexecute();
};

class DownCommand : public ICommand{
    private:
        Light *light;
    public:
        DownCommand(Light*);
        ~DownCommand();
        void execute();
        void unexecute();
};


#endif