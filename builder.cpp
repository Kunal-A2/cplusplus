#include<iostream>
#include <memory>
using namespace std;

// Main Product Class

class Desktop
{
private:
    string keyboard;
    string monitor;
    string motherboard;
    string mouse;
    string processor;
    string ram;
    string speaker;
public:
    void setKeyboard(string);
    void setMonitor(string);
    void setMotherboard(string);
    void setMouse(string);
    void setProcessor(string);
    void setRam(string);
    void setSpeaker(string);
    void showSpec();
};

void Desktop::setKeyboard(string pKeyboard){
    this->keyboard = pKeyboard;
}
void Desktop::setMonitor(string pMonitor)
{
    this->monitor = pMonitor;
}
void Desktop::setMotherboard(string pMotherBoard)
{
    this->motherboard = pMotherBoard;
}
void Desktop::setMouse(string pMouse)
{
    this->mouse = pMouse;
}
void Desktop::setProcessor(string pProcessor)
{
    this->processor = pProcessor;
}
void Desktop::setRam(string pRam)
{
    this->ram = pRam;
}
void Desktop::setSpeaker(string pSpeaker)
{
    this->speaker = pSpeaker;
}
void Desktop::showSpec(){
    cout<<"Keyboard     :=      "<<keyboard<<endl;
    cout<<"Monitor      :=      "<<monitor<<endl;
    cout<<"motherboard  :=      "<<motherboard<<endl;
    cout<<"Mouse        :=      "<<mouse<<endl;
    cout<<"Processor    :=      "<<processor<<endl;
    cout<<"Ram          :=      "<<ram<<endl;
    cout<<"Speaker      :=      "<<speaker<<endl;
}

//------------------------------------------------------


class DesktopBuilder {
    protected:
        // DesktopBuilder has a Desktop product
        Desktop *desktop;
    public:
        DesktopBuilder();
        virtual void buildKeyboard() = 0;
        virtual void buildMonitor() = 0;
        virtual void buildMotherboard() = 0;
        virtual void buildMouse() = 0;
        virtual void buildProcessor() = 0;
        virtual void buildRam() = 0;
        virtual void buildSpeaker() = 0;
        // sometime we can return product from the concreate class
        virtual Desktop* getDesktop(){
            return this->desktop;
        }
        virtual ~DesktopBuilder();
};

DesktopBuilder::DesktopBuilder()
{
    desktop = new Desktop();
}
DesktopBuilder::~DesktopBuilder(){
    cout<<"DesktopBuilder Dtor"<<endl;
    delete desktop;
}
// ------------Concreate class builder----------------
class DellDesktopBuilder : public DesktopBuilder
{
    public:
        void buildKeyboard();
        void buildMonitor();
        void buildMotherboard();
        void buildMouse();
        void buildProcessor();
        void buildRam();
        void buildSpeaker(); 
        ~DellDesktopBuilder();
};

DellDesktopBuilder::~DellDesktopBuilder()
{
    cout<<"DellDesktopBuilder Dtor"<<endl;
}

void DellDesktopBuilder::buildKeyboard(){
    desktop->setKeyboard("Dell keyboard config file");
}
void DellDesktopBuilder::buildMonitor(){
    desktop->setMonitor("Dell  monitor config file");
}
void DellDesktopBuilder::buildMotherboard(){
    desktop->setMotherboard("Dell motherboard config file");
}
void DellDesktopBuilder::buildMouse(){
    desktop->setMouse("Dell mouse config file");
}
void DellDesktopBuilder::buildProcessor(){
    desktop->setProcessor("Dell processor config file");
}
void DellDesktopBuilder::buildRam(){
    desktop->setRam("Dell RAM config file");
}
void DellDesktopBuilder::buildSpeaker(){
    desktop->setSpeaker("Dell speaker config file");
}

// -----------second concreate class --------------------------

class HpDesktopBuilder : public DesktopBuilder
{
    public:
        void buildKeyboard();
        void buildMonitor();
        void buildMotherboard();
        void buildMouse();
        void buildProcessor();
        void buildRam();
        void buildSpeaker(); 
        ~HpDesktopBuilder();
};

HpDesktopBuilder::~HpDesktopBuilder(){
    cout<<"HpDesktopBuilder Dtor"<<endl;
}
void HpDesktopBuilder::buildKeyboard(){
    desktop->setKeyboard("Hp keyboard config file");
}
void HpDesktopBuilder::buildMonitor(){
    desktop->setMonitor("Hp  monitor config file");
}
void HpDesktopBuilder::buildMotherboard(){
    desktop->setMotherboard("Hp motherboard config file");
}
void HpDesktopBuilder::buildMouse(){
    desktop->setMouse("Hp mouse config file");
}
void HpDesktopBuilder::buildProcessor(){
    desktop->setProcessor("Hp processor config file");
}
void HpDesktopBuilder::buildRam(){
    desktop->setRam("Hp RAM config file");
}
void HpDesktopBuilder::buildSpeaker(){
    desktop->setSpeaker("Hp speaker config file");
}

//-------------------------Director class has all the Builder interface -------------

class  DesktopDirector
{
private:
    DesktopBuilder *desktopBuilder;
public:
    DesktopDirector(DesktopBuilder *pDesktopBuilder);
    Desktop* buildDesktop();
    ~ DesktopDirector();
};

Desktop* DesktopDirector::buildDesktop(){
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMotherboard();
        desktopBuilder->buildMouse();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildRam();
        desktopBuilder->buildSpeaker();
        return desktopBuilder->getDesktop();
}
DesktopDirector::DesktopDirector(DesktopBuilder *pDesktopBuilder)
{
    this->desktopBuilder = pDesktopBuilder;
}

DesktopDirector::~DesktopDirector(){
    cout<<"DesktopDirector Dtor"<<endl;
    delete desktopBuilder;
}

// --------------Client -------------
int main()
{
    // HpDesktopBuilder *hpDesktopBuilder =  new HpDesktopBuilder();
    // DellDesktopBuilder *dellDesktopBuilder = new DellDesktopBuilder();
    // DesktopDirector *desktopDirector = nullptr;

    // desktopDirector = new DesktopDirector(hpDesktopBuilder);
    // desktopDirector->buildDesktop()->showSpec();
    // delete desktopDirector;
    // desktopDirector = new DesktopDirector(dellDesktopBuilder); 
    // desktopDirector->buildDesktop()->showSpec();
    // delete desktopDirector;

    //--------------------------------------------------------
    
    // DesktopDirector *desktopDirector = nullptr;
    // desktopDirector = new DesktopDirector(new HpDesktopBuilder());
    // desktopDirector->buildDesktop()->showSpec();
    // delete desktopDirector;
    // desktopDirector = new DesktopDirector(new DellDesktopBuilder()); 
    // desktopDirector->buildDesktop()->showSpec();
    // delete desktopDirector;

    //--------------------------------------------------------
    
    unique_ptr<DesktopDirector> hp_ptr(new DesktopDirector(new HpDesktopBuilder()));
    hp_ptr->buildDesktop()->showSpec();
    unique_ptr<DesktopDirector> dell_ptr(new DesktopDirector(new DellDesktopBuilder()));
    dell_ptr->buildDesktop()->showSpec();
    return 0;
}


