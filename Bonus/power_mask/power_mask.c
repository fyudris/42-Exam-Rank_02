#include <unistd.h>
#include <stdlib.h>

// Simple function to print a string using write()
void put_str(char *str)
{
	while (*str)
		write(1, str++, 1);  // Write each character one by one
}

int main(int ac, char **av)
{
	// Check if exactly one argument is passed
	if (ac == 2)
	{
		// Convert the argument string to an integer
		int n = atoi(av[1]);

		/*
		Bitwise trick:
		To check if a number is a power of two:

		- A power of 2 has only ONE bit set in binary.
		  For example:
		    1  -> 00000001
		    2  -> 00000010
		    4  -> 00000100
		    8  -> 00001000

		- n & (n - 1) clears the lowest set bit of n.
		  So if there's only one set bit, the result is 0.

		Example:
		    n = 8  (1000)
		  n-1 = 7  (0111)
		  n & (n-1) = 0000 → Power of 2 ✅

		  n = 5  (0101)
		n-1 = 4  (0100)
		n & (n-1) = 0100 → Not zero ❌

		We also check that n > 0, because 0 & -1 is 0, but 0 is NOT a power of two.
		*/
		if (n > 0 && (n & (n - 1)) == 0)
			put_str("YES\n");
		else
			put_str("NO\n");
	}
	else
	{
		// If no argument or too many, just print a newline
		write(1, "\n", 1);
	}

	return (0);
}
