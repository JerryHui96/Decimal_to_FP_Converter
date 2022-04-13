/* SPFP_Adder.cpp 
	Name:			Jerry Xu
*/

#include <iostream>
#include <math.h>
#include "Decimal_to_FP.cpp"

using namespace std;




struct FP_value			//Floating Point value
{
	char signBit[1];
	char exp[11];
	char mant[52];

};

FP_value A1x76;		//FP value of 98
FP_value B1x76;		//FP value of 169
FP_value A2x76;		//FP value of 99
FP_value B2x76;		//FP value of -89
FP_value A3x76;		//FP value of -45
FP_value B3x76;		//FP value of 79
FP_value A4x76;		//FP value of -283
FP_value B4x76;		//FP value of -66
FP_value A5x76;		//FP value of 0
FP_value B5x76;		//FP value of 0
FP_value A6x76;		//FP value of 0
FP_value B6x76;		//FP value of -117
FP_value A7x76;		//FP value of -110.125
FP_value B7x76;		//FP value of 99.875
FP_value A8x76;		//FP value of 110.875
FP_value B8x76;		//FP value of 99.125

int indexx76 = 0;


void init(void)
{
	A1x76.signBit[0] = '0';
	A2x76.signBit[0] = '0';
	A3x76.signBit[0] = '0';
	A4x76.signBit[0] = '0';
	A5x76.signBit[0] = '0';
	A6x76.signBit[0] = '0';
	A7x76.signBit[0] = '0';
	A8x76.signBit[0] = '0';
	B1x76.signBit[0] = '0';
	B2x76.signBit[0] = '0';
	B3x76.signBit[0] = '0';
	B4x76.signBit[0] = '0';
	B5x76.signBit[0] = '0';
	B6x76.signBit[0] = '0';
	B7x76.signBit[0] = '0';
	B8x76.signBit[0] = '0';

	for (int i = 0; i < 11; i++)
	{
		A1x76.exp[i] = '0';
		A2x76.exp[i] = '0';
		A3x76.exp[i] = '0';
		A4x76.exp[i] = '0';
		A5x76.exp[i] = '0';
		A6x76.exp[i] = '0';
		A7x76.exp[i] = '0';
		A8x76.exp[i] = '0';
		B1x76.exp[i] = '0';
		B2x76.exp[i] = '0';
		B3x76.exp[i] = '0';
		B4x76.exp[i] = '0';
		B5x76.exp[i] = '0';
		B6x76.exp[i] = '0';
		B7x76.exp[i] = '0';
		B8x76.exp[i] = '0';
	}

	for (int i = 0; i < 52; i++)
	{
		A1x76.mant[i] = '0';
		A2x76.mant[i] = '0';
		A3x76.mant[i] = '0';
		A4x76.mant[i] = '0';
		A5x76.mant[i] = '0';
		A6x76.mant[i] = '0';
		A7x76.mant[i] = '0';
		A8x76.mant[i] = '0';
		B1x76.mant[i] = '0';
		B2x76.mant[i] = '0';
		B3x76.mant[i] = '0';
		B4x76.mant[i] = '0';
		B5x76.mant[i] = '0';
		B6x76.mant[i] = '0';
		B7x76.mant[i] = '0';
		B8x76.mant[i] = '0';
	}
}

/*Function Declaration*/
void display(int bitSize, FP_value val, float value);
void FA_1Bit(char input1, char input2, char cin, char *cout, char *sum);
void FP_Adder(int bitSize, FP_value input1, FP_value input2, char signBit[1], char exp[11], char mant[52]);
int expComparator(int bitSize, char exp1[11], char exp2[11]);
int mantComparator(int bitSize, char mant1[52], char mant[52]);
void arrRightShift(int bitSize, int index, char arr[52]);
void arrLeftShift(int bitSize, int index, char arr[52]);
void invert(int bitSize, char arr[52]);
/**/

/*Stage Declaration*/
void stage1(int bitSize, FP_value input1, FP_value input2, char signBit1output[1], char signBit2output[1], char exp1output[11], char exp2output[11], char mant1output[52], char mant2output[52]);
void stage2(int bitSize, char signBit1Input[1], char signBit2Input[1], char exp1Input[11], char exp2Input[11], char mant1Input[52], char mant2Input[52], char exp1output[11], char exp2output[11], char Finalmantoutput[52], char FinalsignBitoutput[1]);
void stage3(int bitSize, char exp1Input[11], char exp2Input[11], char FinalmantInput[52], char Finalexpoutput[11], char Finalmantoutput[52], int *normShiftoutputPtr);
void stage4(int bitSize, char FinalexpInput[11], char FinalmantInput[52], int *normShiftPtrinput, char Finalexpoutput[11], char Finalmantoutput[52]);
/**/

