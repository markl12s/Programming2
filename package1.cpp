#include <iostream>
#include <iomanip>

using namespace std;

// constants
const int MAXIMUM_SIZE = 10;
const int MAXIMUM_WEIGHT = 100;

int total_size(int length, int width, int height);
bool compare(int total, int target);

int main() {
    // variables
    int weight = 1;
    int length = 2;
    int width = 3;
    int height = 4;

    int totalSize;
    bool tooBig;
    bool tooHeavy;

    totalSize = total_size(length, width, height);

    tooBig = compare(totalSize, MAXIMUM_SIZE);
    tooHeavy = compare(weight, MAXIMUM_WEIGHT);
}

int total_size(int length, int width, int height) {
    int finalSize;
    finalSize = width * length * height;
    return finalSize;
}

bool compare(int total, int target) {
    if (total < target) { return true; }
    else { return false; }
}
