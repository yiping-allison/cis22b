// Program name: Lab #3 More Classes
//
// Description: This program instantiates and uses instances 
//          of a class with non-default constructors.
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
		NutritionData(void);    // default constructor
		NutritionData(std::string fd, int serSz, double calCarb, double calFat,
			double calProtein);    // constructor
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

// default constructor
NutritionData::NutritionData(void) 
{
	foodName = "";
	servingSize = 0;
	calFromCarb = calFromFat = calFromProtein = totalCalories = 0.0;
}

// set non-default constructor
NutritionData::NutritionData(std::string fd, int serSz, double calCarb, double calFat,
	double calProtein) 
{
	setFoodName(fd);
	setServingSize(serSz);
	setCalFromCarb(calCarb);
	setCalFromFat(calFat);
	setCalFromProtein(calProtein);
	setTotalCalories();
}

int main(void)
{
	NutritionData nutritionData[] = {
		NutritionData("Apples raw", 110, 50.6, 1.2, 1.0),
		NutritionData("Bananas", 225, 186, 6.2, 8.2),
		NutritionData("Bread pita whole wheat", 64, 134, 14, 22.6),
		NutritionData("Broccoli raw", 91, 21.9, 2.8, 6.3),
		NutritionData("Carrots raw", 128, 46.6, 2.6, 3.3)
	};

	// Displaying Array Entries
	for (auto entry : nutritionData) {
		// display 'entry'
		std::cout << "Food name: " << entry.getFoodName() << std::endl
			 << "Serving Size: " << entry.getServingSize() << " g" << std::endl
			 << "Calories Per Serving: " << entry.getTotalCalories() << std::endl
			 << "Calories From Carb: " << entry.getCalFromCarb() << std::endl
			 << "Calories From Fat: " << entry.getCalFromFat() << std::endl
			 << "Calories From Protein: " << entry.getCalFromProtein() << std::endl;
		std::cout << std::endl;
	}

	return 0;
}