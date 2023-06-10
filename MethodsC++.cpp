#include <iostream>
using namespace std;

class Target
{
public:
    virtual void Request() = 0;
};

class Adaptee
{
public:
    void SpecificRequest()
    {
        cout << "Adaptee.SpecificRequest()" << endl;
    }
};

class Adapter :public Target, public Adaptee
{
public:
    void Request()
    {
        SpecificRequest();
    }
};

class Client
{
public:
    void ClientMethod(Target& target)
    {
        target.Request();
    }

    void ClientMethod(Target* target)
    {
        target->Request();
    }
};

void main()
{
    Client client;
    Target* target = (Target*) new Adapter();
    client.ClientMethod(target); 
}