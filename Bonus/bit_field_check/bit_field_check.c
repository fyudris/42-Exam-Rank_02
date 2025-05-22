#include <unistd.h>
#include <stdlib.h>

// Write string to stdout
void put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// Check if a given bit is set in a number
int main(int ac, char **av)
{
	if (ac == 3)
	{
		int num = atoi(av[1]);         // Convert first argument to integer
		int bit = atoi(av[2]);         // Convert second argument to integer

		if (bit >= 0 && bit < 32)      // Ensure bit position is valid (optional: 0 to 31)
		{
			/*
			Create a mask with 1 at the bit position:
			    (1 << bit) → shifts the bit left by 'bit' positions

			Then AND with the number:
			    If result is non-zero, that bit is set.
			*/
			if (num & (1 << bit))
				put_str("ON\n");
			else
				put_str("OFF\n");
			return (0);
		}
	}
	// Invalid input
	write(1, "\n", 1);
	return (0);
}
