#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton{

    int count;
    string objName;
    static mutex _mutex;
    static Singleton* _instance;

    private:
        // Make default ctor and dtor private so that no one directly create the object 
        Singleton(string &name) 
        {
            this->objName = name;
            cout<<"Object Creation intiated"<<endl;
        }
        ~Singleton(){
            cout<<"Singleton Dtor called"<<endl;
        }
    public:
        /**
         * Singletons should not be cloneable.
        */
        Singleton(const Singleton &obj) = delete;

        //  Singletons should not be assignable.
        void operator=(const Singleton &obj) = delete;

        static Singleton* createInstance(string name) 
        {
            
            std::lock_guard<std::mutex> lock(_mutex);
            if (_instance == nullptr)
            {
                _instance = new Singleton(name);
            }
            return _instance;
        }

        string getThreadNmae(){
            return this->objName;
        }
        
};

// Static methods should be defined outside the class.
Singleton* Singleton::_instance = nullptr;
std::mutex Singleton::_mutex;

void createthreads(string name){
    Singleton *obj = Singleton::createInstance(name);
    cout<<"Thread Name := "<<std::this_thread::get_id()<<" objNameref := "<<obj->getThreadNmae()<<endl; 
}

int main()
{
    std::thread t1(createthreads, "Foo");
    std::thread t2(createthreads, "Bar");
    std::thread t3(createthreads, "Foo2");
    std::thread t4(createthreads, "Bar2");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}