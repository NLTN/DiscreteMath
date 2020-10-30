/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <iomanip>

class EuclideanAlgorithm
{
	struct ExtendedResult;
public:
	EuclideanAlgorithm() { };
	~EuclideanAlgorithm() { };

	int gcd(int n1, int n2);
	ExtendedResult gcdExtended(int n1, int n2);
private:
	int gcdExtended(int n1, int n2, int& x, int& y);

};

struct EuclideanAlgorithm::ExtendedResult
{
	int gcd; // Greatest Common Divisor
	int n1, n2; // 
	int s, t; // Coefficients
	friend std::ostream& operator<<(std::ostream& os, const EuclideanAlgorithm::ExtendedResult& rhs)
	{
		return os << '(' << rhs.t << ')' << '(' << rhs.n2 << ')' << " + " << '(' << rhs.s << ')' << '(' << rhs.n1 << ')';
	}
};

int EuclideanAlgorithm::gcd(int n1, int n2)
{
	return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

EuclideanAlgorithm::ExtendedResult EuclideanAlgorithm::gcdExtended(int n1, int n2)
{
	ExtendedResult result;
	result.n1 = n1;
	result.n2 = n2;
	result.gcd = gcdExtended(n1, n2, result.s, result.t);
	return result;
}

int EuclideanAlgorithm::gcdExtended(int n1, int n2, int& s, int& t)
{
	if (n1 % n2 == 0)
	{
		s = 0;
		t = 1;
		return n2;
	}
	else
	{
		int s1, t1;
		int g = gcdExtended(n2, n1 % n2, s1, t1);
		s = t1;
		t = s1 - n1 / n2 * t1;

		return g;
	}
}