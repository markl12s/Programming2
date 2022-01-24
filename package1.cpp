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
const double MAXIMUM_WEIGHT = 99.9;

// functions
void get_input(int& weight, int& length, int& width, int& height);
int calculate_volume(int length, int width, int height);
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

    totalSize = calculate_volume(length, width, height);

    tooBig = compare(totalSize, MAXIMUM_SIZE);
    tooHeavy = compare(weight, MAXIMUM_WEIGHT);

    overWeightTot = how_much_overload(weight, MAXIMUM_WEIGHT);
    overSizeTot = how_much_overload(totalSize, MAXIMUM_SIZE);

    print_output(tooBig, tooHeavy, overSizeTot, overWeightTot);

    return 0;
}

void get_input(int& weight, int& length, int& width, int& height) {
    /*
    * inputs
    * @weight: the weight of the package
    * @ length: the length of the package
    * @width: the width of the package
    * @height: the height of the package
    */

    cout << "Please input the weight  : ";
    cin >> weight;
    cout << endl;

    cout << "Please input the length : ";
    cin >> length;

    cout << "Please input the width   : ";
    cin >> width;

    cout << "Please input the height  : ";
    cin >> height;

    /*
    * outputs
    * @weight: the weight of the package
    * @ length: the length of the package
    * @width: the width of the package
    * @height: the height of the package
    */
}

int calculate_volume(int length, int width, int height) {
    /*
    * inputs
    * @length: the length of the package
    * @width: the width of the package
    * @height: the height of the package
    */
    int finalSize;
    finalSize = length * width * height;
    return finalSize;
    /*
    * outputs
    * @finalSize: the volume of the package
    */
}

bool compare(int total, int target) {
    /*
    * inputs
    * @total: the number you are comparing
    * @target: the number you are comparing to
    */

    if (total >= target) { return true; }
    else { return false; }

    /*
    * outputs
    * boolean of whether or not it's bigger
    */
}

int how_much_overload(int total, int target) {
    /*
    * inputs
    * @total: the number you are comparing
    * @target: the number you are comparing to
    */

    if (total > target) { return total - target; }
    else { return -42; }

    /* output
    * integer of how much larger the total is than the target
    * edgecase: if total <= target returns -42, this shouldn't ever occur in the current form of the project
    * debug if occurs
    */
}

void print_output(bool tooBig, bool tooHeavy, int overSizeTot, int overWeightTot) {
    /* inputs
    * @tooBig: whether or not the package is too big
    * @tooHeavy: whether or not the package is too heavy
    * @overSizeTot: 
    */

    string message = "";
    int changes = 0;
    string overSizeString = to_string(overSizeTot);
    string overWeightString = to_string(overWeightTot);

    if (tooHeavy == true) {
        message = "Package is " + overSizeString + " oversized \n";
        changes += 1;
    }
    else { message = "package is within weight \n"; }

    if (tooBig == true) {
        message += "Package is " + overWeightString + " overweight \n";
        changes += 1;
    }
    else { message += "package is within size limits \n"; }

    if (changes == 0) {
        message = "Ship package.";
    }

    cout << message;

    /*
    * no outputs should occur
    */
}
