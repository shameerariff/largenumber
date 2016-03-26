//This code can be compiled using gcc compiler and the command is 
// gcc sampletest.c largeinteger.c -o sampletest
#include <stdio.h>
#include "largeinteger.h"

//User Program Example
int main()
{
	//Get input from the User
	printf("Insert a large number");
	Scan_Number("a");
	printf("Insert another large number");
	Scan_Number("b");
	printf("\n A is ");
	Print_Number("a");
	printf("\n B is ");
	Print_Number("b");
	Copy_Number("c","a");
	Copy_Number("a","b");
	Copy_Number("b","c");
	printf("The value of A and B are swapped\n A is ");
	Print_Number("a");
	printf("\n B is ");
	Print_Number("b");
	int logical=Logical_opp("a","b");
	if(logical == 1)
		puts("A is greater");
	else if (logical == -1)
		puts("B is greater");
	else if(logical == 0)
		puts("A and B are equal");
	else
		puts("Invalid");
	printf("\n");
	return 0;
}
