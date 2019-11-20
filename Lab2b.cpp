// Program name: Lab #2 Advanced File Operations
//
// Description: This program creates a binary file to store data 
//      then reads the file and finds a specfic record to print to the
//      screen.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/19/2018
//
// IDE Used: VS Code
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

struct NutritionData {
	char foodName[40];
	double servingSize;
	double calFromCarb;
	double calFromFat;
	double calFromProtein;
	double totalCalories;
};

int createFile(void);
void readData(void);
long byteNum(int recNum);
void processData(NutritionData dataEntry);
void printData(NutritionData dataEntry);

int main(void)
{   
	if (createFile()) {
		// if file is successfully created, then read data
		readData();
	}

	return 0;
}

//************************************************************************
//* Function name: createFile
//*
//* This function checks if a binary file, nutri.data exists and creates
//*         one if it doesn't
//*
//* Parameters:
//*    void
//*
//* Returns:
//*
//*    int - this function is used as a bool. If this function succeeds,
//*             the main function will run readData
//*
//************************************************************************

int createFile()
{
	std::fstream dataFile;
	const std::string FILE_NAME{ "nutri.dat" };
	const int NUM_DATA{ 5 };

	dataFile.open(FILE_NAME, std::ios::in);
	if (dataFile.fail()) {
		// The file does not exist so create a new one
		dataFile.open(FILE_NAME, std::ios::out | std::ios::binary);
		// Load data
		NutritionData tempdata[] {
			{"Apples raw", 110, 50.6, 1.2, 1.0},
			{"Bananas", 225, 186, 6.2, 8.2},
			{"Bread pita whole wheat", 64, 134, 14, 22.6},
			{"Broccoli raw", 91, 21.9, 2.8, 6.3},
			{"Carrots raw", 128, 46.6, 2.6, 3.3}
		};
		for (int count = 0; count < NUM_DATA; count++) {
			dataFile.write(reinterpret_cast<char *>(&tempdata[count]), sizeof(tempdata[count]));
		}
		// Close file
		dataFile.close();
		return 1;
	} else {    // The file already exists
		dataFile.close();
		std::cout << "The file nutri.dat is an existing file. You can either delete " 
				"the file or move it to another location and then run the program again.";
		return 0;
	}
}

//************************************************************************
//* Function name: readData
//*
//* This function opens a binary file and finds a specific record before
//*         calling processData
//*
//* Parameters:
//*    void
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void readData()
{
	std::fstream dataFile;
	const std::string FILE_NAME{ "nutri.dat" };
	const int RECORD_NUM{ 2 };
	NutritionData entry;

	dataFile.open(FILE_NAME, std::ios::in | std::ios::binary);
	dataFile.seekg(byteNum(RECORD_NUM), std::ios::beg);  // Find specific entry
	dataFile.read(reinterpret_cast<char *>(&entry), sizeof(entry));

	processData(entry); // call process data function
	dataFile.close();
}

//************************************************************************
//* Function name: byteNum
//*
//* This function returns the byte location of a specific record
//*
//* Parameters:
//*    int recNum - An integer containing the specific record number
//*                 requested
//*
//* Returns:
//*
//*    long int - the byte size
//*
//************************************************************************

long byteNum(int recNum)
{
	return sizeof(NutritionData) * recNum;
}

//************************************************************************
//* Function name: processData
//*
//* This function calculates the total calories and calls the print
//*         function.
//*
//* Parameters:
//*    NutritionData dataEntry - contains the address to the structure
//*             storing the requested record
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void processData(NutritionData dataEntry)
{
	// Calculate total calories
	dataEntry.totalCalories = dataEntry.calFromCarb + dataEntry.calFromFat +
		dataEntry.calFromProtein;
	printData(dataEntry);   // call print function
}

//************************************************************************
//* Function name: printData
//*
//* This function prints the requested record
//*
//* Parameters:
//*    NutritionData dataEntry - contains the address to the structure
//*             storing the requested record
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printData(NutritionData dataEntry)
{
	std::cout << std::fixed << std::showpoint << std::setprecision(1);  // set decimal precision
	std::cout << "Food name: " << dataEntry.foodName << std::endl
		 << "Serving Size: " << dataEntry.servingSize << " grams" << std::endl
		 << "Calories Per Serving: " << dataEntry.totalCalories << std::endl
		 << "Calories From Carb: " << dataEntry.calFromCarb << std::endl
		 << "Calories From Fat: " << dataEntry.calFromFat << std::endl
		 << "Calories From Protein: " << dataEntry.calFromProtein;
}