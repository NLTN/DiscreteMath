/*
	Nguyen Nguyen
	Discrete Math Helper
	October 27, 2020
*/

#pragma once
#include <iostream>
#include <cmath>
#include <map>

class PrimeFactorizationResult
{
public:
    PrimeFactorizationResult() { };
    PrimeFactorizationResult(const PrimeFactorizationResult& other) : factors(other.factors) { };
    
    void add(size_t factor)
    {
        auto it = factors.find(factor);
        if (it != factors.end())
            ++(it->second);
        else
        {
            factors.insert(std::make_pair(factor, 1));
        }
    }
        
    friend std::ostream& operator<<(std::ostream& os, const PrimeFactorizationResult& rhs)
    {
        for (auto it = rhs.factors.cbegin(); it != rhs.factors.cend(); it++)
        {
            os << '(' << it->first << '^' << it->second << ") ";
        }
        return os;
    }
private:
    std::map<size_t, int> factors;
};

class PrimeNumber
{
public:
    PrimeNumber() = delete;

	static size_t nextPrime(size_t N)
	{
        size_t prime = N + 1;
        
		while (!isPrime(prime))
        {
			++prime;
		}

		return prime;
	}
    
    // Assumptions: User may enter an odd/even number.
	static bool isPrime(size_t num)
	{
        if (num == 2)
        {
            return true;
        }
        else if (num < 2 || num % 2 == 0)
        {
            return false;
        }
		else
		{
			int i = 3;
			int end = std::sqrt(num);
            
			while (i <= end && num % i != 0)
			{
				i += 2;
			}
            
			return i > end;
		}
	};

    static PrimeFactorizationResult factorize(size_t num)
    {
        PrimeFactorizationResult result;
        
        // Although the number 1 is not a prime nor a composite number,
        // The function still returns 1 as a factor.
        if (num < 2)
        {
            //std::cerr << "This is not a prime nor a composite number" << std::endl;
            result.add(num);
            return result;
        }

        size_t prime = 2;
        while (prime <= num)
        {
            if (num % prime == 0)
            {
                result.add(prime);
                num /= prime;
            }
            else
            {
                prime = nextPrime(prime);
            }
        }
        return result;
    }
};
