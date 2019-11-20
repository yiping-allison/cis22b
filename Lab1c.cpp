// Program name: Lab #1 Dynamic Memory Allocation
//
// Description: The program creates a dynamically allocated array 
// and stores either odd or even values in them. The memory is freed
// at the end of the program.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/06/2018
// Last edited: 07/10/2018
//
// IDE Used: VS Code
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>

int *allocIntArray(int numIntegers);
void storeOddNumbers(int *ptr1);
void storeEvenNumbers(int *ptr2);
void printResults(int *ptr1, int *ptr2);

int main() 
{
	int *ptr1 = NULL,
		*ptr2 = NULL;

	// gets allocated memory of ptr1 and ptr2
	ptr1 = allocIntArray(100);
	ptr2 = allocIntArray(1000);
	
	// store odd and even numbers respectively
	storeOddNumbers(ptr1);
	storeEvenNumbers(ptr2);

	// prints partial outcomes
	printResults(ptr1, ptr2);

	// free memory
	delete [] ptr1;
	delete [] ptr2;

	return 0;
}

//************************************************************************
//* Function name: *allocIntArray
//*
//* This function returns a pointer to a dynamically allocated array
//*
//* Parameters:
//*    numIntegers - Number of integers wanted in array
//*
//* Returns:
//*
//*    pointer to the dynamically allocated array
//*
//************************************************************************

int *allocIntArray(int numIntegers)
{
	int *arr_ptr;

	// allocate new memory of array
	arr_ptr = new int[numIntegers];

	return arr_ptr;
}

//************************************************************************
//* Function name: *storeOddNumbers
//*
//* This function stores odd values starting from 1 into a given
//*     array
//*
//* Parameters:
//*    *ptr1 - the address of pointer 1
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void storeOddNumbers(int *ptr1)
{
	int odd = 1;
	const int MAX_ARR_SIZE = 100;

	for (int count = 0; count < MAX_ARR_SIZE; count++) {
		ptr1[count] = odd;
		odd += 2; 
	}
}

//************************************************************************
//* Function name: *storeEvenNumbers
//*
//* This function stores even values starting from 2 into a given
//*     array
//*
//* Parameters:
//*    *ptr2 - the address of pointer 2
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void storeEvenNumbers(int *ptr2)
{
	int even = 2;
	const int MAX_ARR_SIZE = 1000;

	for (int count = 0; count < MAX_ARR_SIZE; count++) {
		ptr2[count] = even;
		even += 2;
	}
}

//************************************************************************
//* Function name: printResults
//*
//* This function prints out partial results of pointer 1 and
//*     pointer 2.
//*
//* Parameters:
//*    *ptr1 - address of pointer 1
//*    *ptr2 - address of pointer 2
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printResults(int *ptr1, int *ptr2)
{
	const int NUM_PRINT = 3;
	const int PTR1_INDEX = 97;
	const int PTR2_INDEX = 997;

	// display partial ptr1 
	for (int count = 0; count < NUM_PRINT; count++) {
		std::cout << std::setw(2) << std::left << ptr1[count] << std::setw(2);
	}
	std::cout << " ... ";
	for (int count = 0; count < NUM_PRINT; count++) {
		std::cout << std::setw(4) << ptr1[count + PTR1_INDEX];
	}
	std::cout << std::endl;

	// display partial ptr2
	for (int count = 0; count < NUM_PRINT; count++) {
		std::cout << std::setw(2) << ptr2[count] << std::setw(2);
	}
	std::cout << " ... ";
	for (int count = 0; count < NUM_PRINT; count++) {
		std::cout << std::setw(5) << ptr2[count + PTR2_INDEX];
	}
}