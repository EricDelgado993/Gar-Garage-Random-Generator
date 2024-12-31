//-------------------------------------------
// Eric Delgado
// 04-16-2021
// Project 1
//-------------------------------------------

//-------------------------------------------
// Pre-processor directives
//-------------------------------------------
#include <iostream>
#include <string>
#include <string.h>
#include <random>
#include <fstream>

//-------------------------------------------
// Declare Namespace
//-------------------------------------------
using namespace std;

//-------------------------------------------
// Header Files
//-------------------------------------------
#include "Car.h"
#include "CarFunctions.h"

//-------------------------------------------
// Main Function
//-------------------------------------------
int main(int argc, char* argv[])
{
	// check to see if arg count is sufficient
	while (argc > 4 || argc < 4)
	{
		cout << "The program should have 3 parameters." << endl;

		return -1;
	}

	// capture parameter input
	string brandFile = argv[1];
	string colorFile = argv[2];
	string modelFile = argv[3];

	// first parameter validation
	while (brandFile != "brands.txt")
	{
		cout << brandFile << " is not the first parameter" << endl;
		cout << "First Parameter should be brands.txt" << endl;

		system("pause");

		return -2;
	}

	// second parameter validation
	while (colorFile != "colors.txt")
	{
		cout << colorFile << " is not the second parameter" << endl;
		cout << "Second Parameter should be colors.txt" << endl;

		system("pause");

		return -3;
	}

	// third parameter validation
	while (modelFile != "models.txt")
	{
		cout << modelFile << " is not the third parameter" << endl;
		cout << "Third Parameter should be models.txt" << endl;

		system("pause");

		return -4;
	}
	
	// arrays for car attributes
	string brandArray[10];
	string colorArray[10];
	string modelArray[10];

	// array for car objects
	Car carArray[100];

	// call arrayFill to fill data into arrays
	arrayFill(brandFile, brandArray);
	arrayFill(colorFile, colorArray);
	arrayFill(modelFile, modelArray);

	// data check - iterate through array for data instance
	for (int index = 0; index < 10; index++)
	{
		// check for null instance in arrays
		while (brandArray[index] == "" || colorArray[index] == "" || modelArray[index] == "")
		{
			cout << "Data not found in array(s)" << endl;

			system("pause");

			return -5;
		}
	}

	// object for file path
	Output filePath;

	// function calls for program
	createGarage(carArray, 100, brandArray, colorArray, modelArray, 10);
	printUnsortGarage(carArray, 100, "unsortedData.txt");
	printSortGarage(carArray, 100, "sortedData.txt", brandArray, colorArray, modelArray, 10);
	printOutput(carArray, 100, brandArray, colorArray, modelArray, 10, filePath);

}
