/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <string>

class SymmetricKeyCrypto
{
public:
    SymmetricKeyCrypto() { };
    ~SymmetricKeyCrypto() { };

	int encrypt(int m, int key, int N);
	int decrypt(int c, int key, int N);

private:
	int mod(int n1, int n2);
};

int SymmetricKeyCrypto::encrypt(int m, int key, int N)
{
	return (m + key) % N;
}

int SymmetricKeyCrypto::decrypt(int c, int key, int N)
{
	return mod(c - key, N);
}

int SymmetricKeyCrypto::mod(int n1, int n2)
{
	return n1 < 0 ? n1 % n2 + n2 : n1 % n2;
}
