/*
	Nguyen Nguyen, Ben Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#include "functions.h"
#include "menu_controller.h"

int main()
{
	MenuController menuCtrl("***** DISCRETE MATH HELPER - INTEGER PROPERTIES *****");
    menuCtrl.setMenuExitKey("-1");
    
	MenuGroup group1("Calculator");
    group1.addMenuItem("mod(n1, n2), Euclidean Modulo", func_mod);
    group1.addMenuItem("gcd(n1, n2), Greatest Common Divisor", func_gcd);
    group1.addMenuItem("lcm(n1, n2), Least Common Multiple", func_lcm);
    group1.addMenuItem("gcd(n1, n2)=s(n1)+t(n2), Ext. Euclidean Algo", func_gcdExtended);
	group1.addMenuItem("Check Prime Number", func_isPrime);
	group1.addMenuItem("Prime Factorization", func_PrimeFactorization);
	menuCtrl.addGroup(group1);

	MenuGroup group2("Converters");
    group2.addMenuItem("Binary to Decimal and Hex", func_BinaryToDecAndHex);
    group2.addMenuItem("Hex to Dec and Binary", func_HexToDecAndBinary);
    group2.addMenuItem("Decimal to Hex and Binary", func_DecToHexAndBinary);
    group2.addMenuItem("Decimal to Other Base System", func_DecToOtherBaseSystem);
	group2.addMenuItem("Other Base System to Decimal", func_OtherBaseSystemToDec);
    group2.addMenuItem("Text to Binary", func_textToBinary);
	group2.addMenuItem("Binary to Text", func_BinaryToText);
	group2.addMenuItem("Text to Decimal", func_textToDecimal);
	menuCtrl.addGroup(group2);

	MenuGroup group3("Simple Cryptosystem");
	group3.addMenuItem("Encrypt", func_SimpleEncrypt);
	group3.addMenuItem("Decrypt", func_SimpleDecrypt);
	menuCtrl.addGroup(group3);

	MenuGroup group4("RSA");
	group4.addMenuItem("Encrypt", func_RSA_Encryption);
	group4.addMenuItem("Decrypt", func_RSA_Decryption);
	group4.addMenuItem("Encrypt Text Message", func_RSA_EncryptText);
	group4.addMenuItem("Decrypt Text Message", func_RSA_DecryptText);
	menuCtrl.addGroup(group4);

    menuCtrl.show();

	return 0;
}
