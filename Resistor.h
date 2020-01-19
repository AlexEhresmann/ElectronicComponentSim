//************************************************************
// This header file contains the Resistor class declaration  *
// which has public access to the ElectronicComponent        *
// abstract base class. So it inherits all of the public     *
// methods of ElectronicComponent, which it must overwrite.  *
//                                                           *
// It contains 3 private member attributes, 2 constructors,  *
// a virtual destructor and 3 virtual methods.               *
//                                                           *
// The constructor taking one parameter and the getter       *
// methods are defined inline while to_string is defined in  *
// the Resistor class source file.                           *
//************************************************************

#ifndef RESISTOR_H_INCLUDED
#define RESISTOR_H_INCLUDED

#include "ElectronicComponent.h"
#include <string>

class Resistor : public ElectronicComponent
{
    private:

        double resValue;

        string resUnits = "Ohms(s)";

        string componentType;

    public:

        Resistor()
        {

        }

        Resistor(double resistorValue)
        { resValue = resistorValue; }

        virtual ~Resistor()
        {

        }

        virtual double getComponent_value() const
        { return resValue; }

        virtual string getComponent_units() const
        { return resUnits; }

        virtual string to_string() const;

};

#endif
