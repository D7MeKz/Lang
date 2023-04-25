#include "SpreadsheetCell.h"

void SpreadSheetCell::setValue(double inValue)
{
	mValue = inValue;
}

double SpreadSheetCell::getValue() const
{
	return mValue;
}

void SpreadSheetCell::setString(std::string_view inString) {
	mValue = stringToDouble(inString);
}

std::string SpreadSheetCell::getString() const
{
	return doubleToString(mValue);
}

std::string SpreadSheetCell::doubleToString(double inValue) const
{
	return std::to_string(inValue);
}

double SpreadSheetCell::stringToDouble(std::string_view inString) const
{
	return strtod(inString.data(), nullptr);
}


