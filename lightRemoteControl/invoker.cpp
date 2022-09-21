#include "invoker.h"

Invoker::Invoker( ICommand *on, ICommand *off,  ICommand *up,  ICommand *down){
    this->onCommand = on;
    this->offCommand = off;
    this->upCommand = up;
    this->downCommand = down;
    // cout<<"Invoker Ctor called"<<endl;
}
Invoker::~Invoker(){
    delete this->onCommand;
    delete this->offCommand;
    delete this->upCommand;
    delete this->downCommand;
    // cout<<"Invoker Dtor called"<<endl;
}
void Invoker::setOnCommand(){
    this->onCommand->execute();
}
void Invoker::unsetOnCommand(){
    this->onCommand->unexecute();
}

void Invoker::setOffCommand(){
    this->offCommand->execute();
}
void Invoker::unsetOffCommand(){
    this->offCommand->unexecute();
}

void Invoker::setUpCommand(){
    this->upCommand->execute();
}
void Invoker::unsetUpCommand(){
    this->upCommand->unexecute();
}

void Invoker::setDownCommand(){
    this->downCommand->execute();
}
void Invoker::unsetDownCommand(){
    this->downCommand->unexecute();
}