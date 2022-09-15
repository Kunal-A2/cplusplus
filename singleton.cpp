#include<iostream>
#include <thread>
#include<mutex>

using namespace std;

class Singleton{
    static Singleton* _instance;
    int count;
    string objName;
    static mutex _mutex;
    private:
        Singleton(string &name) 
        {
            this->objName = name;
            cout<<"Object Creation intiated"<<endl;
        }
        ~Singleton(){
            cout<<"Singleton Dtor called"<<endl;
        }
    public:
        Singleton(const Singleton &obj) =delete;
        Singleton& operator=(const Singleton &obj) = delete;

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

Singleton* Singleton::_instance = nullptr;
std::mutex Singleton::_mutex;

void createthreads(string name){
    Singleton *obj = Singleton::createInstance(name);
    cout<<"Thread Name := "<<obj->getThreadNmae()<<endl;
}

int main()
{
    string params = "Foo";
    std::thread t1(createthreads, params);
    std::thread t2(createthreads, params);
    std::thread t3(createthreads, params);
    std::thread t4(createthreads, params);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}