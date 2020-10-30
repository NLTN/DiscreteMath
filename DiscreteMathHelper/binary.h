/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "converter.h"
#include "helper.h"

class Binary
{
public:
	Binary() { };
	Binary(int num) : bin(Converter::fromDec(num, 2)) { };
	Binary(std::string binStr)
	{
		Helper::removeWhiteSpaces(binStr);
		bin = binStr;
	};
	~Binary() { };

	Binary operator+(const Binary& binary) const;
	Binary operator-(const Binary& binary) const;
	long long toInteger() const;
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const Binary& bin);

private:
	std::string bin;
};