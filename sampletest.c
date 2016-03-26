//This code can be compiled using gcc compiler and the command is 
// gcc sampletest.c largeinteger.c -o sampletest
make: *** No targets specified and no makefile found.  Stop.
#include <stdio.h>
#include "largeinteger.h"

//User Program Example
int main()
{
	Scan_Array("a",1);
	Scan_Number("b");
	printf("\n A is ");
	Print_Array("a",1);
	printf("\n B is ");
	Print_Number("b");
	Copy_toNumber("c","a",1);
	Copy_toArray("a",1,"b");
	Copy_Number("b","c");
	printf("\n A is ");
	Print_Array("a",1);
	printf("\n B is ");
	Print_Number("b");
	int logical=Logical_opp_Array_Number("a",1,"b");
	if(logical == 1)
		puts("\nA is greater");
	else if (logical == -1)
		puts("\nB is greater");
	else if(logical == 0)
		puts("\nA and B are equal");
	else
		puts("Invalid");
	printf("\n");
	return 0;
}
