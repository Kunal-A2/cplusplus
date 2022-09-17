#include<iostream>
#include<memory>
#include <list>
using namespace std;

//-----------------------------------
class ISubscriber
{
    public:
        virtual void notify(string) = 0;
};

// -------------------------

class User : public ISubscriber
{
    private:
        int user_id;
        string user_name;
    public:
        User(int id, string name){
            this->user_id = id;
            this->user_name = name;
        }
        void notify(string msg){
            cout<<"Msg coming from "<<this->user_name<<" is "<<msg<<endl;
        }
};
//---------------------------------------
class Group
{
    private:
        list<ISubscriber*> users;
    public:
        void subscriber(ISubscriber*);
        void unsubscriber(ISubscriber*);
        void notify(string);
};

void Group::subscriber(ISubscriber* u)
{
    this->users.push_back(u);   
}
void Group::unsubscriber(ISubscriber* u)
{
    this->users.remove(u);
}
void Group::notify(string msg)
{
    for (auto user : users)
    {
        user->notify(msg);
    }
}
//-------------------------------------------------
int main()
{
    unique_ptr<Group> g_ptr (new Group);

    ISubscriber *u1 = new User(1, "Kunal");
    ISubscriber *u2 = new User(2, "Mike");
    ISubscriber *u3 = new User(3, "john");

    g_ptr->subscriber(u1);
    g_ptr->subscriber(u2);
    g_ptr->subscriber(u3);
    g_ptr->notify("First Event");
    g_ptr->unsubscriber(u2);
    g_ptr->notify("Second Event");

    delete u1;
    delete u2;
    delete u3;
    return 0;
}