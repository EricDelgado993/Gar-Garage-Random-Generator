#pragma once

// fill array with data from file
void arrayFill(string fileName, string nameArray[])
{
	ifstream inFile;	// placeholder for file object
	int index = 0;		// index of array

	inFile.open(fileName);

	// iterate through each line until end of file
	while (!inFile.eof())
	{
		// store string from file into array
		inFile >> nameArray[index];

		index++;
	}

	inFile.close();
}

// fill car object array with data from several arrays
void createGarage(Car carArray[], int arraySize1, string brandArray[], string colorArray[], string modelArray[], int arraySize2)
{
	// generates random number between 0 and arraySize2
	random_device rdevice{};
	default_random_engine num{ rdevice() };
	uniform_int_distribution<unsigned int> randomNum{ 0, (unsigned int)arraySize2 - 1};
	
	// generates random number between 0 and 150
	random_device rdevice2{};
	default_random_engine num2{ rdevice2() };
	uniform_int_distribution<unsigned int> randomNum2{ 0, 150 };

	// fill car object array with data
	for (int index = 0; index < arraySize1; index++)
	{
		// variables containing RGN
		// used to select random array element
		int randIndex1 = randomNum(num);
		int randIndex2 = randomNum(num);
		int randIndex3 = randomNum(num);

		// variable for speed (0 - 150)
		int randSpeed = randomNum2(num2);

		// fill elements of car object array with data
		carArray[index].brand = brandArray[randIndex1];
		carArray[index].color = colorArray[randIndex2];
		carArray[index].model = modelArray[randIndex3];
		carArray[index].maxSpeed = randSpeed;
	}


}

// create output text file of car array conents
void printUnsortGarage(Car carArray[], int arraySize, string outPath)
{
	// placeholder for output file
	ofstream outFile;

	outFile.open("Output\\" + outPath);
	
	// print contents of array to file
	for (int index = 0; index < arraySize; index++)
	{
		outFile << "Car #" << index << endl;
		outFile << "------------------------------------------" << endl;
		outFile << "Brand: " << carArray[index].brand << endl;
		outFile << "Model: " << carArray[index].model << endl;
		outFile << "Color: " << carArray[index].color << endl;
		outFile << "Speed: " << carArray[index].maxSpeed << endl;
		outFile << "------------------------------------------" << endl;
		outFile << "" << endl;
	}

	outFile.close();
}

// create output text file of sorted car array contents
void printSortGarage(Car carArray[], int arraySize1, string outPath, string brandArray[], string colorArray[], string modelArray[], int arraySize2)
{
	// variable for user input
	int selection;

	// placeholder for file object
	ofstream outFile;

	outFile.open("Output\\" + outPath);

	cout << "How would you like output to be sorted?" << endl;
	cout << "1. Brands" << endl;
	cout << "2. Models" << endl;
	cout << "3. Colors" << endl;
	
	cin >> selection;

	// sort data by brand
	if (selection == 1)
	{
		// car's index in array
		int carNum = 0;

		// iterate through each car brand
		for (int brandIndex = 0; brandIndex < arraySize2; brandIndex++)
		{
			// iterate through each element in car array
			for (int carIndex = 0; carIndex < arraySize1; carIndex++)
			{
				// print to file if selected brand matches with corresponding element in array
				// check sorts data by brand
				if (carArray[carIndex].brand == brandArray[brandIndex])
				{
					outFile << "Car #" << carNum << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "Brand: " << carArray[carIndex].brand << endl;
					outFile << "Model: " << carArray[carIndex].model << endl;
					outFile << "Color: " << carArray[carIndex].color << endl;
					outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "" << endl;

					carNum++;
				}
			}
		}
	}

	// sort data by model
	else if (selection == 2)
	{
		// car's position in list
		int carNum = 0;

		// iterate through each car model
		for (int modelIndex = 0; modelIndex < arraySize2; modelIndex++)
		{
			// iterate through each element in car array
			for (int carIndex = 0; carIndex < arraySize1; carIndex++)
			{
				// print to file if selected model matches with corresponding element in array
				// check sorts data by model
				if (carArray[carIndex].model == modelArray[modelIndex])
				{
					outFile << "Car #" << carNum << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "Brand: " << carArray[carIndex].brand << endl;
					outFile << "Model: " << carArray[carIndex].model << endl;
					outFile << "Color: " << carArray[carIndex].color << endl;
					outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "" << endl;

					carNum++;
				}
			}
		}
	}

	// sort data by color
	else if (selection == 3) {
		// variable for car's position in list
		int carNum = 0;

		// iterate through each car color
		for (int colorIndex = 0; colorIndex < arraySize2; colorIndex++)
		{
			// iterate through each element in car array
			for (int carIndex = 0; carIndex < arraySize1; carIndex++)
			{
				// print to file if selected color matches with corresponding element in array
				// check sorts data by color
				if (carArray[carIndex].color == colorArray[colorIndex])
				{
					outFile << "Car #" << carNum << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "Brand: " << carArray[carIndex].brand << endl;
					outFile << "Model: " << carArray[carIndex].model << endl;
					outFile << "Color: " << carArray[carIndex].color << endl;
					outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
					outFile << "------------------------------------------" << endl;
					outFile << "" << endl;

					carNum++;
				}
			}
		}
	}

	outFile.close();

}

