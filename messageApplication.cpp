/*
    Example of Observer Design Pattern:

    In client function,
    1. we can create a new group and new User
    2. user can subscribe and unsubscribe the group
    3. User can send Message and Attachment in the any group
    4. If any User will send Message / Attachment then remaing User of that Group will
        be Notify.

*/
#include<iostream>
#include<memory>
#include <list>
using namespace std;
//-----------------------------------
class IGroup;
class ISubscriber;

class IGroup
{
    public:
    virtual string getGroupName() = 0;
    virtual void subscriber(ISubscriber*) = 0;
    virtual void unsubscriber(ISubscriber*) = 0;
    virtual void new_message(string, ISubscriber*) = 0;
    virtual void new_attachment(string, ISubscriber*) = 0;
    virtual ~IGroup(){
        cout<<"Dtor IGroup"<<endl;
    }
};
class ISubscriber
{
    public:
        virtual void subscribeGroup(IGroup*) = 0;
        virtual void unsubscribeGroup(IGroup*) = 0;
        virtual void notify(string, string) = 0;
        virtual void sendMessage(string,string) = 0;
        virtual void sendAttachment(string,string) = 0;
        virtual string getUserName() = 0;
        virtual ~ISubscriber(){
            cout<<"Dtor IUser"<<endl;
        }
};


// -------------------------

class User : public ISubscriber
{
    private:
        int user_id;
        string user_name;
        list<IGroup*> groups;
    public:
        User(int id, string name){
            this->user_id = id;
            this->user_name = name;
        }
        void notify(string msg, string from_user){
            cout<<this->user_name<<" : \x1B[32m"<<msg<<"\033[0m from \x1B[32m"<<from_user<<"\033[0m"<<endl;
        }
        void subscribeGroup(IGroup* grp)
        {
            groups.push_back(grp);
            grp->subscriber(this);
        }
        void unsubscribeGroup(IGroup* grp){
            groups.remove(grp);
            grp->unsubscriber(this);
        }
        string getUserName(){
            return this->user_name;
        }
        void sendMessage(string msg,string groupName)
        {
            cout<<this->user_name<<" -> Sending Message := \x1B[31m"<<msg<<"\033[0m"<<endl;
            for(auto group : groups){
                if (group->getGroupName() == groupName){
                    group->new_message(msg, this);
                    return;
                } 
            }
            cout<<"Group/User not exist !!!"<<endl;
        }
        void sendAttachment(string attachment, string groupName)
        {
            cout<<this->user_name<<" -> Sending Attachment := "<<attachment<<endl;
            for(auto group : groups){
                if (group->getGroupName() == groupName){
                    group->new_attachment(attachment, this);
                    return;
                } 
            }
            cout<<"Group/User not exist !!!"<<endl;
        }
        ~User(){
            cout<<"User Dtor"<<endl;
            for(auto group : groups){
                group->unsubscriber(this);
            }
            groups.clear();
        }
};

//---------------------------------------


class Group : public IGroup
{
    private:
        string groupName;
        string newMessage;
        string newAttachment;
        list<ISubscriber*> users;
    public:
        Group(string name){
            this->groupName = name;
        }
        ~Group(){
            cout<<"Group Dtor"<<endl;
            for(auto user : users){
                user->unsubscribeGroup(this);
            }
            users.clear();
        }
        void subscriber(ISubscriber*);
        void unsubscriber(ISubscriber*);
        void notify(string, ISubscriber*);
        string getGroupName();
        void new_message(string, ISubscriber*);
        void new_attachment(string, ISubscriber*);
};

void Group::subscriber(ISubscriber* u)
{
    this->users.push_back(u);   
}
void Group::unsubscriber(ISubscriber* u)
{
    this->users.remove(u);
}

void Group::notify(string msg, ISubscriber* from_user)
{
    for (auto user : users)
    {
        if(user != from_user)
            user->notify(msg, from_user->getUserName());
    }
}
string Group::getGroupName()
{
    return this->groupName;
}
void Group::new_message( string msg, ISubscriber* user)
{
    this->newMessage = msg;
    this->notify(msg, user);
}
void Group::new_attachment(string attachment, ISubscriber* user)
{
    this->newAttachment = attachment;
}

//------------------------


//-------------------------------------------------
int main()
{
    IGroup *g_tost = new Group("Tost");
    IGroup *g_boost = new Group("Boost");

    ISubscriber *u1 = new User(1, "Kunal");
    ISubscriber *u2 = new User(2, "Mike");
    ISubscriber *u3 = new User(3, "john");
    ISubscriber *u4 = new User(3, "Diana");

    u1->subscribeGroup(g_tost);
    u2->subscribeGroup(g_tost);
    u3->subscribeGroup(g_tost);
    u1->subscribeGroup(g_boost);
    u2->subscribeGroup(g_boost);
    u3->subscribeGroup(g_boost);
    u1->sendMessage("Hi Everyone, Good Morning!!!",  g_tost->getGroupName());
    u2->sendMessage("Hi Everyone, Good Evening!!!",  g_boost->getGroupName());
    u3->unsubscribeGroup(g_tost);
    u4->subscribeGroup(g_tost);
    u2->sendMessage("Hi Everyone, Good Night!!!", g_tost->getGroupName());

    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete g_tost;
    delete g_boost;
    return 0;
}