int main()
{	
	/********************************Preparation, setup, and initialization for this project****************************************************/
	int bitSizex76 = 32;
	char tempSBx76[1];
	char tempExpx76[11];
	char tempMantx76[52];

	int expIndx76;
	int mantIndx76;

	switch (bitSizex76)
	{
		case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
			expIndx76 = 4;
			mantIndx76 = 9;
			break;
		case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
			expIndx76 = 7;
			mantIndx76 = 22;
			break;
		case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
			expIndx76 = 10;
			mantIndx76 = 51;
			break;
		default:
			printf("error");
			break;
	}

	//Test values
	float valuesx76[8][2] =
	{
		{98,169},
		{99, -89},
		{-45, 79},
		{-283, -66},
		{0, 0},
		{0, -117},
		{-110.125, 99.875},
		{110.875, 99.125},
	};

	// 'arr' array stores the 32-bit SP floating point in FP_value data type
	FP_value arrx76[8][2] =
	{
		{A1x76, B1x76},
		{A2x76, B2x76},
		{A3x76, B3x76},
		{A4x76, B4x76},
		{A5x76, B5x76},
		{A6x76, B6x76},
		{A7x76, B7x76},
		{A8x76, B8x76},
	};

	FP_value sumx76[8];		// Array of sums in 32-bit SP FP 
	FP_value PLsumx76[8];		// Results using pipelining 

	//Converts all 16 numbers into 32-bit single precision floating point format, and store in 'arr' array in corresponding position.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			binaryConverter(bitSizex76, valuesx76[i][j], tempSBx76, tempExpx76, tempMantx76);
			arrx76[i][j].signBit[0] = tempSBx76[0];
			for (int k = 0; k < 11; k++)
			{
				arrx76[i][j].exp[k] = tempExpx76[k];
			}
			for (int k = 0; k < 52; k++)
			{
				arrx76[i][j].mant[k] = tempMantx76[k];
			}

			display(bitSizex76, arrx76[i][j], valuesx76[i][j]);
		}
	}
	/************************************************************************End of preparation phase*************************************************************/





	/****************************************************************Unpipelining Signle Precision Floating Point Addition Process**************************************************************************************/
	
	printf("\n\n***************************************************Un-Pipelining Result**************************************************\n\n");
	for (int i = 0; i < 8; i++)
	{
		printf("\nSet %d: Sum of %f and %f = ", i+1, valuesx76[i][0], valuesx76[i][1]);
		float temp = valuesx76[i][0] + valuesx76[i][1];												// Gets the sum of two decimal values in decimal form
		FP_Adder(bitSizex76, arrx76[i][0], arrx76[i][1], tempSBx76, tempExpx76, tempMantx76);		/*	Calculates the sign, exponent, and mantissa of the sum of two 32-bit value in floating point format.
																										tempSB array holds the sign bit of the result
																										tempExp array holds the exponent array of the result in Single Precision Floating Point format
																					tempMant array holds the mantissa array of the result in Single Precision Floating Point format
																				*/
		sumx76[i].signBit[0] = tempSBx76[0];											// Stores result sign bit into corresponding position in sum array
		for (int j = 0; j <= expIndx76; j++)										// Stores result exponent array into corresponding position in sum array
		{
			sumx76[i].exp[j] = tempExpx76[j];
		}
		for (int j = 0; j <= mantIndx76; j++)										// Stores result mantissa array into corresponding position in sum array
		{
			sumx76[i].mant[j] = tempMantx76[j];
		}
		if (i == 4)																// Makes output in console window look nice
		{
			printf("\t");
		}
		printf("\t%f\t%c\t", temp, sumx76[i].signBit[0]);							// Prints result sign bit in console window
		for (int j = 0; j <= expIndx76; j++)										// Prints result exponent array in console window
		{
			printf("%c", sumx76[i].exp[j]);
		}
		printf("\t");				
		for (int j = 0; j <= mantIndx76; j++)										// Prints result mantissa array in console window
		{
			printf("%c", sumx76[i].mant[j]);
		}
	}
	/**********************************************************************End of Unpipelining Single Precision Floating Point Addition Process **********************************************************************************/
	


	/***********************************************************************Start of Pipelining Single Precision Floating Point Addtion Process***********************************************************************************/
	int CCx76 = 0;					//	Clock Cycle, starts at -1, when bool clk is false, clock cycle increase by 1
	int S3normShiftoutx76 = 0;		//	Stage 3 normalized shift number output register
	int *S3normShiftoutPtrx76 = &S3normShiftoutx76;		//	Pointer to reference S3normShiftout
	int S4normShiftinx76 = 0;		//	Stage 4 normalized shift number input register
	int *S4normShiftinPtrx76 = &S4normShiftinx76;		//	Pointer to refernce S4normShiftin

	char S1exp1outputx76[11];		//	Register for Stage 1 exponent 1 binary output
	char S1exp2outputx76[11];		//	Register for Stage 1 exponent 2 binary output
	char S2exp1inputx76[11];		//	Register for Stage 2 exponent 1 binary input
	char S2exp2inputx76[11];		//	Register for Stage 2 exponent 2 binary input
	char S2exp1outputx76[11];		//	Register for stage 2 exponent 1 binary output
	char S2exp2outputx76[11];		//	Register for stage 2 exponent 2 binary output
	char S3exp1inputx76[11];		//	Register for stage 3 exponent 1 binary input
	char S3exp2inputx76[11];		//	Register for stage 3 exponent 2 binary input
	char S3expFoutputx76[11];		//	Register for stage 3 final exponent binary output
	char S4expFinputx76[11];		//	Register for stage 4 final exponent binary input

	char S1mant1outputx76[52];		//	Register for stage 1 mantissa 1 binary output
	char S1mant2outputx76[52];		//	Register for stage 1 mantissa 2 binary output
	char S2mant1inputx76[52];		//	Register for stage 2 mantissa 1 binary input
	char S2mant2inputx76[52];		//	Register for stage 2 mantissa 2 binary input
	char S2mantFoutputx76[52];		//	Register for stage 2 final mantissa binary output

	char S3mantFinputx76[52];		//	Register for stage 3 final mantissa binary input
	char S3mantFoutputx76[52];		//	Register for stage 3 final mantissa binary output
	char S4mantFinputx76[52];		//	Register for stage 4 final mantissa binary input

	/***register Initialization**/
	char S1signBit1outputx76[1] = { '0' };
	char S1signBit2outputx76[1] = { '0' };
	char S2signBit1inputx76[1] = { '0' };
	char S2signBit2inputx76[1] = { '0' };
	for (int i = 0; i <= 11; i++)
	{
		S1exp1outputx76[i] = '0';
		S1exp2outputx76[i] = '0';
		S2exp1outputx76[i] = '0';
		S2exp2outputx76[i] = '0';
		S3expFoutputx76[i] = '0';

		S2exp1inputx76[i] = '0';
		S2exp2inputx76[i] = '0';
		S3exp1inputx76[i] = '0';
		S3exp2inputx76[i] = '0';
		S4expFinputx76[i] = '0';
	}
	for (int i = 0; i <= 52; i++)
	{
		S1mant1outputx76[i] = '0';
		S1mant2outputx76[i] = '0';
		S2mantFoutputx76[i] = '0';

		S3mantFoutputx76[i] = '0';

		S2mant1inputx76[i] = '0';
		S2mant2inputx76[i] = '0';
		S3mantFinputx76[i] = '0';
		S4mantFinputx76[i] = '0';
	}
	/***End Register Initialization**/

	printf("\n\n**************************************************End of Unpipeline Adding Result**************************************\n\n");

	bool clk = false;
	while (1)
	{
		if (clk == true)
		{
			/*	Stage 1
					Input:
						bitSize:			(32 bit, single precision)
						arr[index][0]:		input value 1 in 32-bit SP FP
						arr[index][1]:		input value 2 in 32-bit SP FP
					Output:
						S1signBit1output:	sign bit output for SPFP value 1
						S1signBit2output:	sign bit output for SPFP value 2
						S1exp1output:		exponent output for SPFP value 1
						S1exp2output:		exponent output for SPFP value 2
						S1mant1output:		mantissa output for SPFP value 1
						S1mant2output:		mantissa output for SPFP value 2
					Summary:	Compare input exponents to determine the shift amount for smaller mantissa. Also adds two extra bits in both mantissa
									for 2's compliment in future stage if sign bits from both inputs are different.
									E.g :	mantissa 1 input = 10001000000000... --->  output: 01100010000000....
											mantissa 2 input = 01010010000000... --->  output: 01010100100000....
			
				Stage 2
					Input:
							bitSize:			(32 bit, single precision)
							S2signBit1input:	sign bit input for SPFP value 1
							S2signBit2input:	sign bit input for SPFP value 2
							S2exp1input:		exponent input for SPFP value 1
							S2exp2input:		exponent input for SPFP value 2
							S2mant1input:		mantissa input for SPFP value 1
							S2mant2input:		mantissa input for SPFP value 2
					Output:
							S2exp1output:		exponent output for SPFP value 1
							S2exp2output:		exponent output for SPFP value 2
							S2mantFoutput:		unnormalized SPFP mantissa sum output
							PLsum[index - 1].signBit:	Register for pipeline sum sign bit final output
					Summary:	Determine the sign bit for final result, compare 2 unnormalized input mantissas, 2's complement smaller mantissa if both
								sign bits are different, add both mantissa.

				Stage 3	
					Input:	
							bitSize:			(32 bit, single precision)
							S3exp1input:		sign bit input for SPFP value 1
							S3exp2input:		sign bit input for SPFP value 2
							S3mantFinput:		unnormalized SPFP mantissa sum input
					Output:
							S3expFoutput:		unadjusted SPFP exponent output
							S3mantFoutput:		unnormalized SPFP mantissa sum output
							S3normShiftoutPtr:	pointer to register that holds the number of shifts to normalize mantissa sum
					Summary:	Determine the number of shifts required to normalize mantissa sum and the unadjusted exponent output.

				Stage 4
					Input:
							bitSize:			(32 bit, single precision)
							S4expFinput:		unadjusted SPFP exponent input
							S4mantFinput:		unnormalized SPFP mantissa sum input
							S4normShiftinPtr:	pointer to register taht holds the number of shifts to normalize mantissa sum from Stage 3 output
					Output:
							PLsum[index - 3].exp:	Register for pipeline binary exponent final output
							PLsum[index - 3].mant:	Register for pipeline binary mantissa final output
					Summary:	Normalize input mantissa sum and adjust input exponent to output final normalized mantissa and exponent.
			*/
			stage1(bitSizex76, arrx76[indexx76][0], arrx76[indexx76][1], S1signBit1outputx76, S1signBit2outputx76, S1exp1outputx76, S1exp2outputx76, S1mant1outputx76, S1mant2outputx76);
			stage2(bitSizex76, S2signBit1inputx76, S2signBit2inputx76, S2exp1inputx76, S2exp2inputx76, S2mant1inputx76, S2mant2inputx76, S2exp1outputx76, S2exp2outputx76, S2mantFoutputx76, PLsumx76[indexx76 - 1].signBit);
			stage3(bitSizex76, S3exp1inputx76, S3exp2inputx76, S3mantFinputx76, S3expFoutputx76, S3mantFoutputx76, S3normShiftoutPtrx76);
			stage4(bitSizex76, S4expFinputx76, S4mantFinputx76, S4normShiftinPtrx76, PLsumx76[indexx76 - 3].exp, PLsumx76[indexx76 - 3].mant);

			//	Pass output value from each stage to input registers of its next stage. 
			S2signBit1inputx76[0] = S1signBit1outputx76[0];
			S2signBit2inputx76[0] = S1signBit2outputx76[0];
			S4normShiftinx76 = S3normShiftoutx76;
			for (int i = 0; i <= expIndx76; i++)
			{
				S2exp1inputx76[i] = S1exp1outputx76[i];
				S2exp2inputx76[i] = S1exp2outputx76[i];
				S3exp1inputx76[i] = S2exp1outputx76[i];
				S3exp2inputx76[i] = S2exp2outputx76[i];
				S4expFinputx76[i] = S3expFoutputx76[i];
			}

			for (int i = 0; i <= mantIndx76; i++)
			{
				S2mant1inputx76[i] = S1mant1outputx76[i];
				S2mant2inputx76[i] = S1mant2outputx76[i];
				S3mantFinputx76[i] = S2mantFoutputx76[i];
				S4mantFinputx76[i] = S3mantFoutputx76[i];
			}

			if (indexx76 < 11)
			{
				++indexx76;
			}
		}
		else
		{
			CCx76++;
			if (CCx76 == 12)
			{
				break;
			}
		}

		clk = !clk;		//	Toggle clock value
	}

	printf("*******************************************************Pipelining Adding Result****************************************\n\n");
	/*
		This section outputs results from pipelining process in a console window
	*/
	for (int i = 0; i < 8; i++)
	{
		float tempx76 = valuesx76[i][0] + valuesx76[i][1];											//	Temporary result holding register
		printf("The result of %f and %f =", valuesx76[i][0], valuesx76[i][1]);
		printf("\t");
		if (i == 4)
		{
			printf("\t");
		}
		printf("%f\t", tempx76);
		printf("%c\t", PLsumx76[i].signBit[0]);
		for (int j = 0; j <= expIndx76; j++)
		{
			printf("%c", PLsumx76[i].exp[j]);
		}
		printf("\t");
		for (int j = 0; j <= mantIndx76; j++)
		{
			printf("%c", PLsumx76[i].mant[j]);
		}
		cout << endl;
	}
	printf("\n*******************************************************End of Pipelining Adding Result****************************************\n\n");
	return 0;
}


