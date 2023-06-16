#include <stdio.h>

int main()
{
	char str[2];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[1] = '\0';
	printf("%s\n", str);
}
