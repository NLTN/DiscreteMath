/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <cmath>
#include "euclidean_algorithm.h"

class RSA
{
public:
	RSA(int prime1, int prime2, int encryptKey);
	~RSA();
	int getPrivateKey();
	int encrypt(int m);
	int decrypt(int c);
	std::string getEncryptionFormula(int m);
	std::string getDecryptionFormula(int c);
	size_t mod(size_t n1, size_t n2);

private:
	int p, q, e, d, N, phi;
};

inline RSA::RSA(int prime1, int prime2, int encryptKey)
	: p(prime1), q(prime2), e(encryptKey)
{
	N = p * q;
	phi = (p - 1) * (q - 1);

	EuclideanAlgorithm algo;
	d = algo.gcdExtended(e, phi).s;
}

RSA::~RSA()
{
}

inline int RSA::getPrivateKey()
{
	return d;
}

int RSA::encrypt(int m)
{
	return mod(std::pow(m, e), N);
}

inline std::string RSA::getEncryptionFormula(int m)
{
	std::stringstream ss;
	ss << "c = " << m << "^" << e << " mod " << N;
	return ss.str();
}

inline std::string RSA::getDecryptionFormula(int c)
{
	std::stringstream ss;
	ss << "m = " << c << "^" << d << " mod " << N;
	return ss.str();
}

int RSA::decrypt(int c)
{
	return mod(std::pow(c, d), N);
}

size_t RSA::mod(size_t n1, size_t n2)
{
	return n1 < 0 ? n1 % n2 + n2 : n1 % n2;
}
