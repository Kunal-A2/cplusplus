#include<iostream>
using namespace std;

class Dog
{
    public:
    Dog()
    {
        cout<<" Dog : "<<this<<endl;
        cout<<" Dog() ctor called "<<endl;
        // bark();
        this->bark();
    }
    virtual void bark()
    {
        cout<<"Dog::bark() called"<<endl;
    }
    void seeCat()
    {
        cout<<this<<" : seeCat() called "<<endl;
        bark();
    }
    ~Dog()
    {
        bark();
        cout<< " Dog dtor called"<<endl;
    }
};
class yellowDog : public Dog
{
    public:
    yellowDog()
    {
        cout<<"yellowDog : "<<this<<endl;
        cout<<" yellowDog() ctor called "<<endl;
    }
    virtual void bark()
    {
        cout<<"yellowDog::bark() called"<<endl;
    }
    ~yellowDog()
    {
        cout<< " yellowDog dtor called"<<endl;
    }
};

int main()
{
    yellowDog yd;
    yd.seeCat();
    return 0;
}
