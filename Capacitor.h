//************************************************************
// This header file contains the Capacitor class declaration *
// which has public access to the ElectronicComponent        *
// abstract base class. So it inherits all of the public     *
// methods of ElectronicComponent, which it must overwrite.  *
//                                                           *
// It contains 3 private member attributes, 2 constructors,  *
// a virtual destructor and 3 virtual methods.               *
//                                                           *
// The constructor taking one parameter and the getter       *
// methods are defined inline while to_string is defined in  *
// the Capacitor class source file.                          *
//************************************************************

#ifndef CAPACITOR_H_INCLUDED
#define CAPACITOR_H_INCLUDED

#include "ElectronicComponent.h"
#include <string>

class Capacitor : public ElectronicComponent
{
    private:

        double capValue;

        string capUnits = "Farad(s)";

        string componentType;

    public:
        Capacitor()
        {

        }

        Capacitor(double capacitorValue)
        { capValue = capacitorValue; }

        virtual ~Capacitor()
        {

        }

        virtual double getComponent_value() const
        { return capValue; }
        virtual string getComponent_units() const
        { return capUnits; }

        virtual string to_string() const;

};

#endif
