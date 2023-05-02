#pragma once
#include<iostream>
#include<string>
class SpreadSheetCell
{
public:
	SpreadSheetCell(double inValue);
	void setValue(double inValue);
	double getValue() const;

	void setString(std::string_view inString);
	std::string getString() const;

private:
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;
	double mValue;
};

