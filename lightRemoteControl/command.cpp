#include<iostream>
#include "command.h"
using namespace std;

ICommand::ICommand()
{
    // cout<<"ICommand Ctor "<<endl;
}

ICommand::~ICommand()
{
    // cout<<"ICommand Dtor"<<endl;
}

//---------------------------------------------------


//---------------------------------------------------



OnCommand::OnCommand(Light *recvr){
    this->light = recvr;
    // cout<<"OnCommand Ctor called"<<endl;
}
OnCommand::~OnCommand(){
    delete this->light;
    // cout<<"OnCommand Dtor called"<<endl;
}
void OnCommand::execute(){
    this->light->execute("Set On");
}
void OnCommand::unexecute(){
    this->light->execute("Unet On");
}

//-------------------------------------------

OffCommand::OffCommand(Light *recvr){
    this->light = recvr;
    // cout<<"OffCommand Ctor called"<<endl;
}
OffCommand::~OffCommand(){
    delete this->light;
    // cout<<"OffCommand Dtor called"<<endl;
}
void OffCommand::execute(){
    this->light->execute("Set Off");
}
void OffCommand::unexecute(){
    this->light->execute("Unet Off");
}

//---------------------------------------


UpCommand::UpCommand(Light *recvr){
    this->light = recvr;
    // cout<<"UpCommand Ctor called"<<endl;
}
UpCommand::~UpCommand(){
    delete this->light;
    // cout<<"UpCommand Dtor called"<<endl;
}
void UpCommand::execute(){
    this->light->execute("Set up");
}
void UpCommand::unexecute(){
    this->light->execute("Unet up");
}

//----------------------------------------------

DownCommand::DownCommand(Light *recvr){
    this->light = recvr;
    // cout<<"DownCommand Ctor called"<<endl;
}
DownCommand::~DownCommand(){
    delete this->light;
    // cout<<"DownCommand Dtor called"<<endl;
}
void DownCommand::execute(){
    this->light->execute("Set Down");
}
void DownCommand::unexecute(){
    this->light->execute("Unet Down");
}