// create output text files of selected car array contents
void printOutput(Car carArray[], int arraySize1, string brandArray[], string colorArray[], string modelArray[], int arraySize2, Output path)
{
	ofstream outFile;		// placeholder for output file
	ofstream outFile2;		// placeholder for second output file

	string filePath;		// path for output file
	string filePath2;		// path for second output file

	int countArray[30];		// array holding count values
	int countIndex = 0;		// index for countArray
	int carCount = 0;		// variable for total number of cars in garage
	int dataCount;			// variable to hold information count
	int carNum;				// car's index value in array
	
	// iterate through each car brand
	for (int brandIndex = 0; brandIndex < arraySize2; brandIndex++)
	{
		// store and append brand file path, brand file name, and .txt
		filePath = path.outputBrandPath + brandArray[brandIndex] + ".txt";

		// begin/reset car index and car data count
		carNum = 0;
		dataCount = 0;

		outFile.open(filePath);

		// iterate through each element in car array
		for (int carIndex = 0; carIndex < arraySize1; carIndex++)
		{
			// print to file if selected brand matches with corresponding element in array
			if (carArray[carIndex].brand == brandArray[brandIndex])
			{
				outFile << "Car #" << carNum << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "Brand: " << carArray[carIndex].brand << endl;
				outFile << "Model: " << carArray[carIndex].model << endl;
				outFile << "Color: " << carArray[carIndex].color << endl;
				outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "" << endl;

				carNum++;

				dataCount++;
			}

			else
			{
				carNum++;
			}

			
		}

		// store count in countArray
		countArray[countIndex] = dataCount;

		countIndex++;

		outFile.close();
	}

	// iterate through each car color
	for (int colorIndex = 0; colorIndex < arraySize2; colorIndex++)
	{
		// store and append brand file path, color file name, and .txt
		filePath = path.outputColorPath + colorArray[colorIndex] + ".txt";

		// begin/reset car index and car data count
		carNum = 0;
		dataCount = 0;

		outFile.open(filePath);

		// iterate through each element in car array
		for (int carIndex = 0; carIndex < arraySize1; carIndex++)
		{
			// print to file if selected color matches with corresponding element in array
			if (carArray[carIndex].color == colorArray[colorIndex])
			{
				outFile << "Car #" << carNum << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "Brand: " << carArray[carIndex].brand << endl;
				outFile << "Model: " << carArray[carIndex].model << endl;
				outFile << "Color: " << carArray[carIndex].color << endl;
				outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "" << endl;

				carNum++;

				dataCount++;
			}

			else
			{
				carNum++;
			}
		}

		// store count in countArray
		countArray[countIndex] = dataCount;

		countIndex++;

		outFile.close();
	}

	// iterate through each car model
	for (int modelIndex = 0; modelIndex < arraySize2; modelIndex++)
	{
		// store and append brand file path, model file name, and .txt
		filePath = path.outputModelPath + modelArray[modelIndex] + ".txt";

		// begin/reset car index and car data count
		carNum = 0;
		dataCount = 0;

		outFile.open(filePath);

		// iterate through each element in car array
		for (int carIndex = 0; carIndex < arraySize1; carIndex++)
		{
			// print to file if selected model matches with corresponding element in array
			if (carArray[carIndex].model == modelArray[modelIndex])
			{
				outFile << "Car #" << carNum << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "Brand: " << carArray[carIndex].brand << endl;
				outFile << "Model: " << carArray[carIndex].model << endl;
				outFile << "Color: " << carArray[carIndex].color << endl;
				outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
				outFile << "------------------------------------------" << endl;
				outFile << "" << endl;

				carNum++;

				dataCount++;
			}

			else
			{
				carNum++;
			}
		}

		// store count in countArray
		countArray[countIndex] = dataCount;

		countIndex++;

		outFile.close();
	}

	// store and append file path and file name
	filePath = path.outputSpeedPath + "fastCars.txt";
	filePath2 = path.outputSpeedPath + "slowCars.txt";

	outFile.open(filePath);
	outFile2.open(filePath2);

	// begin car index count
	carNum = 0;

	// iterate though each car array element
	// sort cars by speed value
	for (int carIndex = 0; carIndex < arraySize1; carIndex++)
	{
		// write element to fastCars.txt if speed > 70
		if (carArray[carIndex].maxSpeed > 70)
		{
			outFile << "Car #" << carNum << endl;
			outFile << "------------------------------------------" << endl;
			outFile << "Brand: " << carArray[carIndex].brand << endl;
			outFile << "Model: " << carArray[carIndex].model << endl;
			outFile << "Color: " << carArray[carIndex].color << endl;
			outFile << "Speed: " << carArray[carIndex].maxSpeed << endl;
			outFile << "------------------------------------------" << endl;
			outFile << "" << endl;

			carNum++;
		}

		// write element to slowCars.txt if speed <= 70
		else
		{
			outFile2 << "Car #" << carNum << endl;
			outFile2 << "------------------------------------------" << endl;
			outFile2 << "Brand: " << carArray[carIndex].brand << endl;
			outFile2 << "Model: " << carArray[carIndex].model << endl;
			outFile2 << "Color: " << carArray[carIndex].color << endl;
			outFile2 << "Speed: " << carArray[carIndex].maxSpeed << endl;
			outFile2 << "------------------------------------------" << endl;
			outFile2 << "" << endl;

			carNum++;
		}
	}

	outFile.close();
	outFile2.close();

	// reset count index
	countIndex = 0;

	// sum elements in countArray section for total cars in garage
	for (int index = 0; index < 10; index++)
	{
		carCount += countArray[index];
	}

	outFile.open("Output\\garageStats.txt");

	outFile << "Garage Stats" << endl;
	outFile << "----------------------------" << endl;
	outFile << "Num of Cars in Garage: " << carCount << endl;

	outFile << "\nBrand Counts" << endl;

	// write brand counts to file
	for (int brandIndex = 0; brandIndex < arraySize2; brandIndex++)
	{
		outFile << brandArray[brandIndex] << ": " << countArray[countIndex] << endl;
		countIndex++;
	}

	outFile << "\nColor Counts" << endl;

	// write color counts to file
	for (int colorIndex = 0; colorIndex < arraySize2; colorIndex++)
	{
		outFile << colorArray[colorIndex] << ": " << countArray[countIndex] << endl;
		countIndex++;
	}

	outFile << "\nModel Counts" << endl;

	// write model counts to file
	for (int modelIndex = 0; modelIndex < arraySize2; modelIndex++)
	{
		outFile << modelArray[modelIndex] << ": " << countArray[countIndex] << endl;
		countIndex++;
	}

	outFile << "----------------------------" << endl;

	outFile.close();
	
}