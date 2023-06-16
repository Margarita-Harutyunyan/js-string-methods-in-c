#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int endsWith(char* str, char* end) {
	int ends = 1;
	int lenStr = strlen(str);
	int lenEnd = strlen(end);
	int start = lenStr - lenEnd;
	for (int i = 0; i < lenEnd; ++i) {
		if (end[i] != str[start]) {
			ends = 0;
			break;
		}
		++start;
	}

	return ends;
}


int main()
{
	if (endsWith("Cats are the best!", "best!")) {
			printf("True\n");
	} else {
		printf("False\n");
	}
}
