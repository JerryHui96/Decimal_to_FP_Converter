/*	Decimal_to_FP.cpp :
	This project is to create 64-bit, 32-bit, and 16-bit floating point in binary form.

	Name:		Jerry Xu
*/

#include <iostream>
#include <math.h>

using namespace std;

char getSignBit(float value);	//	Gets the sign bit of a value in 16, 32, or 64 bit format. 
int * binaryConverter(int bitSize, float value, char signBit[1], char exp[11], char mant[52]);	//	Converts value into binary format
char* toBinary(int value);		//	Converts input value into binary
char intToCharConverter(int value);	//	converts integer to char value

char sign[1];
char expo[5];
char mant[10];

/*
int main()
{
	//binaryConverter(32, -110.125);
	
	
	float arr[8][2] =
	{
		{0.1, 0.55},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
	};
	
	#Comment out the following for loop is wish to run this file separately
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//binaryConverter(32, arr[i][j]);
			binaryConverter(16, arr[i][j], sign, expo, mant);
			printf("\n");
		}
	}
	
	binaryConverter(16, arr[0][0], sign, expo, mant);
	printf("\n");
	binaryConverter(16, arr[0][1], sign, expo, mant);
	printf("\n");
	binaryConverter(16, 0.65, sign, expo, mant);
	printf("\n");

	return 0;
}
*/
								// main function

char getSignBit(float value)
{
	if (value >= 0)
	{
		return '0';
	}
	else
	{
		return '1';
	}
}
char intToCharConverter(int value)
{
	char output;

	switch (value)
	{
	case 0:
		output = '0';
		break;
	case 1:
		output = '1';
		break;
	case 2:
		output = '2';
		break;
	case 3:
		output = '3';
		break;
	case 4:
		output = '4';
		break;
	case 5:
		output = '5';
		break;
	case 6:
		output = '6';
		break;
	case 7:
		output = '7';
		break;
	case 8:
		output = '8';
		break;
	case 9:
		output = '9';
		break;
	}
	return output;
}
int charToIntConverter(char value)
{
	int output;
	switch (value)
	{
	case '0':
		output = 0;
		break;
	case '1':
		output = 1;
		break;
	case '2':
		output = 2;
		break;
	case '3':
		output = 3;
		break;
	case '4':
		output = 4;
		break;
	case '5':
		output = 5;
		break;
	case '6':
		output = 6;
		break;
	case '7':
		output = 7;
		break;
	case '8':
		output = 8;
		break;
	case '9':
		output = 9;
		break;
	default:
		//printf("error1");
		return 0;
	}

	return output;
}
char* toBinary(int value)
{
	char output[100];
	int temp;

	for (int i = 0; i < 100; i++)				//Initialize the array to 0
	{
		output[i] = '0';
	}

	for (int i = 0; value > 0; i++)				//Converting decimal to binary and store in output array.
	{
		temp = value % 2;
		output[i] = intToCharConverter(temp);
		value = value / 2;
	}

	return output;
}
int* binaryConverter(int bitSize, float value, char signBit[1], char exp[11], char mant[52])		//Converting a float decimal into Half/Single/Double precision binary
{
	signBit[0] = getSignBit(value);					//	Gets sign bit of input value
	char store[100];								//	
	char* temp;										
	int normExponent = 0;							//	Normalized exponent in FP binary
	int expInd;										//	Exponent index, determine by desired output precision
	int mantInd;									//	Mantissa index, determine by desired output precision
	int ebias;										//	Bias exponent, determine by desired output precision
	int biasExponent = 0;							//	Bias exponent in FP binary
	int a;											//	Integer part of value
	float b;										//	Decimal part of value
	if (value >= 0)
	{
		a = int(value);
		b = value - a;
	}
	else
	{
		a = int(0 - value);
		b = 0 - value - a;
	}
	switch (bitSize)
	{
	case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		ebias = 15;
		break;
	case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		ebias = 127;
		break;
	case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		ebias = 1027;
		break;
	default:
		printf("error");
		break;
		return 0;
	}
	/*******************************Determining Normalized Exponent in binary*****************************/
	temp = toBinary(a);									//	Converts integer part of input value and store in register with the address stored in temp  
	for (int i = 10; i >= 0; i--)
	{
		if (*(temp + i) == '1' && biasExponent == 0)	//	Determine normalized exponent in decimal value and save in store array
		{
			normExponent = i + ebias;					//	Calculate normalized exponent in decimal value and store in normExponent register 
			biasExponent = i;							

			for (int j = 0; j <= i; j++)
			{
				store[j] = *(temp + i - j);				//	Stores converted binary array of integer into store register
			}
			break;
		}

	}

	temp = toBinary(normExponent);						//	Determine decimal part of input value and store store in register with the address stored in temp  

	for (int i = expInd; i >= 0; i--)					//	Save normalized exponent in binary in exp array
	{
		exp[expInd - i] = *(temp + i);
	}


	/************************************Determining Mantissa in binary**************************/

	for (int i = 0; i <= mantInd; i++)
	{
		if (i < biasExponent)				
		{
			mant[i] = store[1 + i];						// Stores converted integer binary array of integer in mant register
		}
		else
		{
			if (b * 2 >= 1)
			{
				mant[i] = '1';
				b = b * 2 - 1;
			}
			else
			{
				mant[i] = '0';
				b = b * 2;
			}
		}
	}

	
	//Display the converted FP in binary form
	printf("The %d bit Floating Point of %f in binary = ", bitSize, value);
	printf("%c\t", signBit[0]);
	for (int i = 0; i <= expInd; i++)
	{
		printf("%c", exp[i]);
	}
	printf("\t");
	for (int i = 0; i <= mantInd; i++)
	{
		printf("%c", mant[i]);
	}
	printf("\n");
	

	return 0;
}

/**/
