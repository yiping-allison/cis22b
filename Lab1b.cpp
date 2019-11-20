// Program name: Lab #1 Expenses Report
//
// Description: The program prints the contents of a 1-D array which 
// contains a company's expenses. It also calculates total and the average.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/06/2018
//
// IDE Used: VS Code
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>

const int NUM_EXPENSES = 7;

void printReport(double arr[], double *ptr);

int main()
{
	double expenses[NUM_EXPENSES] = {
		45.25, 49.38, 12.75,
		123.50, 8.25, 19.95, 145.70
	};
	double *ptr;

	ptr = &expenses[0];
	printReport(expenses, ptr);

	return 0;
}

//************************************************************************
//* Function name: printReport
//*
//* This function prints the company expenses
//*
//* Parameters:
//*    arr - array holding all 7 expenses
//*    *ptr - pointer pointing to the first element inside the array
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printReport(double arr[], double *ptr)
{
	double total = 0;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << " #             Amount\n";
	std::cout << "---------------------\n";
	for (int count = 0; count < NUM_EXPENSES; count++) {
		std::cout << std::setw(2) << count + 1 << std::setw(19) << *ptr << std::endl;
		ptr++;
	}
	std::cout << "Total" << std::setw(16);
	
	// Calculate total expense
	for (int count = 0; count < NUM_EXPENSES; count++) {
		total += arr[count];
	}
	std::cout << total << std::endl;
	std::cout << "Average" << std::setw(14) << total / NUM_EXPENSES;
}