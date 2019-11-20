// Program name: Lab #3 Classes
//
// Description: This program processes nutrition information 
//         with a class.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/26/2018
//
// IDE Used: VS Code
//

#include <iostream>
#include <iomanip>
#include <string>

class NutritionData {
	private:
		std::string foodName;
		int servingSize;
		double calFromCarb;
		double calFromFat;
		double calFromProtein;
		double totalCalories;

	public:
		NutritionData();
		void setFoodName(std::string name) { foodName = name; }
		void setServingSize(int serveSize) { servingSize = serveSize;}
		void setCalFromCarb(double calCarb) { calFromCarb = calCarb; }
		void setCalFromFat(double calFat) { calFromFat = calFat; }
		void setCalFromProtein(double calProtein) { calFromProtein = calProtein; }
		void setTotalCalories(void) { totalCalories = getCalFromCarb() + getCalFromFat() +
			getCalFromProtein(); }
		std::string getFoodName(void) const { return foodName; }
		int getServingSize(void) const { return servingSize; }
		double getCalFromCarb(void) const { return calFromCarb; }
		double getCalFromFat(void) const { return calFromFat; }
		double getCalFromProtein(void) const { return calFromProtein; }
		double getTotalCalories(void) const { return totalCalories; }
};

// Use constructor to intialize variables to 0 or blank string
NutritionData::NutritionData()
{
	foodName = "";
	servingSize = 0;
	calFromCarb = calFromFat = calFromProtein = totalCalories = 0.0;  
}

void loadData(NutritionData *entry);
void printData(NutritionData pita);

int main(void)
{
	NutritionData pita; // declare empty class

	// set info for pita
	loadData(&pita);
	// display pita
	printData(pita);
	
	return 0;
}

//************************************************************************
//* Function name: loadData
//*
//* This function loads pre-set data into the set mutator functions
//*        of the Class, entry (pita)
//*
//* Parameters:
//*    NutritionData *entry - contains the address of the Class, 'pita'
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void loadData(NutritionData *entry)
{
	entry -> setFoodName("Bread pita whole wheat");
	entry -> setServingSize(64);
	entry -> setCalFromCarb(134);
	entry -> setCalFromFat(14);
	entry -> setCalFromProtein(22.6);
	entry -> setTotalCalories();
}

//************************************************************************
//* Function name: printData
//*
//* This function prints the contents of the class
//*
//* Parameters:
//*    NutritionData entry - contains the copy of the Class, 'pita'
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void printData(NutritionData pita)
{
	// set precision and decimal point lvls
	std::cout << std::fixed << std::showpoint << std::setprecision(1);
	// display 'pita'
	std::cout << "Food name: " << pita.getFoodName() << std::endl
		 << "Serving Size: " << pita.getServingSize() << " grams" << std::endl
		 << "Calories Per Serving: " << pita.getTotalCalories() << std::endl
		 << "Calories From Carb: " << pita.getCalFromCarb() << std::endl
		 << "Calories From Fat: " << pita.getCalFromFat() << std::endl
		 << "Calories From Protein: " << pita.getCalFromProtein();
}