#include <iostream>
using namespace std;
 
class Vehical {    
    public:
        Vehical(){
            cout<<" ........Vehical ctor ........."<<endl;
        }
        
        virtual void init() = 0;
        virtual void vehicalDetails() = 0;

        virtual ~Vehical(){
            cout<<"  ~~~~~~~~~Vehical dtor called ~~~~~~~~~~"<<endl;
        }
};

class Car : public Vehical
{
    private:
        int number_of_saet;
        string model;
        string vehical_number;
        string company;
        string engin_type;  
    public:
        Car(){
            this->init();
            cout<<".......... Car Object created ....... "<<endl;
        }
        void init() override
        {
            cout<<"Car Object initializing .... "<<endl;
            cout<<"Enter Company  :=    ";
            cin>>this->company;
            cout<<"Enter model  :=    ";
            cin>>this->model;
            cout<<"Enter engine_type  :=    ";
            cin>>this->engin_type;
            cout<<"Enter vehical_number  :=    ";
            cin>>this->vehical_number;
            cout<<"Enter number_of_seat  :=    ";
            cin>>this->number_of_saet;
        }
        void vehicalDetails(){
            cout<<"Car details -> model := "<<model<<", company := "<<company
                <<", engine_type := "<<engin_type<<", vehical_number := "<<vehical_number
                <<", Seat := "<<number_of_saet<<endl; 
        }
        ~Car(){
            cout<<" ~~~~~~~~~ Car Dtor ~~~~~~~~~~~~~"<<endl;
        }
};

class Bike : public Vehical
{
    private:
        string model;
        string vehical_number;
        string company;
    public:
        Bike(){
            this->init();
            cout<<" ............Bike Object created ....."<<endl;
        }
        void init() override
        {
            cout<<"Bike Object initializing .... "<<endl;
            cout<<"Enter Company  :=    ";
            cin>>this->company;
            cout<<"Enter model  :=    ";
            cin>>this->model;
            cout<<"Enter vehical_number  :=    ";
            cin>>this->vehical_number;
        }
        void vehicalDetails(){
            cout<<"Bike details -> model := "<<model<<", company := "<<company
                <<", vehical_number := "<<vehical_number<<endl; 
        }
        ~Bike(){
            cout<<"~~~~~~~~~~~ Bike Dtor ~~~~~~~~~~~~"<<endl;
        }
};
 

class Truck : public Vehical
{
    private:
        int number_of_wheel;
        string model;
        string vehical_number;
        string company;
    public:
        Truck(){
            this->init();
            cout<<" ...... Truck obj created ...."<<endl;
        }
        void init() override
        {
            cout<<"Truck Object initializing .... "<<endl;
            cout<<"Enter Company  :=    ";
            cin>>this->company;
            cout<<"Enter model  :=    ";
            cin>>this->model;
            cout<<"Enter vehical_number  :=    ";
            cin>>this->vehical_number;
            cout<<"Enter number_of_wheel  :=    ";
            cin>>this->number_of_wheel;
        }
        void vehicalDetails(){
            cout<<"Truck details -> model := "<<model<<", company := "<<company
                <<", vehical_number := "<<vehical_number<<", number_of_wheel := "<<number_of_wheel<<endl; 
        }
        ~Truck(){
            cout<<" ~~~~~~~~ Truck Dtor ~~~~~~~~~~"<<endl;
        }
};

/*
    Factory class
*/

class VehicalFactory{
    public:
    static Vehical* getInstance(string  vehical_type){
        Vehical *vehical_ptr = nullptr;
        if (vehical_type == "Car"){
            vehical_ptr = new Car;
        } else if(vehical_type == "Bike") {
            vehical_ptr = new Bike;
        } else if( vehical_type == "Truck"){
            vehical_ptr = new Truck;
        }
        return vehical_ptr;
    }
};
/*
    client code
*/ 
int main(){
    Vehical *car = VehicalFactory::getInstance("Car");
    Vehical *bike = VehicalFactory::getInstance("Bike");
    car->vehicalDetails();
    bike->vehicalDetails();
    //delete the allocated space of object
    delete car;
    delete bike;
    return 0;
}

/* Test Input 
BMW
M8
Petrol
12BR1675
6
Ducati
SuperSport
09BR2212
*/