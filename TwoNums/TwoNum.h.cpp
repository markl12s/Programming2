// External backup here : https://github.com/markl12s/Programming2/tree/main/TwoNums

/*
* course: BuCS 238 Computer Programming II
*
* assignment : 3
* program : TwoNum
* programmer : Mark Leard
*
* description : various functions with Two numbers
*
* last modified: 21 Feb 2022
*/


#include <iostream>
#include <iomanip>

using namespace std;

// TwoNums
class TwoNum {
public:
    // constructors
    TwoNum() {
        num1 = 0;
        num2 = 0;
    }

    TwoNum(int firstNum, int secondNum) {
        num1 = firstNum;
        num2 = secondNum;
    }

    // methods
    void GetNum1() {
        cout << num1;
    }

    void GetNum2() {
        cout << num2;
    }

    void GetNumbers() {
        cout << num1 << ", " << num2 << endl;
    }

    void Sum() {
        total = num1 + num2;
        cout << total;
    }

    void Set(int first, int second) {
        num1 = num1 + first;
        num2 = num1 + second;
    }

private:
    // variables
    int num1;
    int num2;
    int total;
};
