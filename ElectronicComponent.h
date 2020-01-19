//************************************************************
// The ElectronicComponent header file declares the          *
// ElectronicComponent abstract base class with three pure   *
// virtual functions and a virtual ElectronicComponent       *
// destructor.                                               *
//                                                           *
// The file contains an overloaded << operator function      *
// outside of the class, as a stand alone function being     *
// overwritten in the ostream class to allow use of << with  *
// ElectronicComponent objects. So it isn't inherited by     *
// derived objects or required to be declared in them but is *
// accessible by all source files including this header file.*
//************************************************************

#ifndef ELECTRONICCOMPONENT_H_INCLUDED
#define ELECTRONICCOMPONENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ElectronicComponent
{
    public:

        virtual double getComponent_value() const = 0;

        virtual string getComponent_units() const = 0;

        virtual string to_string() const = 0;

        virtual ~ElectronicComponent(){}

};

ostream& operator<< (std::ostream& outputStream, const ElectronicComponent& component);

#endif
