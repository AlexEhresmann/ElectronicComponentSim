
//************************************************************
// This program reads information about electronic components*
// from the keyboard, stores that information using classes  *
// with inheritance, polymorphism and virtual functions then *
// prints information about the components.                  *
//                                                           *
// It includes header file for the use of stream operators,  *
// stream objects, string objects, string conversion, and    *
// programmer defined class objects.                         *
//************************************************************

#include <iostream>
#include <cstdlib>
#include <string>
#include "ElectronicComponent.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Battery.h"

using namespace std;

// These are the function prototypes

void componentsMenu();
void setComponents_contents(ElectronicComponent *[], int &);
void getComponents_contents(ElectronicComponent *[], int );
void deleteComponents(ElectronicComponent *[], int );

//************************************************************
// The main function defines an array of 50 pointers to      *
// abstract base class objects, which objects of all derived *
// classes are. Then the counter variable count, and the     *
// array are passed into the setComponents_contents function *
// which gets a valid choice from the user. Count is passed  *
// by reference so that it keeps a running total of how many *
// times valid component values were given.                  *
//                                                           *
// Then since arrays are passed by reference by default, the *
// array with the values entered into it during the          *
// setComponents_contents, and the current count value are   *
// passed into the getComponents_contents function which     *
// prints out the values entered into the array by the user. *
//                                                           *
// Then the deleteComponents function is called with the     *
// array and count passed in, which deletes each element in  *
// the array by calling the destructor corresponding to it's *
// derived class type since each element of the array was    *
// dynamically allocated.                                    *
//************************************************************

int main()
{
    const int MAX_CMPNNT_NUM = 50;

    ElectronicComponent *components[MAX_CMPNNT_NUM];

    int count = 0;

    setComponents_contents(components, count);

    getComponents_contents(components, count);

    deleteComponents(components, count);


    return 0;
}

//************************************************************
// The componentsMenu function outputs the menu of component *
// types when called.                                        *
//************************************************************

void componentsMenu()
{
    cout << "Please enter 1, 2, 3 or 4:"
         << "\n1 - Enter information about a resistor"
         << "\n2 - Enter information about a capacitor"
         << "\n3 - Enter information about a battery"
         << "\n4 - Print component information and terminate the program" << endl;
}

//************************************************************
// The setComponents_contents function takes the array and a *
// reference to count as parameters.                         *
//                                                           *
// Then calls the componentsMenu function and begins a nested*
// do/while loop that asks the user to choose from the       *
// component options, then takes the entry in as a string,   *
// tests' it for validity, and repeats the process until a   *
// valid choice is made.                                     *
//                                                           *
// When a valid choice has been made, then it converts the   *
// strChoice string to a c-string using c_str, and converts  *
// it to a double with atof.                                 *
//                                                           *
// Then the double userChoice is tested for validity using a *
// series of if/else if conditionals.                        *
//                                                           *
// Then depending on the user choice, another do/while loop  *
// is executed until a valid component value is entered.     *
//                                                           *
// A bool variable is set as a flag for invalid characters in*
// the component value string which are caught by looping    *
// through each character of the string, checking for invalid*
// characters. And this repeats until a valid value is given.*
//                                                           *
// Then the resVal_str is converted to a double. And set as  *
// the value of a dynamically created derived class object in*
// the array at location count.                              *
//                                                           *
// Then count is incremented, and the outermost do/while     *
// starts over, outputting the component choice menu and     *
// asking for another choice and component value until the   *
// user selects option 4. In which case the function ends.   *
//                                                           *
// And if the user enters 4 before anything else, the program*
// outputs an error prompt and exit's.                       *
//************************************************************

