#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toLowerCase(char* str) {
	char* lower = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (lower == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	
	char l;
	int i = 0;
	for (i; i < strlen(str); ++i) {
		if (isupper(str[i])) {
			l = tolower(str[i]);
		} else {
			l = str[i];
		}
		lower[i] = l;
	}
	lower[i] = '\0';
	return lower;
}

int main()
{
	char* lower = toLowerCase("The quick brown fox jumps over the lazy dog.");
	printf("%s\n", lower);
	free(lower);
}
	
