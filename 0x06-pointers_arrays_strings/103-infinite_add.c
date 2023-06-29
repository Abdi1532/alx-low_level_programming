#include <stdio.h>
#include <string.h>

/**
 * infinite_add - Adds two numbers represented as strings.
 * @n1: First number as a string.
 * @n2: Second number as a string.
 * @r: Buffer to store the result.
 * @size_r: Size of the result buffer.
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored in @r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int carry = 0;
	int sum = 0;
	int max_len = (len1 > len2) ? len1 : len2;
	int i = max_len - 1;

	if (max_len + 1 > size_r)
		return 0;

	r[size_r - 1] = '\0';

	while (i >= 0)
	{
		int digit1 = (i >= len1) ? 0 : (n1[i] - '0');
		int digit2 = (i >= len2) ? 0 : (n2[i] - '0');

		sum = carry + digit1 + digit2;
		carry = sum / 10;
		sum = sum % 10;

		r[i] = sum + '0';
		i--;
	}

	if (carry == 1)
	{
		if (size_r == max_len)
			return 0;

		memmove(r + 1, r, size_r - 1);
		r[0] = '1';
		return r;
	}

	return r;
}
