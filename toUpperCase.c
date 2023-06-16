#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toUpperCase(char* str) {
	char* upper = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (upper == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	
	char u;
	int i = 0;
	for (i; i < strlen(str); ++i) {
		if (islower(str[i])) {
			u = toupper(str[i]);
		} else {
			u = str[i];
		}
		upper[i] = u;
	}
	upper[i] = '\0';
	return upper;
}

int main()
{
	char* upper = toUpperCase("The quick brown fox jumps over the lazy dog.");
	printf("%s\n", upper);
	free(upper);
}
	
