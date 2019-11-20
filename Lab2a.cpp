// Program name: Lab #2 Structured Data
//
// Description: This program processes an array of structured 
//      sales data
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/12/2018
// Last edited: 07/16/2018
//
// IDE Used: VS Code
//

#include <iostream>
#include <iomanip>
#include <string>

struct Sale
{
	std::string itemName;
	int quantity;
	double unitPrice;
	double salePrice;
};

void loadData(Sale data[], int SALES_SIZE);
double processData(Sale data[], int SALES_SIZE);
void printData(Sale data[], int SALES_SIZE);

int main()
{
	const int SALES_SIZE { 5 };
	Sale salesData[SALES_SIZE];

	// Call Load Data
	loadData(salesData, SALES_SIZE);
	// Print Data
	printData(salesData, SALES_SIZE);

	return 0;
}

//************************************************************************
//* Function name: loadData
//*
//* This function enters sales data into a structure array
//*
//* Parameters:
//*    Sale data[] - contains the address of Sale structure array
//*    size - total amount of items in the array
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void loadData(Sale data[], int SIZE)
{
	// load pre-defined data into array
	for (int count = 0; count < SIZE; count++) {
		switch (count) {
			case 0: data[count] = Sale {"Milk", 1, 5.85};
					break;
			case 1: data[count] = Sale {"Whole Wheat Bread", 2, 3.75};
					break;
			case 2: data[count] = Sale {"Napkin", 3, 2.35};
					break;
			case 3: data[count] = Sale {"Paper Towel", 3, 2.95};
					break;
			case 4: data[count] = Sale {"Soap", 1, 1.95};
		}
	}
}

//************************************************************************
//* Function name: processData
//*
//* This function adds prices and returns the total price of all items
//*
//* Parameters:
//*    Sale data[] - contains the address of Sale structure array
//*    size - total amount of items in the array
//*
//* Returns:
//*
//*    total - total price of all items accounting for quantity purchased
//*
//************************************************************************

double processData(Sale data[], int SIZE)
{
	double total = 0;

	// calculate price per quantity bought
	for (int count = 0; count < SIZE; count++) {
		data[count].salePrice = data[count].quantity * data[count].unitPrice;
		total += data[count].salePrice;  // keeps a running total
	}
	return total;
}

//************************************************************************
//* Function name: printData
//*
//* This function prints the final sales price amount report
//*
//* Parameters:
//*    Sale data[] - contains the address of Sale structure array
//*    size - total amount of items in the array
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printData(Sale data[], int SIZE)
{
	double totalAmount;
	const int MAX_TITLE_COL = 34;

	// find the running total of all items
	totalAmount = processData(data, SIZE);
	// format decimal point
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	// display headers
	std::cout << "Sales\n"
		 << "Item" << std::setw(MAX_TITLE_COL - 16) << "Qty" << std::setw(6)
		 << "Unit" << std::setw(5) << "Amt" << std::endl;
	// display = line
	for (int count = 0; count < MAX_TITLE_COL; count++) {
		std::cout << "=";
	}
	std::cout << std::endl;   // move to new line
	// Display array contents
	for (int count = 0; count < SIZE; count++) {
		std::cout << std::left << std::setw(MAX_TITLE_COL - 16) << data[count].itemName  
			 << std::right << std::setw(4) << data[count].quantity
			 << std::setw(6) << data[count].unitPrice
			 << std::setw(6) << data[count].salePrice;
		std::cout << std::endl;
	}
	std::cout << std::endl;   // leave a line blank
	// display total
	std::cout << std::left << std::setw(MAX_TITLE_COL - 5) << "Total"
		 << totalAmount;
}