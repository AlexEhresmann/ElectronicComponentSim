//************************************************************
// This source file contains the overwritten to_string method*
// for the Capacitor class.				                     *
//************************************************************

#include "Capacitor.h"
#include <string>
#include <sstream>

string Capacitor::to_string() const
{
    ostringstream sstream;
    sstream << capValue;

    return " Capacitor value (" + sstream.str() + " " + capUnits + ")";
}
