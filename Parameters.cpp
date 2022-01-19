#include <iostream>

using namespace std;

// function prototype
void PassByValue(int num);
void PassByReference(int& num);
int PassByFunction(int num);

int main()
{
	int number = 5;
	PassByValue(number);
	cout << "in main PassByValue " << number << endl << endl;

	PassByReference(number);
	cout << "in main PassByReference " << number << endl << endl;

	PassByFunction(number);
	cout << "in main PassByFunction " << number << endl << endl;

	return 0;
}

void PassByValue(int num)
{
	cout << "in PassByValue : " << num << endl;
	num++;
	cout << "in PassByValue : " << num << endl;
}

void PassByReference(int& num)
{
	cout << "in PassByReference : " << num << endl;
	num++;
	cout << "in PassByReference : " << num << endl;
}

int PassByFunction(int num)
{
	cout << "in PassByFunction : " << num << endl;
	num++;
	cout << "in PassByFunction : " << num << endl;
	return num;
}
