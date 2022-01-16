/*
* course: BuCS 238 Computer Programming II
*
* assignment : 1
* program : package.cpp
* programmer : Mark Leard
*
* description : compute package size
*
*  comments : methods and a function with parameters
*  style notes : variables camel case, functions snake case, constants upper snake case
*
* last modified: 15 Jan 2022
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// constants
const int MAXIMUM_SIZE = 10;
const int MAXIMUM_WEIGHT = 100;

// functions
void get_input(int& weight, int& length, int& width, int& height);
int calculate_size(int length, int width, int height);
bool compare(int total, int target);
int how_much_overload(int total, int target);
void print_output(bool tooBig, bool tooHeavy, int overSizeTot, int overWeightTot);

int main() {
    // variables
    int weight = 1;
    int length = 1;
    int width = 1;
    int height = 1;

    int totalSize;
    bool tooBig;
    bool tooHeavy;
    int overWeightTot;
    int overSizeTot;

    get_input(weight, length, width, height);

    totalSize = calculate_size(length, width, height);

    tooBig = compare(totalSize, MAXIMUM_SIZE);
    tooHeavy = compare(weight, MAXIMUM_WEIGHT);

    overWeightTot = how_much_overload(weight, MAXIMUM_WEIGHT);
    overSizeTot = how_much_overload(totalSize, MAXIMUM_SIZE);

    print_output(tooBig, tooHeavy, overSizeTot, overWeightTot);
}

void get_input(int& weight, int& length, int& width, int& height) {
    cout << "Please input the weight" << endl;
    cin >> weight;

    cout << "Please length the height" << endl;
    cin >> length;

    cout << "Please input the width" << endl;
    cin >> width;

    cout << "Please input the height" << endl;
    cin >> height;
}

int calculate_size(int length, int width, int height) {
    int finalSize;
    finalSize = length * width * height;
    return finalSize;
}

bool compare(int total, int target) {
    if (total >= target) { return true; }
    else { return false; }
}

int how_much_overload(int total, int target) {
    if (total > target) { return total - target; }
    else { return 0; }
}

void print_output(bool tooBig, bool tooHeavy, int overSizeTot, int overWeightTot) {
    string message = "";
    int changes = 0;
    string overSizeString = to_string(overSizeTot);
    string overWeightString = to_string(overWeightTot);
    
    if ( tooHeavy == true ) {
        message = "Package is " + overSizeString + " oversized \n";
        changes += 1;
    }
    else { message = "package is within weight"; }

    if ( tooBig == true ) {
        message += "Package is " + overWeightString + " overweight \n";
        changes += 1;
    }
    else { message += "package is within size limits \n"; }

    if (changes == 0) {
        message = "Ship package.";
    }

    cout << message;
}
