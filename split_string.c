#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int print_ar_m(char** mult_ar, int dims);

int main(void)
{
	//dummy input
	char* in_str = "abc\ndef\nghi";
	 
	// Get input string length
	double length = strlen(in_str);
	// Calculate number of EOL chars(\n) in string
	double spaces = floor(sqrt(length)-1);
	// Calculate dimensions of square of chars
	int dims = sqrt(length - spaces);
	// Allocate memory for square of chars
	// this must be array of arrays or pointer to pointers
	char** split_str = malloc(sizeof(char)*(dims^2));
	//set up variables for looping	
	int x = 0;
	int y = 0;
	char* start = in_str;
	printf("dim : %i\n",dims);
	// Loop through x and y axes of square assigning string values
	// and discarding EOL
	while (y < dims)
	{
		// re-zero x val
		while (x < dims)
		{
			
			if (*in_str != 10)
			{
				// Corrected, split_str is now char**
				split_str[y][x] = *in_str;
				x++;
				in_str++;
				
			} else {in_str++;}
			
		}
		x = 0;
		y++;
	}
	
	print_ar_m(split_str,dims);	


free(split_str);
}


int print_ar_m(char** mult_ar, int dims)
{
	int y = 0,x = 0;
	while (y < dims)
	{
		while (x < dims)
		{
			printf("%c",mult_ar[y][x]);
			x++;
		}
		printf("\n");
		// re-zero x val
		x = 0;
		y++;
	}
	return 0;
}
