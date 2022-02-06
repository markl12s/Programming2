/*
* course: BuCS 238 Computer Programming II
*
* assignment : 1
* program : package.cpp
* programmer : Mark Leard
*
* description : compute package size
*
* comments : methods and a function with parameters
* style notes : variables camel case, functions snake case, constants upper snake case
*
* last modified: 15 Jan 2022

GRADING: 30/50 initially
        + 5
FINAL:  35/50

Algorithm: corrected and better
Module Interface Chart: not changed and very difficult to read, but the right idea
note to self: make sure to improve this next time, especially if he is giving this indept feedback
Code:

I put in debugging so you can see how to solve your issues.
Two main problems. One was a type mismatch and the other was an incorrect comparison.
You can see the changes I made so your program works correctly.
You should NOT give up on this and turn in code which doesn't work.
Your coding was much more complicated than it needed to be.  

Work harder to simplify it in subsequent programs.

Nonetheless, good try! Keep working at it.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// development tools
const bool TESTING = false;

// constants
const int MAXIMUM_SIZE = 10;
const double MAXIMUM_WEIGHT = 99.9;

// functions
void get_input(double& weight, int& length, int& width, int& height);
int calculate_volume(int length, int width, int height);
bool compare(double total, double target);
double how_much_overload(double total, double target);
void print_output(bool tooBig, bool tooHeavy, double overSizeTot, double overWeightTot);

//
// main loop
//
int main() {
    int i = 0;

    // COMMENT
    // It would be much better to put weight in the while loop
    // and stop the loop when weight is -1.  Using "break" is
    // generally considered to be poor programming.

    while (i < i + 1) {
        // size variables 
        double weight = 1;
        int length = 1;
        int width = 1;
        int height = 1;

        // final sizes
        int totalSize;

        // -----------------------------------
        // int overWeightTot;
        double overWeightTot;  // Bob change
        // -----------------------------------

        // probably should've been double, like overWeightTot
        int overSizeTot;

        // within limits
        // names should've been isTooBig and isTooHeavy
        bool tooBig;
        bool tooHeavy;

        // break is bad programming
        get_input(weight, length, width, height);
        if (weight == -1) { break; }

        totalSize = calculate_volume(length, width, height);

        // Bob programming to test calculate_volume
        // Test data: 1, 1 1 10   1, 1 1 11  1, 9 10 10
        // Result: it works
        cout << "totalSize : " << totalSize << endl;

        tooBig = compare((double)totalSize, (double)MAXIMUM_SIZE);
        tooHeavy = compare(weight, MAXIMUM_WEIGHT);
        
        // Bob programming to test compare()
        // Test data: 1, 1 1 9   1, 1 1 10   1, 1 1 11  99.8, 1 1 1   99.9, 1 1 1   100, 1 1 1
        // Result: Fails on boundaries
        // Fix: if (total>=target) should be if (total>target) : corrected
        // Note: might be type conversion issues since the type of the parameters changes
        //       in this case, it works because of automatic type conversion, but again
        //       it's "sloppy" programming
        cout << "tooBig    : " << tooBig << endl;
        cout << "tooHeavy  : " << tooHeavy << endl;
        // make both the same type, typecast to double
        // this was double and an int, to one function
        // always make sure to give the function they type of inputs it is designed to take

        overWeightTot = how_much_overload(weight, MAXIMUM_WEIGHT);
        overSizeTot = how_much_overload(totalSize, MAXIMUM_SIZE);

        // Bob programming to test how_much_overload()
        // Test data: 1, 1 1 10   1, 1 1 11  99.8, 1 1 1   99.9, 1 1 1   100, 1 1 1
        // Result: Fails all tests
        // Fix: You had overWeightTot defined as int, but it returns a double. Corrected.

        cout << "overWeightTot : " << overWeightTot << endl;
        cout << "overSizeTot   : " << overSizeTot << endl;

  
        print_output(tooBig, tooHeavy, overSizeTot, overWeightTot);

        cout << endl << endl;
    }
    return 0;
}

//
// functions
//
void get_input(double& weight, int& length, int& width, int& height) {
    /*
    * pre: none
    * post: weight, length, width and height are entered by user
    *
    * inputs
    * @Weight: the weight of the package
    * @Length: the length of the package
    * @Width : the width of the package
    * @Height: the height of the package
    */

    cout << "In order to exit put -1 as weight." << endl;
    cout << "Please input the weight  : ";
    cin >> weight;
    cout << endl;

    if (weight != -1) {
        cout << "Please input the length  : ";
        cin >> length;

        cout << "Please input the width   : ";
        cin >> width;

        cout << "Please input the height  : ";
        cin >> height;
        cout << endl;
    }

    /*
    * outputs
    * @Weight: the weight of the package
    * @Length: the length of the package
    * @Width: the width of the package
    * @Height: the height of the package
    */
}

int calculate_volume(int length, int width, int height) {
    /*
    * pre: lenght, width and height all defined as integers
    * post: volume calculated and returned as integer
    */

    int finalSize;
    finalSize = length * width * height;
    return finalSize;
}

bool compare(double total, double target) {
    /*
    * pre: total and target are doubles
    * post: tells whether total > target
    *
    * inputs
    * @total: the number you are comparing
    * @target: the number you are comparing to
    */

    // -----------------------------------
    //  if (total >= target) { return true; } this was wrong because it maximum is legal
    if (total > target) { return true; }
    // -----------------------------------
    else { return false; }

    /*
    * outputs
    * boolean of whether or not it's bigger
    */
}

double how_much_overload(double total, double target) {
    /*
    * pre: total and target are both doubles
    * post: tells how much  bigger total is than target
    * if it returns -42 that means total > target, should never print out that, that is mostly a debuggins tool
    *
    * inputs
    * @total: the number you are comparing
    * @target: the number you are comparing to
    */

    // compare total to target
    if (TESTING) {
        cout << "total  : " << total << endl;
        cout << "target : " << target << endl;
    }

     if (total > target) { return total - target; }
     else { // return -42; don't do this, should've been the line below
         return 0;
     }

    /* output
    * integer of how much larger the total is than the target
    * edgecase: if total <= target returns -42, this shouldn't ever occur in the current form of the project
    * debug if occurs
    */
}

void print_output(bool tooBig, bool tooHeavy, double overSizeTot, double overWeightTot) {
    /*
    * pre: checked if package is too big or too heavy, and know how much to big/heavy it is
    * post: printed out results for user
    *
    * inputs
    * @tooBig: whether or not the package is too big
    * @tooHeavy: whether or not the package is too heavy
    * @overSizeTot:
    */

    string message = "";
    string overSizeString = to_string(overSizeTot);
    string overWeightString = to_string(overWeightTot);

    cout << "PACKAGE INFORMATION" << endl;

    if (TESTING) { cout << "is too heavy : " << tooHeavy << endl; }

    int changes = 0;
    if (tooHeavy) {
        message = "Package is " + overWeightString + " oversized \n";
        ++changes;
    }
    else { message = "package is within weight \n"; }

    if (TESTING) { cout << "is too big : " << tooBig << endl; }

    if (tooBig) { /// wrong thing
        message += "Package is " + overSizeString + " overweight \n";
        ++changes;
    }
    else { message += "package is within size limits \n"; }

    if (changes == 0) { message = "Ship Package"; }

    cout << message;
}

// next time don't overenginner it like this
// Keep it simple, didn't have to be this hard
