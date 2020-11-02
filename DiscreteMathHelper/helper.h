/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <string>

class Helper
{
public:
	static int gcd(int n1, int n2)
	{
		return n2 == 0 ? n1 : gcd(n2, n1 % n2);
	}

	static int lcm(int n1, int n2)
	{
		return (n1 * n2) / gcd(n1, n2);
	}

	static int mod(int n1, int n2)
	{
        // return n1 < 0 ? n1 % n2 + n2 : n1 % n2;
        if(n1 < 0)
        {
            return n1 % n2 == 0 ? 0 : n1 % n2 + n2;
        }
        else
        {
            return n1 % n2;
        }
	}

	template <typename T>
	static void prompt(const std::string& text, T& out)
	{
		std::cout << text;

		if constexpr (std::is_same<T, std::string>::value)
		{
			std::cin.ignore();
			std::cin.clear();
			std::getline(std::cin, out);
		}
		else
		{
			std::cin >> out;
		}
	}

    static bool isBinaryString(const std::string& str)
    {
        size_t i = 0;
        size_t len = str.length();
        
        while (i < len && (str[i] == '0' || str[i] == '1'))
        {
            ++i;
        }
        
        return i == len;
    }
    
	static void removeWhiteSpaces(std::string& str)
	{
		size_t length = str.length();

		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
			{
				str.erase(i, 1);
				--length;
				--i;
			}
		}
	}

	static void repeat(void(*f)())
	{
		std::string input;
        
		do
		{
			f();
			std::cout << std::endl << "Try again? yes / no? ";
			std::cin >> input;
		} while (tolower(input[0]) == 'y');
	}
};
