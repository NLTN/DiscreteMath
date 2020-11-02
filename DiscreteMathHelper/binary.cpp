/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#include "binary.h"

Binary Binary::operator+(const Binary& binary) const
{
    // I was just Too Lazy!!!
    return Binary(toInteger() + binary.toInteger());
    
    /*
	Binary result;
	int s = 0; //Digit sum to carry

	// Traverse backward from last to first
	size_t i = bin.size() - 1, j = binary.bin.size() - 1;
    
	while (i >= 0 || j >= 0 || s == 1)
	{
		// sum of the last digits and carry 
		if (i >= 0 && bin[i] == '1')
		{
			++s;
		}

		if (j >= 0 && binary.bin[j] == '1')
		{
			++s;
		}

		result.bin.insert(0, 1, char(s % 2 + '0'));

		// Update the carry 
		s /= 2;

		i--; j--;
	}

	return result;
    */
}

Binary Binary::operator-(const Binary& binary) const
{
	// Too Lazy!!! 
	// First, Convert the binary to Dec. Second, do the subtraction.
	// Finally, Convert the number back to binary :-) :-) :-)

	int a = Converter::toDec(std::stoi(bin), 2);
	int b = Converter::toDec(std::stoi(binary.bin), 2);
	return Binary(a - b);
}

long long Binary::toInteger() const
{
	return Converter::binaryStringToDec(bin);
}

std::string Binary::toString() const
{
	return  bin;
}

std::ostream& operator<<(std::ostream& os, const Binary& bin)
{
	return os << bin.bin;
}
