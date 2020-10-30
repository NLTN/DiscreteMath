/*
	Nguyen Nguyen, Ben Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#include "functions.h"
#include "menu_controller.h"

int main()
{
	MenuController menuCtrl("*** DISCRETE MATH HELPER - INTEGER PROPERTIES ***");
    menuCtrl.setMenuExitKey("-1");
    
	MenuGroup group1("Calculator");
	group1.addMenuItem("Mod (Euclidean Mod)", &run_Mod);
	group1.addMenuItem("gcd (Greatest Common Divisor)", &run_gcd);
	group1.addMenuItem("lcm (Least Common Multiple)", &run_lcm);
	group1.addMenuItem("gcd Extended (Greatest Common Divisor)", &run_gcdExt);
	group1.addMenuItem("Check Prime Number", &run_isPrime);
	group1.addMenuItem("Prime Factorization", run_PrimeFactorization);
	menuCtrl.addGroup(group1);

	MenuGroup group2("Converters");
    group2.addMenuItem("Binary to Decimal and Hex", &run_BinaryToDecAndHex);
	//group2.addMenuItem("Binary to Decimal", &run_Bin2Dec);
	//group2.addMenuItem("Binary to Hex", &run_Bin2Hex);
    
    group2.addMenuItem("Decimal to Hex and Binary", &run_DecToHexAndBinary);
	//group2.addMenuItem("Decimal to Binary", &run_Dec2Bin);
	//group2.addMenuItem("Decimal to Hex", &run_Dec2Hex);
	
    group2.addMenuItem("Decimal to Other Base System", &run_DecToOtherBaseSystem);
	group2.addMenuItem("Other Base System to Decimal", &run_OtherBaseSystemToDec);
	
    group2.addMenuItem("Hex to Dec and Binary", &run_HexToDecAndBinary);
    //group2.addMenuItem("Hex to Dec", &run_Hex2Dec);
	//group2.addMenuItem("Hex to Binary", &run_Hex2Bin);
	
    group2.addMenuItem("Text to Binary", &run_textToBinary);
	group2.addMenuItem("Binary to Text", &run_BinaryToText);
	group2.addMenuItem("Text to Decimal", &run_textToDecimal);
	menuCtrl.addGroup(group2);

	MenuGroup group3("Simple Cryptosystem");
	group3.addMenuItem("Encrypt", run_SimpleEncrypt);
	group3.addMenuItem("Decrypt", run_SimpleDecrypt);
	menuCtrl.addGroup(group3);

	MenuGroup group4("RSA");
	group4.addMenuItem("Encrypt", &run_RSA_Encryption);
	group4.addMenuItem("Decrypt", &run_RSA_Decryption);
	group4.addMenuItem("Encrypt Text Message", &run_RSA_EncryptText);
	group4.addMenuItem("Decrypt Text Message", &run_RSA_DecryptText);
	menuCtrl.addGroup(group4);

    menuCtrl.show();

	return 0;
}
