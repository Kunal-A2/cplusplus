#include "receiver.h"
string Light::getState()
{
    return this->state;
}
void Light::execute(string option){
    this->state = option;
}