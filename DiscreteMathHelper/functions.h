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

void func_BinaryToDecAndHex()
{
    string input;
	Helper::prompt("Enter a binary string: ", input);
    if (Helper::isBinaryString(input))
    {
        Binary bin(input);
        cout << endl;
        printf("%-29s%-15s%s\n", "Binary", "Decimal", "Hex");
        printf("%-29s%-15lli%s\n", input.c_str(), Converter::binaryStringToDec(input), Converter::fromDec(bin.toInteger(), 16).c_str());
    }
    else
    {
        cerr << "ERROR: Not a binary string" << endl;
    }
}

void func_DecToHexAndBinary()
{
    int input;
	Helper::prompt("Enter an Integer: ", input);
    cout << endl;
    printf("%-15s%-15s%s\n", "Decimal", "Hex", "Binary");
	printf("%-15d%-15s%s\n", input, Converter::fromDec(input, 16).c_str(), Converter::fromDec(input, 2).c_str());
}

void func_HexToDecAndBinary()
{
    string input;
	Helper::prompt("Enter a Hex string: ", input);
    long long dec = Converter::hexStringToDec(input);
    Binary bin(dec);
    
    cout << endl;
    printf("%-15s%-15s%s\n", "Hex", "Decimal", "Binary");
	printf("%-15s%-15lli%s\n", input.c_str(), dec, bin.toString().c_str());
}

void func_mod()
{
	int num1, num2;
	Helper::prompt("Enter an integer n1: ", num1);
	Helper::prompt("Enter an integer n2: ", num2);
	cout << num1 << " mod " << num2 << " = " << Helper::mod(num1, num2) << endl;
}

void func_DecToOtherBaseSystem()
{
	int num, base;
	Helper::prompt("Enter an Integer: ", num);
	Helper::prompt("Enter a base: ", base);
	cout << "\nAnswer: " << Converter::fromDec(num, base) << endl;
}

void func_OtherBaseSystemToDec()
{
	int input, base;
	Helper::prompt("Enter an Integer: ", input);
	Helper::prompt("Enter a base: ", base);
	cout << "\nAnswer: " << Converter::toDec(input, base) << endl;
}

void func_textToBinary()
{
	string input;
	int bits;
	Helper::prompt("Enter a text: ", input);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical;
	cout << numerical.textToBinary(input, bits) << endl;
}

void func_BinaryToText()
{
	string input;
    Helper::prompt("Enter a binary string: ", input);
    if (Helper::isBinaryString(input))
    {
        int bits;
        Helper::prompt("Enter the number of bits per char: ", bits);
        NumericalMessage numerical;
        cout << numerical.binaryToText(input, bits) << endl;
    }
    else
    {
        cerr << "ERROR: Not a binary string" << endl;
    }
}

void func_textToDecimal()
{
	string input;
	int bits;
	Helper::prompt("Enter a text: ", input);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage numerical(0);
	Binary temp = numerical.textToBinary(input, bits);

	cout << temp.toInteger() << endl;
}

void func_isPrime()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	cout << (PrimeNumber::isPrime(input) ? "The number is Prime" : "The number is NOT Prime") << endl;
}

void func_PrimeFactorization()
{
	int input;
	Helper::prompt("Enter an Integer: ", input);
	cout << PrimeNumber::factorize(input) << endl;
}

void func_gcd()
{
	int num1, num2, result;
	Helper::prompt("Enter an integer n1: ", num1);
	Helper::prompt("Enter an integer n2: ", num2);
	result = Helper::gcd(num1, num2);
	cout << "gcd(" << num1 << ", " << num2 << ") = " << PrimeNumber::factorize(result) << "= " << result << endl;
}

void func_lcm()
{
	int num1, num2, result;
	Helper::prompt("Enter an integer n1: ", num1);
	Helper::prompt("Enter an integer n2: ", num2);

	result = Helper::lcm(num1, num2);
	cout << "lcm(" << num1 << ", " << num2 << ") = " << PrimeNumber::factorize(result) << "= " << result << endl;
}

