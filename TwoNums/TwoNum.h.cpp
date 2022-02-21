// External backup here : 

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
    int GetNum1() {
        return num1;
    }

    int GetNum2() {
        return num2;
    }

    void GetNumbers(int num1, int num2) {
        cout << num1 << ", " << num2 << endl;
    }

private:
    // variables
    int num1;
    int num2;
};
