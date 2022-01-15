#include <iostream>
#include <iomanip>

using namespace std;

// constants
const int MAXIMUM_SIZE = 10;
const int MAXIMUM_WEIGHT = 100;

int total_size(int length, int width, int height);

int main() {
    // variables
    int weight = 1;
    int length = 1;
    int width = 1;
    int height = 1;
    int totalSize;

    totalSize = total_size(length, width, height);
}

int total_size(int length, int width, int height) {
    int finalSize;
    finalSize = width * length * height;
    return finalSize;
}
