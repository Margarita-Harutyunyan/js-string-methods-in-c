#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int includes(char* str, char* substr) {
	int start = 0;
	int includes = 0;

	while (start < strlen(str)) {
		if (str[start] == substr[0]) {
			includes = 1;
			for (int i = 0; i < strlen(substr); ++i) {
				if (str[start + i] != substr[i]) {
					includes = 0;
					break;
				}
			}
			if (includes) {
				return includes;
			}
		}
		++start;
	}
	return includes;
}
	

int main()
{
	if (includes("The quick brown fox jumps over the lazy dog.", "fox")) {
		printf("True\n");
	} else {
		printf("False\n");
	}
}
