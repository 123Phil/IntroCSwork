// ============================================================================
// File: HW15/catfiles.c
// ============================================================================
// Programmer: Phillip Stewart
// Date: 18 Apr 2012
// Class: CSCI 223 ("C Programming")
// Time: TR 4-6
// Instructor: Mr. Edwards
// Project: CatFiles
// Description: Uses command line arguements to concatenate files and write
//				them to a new destination file.
// ============================================================================



#include <stdlib.h>
#include <stdio.h>



// ==== Main ==================================================================
// ============================================================================
int main(int argc, char** argv)
{
	if (argc < 3)
		{
		puts("Usage: ./catfiles <dest.txt> <src1.txt> <src2.txt> <...>");
		exit(EXIT_SUCCESS);
		}
	else
		{
		auto FILE* destFile;
		auto FILE* srcFile;
		auto int kittyCat;
		auto int ctr;
		
		destFile = fopen(argv[1], "w");
		if (NULL == destFile)
			{
			puts("Failed to open destination file.");
			exit(EXIT_FAILURE);
			}
		
		for (ctr = 1; ctr < argc; ctr++)
			{
			srcFile = fopen(argv[ctr], "r");
			if (NULL == srcFile)
				{
				printf("Failed to open source file: %s\n", argv[ctr]);
				exit(EXIT_FAILURE);
				}
			
			while (EOF != (kittyCat = fgetc(srcFile)))
				fputc(kittyCat, destFile);
			
			fclose(srcFile);
			}
		fclose(destFile);
		}
	return 0;
}

