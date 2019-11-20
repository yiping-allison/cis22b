// Program name: Lab #1 Sentence Capitalizer
//
// Description: The program capitalizes the first letter of 
//      a sentence
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/11/2018
// Last modified: 07/12/2018
//
// IDE Used: VS Code
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

void printSentence(char *ptr);
void sentenceCapitalizer(char *ptr);

int main()
{
	char userString[] = "No, not tonight.  it's a very popular place "
		"and you have to make reservations in advance. besides, "
		"it's expensive, and I don't have any money.";

	// print unaltered sentence
	printSentence(userString);

	// modify sentence capitalization
	sentenceCapitalizer(userString);

	// print altered sentence
	printSentence(userString);
	
	return 0;
}

//************************************************************************
//* Function name: printSentence
//*
//* This function prints the sentence from the array
//*
//* Parameters:
//*    *ptr - pointer containing address of sentence array
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printSentence(char *ptr)
{
	static int COUNT = 0;

	// display before message
	if (COUNT == 0) {
		std::cout << "The text before the modification:\n" << std::endl;
		COUNT++;
	} else {
		// display after message
		std::cout << std::endl << std::endl;
		std::cout << "The text after the modification:\n" << std::endl;
	}

	// print contents of the array
	for (int count = 0; count < strlen(ptr); count++) {
		std::cout << ptr[count];
	}
}

//************************************************************************
//* Function name: sentenceCapitalizer
//*
//* This function capitalizes the first letter of each sentence
//*
//* Parameters:
//*    *ptr - pointer containing address of sentence array
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void sentenceCapitalizer(char *ptr)
{     
	// Capitalize the beginning of string if first letter is alphabetical
	if (ptr[0] && isalpha(ptr[0])) {
		ptr[0] = toupper(ptr[0]);
		ptr++;
	}
	// For all others not the first sentence
	while (*ptr != '\0') {
		if (*ptr == '.' || *ptr == '!' || *ptr == '?') {
			ptr++;  // increment after period
			// skips all whitespaces after period
			while (isspace(*ptr)) { 
				ptr++;
			}
			// is alphabetic
			if (isalpha(*ptr)) {
				*ptr = toupper(*ptr);
			}
		}
		ptr++;  // pointer increment
	}
}