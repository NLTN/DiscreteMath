/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <cmath>
#include "euclidean_algorithm.h"
#include "helper.h"
//00010110
class RSA
{
public:
	RSA(int prime1, int prime2, int encryptKey);
	int getPrivateKey();
	int encrypt(int m);
	int decrypt(int c);
	std::string getEncryptionFormula(long long m);
	std::string getDecryptionFormula(long long c);
    
private:
	int p, q, e, d, N, phi;
};

RSA::RSA(int prime1, int prime2, int encryptKey)
	: p(prime1), q(prime2), e(encryptKey)
{
	N = p * q;
	phi = (p - 1) * (q - 1);

	EuclideanAlgorithm algo;
    d = Helper::mod(algo.gcdExtended(e, phi).s, phi);
}

int RSA::getPrivateKey()
{
	return d;
}

int RSA::encrypt(int m)
{
	return Helper::mod(std::pow(m, e), N);
}

std::string RSA::getEncryptionFormula(long long m)
{
	std::stringstream ss;
	ss << "c = " << m << "^" << e << " mod " << N;
	return ss.str();
}

std::string RSA::getDecryptionFormula(long long c)
{
	std::stringstream ss;
	ss << "m = " << c << "^" << d << " mod " << N;
	return ss.str();
}

int RSA::decrypt(int c)
{
	return Helper::mod(std::pow(c, d), N);
}
