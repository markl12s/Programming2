#include <iostream>

using namespace std;

// constants
const MAXIMUM_SIZE = 10;
const MAXIMUM_WEIGHT = 100;

int main(){
    // variables
    int weight = 1;
    int length = 1;
    int width = 1;
    int height = 1;

    int totalSize = total_size(length, width, height);
    cout << totalSize;
}

int total_size(length, width, height){
    totalSize = length * width * height;
    return totalSize;
}

// create function to return array of user input of weight, length width and height
