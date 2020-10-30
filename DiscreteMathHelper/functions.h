/*
	Nguyen Nguyen, Ben Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include "helper.h"
#include "binary.h"
#include "prime_number.h"
#include "numerical_message.h"
#include "symmetric_key_crypto.h"
#include "euclidean_algorithm.h"
#include "rsa.h"

using namespace std;

void run_BinaryToDecAndHex()
{
    string input;
	Helper::prompt("Enter a binary string: ", input);
	Binary bin(input);
    cout << endl;
    printf("%-15s%-15s%s\n", "Binary", "Decimal", "Hex");
	printf("%-15s%-15lli%s\n", input.c_str(), Converter::binaryStringToDec(input), Converter::fromDec(bin.toInteger(), 16).c_str());
}

void run_DecToHexAndBinary()
{
    int input;
	Helper::prompt("Enter an Integer: ", input);
    cout << endl;
    printf("%-15s%-15s%s\n", "Decimal", "Hex", "Binary");
	printf("%-15d%-15s%s\n", input, Converter::fromDec(input, 16).c_str(), Converter::fromDec(input, 2).c_str());
}

void run_HexToDecAndBinary()
{
    string input;
	Helper::prompt("Enter a Hex string: ", input);
    long long dec = Converter::hexStringToDec(input);
    Binary bin(dec);
    
    cout << endl;
    printf("%-15s%-15s%s\n", "Hex", "Decimal", "Binary");
	printf("%-15s%-15lli%s\n", input.c_str(), dec, bin.toString().c_str());
}

void run_Bin2Dec()
{
	string input;
	Helper::prompt("Enter a binary string: ", input);
	Binary bin(input);
	cout << "Binary" << std::setw(10) << "Decimal" << endl;
	cout << "-------------------------------------" << endl;
	cout << input << std::setw(10) << bin.toInteger() << endl;
}

void run_Bin2Hex()
{
	string input;
	Helper::prompt("Enter a binary string: ", input);
	Binary bin(input);
	cout << "\nBinary" << std::setw(17) << "Hexadecimal" << endl;
	cout << "-------------------------------------" << endl;
	cout << input << std::setw(17) << Converter::fromDec(bin.toInteger(), 16) << endl;
}

void run_Dec2Bin()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	Binary bin(input);
	cout << "\nDecimal" << std::setw(15) << "Binary" << endl;
	cout << "-------------------------------------" << endl;
	cout << input << std::setw(17) << bin.toString() << endl;
}

void run_Dec2Hex()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	cout << "\nDecimal" << std::setw(15) << "Hexadecimal" << endl;
	cout << "-------------------------------------" << endl;
	cout << input << std::setw(17) << Converter::fromDec(input, 16) << endl;
}

void run_Mod()
{
	int num1, num2;
	Helper::prompt("Enter an 1st number: ", num1);
	Helper::prompt("Enter an 2nd number: ", num2);
	cout << num1 << " mod " << num2 << " = " << Helper::mod(num1, num2) << endl;
}

void run_DecToOtherBaseSystem()
{
	int num, base;
	Helper::prompt("Enter an Integer: ", num);
	Helper::prompt("Enter a base: ", base);
	cout << "\nAnswer: " << Converter::fromDec(num, base) << endl;
}

void run_OtherBaseSystemToDec()
{
	int input, base;
	Helper::prompt("Enter an Integer: ", input);
	Helper::prompt("Enter a base: ", base);
	cout << "\nAnswer: " << Converter::toDec(input, base) << endl;
}

void run_Hex2Dec()
{
	string input;
	Helper::prompt("Enter a Hex string: ", input);
	cout << Converter::hexStringToDec(input) << endl;
}

void run_Hex2Bin()
{
	string input;
	Helper::prompt("Enter a Hex string: ", input);
	Binary bin(Converter::hexStringToDec(input));
	cout << bin << endl;
}

void run_textToBinary()
{
	string input;
	int bits;
	Helper::prompt("Enter a text: ", input);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical;
	cout << numerical.textToBinary(input, bits) << endl;
}

void run_BinaryToText()
{
	string input;
	int bits;
	Helper::prompt("Enter a binary string: ", input);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical;
	cout << numerical.binaryToText(input, bits) << endl;
}

void run_textToDecimal()
{
	string input;
	int bits;
	Helper::prompt("Enter a text: ", input);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical(0);
	Binary temp = numerical.textToBinary(input, bits);

	cout << temp.toInteger() << endl;
}

void run_isPrime()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	cout << (PrimeNumber::isPrime(input) ? "The number is Prime" : "The number is NOT Prime") << endl;
}

void run_PrimeFactorization()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	cout << PrimeNumber::factorize(input) << endl;
}

void run_gcd()
{
	int num1, num2, result;
	Helper::prompt("Enter an Integer: ", num1);
	Helper::prompt("Enter an Integer: ", num2);
	result = Helper::gcd(num1, num2);
	cout << "gcd(" << num1 << ", " << num2 << ") = " << PrimeNumber::factorize(result) << "= " << result << endl;
}

void run_lcm()
{
	int num1, num2, result;
	Helper::prompt("Enter an Integer: ", num1);
	Helper::prompt("Enter an Integer: ", num2);

	result = Helper::lcm(num1, num2);
	cout << "lcm(" << num1 << ", " << num2 << ") = " << PrimeNumber::factorize(result) << "= " << result << endl;
}

void run_gcdExt()
{
	int num1, num2;
	Helper::prompt("Enter an Integer: ", num1);
	Helper::prompt("Enter an Integer: ", num2);
	EuclideanAlgorithm algo;
	auto result = algo.gcdExtended(num1, num2);
	cout << "gcd(" << num1 << ", " << num2 << ") = " << result << " = " << result.gcd << endl;
}

void run_SimpleEncrypt()
{
	int m, key, N;
	SymmetricKeyCrypto crypto;
	Helper::prompt("Enter the plaintext as Integer m: ", m);
	Helper::prompt("Enter a key as Integer k: ", key);
	Helper::prompt("Enter a Prime number N: ", N);
	cout << crypto.encrypt(m, key, N) << endl;
}

void run_SimpleDecrypt()
{
	int c, key, N;
	SymmetricKeyCrypto crypto;
	Helper::prompt("Enter the ciphertext as Integer c: ", c);
	Helper::prompt("Enter a key as Integer k: ", key);
	Helper::prompt("Enter a Prime number N: ", N);
	cout << crypto.decrypt(c, key, N) << endl;
}

void run_RSA_Encryption()
{
	int p, q, e, m;
	Helper::prompt("Enter p as Prime number: ", p);
	Helper::prompt("Enter q as Prime number: ", q);
	Helper::prompt("Enter public key as Prime number: ", e);
	RSA rsa(p, q, e);
	cout << "Private Key: " << rsa.getPrivateKey() << endl;
	Helper::prompt("Enter message as Integer: ", m);
	cout << rsa.getEncryptionFormula(m) << endl;
}

void run_RSA_EncryptText()
{
	int p, q, e, bits;
	string m;
	Helper::prompt("Enter p as Prime number: ", p);
	Helper::prompt("Enter q as Prime number: ", q);
	Helper::prompt("Enter public key as Prime number: ", e);

	RSA rsa(p, q, e);
	cout << "Private Key: " << rsa.getPrivateKey() << endl;

	Helper::prompt("Enter text message: ", m);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical(0);
	Binary temp = numerical.textToBinary(m, bits);
	Binary temp2("1");
	cout << rsa.getEncryptionFormula((temp + temp2).toInteger()) << endl;
}

void run_RSA_Decryption()
{
	int p, q, e, c;
	Helper::prompt("Enter p as Prime number: ", p);
	Helper::prompt("Enter q as Prime number: ", q);
	Helper::prompt("Enter public key as Prime number: ", e);
	RSA rsa(p, q, e);
	cout << "Private Key: " << rsa.getPrivateKey() << endl;
	Helper::prompt("Enter message as Integer: ", c);
	cout << rsa.getDecryptionFormula(c) << endl;
}

void run_RSA_DecryptText()
{
	int p, q, e, c;
	Helper::prompt("Enter p as Prime number: ", p);
	Helper::prompt("Enter q as Prime number: ", q);
	Helper::prompt("Enter public key as Prime number: ", e);
	RSA rsa(p, q, e);
	cout << "Private Key: " << rsa.getPrivateKey() << endl;
	Helper::prompt("Enter message as Integer: ", c);
	cout << rsa.getDecryptionFormula(c) << endl;

	int result, bits;
	Helper::prompt("Enter a result: ", result);
	Helper::prompt("Enter the bits per char: ", bits);
	Binary bin(result);
	Binary temp("1");
	NumericalMessage nMsg;
	cout << nMsg.binaryToText((bin - temp).toString(), bits);
}

void run_PrintRSAFormulas()
{
	cout << "N = p * q" << endl;
	cout << "phi = (p - 1) * (q - 1)" << endl;
	cout << "Encrypt formula: c = m^e mod N " << endl;
	cout << "Decrypt formula: m = c^d mod N " << endl;
}
