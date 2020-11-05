/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "helper.h"
#include "converter.h"

class NumericalMessage
{
public:
	NumericalMessage();
	NumericalMessage(int shiftKey);
    int charToNumber(char c) const;
    char numberToChar(int num) const;
	std::string toNumberic(std::string message);
	std::string toText(std::string cipher);
	std::string textToBinary(std::string message, int bitsPerCharacter);
	std::string binaryToText(std::string binString, int bitsPerCharacter);
	std::string textToHex(std::string message); // WRONG

private:
	int shift = 0;
};

NumericalMessage::NumericalMessage()
{

}

inline NumericalMessage::NumericalMessage(int shiftKey) : shift(shiftKey)
{
}

int NumericalMessage::charToNumber(char c) const
{
    return c - 'A';
}

char NumericalMessage::numberToChar(int num) const
{
	return num + 64;
}

inline std::string NumericalMessage::toNumberic(std::string message)
{
	std::ostringstream os;
	size_t len = message.length();
    
	for (int i = 0; i < len; ++i)
	{
		os << static_cast<int>(message[i]) + shift - 64;
	}

	return os.str();
}

std::string NumericalMessage::toText(std::string cipher)
{
	std::string result;

	if (cipher.length() % 2 != 0)
	{
		cipher = "0" + cipher;
	}

	size_t len = cipher.length();

	for (size_t i = 0; i < len; i += 2)
	{
		int temp = std::stoi(cipher.substr(i, 2));
		result.push_back(char(temp + shift + 64));
	}

	return result;
}

std::string NumericalMessage::textToBinary(std::string message, int bitsPerCharacter)
{
	std::string result;
	size_t len = message.length();

	for (size_t i = 0; i < len; ++i)
	{
		int temp = std::stoi(toNumberic(std::string(1, message[i])));
		std::string t = Converter::fromDec(temp, 2);
		if (t.length() < bitsPerCharacter)
		{
			t.insert(0, std::string(bitsPerCharacter - t.length(), '0'));
		}
		result += t + " ";
	}

	return result;
}

inline std::string NumericalMessage::binaryToText(std::string binStr, int bitsPerChar)
{
	Helper::removeWhiteSpaces(binStr);
	binStr.insert(0, binStr.length() % bitsPerChar, '0');

	std::string result;
	size_t len = binStr.length();
    
	for (int i = 0; i < len; i += bitsPerChar)
	{
		result.push_back(char(Converter::binaryStringToDec(binStr.substr(i, bitsPerChar)) + 64));
	}

	return result;

}

/// <summary>
/// WRONG
/// </summary>
/// <param name="message"></param>
/// <returns></returns>
inline std::string NumericalMessage::textToHex(std::string message)
{
	std::string result;
	size_t len = message.length();

	std::string ori;
	for (size_t i = 0; i < len; ++i)
	{
		int temp = std::stoi(toNumberic(std::string(1, message[i])));
		ori += toNumberic(std::string(1, message[i]));
		std::string t = Converter::fromDec(temp, 16);
		//t.insert(0, std::string(bitsPerCharacter - t.length(), '0'));
		result += t + " ";
	}
	std::cout << "ORI = " << ori << std::endl;
	return result;
}


