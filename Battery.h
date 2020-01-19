//************************************************************
// This header file contains the Battery class declaration   *
// which has public access to the ElectronicComponent        *
// abstract base class. So it inherits all of the public     *
// methods of ElectronicComponent, which it must overwrite.  *
//                                                           *
// It contains 3 private member attributes, 2 constructors,  *
// a virtual destructor and 3 virtual methods.               *
//                                                           *
// The constructor taking one parameter and the getter       *
// methods are defined inline while to_string is defined in  *
// the Battery class source file.                            *
//************************************************************

#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED

#include "ElectronicComponent.h"
#include <string>

class Battery : public ElectronicComponent
{
    private:

        double batValue;

        string batUnits = "Volt(s)";

        string componentType;

    public:

        Battery()
        {

        }

        Battery(double batteryValue)
        { batValue = batteryValue; }

        virtual ~Battery()
        {

        }


        virtual double getComponent_value() const
        { return batValue; }

        virtual string getComponent_units() const
        { return batUnits; }

        virtual string to_string() const;

};

#endif