/**************************************************Unpipelining Functions Definition*******************************************/
//	Display the decimal and sign bit, exponent, and mantissa of the input value in binary
void display(int bitSize, FP_value val, float value)
{
	int expInd;
	int mantInd;

	switch (bitSize)
	{
	case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	printf("The %d bit Floating Point of %f in binary = ", bitSize, value);
	printf("\t%c\t", val.signBit[0]);
	for (int i = 0; i <= expInd; i++)
	{
		printf("%c", val.exp[i]);
	}
	printf("\t");
	for (int i = 0; i <= mantInd; i++)
	{
		printf("%c", val.mant[i]);
	}
	printf("\n");
}
//	1 Bit Full Adder, takes 2 input value and a carry to output the sum and a carry out bit
void FA_1Bit(char input1, char input2, char cin, char *cout, char *sum)
{
	int tempInput1 = charToIntConverter(input1);
	int tempInput2 = charToIntConverter(input2);
	int tempCin = charToIntConverter(cin);
	int tempCout;
	int tempSum;

	tempCout = (tempInput1 & tempInput2) | (tempInput2 & tempCin) | (tempInput1 & tempCin);

	tempSum = (!tempInput1 & !tempInput2 | tempInput1 & tempInput2) & tempCin | (!tempInput1 & tempInput2 | tempInput1 & !tempInput2) & !tempCin;

	*cout = intToCharConverter(tempCout);
	*sum = intToCharConverter(tempSum);
}
//	Takes 2 floating point values in binary and outputs the sign bit, exponent, and mantissa of their sum in SPFP format.
void FP_Adder(int bitSize, FP_value input1, FP_value input2, char signBit[1], char exp[11], char mant[52])
{
	int shift = 0;					// Position to be shifted
	int invertCout;					// Carry out for the invert function
	char temp[52];					// Stores mantissa array of the smaller value to be shifted
	char temp1[52];					// Addtional mantissa array
	char *tempPtr;					// Pointer to temperory arrays
	char cin = '0';					// Carry in for mantissa addition using 1 bit full adder
	char cout = '0';				// Carry out for mantissa addition using 1 bit full adder
	char *coPtr = &cout;			// Address of Carry out for mantissa ddition using 1 bit full adder
	int tempVal = 0;				// Temporary value holder
	int expInd;						// Exponent index
	int mantInd;					// Mantissa index

	switch (bitSize)
	{ 
	case 16:						// 16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						// 32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break; 
	case 64:						// 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	// Check to see if the first input exponent array is 0
	for (int i = 0; i <= expInd; i++)						//Checks if input 1 is 0 by checking all its exponent bits
	{
		if (input1.exp[i] == '1')
		{
			break;
		}
		else if (i == expInd && input1.exp[i] == '0')
		{
			signBit[0] = input2.signBit[0];
			for (int i = 0; i <= expInd; i++)
			{
				exp[i] = input2.exp[i];
			}
			for (int i = 0; i < mantInd; i++)
			{
				mant[i] = input2.mant[i];
			}
			return;
		}
	}

	// Check to see if the second input exponent array is 0
	for (int i = 0; i <= expInd; i++)						//Checks if input 2 is 0 by checking all its exponent bits
	{
		if (input2.exp[i] == '1')
		{
			break;
		}
		else if (i == expInd && input2.exp[i] == '0')
		{
			signBit[0] = input1.signBit[0];
			for (int i = 0; i <= expInd; i++)
			{
				exp[i] = input1.exp[i];
			}
			for (int i = 0; i < mantInd; i++)
			{
				mant[i] = input1.mant[i];
			}
			return;
		}
	}

	
	shift = expComparator(bitSize, input1.exp, input2.exp);		// Compares both input exponent arrays, returns the number of positions need to be shifted
	
	// Preliminary decisions on result exponent bits and sign bit
	if (shift > 0)												// POSITIVE shift value
	{
		for (int i = 0; i <= mantInd; i++)
		{
			temp[i] = input2.mant[i];
			temp1[i] = input1.mant[i];
		}

		arrRightShift(bitSize, shift, temp);					// Right shifts temp (input 1) exponent array
		for (int i = 0; i <= expInd; i++)
		{
			exp[i] = input1.exp[i];
		}

		signBit[0] = input1.signBit[0];							// Assign result sign bit
	}
	else if (shift < 0)											// NEGATIVE shift value
	{
		for (int i = 0; i <= mantInd; i++)
		{
			temp[i] = input1.mant[i];
			temp1[i] = input2.mant[i];
		}

		arrRightShift(bitSize, 0 - shift, temp);				// Right shifts temp (input 2) exponent array
		for (int i = 0; i <= expInd; i++)
		{
			exp[i] = input2.exp[i];
		}
		signBit[0] = input2.signBit[0];							// Assu result sign bit
	}
	else														// shift == 0, meaning both exponent arrays are equal in value								
	{
		for (int i = 0; i < 52; i++)
		{
			temp[i] = input1.mant[i];
			temp1[i] = input2.mant[i];
		}
		for (int i = 0; i < 11; i++)
		{
			exp[i] = input2.exp[i];
		}

		if (mantComparator(bitSize, input1.mant, input2.mant) == 1)
		{
			signBit[0] = input1.signBit[0];						// Assign result sign bit
		}
		else
		{
			signBit[0] = input2.signBit[0];						// Assign result sign bit
		}
	}

	if (input1.signBit[0] == input2.signBit[0])					// Both positive or negative values
	{
		for (int i = mantInd; i >= 1; i--)
		{
			if (shift == 0)										// Both exponent arrays have the same decimal value, therefore both arrays are aligned. 
			{
				temp[i] = temp[i - 1];							// Add 0 to the beginning of temp array
				temp1[i] = temp1[i - 1];						// Add 0 to the beginning of temp1 array
				if (i == 1)
				{
					temp[0] = '1';								// Add 1 to the beginning of temp array for future calculation
					temp1[0] = '1';								// Add 1 to the beginning of temp1 array for future calculation
				}

			}
			else if (shift != 0)								// Both exponent arrays do not have the same decimal value, therefore, one of the arrays are already shifted and aligned
			{
				temp[i] = temp[i - 1];
				temp1[i] = temp1[i - 1];
				if (i == 1)
				{
					temp[0] = '0';								// Add 0 to the beginning of temp array for future calculation, this array is already shifted with 1 earlier.
					temp1[0] = '1';								// Add 1 to the beginning of temp1 array for future calculation.
				}

			}
		}

		for (int i = mantInd; i >= 0; i--)
		{
			FA_1Bit(temp[i], temp1[i], cin, coPtr, mant + i);	// Perform mantissa addition with shifted and aligned temp exponent arrays, and store in mant array
			cin = *coPtr;
			*coPtr = '0';
		}
		 
		if (cin == '1')											// Overflow after MSB addition in mantissa array
		{
			
			for (int i = expInd; i >= 0; i--)					// Add 1 to result exponent array for overflow from mantissa array addition
			{
				FA_1Bit(exp[i], '0', cin, coPtr, exp + i);
				cin = *coPtr;
				*coPtr = '0';
			}
		}
		else if (cin == '0')									// No overflow after MSB addition in mantissa array
		{
			shift = 0;											// Reset shift value for following use
			for (int i = 0; i <= mantInd; i++)					// Sweep for the first 1 from left to right in mantissa array to determine the number of position needed to left shift. 
			{
				if (mant[i] == '1')
				{
					shift = i;
					break;
				}
			}
			arrLeftShift(bitSize, shift+1, mant);
			for (int i = shift; i > 0; i--)						// Add 'shift' amount to result exponent array
			{
				FA_1Bit(exp[i], '0', '1', coPtr, exp + i);
				*coPtr = '0';
			}
		}

	}
	else if (input1.signBit[0] != input2.signBit[0])			// One positive and one negative values
	{
		for (int i = mantInd; i >= 0; i--)
		{
			if (i == 1)											
			{
				temp1[i] = '1';									// Add 1 to second index of temp1 mantissa array
				if (shift == 0)
				{
					temp[i] = '1';								// Add 1 to second index of temp mantissa array if there is no alignment required
				}
				else
				{
					temp[i] = '0';								// Add 0 to second index of temp mantissa array if there is alignment 
				}
			}
			else if (i == 0)
			{
				temp[i] = '0';									// Add 0 to first index of temp mantissa array
				temp1[i] = '0';									// Add 0 to first index of temp1 mantissa array
			}
			else
			{
				temp[i] = temp[i - 2];							// Left shift temp mantissa array 2 positions
				temp1[i] = temp1[i - 2];						// Left shift temp1 mantissa array 2 positions
			}
		}

		switch (mantComparator(bitSize, temp, temp1))			// Compare aligned temp and temp1 mantissa arrays
		{
		case 1:
			invert(bitSize, temp1);								// Convert temp1 mantissa array into 2's Compliment if return 1
			break;
		case -1:
			invert(bitSize, temp);								// Convert temp mantissa array into 2's Compliment if return -1
			break;
		}

		cin = '0';												// Reset carry in value
		for (int i = mantInd; i >= 0; i--)						// Add shifted, inverted input mantissa arrays and store in mant array
		{
			FA_1Bit(temp[i], temp1[i], cin, coPtr, mant + i);
			cin = *coPtr;
			*coPtr = '0';
		}

		shift = 0;												// Reset shift value
		for (int i = 0; i <= mantInd; i++)						// Sweep result mantissa array for the first '1' from left to right and determine the number of position to be shifted.
		{
			if (mant[i] == '1')
			{
				shift = i - 1;
				break;
			}
		}

		if (shift < 0)											// NEGATIVE shift value indicates right shift of the result mantissa array required.
		{
			cin = '0';
			arrRightShift(bitSize, 0 - shift, mant);			// Right shift result mantissa array 'shift' positions
			for (int i = expInd; i >= 0; i++)
			{
				if (0 - shift != 0)
				{
					FA_1Bit(exp[i], '0', cin, coPtr, exp + i);	// Add 'shift' value to result exponent array
					cin = *coPtr;
					*coPtr = '0';
					shift++;
				}
			}
		}
		else if (shift > 0)										// POSITIVE shift value indicates left shift of the result mantissa array required.
		{
			arrLeftShift(bitSize, shift + 2, mant);				// Left shift result mantissa array 'shift' + 2 positions to adjust added 0 and 1 in the beginning of mantissa array earlier
			
			
			for (int i = 0; i <= expInd; i++)					// Adjust result exponent array
			{
				if (exp[i] == '1')
				{
					tempVal += pow(2, expInd - i);
				}
			}
			tempVal -= shift;
			tempPtr = toBinary(tempVal);
			for (int i = expInd; i >= 0; i--)
			{
				exp[i] = *(tempPtr + expInd - i);
			}
		}
	}
}
//	Function to compare 2 input exponent arrays, return value can be positive or negative.
//	POSITIVE return values indicates exp1 array has LARGER decimal value than exp2 array.
//	NEGATIVE return values indicates exp1 array has SMALLER decimal value than exp2 array.
int expComparator(int bitSize, char exp1[11], char exp2[11])
{
	int shift = 0;					// Stores the number of shifts needed to align the smaller exponent array to the larger exponent array
	int expInd;						// Index for exponent arrays
	int input1Val = 0;				// Stores decimal value of exp1 array, initialized to 0
	int input2Val = 0;				// Stores decimal value of exp2 array, initialized to 0
	switch (bitSize)
	{
	case 16:						// 16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		break;
	case 32:						// 32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		break;
	case 64:						// 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= expInd; i++)			//Converts exponent arrays into decimal values
	{
		if (exp1[i] == '1')
		{
			input1Val += pow(2, expInd - i);
		}
		if (exp2[i] == '1')
		{
			input2Val += pow(2, expInd - i);
		}
	}
	shift = input1Val - input2Val;
	return shift;
}
//	Function to compare 2 input mantissa arrays, returns -1, 1, or 0
//	Return value 1 indicates mant1 array has LARGER decimal value than mant2 array.
//	Return value -1 indicates mant1 array has SMALLER decimal value than mant2 array.
//	 Return value 0 indicates mant1 array has the SAME decimal value as mant2 array.
int mantComparator(int bitSize, char mant1[52], char mant2[52])
{
	int mantInd;					// Index for exponent arrays
	switch (bitSize)
	{
	case 16:						// 16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		mantInd = 9;
		break;
	case 32:						// 32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		mantInd = 22;
		break;
	case 64:						// 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= mantInd; i++)
	{
		if (mant1[i] == '0' && mant1[i] != mant2[i])
		{
			return -1;
		}
		else if (mant1[i] == '1' && mant1[i] != mant2[i])
		{
			return 1;
		}
	}

	return 0;
}
//	Right shifts input array 'index' amount of position
void arrRightShift(int bitSize, int index, char arr[52])
{
	int expInd;
	int mantInd;

	switch (bitSize)
	{
	case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = mantInd + index; i >= 0; i--)
	{
		if (i >= index)
		{
			arr[i] = arr[i - index];
		}
		else if (i == index - 1)
		{
			arr[i] = '1';
		}
		else
		{
			arr[i] = '0';
		}
	}
}
//	Left shifts input array 'index' amount of position
void arrLeftShift(int bitSize, int index, char arr[52])
{
	int expInd;
	int mantInd;

	switch (bitSize)
	{
	case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= mantInd; i++)
	{
		if (i > mantInd - index)
		{
			arr[i] = '0';
		}
		else
		{
			arr[i] = arr[i + index];
		}
	}
}
void invert(int bitSize, char arr[52])
{
	char cout = '0';
	char cin = '1';
	char *coPtr = &cout;
	int expInd;
	int mantInd;

	switch (bitSize)
	{
	case 16:						//16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= mantInd; i++)
	{
		switch (arr[i])
		{
		case '1':
			arr[i] = '0';
			break;
		case '0':
			arr[i] = '1';
			break;
		}
	}
	
	for (int i = mantInd; i >= 0; i--)
	{
		FA_1Bit(arr[i], '0', cin, coPtr, arr + i);
		cin = *coPtr;
		*coPtr = '0';
	}
}
/*********************************************************Pipelining Functions Definition*******************************************************/
void stage1(int bitSize, FP_value input1, FP_value input2, char signBit1output[1], char signBit2output[1], char exp1output[11], char exp2output[11], char mant1output[52], char mant2output[52])
{
	int shift = 0;					//	Position to be shifted
	int expInd;						//	Exponent index
	int mantInd;					//	Mantissa index

	switch (bitSize)
	{
	case 16:						//	16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//	32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//	 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= expInd; i++)						//	Pass input 1 and 2 exponent to output exponent array registers
	{
		exp1output[i] = input1.exp[i];
		exp2output[i] = input2.exp[i];
	}

	for (int i = 0; i <= expInd; i++)						//	Checks if input 1 is 0 by checking all its exponent bits
	{
		if (input1.exp[i] == '1')
		{
			break;
		}
		else if (i == expInd && input1.exp[i] == '0')		//	If exponent is 0, pass input 1 and 2 sign bits to output sign bit registers
		{
			signBit1output[0] = input1.signBit[0];
			signBit2output[0] = input2.signBit[0];
			for (int j = 0; j <= mantInd; j++)				//	Pass input 1 and 2 mantissa arrays to output mantissa array registers
			{
				mant1output[j] = input1.mant[j];
				mant2output[j] = input2.mant[j];
			}

			arrRightShift(bitSize, 2, mant1output);			//	Right shifts mantissa 1 
			arrRightShift(bitSize, 2, mant2output);
			mant1output[1] = '0';

			int val1 = 0;
			int val2 = 0;

			/***Checks if input 2 exponent is also 0*/
			for (int j = 0; j <= expInd; j++)
			{
				if (input1.exp[j] == '1')
				{
					val1 = pow(2, expInd - j);
				}
				if (input2.exp[j] == '1')
				{
					val2 = pow(2, expInd - j);
				}
			}

			if (val1 == val2)
			{
				mant2output[1] = '0';
			}

			return;

		}
	}

	// Check to see if the second input exponent array is 0
	for (int i = 0; i <= expInd; i++)						//	Checks if input 2 is 0 by checking all its exponent bits
	{
		if (input2.exp[i] == '1')
		{
			break;
		}
		else if (i == expInd && input2.exp[i] == '0')
		{
			signBit1output[0] = input1.signBit[0];
			signBit2output[0] = input2.signBit[0];
			for (int j = 0; j < mantInd; j++)
			{
				mant1output[j] = input1.mant[j];
				mant2output[j] = input2.mant[j];
			}
			arrRightShift(bitSize, 2, mant1output);
			arrRightShift(bitSize, 2, mant2output);
			mant2output[1] = '0';
			return;
		}
	}

	shift = expComparator(bitSize, input1.exp, input2.exp);		//	Compare input 1 and 2 exponents in binary to determine the number of shifts needed for smaller mantissa 
	if (shift > 0)												//	POSITIVE shift value
	{
		for (int i = 0; i <= mantInd; i++)
		{
			mant2output[i] = input2.mant[i];					//	Stores both input mantissa to output mantissa registers
			mant1output[i] = input1.mant[i];
		}

		arrRightShift(bitSize, shift + 2, mant2output);			//	Right shifts mant 2 array
		arrRightShift(bitSize, 2, mant1output);					//	Right shifts mant 1 array 
	}
	else if (shift < 0)											//	NEGATIVE shift value
	{
		for (int i = 0; i <= mantInd; i++)
		{	
			mant1output[i] = input1.mant[i];					//	Stores both input mantissa to output mantissa registers
			mant2output[i] = input2.mant[i];
		}

		arrRightShift(bitSize, 0 - (shift - 2), mant1output);	//	Right shifts mant 1 array
		arrRightShift(bitSize, 2, mant2output);
	}
	else														//	shift == 0, meaning both exponent arrays are equal in value								
	{
		for (int i = 0; i < 52; i++)
		{
			mant1output[i] = input1.mant[i];					//	Stores both input mantissa to output mantissa registers
			mant2output[i] = input2.mant[i];
		}
		arrRightShift(bitSize, 2, mant1output);					//	Right shifts both mantissa arrays
		arrRightShift(bitSize, 2, mant2output);
	}

	signBit1output[0] = input1.signBit[0];						//	Stores both input sign bits to output sign bit registers
	signBit2output[0] = input2.signBit[0];

	for (int i = 0; i <= expInd; i++)
	{
		exp1output[i] = input1.exp[i];							//	Stores both input exponent array into output exponent registers
		exp2output[i] = input2.exp[i];
	}
}
void stage2(int bitSize, char signBit1Input[1], char signBit2Input[1], char exp1Input[11], char exp2Input[11], char mant1Input[52], char mant2Input[52], char exp1output[11], char exp2output[11], char Finalmantoutput[52], char FinalsignBitoutput[1])
{
	int shift = 0;					// Position to be shifted
	char cin = '0';					// Carry in for mantissa addition using 1 bit full adder
	char cout = '0';				// Carry out for mantissa addition using 1 bit full adder
	char *coPtr = &cout;			// Address of Carry out for mantissa ddition using 1 bit full adder
	int expInd;						// Exponent index
	int mantInd;					// Mantissa index

	switch (bitSize)
	{
	case 16:						// 16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						// 32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						// 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	shift = expComparator(bitSize, exp1Input, exp2Input);	//	Compare input 1 and 2 exponents in binary to determine the number of shifts needed for smaller mantissa 

	if (shift < 0)
	{
		FinalsignBitoutput[0] = signBit2Input[0];			//	Stores input 2 sign bit into final sign bit output register
	}
	else
	{
		FinalsignBitoutput[0] = signBit1Input[0];			//	Stores input 1 sign bit into final sign bit output register
	}
	
	
	for (int i = 0; i <= expInd; i++)
	{
		exp1output[i] = exp1Input[i];						//	Stores input 1 and 2 exponent array into exponent output registers
		exp2output[i] = exp2Input[i];
	}
	

	for (int i = 0; i <= expInd; i++)						//	Checks if input 1 is 0 by checking all its exponent bits
	{
		if (exp1Input[i] == '1')
		{
			break;
		}
		else if (i == expInd && exp1Input[i] == '0')
		{
			for (int j = 0; j <= mantInd; j++)
			{
				Finalmantoutput[j] = mant2Input[j];			//	Stores input 2 mantissa into mantissa output register
			}
		}
	}

	// Check to see if the second input exponent array is 0
	for (int i = 0; i <= expInd; i++)						//	Checks if input 2 is 0 by checking all its exponent bits
	{
		if (exp2Input[i] == '1')
		{
			break;
		}
		else if (i == expInd && exp2Input[i] == '0')
		{
			for (int j = 0; j <= mantInd; j++)
			{
				Finalmantoutput[j] = mant1Input[j];			//	Stores input 1 mantissa into mantissa output register
			}
			return;
		}
	}

	//printf("%c, %c", signBit1Input[0], signBit2Input[0]);

	if(signBit1Input[0] != signBit2Input[0])
	{
		switch (mantComparator(bitSize, mant1Input, mant2Input))		//	Compare aligned temp and temp1 mantissa arrays
		{
		case 1:
			invert(bitSize, mant2Input);								//	Invert input 2 mantissa array if return 1

			break;
		default:
			invert(bitSize, mant1Input);								//	Invert input 1 mantissa array if return -1 or 0
			break;
		}
	}

	for (int i = mantInd; i >= 0; i--)
	{
		FA_1Bit(mant1Input[i], mant2Input[i], cin, coPtr, Finalmantoutput + i);		//	Add both input mantissa and store in mantissa output register
		cin = *coPtr;
		*coPtr = '0';
	}
}
void stage3(int bitSize, char exp1Input[11], char exp2Input[11], char FinalmantInput[52], char Finalexpoutput[11], char Finalmantoutput[52], int *normShiftoutputPtr) 
{
	int shift = 0;					//	Position to be shifted
	int expInd;						//	Exponent index
	int mantInd;					//	Mantissa index

	switch (bitSize)
	{
	case 16:						//	16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						//	32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						//	64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	for (int i = 0; i <= mantInd; i++)
	{
		if (FinalmantInput[i] == '1')
		{
			*normShiftoutputPtr = i + 1;		//	Determine the number of shifts needed to normalize mantissa sum
			break;
		}
	}

	for (int i = 0; i <= expInd; i++)						//	Checks if input 1 is 0 by checking all its exponent bits
	{
		if (exp1Input[i] == '1')
		{
			break;
		}
		else if (i == expInd && exp1Input[i] == '0')
		{
			for (int j = 0; j <= expInd; j++)
			{
				Finalexpoutput[j] = exp2Input[j];			//	Stores input 2 exopnent array into exponent output register
			}
			for (int j = 0; j <= mantInd; j++)
			{
				Finalmantoutput[j] = FinalmantInput[j];		//	stores input sum mantissa array into mantissa output register
			}
			return; 
		}
	}

	// Check to see if the second input exponent array is 0
	for (int i = 0; i <= expInd; i++)						//	Checks if input 2 is 0 by checking all its exponent bits
	{
		if (exp2Input[i] == '1')
		{
			break;
		}
		else if (i == expInd && exp2Input[i] == '0')
		{
			for (int j = 0; j <= expInd; j++)
			{
				Finalexpoutput[j] = exp2Input[j];			//	Stores input 2 exponent array into exponent output register
			}
			for (int j = 0; j <= mantInd; j++)
			{
				Finalmantoutput[j] = FinalmantInput[j];		//	Stores input sum mantissa into mantissa output register
			}
			return;
		}
	}

	shift = expComparator(bitSize, exp1Input, exp2Input);	//	Compare input 1 and 2 exponents in binary to determine the number of shifts needed for smaller mantissa 

	if (shift < 0)
	{
		for (int i = 0; i <= expInd; i++)
		{
			Finalexpoutput[i] = exp2Input[i];				//	Stores input 2 exponent array into exponent output register 
		}
	}
	else
	{
		for (int i = 0; i <= expInd; i++)
		{
			Finalexpoutput[i] = exp1Input[i];				//	Stores input 1 exponent array into exponent output register
		}
	}

	for (int i = 0; i <= mantInd; i++)
	{
		Finalmantoutput[i] = FinalmantInput[i];				//	Stores input sum mantissa into mantissa output register
	}
}
void stage4(int bitSize, char FinalexpInput[11], char FinalmantInput[52], int *normShiftPtrinput, char Finalexpoutput[11], char Finalmantoutput[52])
{
	int shift = 0;					// Position to be shifted
	char cin = '0';					// Carry in for mantissa addition using 1 bit full adder
	char cout = '0';				// Carry out for mantissa addition using 1 bit full adder
	char *coPtr = &cout;			// Address of Carry out for mantissa ddition using 1 bit full adder
	char *tempPtr;					// Pointer to temperory arrays
	int tempVal = 0;				// Temporary value holder
	int expInd;						// Exponent index
	int mantInd;					// Mantissa index

	switch (bitSize)
	{
	case 16:						// 16-bit FP: 1 sign bit, 5 exponent bits, 10 mantissa bits
		expInd = 4;
		mantInd = 9;
		break;
	case 32:						// 32-bit FP: 1 sign bit, 8 exponent bits, 23 mantissa bits
		expInd = 7;
		mantInd = 22;
		break;
	case 64:						// 64-bit FP: 1 sign bit, 11 exponent bits, 52 mantissa bits
		expInd = 10;
		mantInd = 51;
		break;
	default:
		printf("error");
		break;
	}

	if (indexx76 >= 3 && indexx76 <= 11)
	{
		arrLeftShift(bitSize, *normShiftPtrinput, FinalmantInput);		//	Normalize input sum mantissa 
		for (int k = 0; k <= mantInd; k++)
		{
			Finalmantoutput[k] = FinalmantInput[k];						//	Store input sum mantissa into mantissa output register
		}

		for (int i = 0; i <= expInd; i++)
		{
			Finalexpoutput[i] = FinalexpInput[i];						//	Store input exponent into exponent output register
		}

		if (2 - *normShiftPtrinput > 0)									//	Adjust exponent array
		{
			for (int i = 0; i < 2 - *normShiftPtrinput; i++)
			{
				cin = '1';
				for (int j = expInd; j >= 0; j--)
				{
					FA_1Bit(FinalexpInput[j], '0', cin, coPtr, Finalexpoutput + j);		
					cin = *coPtr;
					*coPtr = '0';
				}
			}
		}
		else if (2 - *normShiftPtrinput < 0)							//	Adjust result exponent array
		{
			for (int i = 0; i <= expInd; i++)
			{
				if (FinalexpInput[i] == '1')
				{
					tempVal += pow(2, expInd - i);
				}
			}
			tempVal = tempVal - (*normShiftPtrinput - 2);
			tempPtr = toBinary(tempVal);
			for (int i = expInd; i >= 0; i--)
			{
				Finalexpoutput[i] = *(tempPtr + expInd - i);
			}
		}
	}
}
