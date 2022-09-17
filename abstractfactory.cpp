#include<iostream>
#include<memory>
using namespace std;
class  IButton
{
    private:
    public:
        virtual void press() = 0;
        virtual ~IButton(){
            cout<<"IButton Dtor"<<endl;
        }
};

class MacButton : public IButton
{
    public:
        MacButton(){
            cout<<"MacButton Ctor"<<endl;
        }
        void press(){
            cout<<"Mac Button pressed"<<endl;
        }
        ~MacButton(){
            cout<<"MacButton Dtor"<<endl;
        }
};

class WindowsButton : public IButton
{
    public:
        WindowsButton(){
            cout<<"WindowsButton Ctor"<<endl;
        }
        void press(){
            cout<<"Windows Button pressed"<<endl;
        }
        ~WindowsButton(){
             cout<<"WindowsButton Dtor"<<endl;
        }
};

class ITextBox
{
private:
public:
    ITextBox(){
        cout<<"IText ctor"<<endl;
    }
     virtual void showTextBox() = 0;
     virtual ~ITextBox(){
        cout<<"IText Dtor"<<endl;
    }
};

class MacTextBox : public ITextBox
{
    public:
        MacTextBox(){
            cout<<"MacTextBox Ctor"<<endl;
        }
        void showTextBox(){
            cout<<"Mac TextBox Box"<<endl;
        }
        ~MacTextBox(){
            cout<<"MacTextBox Dtor"<<endl;
        }
};

class WindowsTextBox : public ITextBox
{
    public:
        WindowsTextBox(){
            cout<<"WindowsTextBox Ctor"<<endl;
        }
        void showTextBox(){
            cout<<"Windows TextBox Box"<<endl;
        }
        ~WindowsTextBox(){
            cout<<"WindowsTextBox Dtor"<<endl;
        }
};

class IGuiFactory{
    public:
        IGuiFactory(){
            cout<<"IGuiFactory Ctor"<<endl;
        }
        virtual IButton* createButton() = 0;
        virtual ITextBox* createTextBox() = 0;
        virtual ~IGuiFactory(){
            cout<<"IGuiFactory Dtor"<<endl;
        }

};

class MacFactory: public IGuiFactory
{
    public:
        MacFactory(){
            cout<<"MacFactory Ctor"<<endl;
        }
        IButton* createButton(){
            return new MacButton();
        }
        ITextBox* createTextBox(){
            return new MacTextBox();
        }
        ~MacFactory(){
            cout<<"MacFactory Dtor"<<endl;
        }
};
class WindowsFactory: public IGuiFactory
{
    public:
        WindowsFactory(){
            cout<<"WindowsFactory Ctor"<<endl;
        }
        IButton* createButton(){
            return new WindowsButton();
        }
        ITextBox* createTextBox(){
            return new WindowsTextBox();
        }
        ~WindowsFactory(){
            cout<<"WindowsFactory Dtor"<<endl;
        }
};

class GUIAbstractfactory
{
    public:
    static IGuiFactory* createfactory(string osType){
        if(osType == "windows"){
            return new WindowsFactory();
        }else if(osType == "mac"){
            return new MacFactory();
        }
        return new MacFactory();
    }
};

// -----------------client------------------
int main()
{
    string osType;
    cout<<"Enter your machine OS    :=   ";
    cin>>osType;

    IGuiFactory* fact = GUIAbstractfactory::createfactory(osType);
    IButton* button = fact->createButton();
    button->press();

    ITextBox* textbox = fact->createTextBox();
    textbox->showTextBox();

    delete fact;
    delete button;
    delete textbox;
    return 0;
}