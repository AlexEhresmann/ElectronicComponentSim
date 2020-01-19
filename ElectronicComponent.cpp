//************************************************************
// This source file contains the definition of the overloaded*
// << operator. 					                         *
//************************************************************

#include "ElectronicComponent.h"
#include <iostream>

ostream& operator<< (std::ostream& outputStream, const ElectronicComponent& component)
{
    outputStream << component.to_string();

    return outputStream;
}