void setComponents_contents(ElectronicComponent *components[], int &count)
{
    string strChoice;
    double userChoice;

    do
    {
        do
        {
            componentsMenu();

            getline(cin,strChoice);

            if(strChoice != "1" && strChoice != "2" && strChoice != "3" && strChoice != "4")
            {
                cout << "Entry not accepted. Please enter ONLY 1, 2, 3, or 4" << endl << endl;
            }

        }while(strChoice != "1" && strChoice != "2" && strChoice != "3" && strChoice != "4");

        userChoice = atof(strChoice.c_str());

        if(userChoice == 1)
        {
            string resVal_str;
            double rValue;
            bool badValue = 0;

            do
            {
                badValue = 0;

                cout << "Please enter a value for the component" << endl;

                getline(cin,resVal_str);

                //ERROR CHECHKING
                for(unsigned int i = 0; i < resVal_str.size(); i++)
                {
                    if(resVal_str.at(i) != '0' && resVal_str.at(i) != '1' && resVal_str.at(i) != '2' && resVal_str.at(i) != '3' && resVal_str.at(i) != '4' && resVal_str.at(i) != '5' && resVal_str.at(i) != '6' && resVal_str.at(i) != '7' && resVal_str.at(i) != '8' && resVal_str.at(i) != '9' && resVal_str.at(i) != '.')
                    {
                        badValue = 1;
                    }
                }

                if(badValue)
                {
                    cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl << endl;
                }

            }while(badValue == 1);

            rValue = atof(resVal_str.c_str());

            components[count] = new Resistor(rValue);

            count++;
        }

        else if(userChoice == 2)
        {
            string capVal_str;
            double cValue;
            bool badValue = 0;

            do
            {
                badValue = 0;

                cout << "Please enter a value for the component" << endl;

                getline(cin,capVal_str);

                //ERROR CHECHKING
                for(unsigned int i = 0; i < capVal_str.size(); i++)
                {
                    if(capVal_str.at(i) != '0' && capVal_str.at(i) != '1' && capVal_str.at(i) != '2' && capVal_str.at(i) != '3' && capVal_str.at(i) != '4' && capVal_str.at(i) != '5' && capVal_str.at(i) != '6' && capVal_str.at(i) != '7' && capVal_str.at(i) != '8' && capVal_str.at(i) != '9' && capVal_str.at(i) != '.')
                    {
                        badValue = 1;
                    }
                }

                if(badValue)
                {
                    cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl << endl;
                }

            }while(badValue == 1);

            cValue = atof(capVal_str.c_str());

            components[count] = new Capacitor(cValue);

            count++;
        }

        else if(userChoice == 3)
        {
            string batVal_str;
            double bValue;
            bool badValue = 0;

            do
            {
                badValue = 0;

                cout << "Please enter a value for the component" << endl;

                getline(cin,batVal_str);

                //ERROR CHECHKING
                for(unsigned int i = 0; i < batVal_str.size(); i++)
                {
                    if(batVal_str.at(i) != '0' && batVal_str.at(i) != '1' && batVal_str.at(i) != '2' && batVal_str.at(i) != '3' && batVal_str.at(i) != '4' && batVal_str.at(i) != '5' && batVal_str.at(i) != '6' && batVal_str.at(i) != '7' && batVal_str.at(i) != '8' && batVal_str.at(i) != '9' && batVal_str.at(i) != '.')
                    {
                        badValue = 1;
                    }
                }

                if(badValue)
                {
                    cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl << endl;
                }

            }while(badValue == 1);

            bValue = atof(batVal_str.c_str());

            components[count] = new Battery(bValue);

            count++;
        }

    }while(userChoice != 4);

    if(userChoice == 4 && count == 0)
    {
        cout << "Error, not given any component data" << endl;
        exit(0);
    }
}

//************************************************************
// The getComponents_contents function takes in the array    *
// and count variable resulting from the                     *
// setComponents_contents function as parameters. Then it    *
// loops through the array twice, printing out the attributes*
// corresponding to the class type of the object being       *
// pointed to be the pointer at each array element, using    *
// count to only access array elements that were dynamically *
// given derived class object to point to.                   *
//                                                           *
// The arrow operator is used to access the                  *
// getComponent_value and getComponent_units methods for each*
// array element. These are both pure virtual functions in   *
// the abstract base class which then dynamically bind to the*
// derived type of the object that each array pointer points *
// to, calling the corresponding overwritten versions of them*
// The second loop uses an overloaded << operator in the     *
// third instance of << in the body of the second for loop to*
// use a << operator with a programmer defined object.       *
//                                                           *
// The overloaded << operator takes a reference to an output *
// stream object on the left of << and a const reference     *
// to an ElectronicComponent object on the right. Then is    *
// calls the pure virtual to_string method corresponding to  *
// the overwritten version of the type of the object being   *
// pointed to, which returns the component value and units as*
// a string and then returns that string to the output stream*                                                *
//************************************************************

void getComponents_contents(ElectronicComponent *components[], int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << "Component value is " << components[i]->getComponent_value() << " " << components[i]->getComponent_units() << endl;
    }

    cout << endl;

    for(int i = 0; i < count; i++)
    {
        cout << "Component " << (i+1) << *components[i] << endl;
    }
}

//************************************************************
// The deleteComponents function takes the array and the     *
// count resulting from the setComponents_contents function. *
//                                                           *
// Then it the count to loop through the array elements that *
// were dynamically allocated as derived class objects, then *
// using the delete keyword to call the virtual destructor in*
// the abstract base class ElectronicComponent, which will   *
// call the destructor corresponding to the class type of the*
// object being pointed to by the pointer at the given array *
// location.                                                 *
//************************************************************

void deleteComponents(ElectronicComponent *components[], int count)
{
    for(int i = 0; i < count; i++)
    {
        delete components[i];
    }
}
