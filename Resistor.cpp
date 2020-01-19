//************************************************************
// This source file contains the overwritten to_string method*
// for the Resistor class.				                     *
//************************************************************

#include "Resistor.h"
#include <string>
#include <sstream>

string Resistor::to_string() const
{
    ostringstream sstream;
    sstream << resValue;

    return " Resistor value (" + sstream.str() + " " + resUnits + ")";
}
