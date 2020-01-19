//************************************************************
// This source file contains the overwritten to_string method*
// for the Battery class.				     *
//************************************************************

#include "Battery.h"
#include <string>
#include <sstream>

string Battery::to_string() const
{
    ostringstream sstream;
    sstream << batValue;

    return " Battery value (" + sstream.str() + " " + batUnits + ")";
}
