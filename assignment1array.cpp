#include "assignment1array.h"

const int SIZE = 100;
//Check for a certain integer and return its index.
int NumberCheck(int array[], int size, int number) {
	for (int i = 0; i < size; i++) {
		if (array[i] == number) {
			return i;
		}
	}
	return -1;
}
//function to modify the value of an integer when called with the index 
void ModifyInteger(int array[], int index, int newValue) {
	if (index < 0 || index >= SIZE) {
		throw out_of_range("Index out of range");
	}
	cout << "Old Value: " << array[index] << endl;
	array[index] = newValue;
	cout << "New Value: " << array[index] << endl;
}
//adds integer to the end of the array
void addInteger(int array[], int& size, int newValue) {
	if (size >= SIZE) {
		throw overflow_error("Array is full");
	}
	array[size++] == newValue;
}
//delete or replace an integer with 0.
void DeleteInteger(int array[], int& size, int index, bool remove) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of range");
	}
	if (remove) {
		for (int i = index; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
		size--;

	}
	else {
		array[index] = 0;
	}
}
