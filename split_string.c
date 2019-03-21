#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
	char** split_str = malloc(sizeof(char)*(dims^2));
	//set up variables for looping	
	int x,y = 0;
	char* start = in_str;
	// Loop through x and y axes of square assigning string values
	// and discarding EOL
	while (y < dims)
	{
		// re-zero x val
		x = 0;
		while (x < dims)
		{
			if (*in_str != 10)
			{
				// Corrected, split_str is now char**
				split_str[y][x] = *in_str;
			}
			x++;
			in_str++;
		}
		y++;
	}
free(split_str);
}
