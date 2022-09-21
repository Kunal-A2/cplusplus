#include<iostream>
using namespace std;

class  ICommand
{
private:    
public:
    ICommand();
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    ~ICommand();
};

ICommand::ICommand()
{
    // cout<<"ICommand Ctor "<<endl;
}

ICommand::~ICommand()
{
    // cout<<"ICommand Dtor"<<endl;
}

//---------------------------------------------------
class Receiver{
    private:
        string state;
    public:
        Receiver();
        ~Receiver();
        string getState();
        void execute(string option);
};
Receiver::Receiver(){
    // cout<<"Receiver Ctor Called"<<endl;
}
Receiver::~Receiver(){
    // cout<<"Receiver Dtor Called"<<endl;
}
string Receiver::getState()
{
    return this->state;
}
void Receiver::execute(string option){
    this->state = option;
    // cout<<"Perform Action on Receiver"<<endl;
}

//---------------------------------------------------
class Command : public ICommand{
    private:
        Receiver *receiver;
    public:
        Command(Receiver*);
        ~Command();
        void execute();
        void unexecute();
};

Command::Command(Receiver *recvr){
    this->receiver = recvr;
    // cout<<"Command Ctor called"<<endl;
}
Command::~Command(){
    delete this->receiver;
    // cout<<"Command Dtor called"<<endl;
}
void Command::execute(){
    this->receiver->execute("Set");
}
void Command::unexecute(){
    this->receiver->execute("Unet");
}
//---------------------------------------------------
class Invoker{
    private:
        ICommand *command;
    public:
        Invoker(ICommand*);
        ~Invoker();
        void setCommand();
        void unsetCommand();
};
Invoker::Invoker(ICommand *cmd){
    this->command = cmd;
    // cout<<"Invoker Ctor called"<<endl;
}
Invoker::~Invoker(){
    delete this->command;
    // cout<<"Invoker Dtor called"<<endl;
}
void Invoker::setCommand(){
    this->command->execute();
}
void Invoker::unsetCommand(){
    this->command->unexecute();
}

//--------------------------------------------------

int main()
{
    Receiver *rcvr = new Receiver();
    Invoker *client = new Invoker(new Command(rcvr));

    client->setCommand();
    cout<<"Current receiver state := "<<rcvr->getState()<<endl;
    client->unsetCommand();
    cout<<"Current receiver State := "<<rcvr->getState()<<endl;
    return 0;
}