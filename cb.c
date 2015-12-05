// ============================================================================
// File: HW12/cb.c
// ============================================================================
// Programmer: Phillip Stewart
// Date: 20 MAR 2012
// Class: CSCI 223 ("C Programming")
// Time: TR 4-6
// Instructor: Mr. Edwards
// Project: Convert Base
// Description: Converts a command line arguement from base 10 to hex for 
//				non-h intergers, and converts hex into base 10.
// ============================================================================



#include <stdio.h>
#include <string.h>



// == Main ====================================================================
int main(int argc, char** argv)
{
	if (1 == argc) puts("Usage: cb <number>[h]");
	else if (2 == argc)
		{
		auto int tint;
		auto char* poot;
		auto char suffix = 0;
		if (NULL != (poot = strchr(argv[1], 'h')))
			{//if there's an h, make it 0 and scan for hex value
			*poot = 0;
			if (1 == sscanf(argv[1], "%x", &tint)) printf("%d\n", tint);
			else puts("Invalid input...");
			}
		//if no h, scan int, check for format
		else if (1 == sscanf(argv[1], "%d%c", &tint, &suffix)) 
				printf("%Xh\n", tint);
		else puts("Invalid input...");
		}
	else puts("Invalid input...");
	return 0;
}//end of main


