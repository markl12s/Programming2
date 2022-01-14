/*
* course: BuCS 238 Computer Programming II
* 
* assignment : 0
* program : GasPrice4.cpp
* programmer : Mark Leard
* 
* description : compute cost of gas per month
* 
*  comments : methods and a function with parameters
* 
* last modified: 13 Jan 2022
*/

#include <iostream>
#include <iomanip>

using namespace std;

// constants
const double GAS_PRICE = 2.999;

// functions
void printCopyright();
void getInfo(int& monthlyMileage, double& mpg); // the & for when the variable will change, so it will change the actual variable
double calculateResults(int monthlyMileage, double mpg);
void outputResults(double monthlyGasCost);

int main() {
	// variables
	int monthlyMileage;
	double mpg; // Miles Per Gallon
	double monthlyGasCost;

	printCopyright();
	getInfo(monthlyMileage, mpg);
	monthlyGasCost = calculateResults(monthlyMileage, mpg);
	outputResults(monthlyGasCost);

	return 0;
}


void printCopyright() {
	cout << "GasPrice program" << endl;
	cout << "c 2022 Mark Leard" << endl << endl;
}

void getInfo(int& monthlyMileage, double& mpg) {
	cout << "Enter monthly mileage  : ";
	cin >> monthlyMileage;

	cout << "Enter miles per gallon : ";
	cin >> mpg;
}

double calculateResults(int monthlyMileage, double mpg) {
	double monthlyGasCost;

	monthlyGasCost = (monthlyMileage / mpg) * GAS_PRICE;

	return monthlyGasCost;
}

void outputResults(double monthlyGasCost) {
	cout << endl << "You spend $";
	cout << fixed << setprecision(2);
	cout << monthlyGasCost << " a month on gas." << endl;

	printf("You spend $%0.2f a month on gas. \n\n", monthlyGasCost);
}
