// Program name: Lab #1 2D-Arrays
//
// Description: The program prints the contents of a 2-D array which 
// contains company's sales data in the four quarters of the year.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/05/2018
//
// IDE Used: VS Code
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>

const int Quarter = 4;

void printSalesData(double arr[][Quarter], int numDivisions);

int main() {
	double companySales[3][Quarter] = {
		{201.24, 150.91, 270.83, 421.51},
		{312.43, 422.14, 251.85, 732.53},
		{271.83, 321.55, 321.67, 641.69}
	};

	// feeds company data to a print function
	printSalesData(companySales, 3);
	
	return 0;
}

//************************************************************************
//* Function name: printSalesData
//*
//* This function prints the company sales data
//*
//* Parameters:
//*    arr - array holding the sales data for all 4 quarters
//*    division - the number of divisions in the company
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printSalesData(double arr[][Quarter], int division)
{
	std::cout << "Corporation Sales Report\n";
	std::cout << " " << "DIV" << "        Q1        Q2        Q3";
	std::cout << "        Q4\n";
	for (int count = 0; count < 3; count++) {
		std::cout << "   " << count << "    ";
		for (int innerCount = 0; innerCount < Quarter; innerCount++) {
			std::cout << arr[count][innerCount] << "    ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}