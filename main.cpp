/*Sergio Olivas
* Assigment 1
*/
#include "assignment1array.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//number of integers in the file.
const int SIZE = 100;

int main() {

	//Array to take input from file.
	int numbers[SIZE];
	int count = 0;

	//Check if file opened correctly and add the numbers into the array.
	ifstream inputFile("A1input.txt");
	if (!inputFile.is_open()) {
		cerr << "Failed to open the file." << endl;
	}
	string line;
	while (getline(inputFile, line)) {
		istringstream lineStream(line);
		int number;
		while (lineStream >> number) {
			if (count < SIZE) {
				numbers[count++] = number;
			}
			else {
				cerr << "Array size exceeded." << endl;
				inputFile.close();
			}
		}
	}
	inputFile.close();
	//Trying the functions out with exceptions.
	try {
		int numberToFind = 28;
		int index = NumberCheck(numbers, count, numberToFind);
		if (index != -1) {
			std::cout << "Number " << numberToFind << " found at index " << index << "." << std::endl;
		}
		else {
			std::cout << "Number " << numberToFind << " not found in the array." << std::endl;
		}

		int indexToModify = 78;
		int newValue = 22;
		ModifyInteger(numbers, indexToModify, newValue);

		int newValueToAdd = 101;
		addInteger(numbers, count, newValueToAdd);
		std::cout << "Added new value: " << newValueToAdd << std::endl;

		int indexToReplace = 11;
		DeleteInteger(numbers, count, indexToReplace, true);
		std::cout << "Removed value at index " << indexToReplace << "." << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}

	return 0;
}