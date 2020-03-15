#include "exampleWithCopyConstructor.h"

exampleWithCopyConstructor::exampleWithCopyConstructor()
{
    //ctor
}

exampleWithCopyConstructor::~exampleWithCopyConstructor()
{
    //dtor
}

exampleWithCopyConstructor::exampleWithCopyConstructor(const exampleWithCopyConstructor& other)
{
    //copy ctor
}

exampleWithCopyConstructor& exampleWithCopyConstructor::operator=(const exampleWithCopyConstructor& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
