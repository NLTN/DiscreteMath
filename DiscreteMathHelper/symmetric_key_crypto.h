/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <string>
#include "helper.h"

class SymmetricKeyCrypto
{
public:
    SymmetricKeyCrypto() { };
    ~SymmetricKeyCrypto() { };

	int encrypt(int m, int key, int N);
	int decrypt(int c, int key, int N);
};

int SymmetricKeyCrypto::encrypt(int m, int key, int N)
{
	return (m + key) % N;
}

int SymmetricKeyCrypto::decrypt(int c, int key, int N)
{
	return Helper::mod(c - key, N);
}
