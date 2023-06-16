#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int startsWith(char* string, char* searchString, int position) {
	int starts = 1;
	for (int i = 0; i < strlen(searchString); ++i) {
		if (string[position + i] != searchString[i]) {
			starts = 0;
			break;
		}
	}
	return starts;
}

int main()
{
	if (startsWith("Saturday night plans", "Sat", 0)) {
		printf("True\n");
	} else {
		printf("False\n");
	}
}
