// Program name: Lab #5 Linked List
//
// Description: The program uses a linked list to manipulate 
//      a sequence of numbers.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 08/02/2018
//
// IDE Used: VS Code
//

#include <iostream>
#include <iomanip>
#include <string>
#include "NumberList.h"

void insertNumbers(NumberList &);
void displayList(NumberList &);
void deleteNumbers(NumberList &);

int main()
{
	NumberList list;    // create an empty list

	insertNumbers(list);
	displayList(list);
	deleteNumbers(list);
	displayList(list);

	return 0;
}

//************************************************************************
//* Function name: insertNumbers
//*
//* This function inserts a series of numbers into the linked list 
//*
//* Parameters:
//*    NumberList &lt - this contains the address of a previously
//*             initialized NumberList variable in the main function
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void insertNumbers(NumberList &lt)
{
	lt.insertNode(75.2);
	lt.insertNode(108.3);
	lt.insertNode(38.45);
	lt.insertNode(45.83);
	lt.insertNode(173.45);
	lt.insertNode(163.52);
	lt.insertNode(106.94);
}

//************************************************************************
//* Function name: displayList
//*
//* This function displays the contents of the linked list 
//*
//* Parameters:
//*    NumberList &lt - this contains the address of a previously
//*             initialized NumberList variable in the main function
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void displayList(NumberList &lt)
{
	static int count = 0;
	if (count == 0) {
		std::cout << "Displaying list after inserting numbers" << std::endl;
		count++;
	} else {
		std::cout << "Displaying list after deleting numbers" << std::endl;
	}
	lt.displayList();
}

//************************************************************************
//* Function name: deleteNumbers
//*
//* This function deletes a series of numbers from the linked list 
//*
//* Parameters:
//*    NumberList &lt - this contains the address of a previously
//*             initialized NumberList variable in the main function
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void deleteNumbers(NumberList &lt)
{
	lt.deleteNode(45.83);
	lt.deleteNode(173.45);
}