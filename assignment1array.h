#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int NumberCheck(int array[], int size, int number);
void ModifyInteger(int array[], int index, int newValue);
void addInteger(int array[], int& size, int newValue);
void DeleteInteger(int array[], int& size, int index, bool remove);