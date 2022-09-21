#include <iostream>
using namespace std;


//====================================

class Adaptee
{
private:
    /* data */
public:
    Adaptee();
    void specificRequest();
    ~Adaptee();
};

Adaptee::Adaptee()
{
    cout<<"Adaptee Ctor called"<<endl;
}

Adaptee::~Adaptee()
{
    cout<<"Adaptee Dtor called"<<endl;
}

void Adaptee::specificRequest()
{
    cout<<"Adaptee specificRequest called"<<endl;
}

//===========================================
class IAdaptor{
    public:
        virtual void request() = 0;
};


class Adaptor : public IAdaptor
{
private:
    Adaptee *adaptee;
public:
    Adaptor(Adaptee*);
    ~Adaptor();
    void request();
};

Adaptor::Adaptor(Adaptee *adapte)
{
    this->adaptee = adapte;
}

Adaptor::~Adaptor()
{
    delete this->adaptee;
}

void Adaptor::request()
{
    this->adaptee->specificRequest();
}


//==================================================

int main()
{
    IAdaptor *adaptor = new Adaptor( new Adaptee());
    adaptor->request();
    delete adaptor;
    return 0;
}