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
    int phi = (p - 1) * (q - 1);
    cout << "\n  N = p * q = " << p * q << endl;
    cout << "  Phi = (p - 1) * (q - 1) = " << (p - 1) * (q - 1) << endl;

    EuclideanAlgorithm algo;
    auto gcdResult = algo.gcdExtended(e, phi);
    cout << "  gcdExtended(" << e << ", " << phi << ") = " << gcdResult << " = " << gcdResult.gcd << endl;
    cout << "  Private key d = " << gcdResult.s << " mod " << phi << " = " << rsa.getPrivateKey() << endl;
    cout << endl;
    
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
    int phi = (p - 1) * (q - 1);
    cout << "\n  N = p * q = " << p * q << endl;
    cout << "  Phi = (p - 1) * (q - 1) = " << (p - 1) * (q - 1) << endl;

    EuclideanAlgorithm algo;
    auto gcdResult = algo.gcdExtended(e, phi);
    cout << "  gcdExtended(" << e << ", " << phi << ") = " << gcdResult << " = " << gcdResult.gcd << endl;
    cout << "  Private key d = " << gcdResult.s << " mod " << phi << " = " << rsa.getPrivateKey() << endl;
    cout << endl;

    Helper::prompt("Enter plain text message: ", m);
    Helper::prompt("Enter the number of bits per char: ", bits);
    NumericalMessage nMsg;
    Binary temp = nMsg.textToBinary(m, bits);
    
    // =========== STRING TO INT CONVERTION SCHEME - (BEGIN) =============
    cout << "\n========= String to Integer Convertion Scheme =========\n";
    cout << "1. Replace each letter with its position in the alphabet" << endl;
    cout << "   and Turn each number into a 4-bit binary number" << endl;

    for (int i = 0; i < m.length(); i++)
    {
        int num = nMsg.charToNumber(m[i]);
        string bin = Converter::fromDec(num, 2);
        bin.insert(0, std::string(bits - bin.length(), '0'));
        
        cout << m[i] << " = " << num << " = " << bin << endl;
    }
    cout << endl;
    
    cout << "2. Concatenate the bits" << endl;
    cout << temp << endl << endl;

    cout << "3. Add a number (In the lecture slides, she adds 1)" << endl;
    int shift;
    Helper::prompt("Enter an Interger number you want to add: ", shift);
    Binary temp2(shift);
    
    cout << "Convert " << shift << " to binary: "
        << temp2.toString().insert(0, std::string(bits - temp2.toString().length(), '0'))
        << endl << endl;
    cout << temp.toString() << " + "
        << temp2.toString().insert(0, std::string(bits - temp2.toString().length(), '0'))
        << " = " << (temp + temp2).toString() << " = " << (temp + temp2).toInteger()
        << endl;
    // ========= STRING TO INT CONVERTION SCHEME - (END) ===============
    
    cout << endl << string(50, '*') << endl;
    cout << "Encryption formula: "
        << rsa.getEncryptionFormula((temp + temp2).toInteger());
    cout << endl << string(50, '*') << endl;
}

void func_RSA_Decryption()
{
    int p, q, e, c;
    Helper::prompt("Enter a prime number p: ", p);
    Helper::prompt("Enter a prime number q: ", q);
    Helper::prompt("Enter a prime number for public key e: ", e);
    
    RSA rsa(p, q, e);
    int phi = (p - 1) * (q - 1);
    cout << "\n  N = p * q = " << p * q << endl;
    cout << "  Phi = (p - 1) * (q - 1) = " << (p - 1) * (q - 1) << endl;
    
    EuclideanAlgorithm algo;
    auto gcdResult = algo.gcdExtended(e, phi);
    cout << "  gcdExtended(" << e << ", " << phi << ") = " << gcdResult << " = " << gcdResult.gcd << endl;
    cout << "  Private key d = " << gcdResult.s << " mod " << phi << " = " << rsa.getPrivateKey() << endl;
    cout << endl;

    Helper::prompt("Enter the cipher as Interger c: ", c);
    cout << "Decryption formula: " << rsa.getDecryptionFormula(c) << endl;
}

void func_RSA_DecryptText()
{
    int p, q, e, c;
    Helper::prompt("Enter a prime number p: ", p);
    Helper::prompt("Enter a prime number q: ", q);
    Helper::prompt("Enter a prime number for public key e: ", e);

    RSA rsa(p, q, e);
    int phi = (p - 1) * (q - 1);
    cout << "\n  N = p * q = " << p * q << endl;
    cout << "  Phi = (p - 1) * (q - 1) = " << (p - 1) * (q - 1) << endl;
    EuclideanAlgorithm algo;
    auto gcdResult = algo.gcdExtended(e, phi);
    cout << "  gcdExtended(" << e << ", " << phi << ") = " << gcdResult << " = " << gcdResult.gcd << endl;
    cout << "  Private key d = " << gcdResult.s << " mod " << phi << " = " << rsa.getPrivateKey() << endl;
    cout << endl;

    Helper::prompt("Enter the cipher as Interger c: ", c);
    cout << endl << string(50, '*') << endl;
    cout << "Decryption formula: " << rsa.getDecryptionFormula(c);
    cout << endl << string(50, '*') << endl;

    int result, bits;
    Helper::prompt("Enter the result of m: ", result);
    Helper::prompt("Enter the number of bits per char: ", bits);

    Binary bin(result);
    cout << "\n1. Convert the number " << result << " to Binary:" << endl;
    cout << result << " = " << bin.toString() << endl << endl;

    int shift;
    cout << "2. Subtract a number (If 1 is added in the Encrytion, then subtract 1)" << endl;
    Helper::prompt("Enter an Interger number you want to subtract: ", shift);

    Binary temp2(shift);
    string tranformedBinStr = (bin - temp2).toString();
    if (!(tranformedBinStr.length() / 4))
    {
        tranformedBinStr = tranformedBinStr.insert(0, std::string(bits - tranformedBinStr.length() % bits, '0'));
    }

    cout << "\nConvert " << shift << " to binary: "
        << temp2.toString().insert(0, std::string(bits - temp2.toString().length(), '0'))
        << endl << endl;

    cout << bin.toString().insert(0, std::string(bits - bin.toString().length() % bits, '0'))
        << " - "
        << temp2.toString().insert(0, std::string(bits - temp2.toString().length(), '0'))
        << " = "
        << tranformedBinStr
        << endl;

    cout << "\n======= Integer to String Convertion Scheme =======" << endl;
    NumericalMessage nMsg;
    for (int i = 0; i < tranformedBinStr.length(); i += bits)
    {
        string seg = tranformedBinStr.substr(i, bits);
        cout << seg << " = " << Converter::binaryStringToDec(seg)
            << " = " << nMsg.numberToChar(Converter::binaryStringToDec(seg))
            << endl;
    }

    cout << "\n****************** Concatinate *******************" << endl;
    cout << nMsg.binaryToText((bin - temp2).toString(), bits);
    cout << endl << string(50, '*') << endl;
}
