// Program name: Lab #4 Inheritance
//
// Description: The program instantiates and uses instances of a 
//      derived class with default and non-default constructors.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Yiping Su
//
// Date: 07/31/2018
//
// IDE Used: VS Code
//

#include <iostream>
#include <iomanip>
#include <string>

class RealProperty {

	private:
		std::string streetAddress;
		int squareFootage;
		double taxes;

	public:
		RealProperty();
		RealProperty(std::string stadd, int sqft, double t);
		void setStreetAddress(std::string stadd) { streetAddress = stadd; }
		void setSquareFootage(int sqft) { squareFootage = sqft; }
		void setTaxes(double t) { taxes = t; }
		std::string getStreetAddress(void) const { return streetAddress; }
		int getSquareFootage(void) const { return squareFootage; }
		double getTaxes(void) const { return taxes; }

};

// default constructor
RealProperty::RealProperty()
{
	streetAddress = "";
	squareFootage = 0;
	taxes = 0.0;
}

// non-default constructor
RealProperty::RealProperty(std::string stadd, int sqft, double t)
{
	setStreetAddress(stadd);
	setSquareFootage(sqft);
	setTaxes(t);
}

class Apartment : public RealProperty {
	private:
		double monthlyRent;
	public:
		// default constructor
		Apartment() : RealProperty() 
		{
			monthlyRent = 0.0;
			RealProperty::setStreetAddress("");
			RealProperty::setSquareFootage(0);
			RealProperty::setTaxes(0.0);
		}
		// non-default constructor
		Apartment(std::string stadd, int sqft, double t, double mr) : 
			RealProperty(stadd, sqft, t)
		{
			setMonthlyRent(mr);
			RealProperty::setStreetAddress(stadd);
			RealProperty::setSquareFootage(sqft);
			RealProperty::setTaxes(t);            
		}
		// set monthly rent
		void setMonthlyRent(double mr) { monthlyRent = mr; }
		// get monthly rent
		double getMonthlyRent(void) { return monthlyRent; }
};

void displayPropertyInfo(Apartment &);
void displayApartmentInfo(Apartment &);

int main()
{
	// declare/initialize apartment variable
	Apartment property("Cupertino", 1200, 200, 2550.0);
	// display property info
	displayPropertyInfo(property);
	// display apartment info
	displayApartmentInfo(property);

	return 0;
}

//************************************************************************
//* Function name: displayPropertyInfo
//*
//* This function prints the contents of property info 
//*
//* Parameters:
//*    Apartment &info - this contains the address of a previously
//*             initialized Apartment variable in the main function
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void displayPropertyInfo(Apartment &info)
{
	std::cout << "Property is located at: " << info.getStreetAddress() << std::endl
		 << "Square footage: " << info.getSquareFootage() << std::endl 
		 << "Taxes: " << info.getTaxes() << std::endl << std::endl;
}

//************************************************************************
//* Function name: displayApartmentInfo
//*
//* This function prints the contents of property info including the
//*         apartment rent 
//*
//* Parameters:
//*    Apartment &info - this contains the address of a previously
//*             initialized Apartment variable in the main function
//*
//* Returns:
//*
//*    void
//*
//************************************************************************

void displayApartmentInfo(Apartment &info)
{
	std::cout << "Apartment is located at: " << info.getStreetAddress() << std::endl
		 << "Square footage: " << info.getSquareFootage() << std::endl 
		 << "Taxes: " << info.getTaxes() << std::endl 
		 << "Monthly rent: " << std::fixed << std::showpoint << std::setprecision(2) 
		 << info.getMonthlyRent(); 
}