void func_gcdExtended()
{
	int num1, num2;
	Helper::prompt("Enter an integer n1: ", num1);
	Helper::prompt("Enter an integer n2: ", num2);
	EuclideanAlgorithm algo;
	auto result = algo.gcdExtended(num1, num2);
	cout << "gcd(" << num1 << ", " << num2 << ") = " << result << " = " << result.gcd << endl;
}

void func_SimpleEncrypt()
{
	int m, key, N;
	SymmetricKeyCrypto crypto;
	Helper::prompt("Enter the plaintext as Integer m: ", m);
	Helper::prompt("Enter a key as Integer k: ", key);
	Helper::prompt("Enter a Prime number N: ", N);
    cout << endl << "Encryption formula: c = (" << m << " + " << key << ") % " << N;
	cout << " = " << crypto.encrypt(m, key, N) << endl;
}

void func_SimpleDecrypt()
{
	int c, key, N;
	SymmetricKeyCrypto crypto;
	Helper::prompt("Enter the ciphertext as Integer c: ", c);
	Helper::prompt("Enter a key as Integer k: ", key);
	Helper::prompt("Enter a Prime number N: ", N);
    cout << endl  << "Decryption formula: m = (" << c << " - " << key << ") % " << N;
	cout << " = " << crypto.decrypt(c, key, N) << endl;
}

void func_RSA_Encryption()
{
	int p, q, e, m;
	Helper::prompt("Enter a prime number p: ", p);
	Helper::prompt("Enter a prime number q: ", q);
	Helper::prompt("Enter a prime number for public key e: ", e);
	RSA rsa(p, q, e);
	Helper::prompt("Enter message as Integer m: ", m);
	cout  << endl  << "Encryption formula: "
        << rsa.getEncryptionFormula(m) << endl;
}

void func_RSA_EncryptText()
{
	int p, q, e, bits;
	string m;
	Helper::prompt("Enter a prime number p: ", p);
	Helper::prompt("Enter a prime number q: ", q);
	Helper::prompt("Enter a prime number for public key e: ", e);

	RSA rsa(p, q, e);
	Helper::prompt("Enter plain text message: ", m);
	Helper::prompt("Enter the number of bits per char: ", bits);
	NumericalMessage nMsg;
	Binary temp = nMsg.textToBinary(m, bits);
	Binary temp2("1");
	cout << endl  << "Encryption formula: "
        << rsa.getEncryptionFormula((temp + temp2).toInteger()) << endl;
}

void func_RSA_Decryption()
{
	int p, q, e, c;
	Helper::prompt("Enter a prime number p: ", p);
	Helper::prompt("Enter a prime number q: ", q);
	Helper::prompt("Enter a prime number for public key e: ", e);
	RSA rsa(p, q, e);
    Helper::prompt("Enter the cipher as Interger c: ", c);
    cout << endl << "Private key: d  = " << rsa.getPrivateKey() << endl;
	cout << "Decryption formula: " << rsa.getDecryptionFormula(c) << endl;
}

void func_RSA_DecryptText()
{
	int p, q, e, c;
	Helper::prompt("Enter a prime number p: ", p);
	Helper::prompt("Enter a prime number q: ", q);
	Helper::prompt("Enter a prime number for public key e: ", e);
	RSA rsa(p, q, e);
    Helper::prompt("Enter the cipher as Interger c: ", c);
    cout << endl << "Private key: d = " << rsa.getPrivateKey() << endl;
	cout << "Decryption formula: " << rsa.getDecryptionFormula(c) << endl;

	int result, bits;
	Helper::prompt("Enter the result of m: ", result);
	Helper::prompt("Enter the number of bits per char: ", bits);
	Binary bin(result);
	Binary temp("1");
	NumericalMessage nMsg;
	cout << nMsg.binaryToText((bin - temp).toString(), bits);
}

void func_PrintRSAFormulas()
{
	cout << "N = p * q" << endl;
	cout << "phi = (p - 1) * (q - 1)" << endl;
	cout << "Encrypt formula: c = m^e mod N " << endl;
	cout << "Decrypt formula: m = c^d mod N " << endl;
}
