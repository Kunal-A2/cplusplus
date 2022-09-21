/*
    Command Design Pattern Example
    1) Build a LightRemoteControl(invoker), use is having facility of "On", "Off", "Up" and "Down"
    2) Now this controler commands is associated with specific command class
    3) every command is associated with receiver(Target).
    4) Receiver class(Light) is having state which can be change on controler command  
*/
#include<iostream>
#include "receiver.h"
#include "command.h"
#include "invoker.h"
using namespace std;


int main()
{
    Light *rcvr = new Light();
    Invoker *client = new Invoker(new OnCommand(rcvr), new OffCommand(rcvr), new UpCommand(rcvr),new DownCommand(rcvr));
    client->setOnCommand();
    cout<<"Current receiver state := "<<rcvr->getState()<<endl;
    client->unsetOnCommand();
    cout<<"Current receiver State := "<<rcvr->getState()<<endl;

    client->setOffCommand();
    cout<<"Current receiver state := "<<rcvr->getState()<<endl;
    client->unsetOffCommand();
    cout<<"Current receiver State := "<<rcvr->getState()<<endl;

    client->setUpCommand();
    cout<<"Current receiver state := "<<rcvr->getState()<<endl;
    client->unsetUpCommand();
    cout<<"Current receiver State := "<<rcvr->getState()<<endl;

    client->setDownCommand();
    cout<<"Current receiver state := "<<rcvr->getState()<<endl;
    client->unsetDownCommand();
    cout<<"Current receiver State := "<<rcvr->getState()<<endl;

    return 0;
}