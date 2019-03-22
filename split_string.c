#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



char* vert_tran(char *square);
char* hor_tran(char *square);

int print_ar_m(char** mult_ar, int dims);
char** split_ar(char* in_str);
char* rejoin_str(char** in_ar, int dims);
int calc_dims(char* str);

int main(void)
{
	//dummy inputs
	char* str = "abc\ndef\nghi";
	//char* str = "abcd\nefgh\nijkl\nmnop";
	
	// before
	printf("%s\n\n", str);
	
	str = vert_tran(str);
	// after
	printf("%s\n", str);
}




// function performing transformation of an array of chars with vertical symmetry
char* vert_tran(char* str){
	
	// split string, return malloc'd char**
	char** square = split_ar(str);
	// calc dimensions of square
	int dims = calc_dims(str);
	// malloc temp memory for each row 
	char* row_temp = malloc(sizeof(char)*dims);
	int i, j=0;
	// loop through each row and mirror and then reassign back to row
	while(j < dims)
	{
	for (i = 0; i<dims; i++) row_temp[i] = square[j][dims-i-1];
	for (i = 0; i<dims; i++) square[j][i] = row_temp[i];
	j++;
	}
	// reform string(char*) from char**
	str = rejoin_str(square, dims);
	
	// clear allocated memory
	for (int i = 0; i<dims; i++) free(square[i]);
	free(square);
	free(row_temp);
	// return value
	return str;
	
}

char* hor_tran(char *str)
{
	// rest of function is identical to vert_tran however it mirrors the columns first
	char** square = split_ar(str);
	int dims = calc_dims(str);
	char* col_temp = malloc(sizeof(char)*dims);
	int i, j=0;
	
	while(j < dims)
	{
	for (i = 0; i<dims; i++) col_temp[i] = square[dims-i-1][j];
	for (i = 0; i<dims; i++) square[i][j] = col_temp[i];
	j++;
	}
	str = rejoin_str(square, dims);
	for (int i = 0; i<dims; i++) free(square[i]);
	free(square);
	free(col_temp);
	
	return str;
}



char* rejoin_str(char** in_ar, int dims)
{
char* start = malloc((sizeof(char)*dims*dims)+dims-1);
int y,x, count = 0;

	for (y = 0; y < dims; y++)
	{
		for (x = 0; x < dims; x++) 
		{
		start[count] = in_ar[y][x];
		//printf("%c", in_ar[y][x]);
		//printf("%i\n", count);
		count++;
		}
		start[count++] = '\n';
	}
	
	return start;
}


int calc_dims(char* str){
	return sqrt((double)strlen(str) - (double)floor((double)sqrt((double)strlen(str))-1));
}	
	

char** split_ar(char* in_str)
{
	// Get input string length
	double length = strlen(in_str);
	// Calculate number of EOL chars(\n) in string
	double spaces = floor(sqrt(length)-1);
	// Calculate dimensions of square of chars
	int dims = sqrt(length - spaces);
	// Allocate memory for square of chars
	// this must be array of arrays or pointer to pointers
	char** split_str = malloc(sizeof(char*) * dims);
	for (int i = 0; i<dims; i++)
	{
		split_str[i] = malloc(sizeof(char) * dims);
	}
	//set up variables for looping	
	int x = 0;
	int y = 0;
	// Loop through x and y axes of square assigning string values
	// and discarding EOL
	while (y < dims)
	{
		// re-zero x val
		while (x < dims)
		{
			// check whether the current in_str(source) value is LF char.  if so ignore and increment source
			if (*in_str != 10)
			{
				// if not LF char then assign to correct part of split_str array and increment counters
				//split_str[y][x] = *in_str; // segfault y = 3 x = 0 dims = 4
				split_str[y][x] = *in_str;
				x++;
				in_str++;
				
			} else {in_str++;}
			
		}
		// re-zero x counter and increment y
		x = 0;
		y++;
	}
	return split_str;
	
}

// function looping through multidimensional square array mult_ar of size dims 
// prints the values in a grid
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
		x = 0;
		y++;
	}
	return 0;
}
