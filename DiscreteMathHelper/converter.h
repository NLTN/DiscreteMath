/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <string>
#include <cmath>

class Converter
{
public:
	Converter() = delete;

	static std::string fromDec(long long dec, int toBase)
	{
		std::string result;
        
		while (dec > 0)
		{
			if (toBase == 16 && dec % toBase > 9)
			{
				result.insert(0, 1, char((dec % toBase) - 10 + 'A'));
			}
			else
			{
				result = std::to_string(dec % toBase) + result;
			}
			dec /= toBase;
		}
        
		return result;
	};

	static int toDec(int num, int fromBase)
	{
		int result = 0;
		int p = 0;
        
		while (num > 0)
		{
			result += (num % 10) * std::pow(fromBase, p);
			num /= 10;
			++p;
		}

		return result;
	};

	static int hexStringToDec(const std::string& hexStr)
	{
        int result = 0;
		size_t len = hexStr.length();
        
		for (int i = 0; i < len; ++i)
		{
			int value = hexStr[i] - '0' < 10 ? hexStr[i] - '0' : 10 + hexStr[i] - 'A';
			result += value * std::pow(16, len - i - 1);
		}
        
		return result;
	};

	static long long binaryStringToDec(const std::string& binStr)
	{
		long long result = 0;
		size_t len = binStr.length();
        
		for (size_t i = 0; i < len; ++i)
		{
			if (binStr[i] == '1')
			{
				result += std::pow(2, len - i - 1);
			}
		}
        
		return result;
	};
};
