#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trimEnd(char* str) {
	int index = strlen(str) - 1;
	while (str[index] == ' ') {
		--index;
	}
	
	char* res = (char*)malloc((index + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to trim\n");
		return NULL;
	}
	strncpy(res, str, index);
	return res;
}

int main() {
	char* trimmed = trimEnd("   Hello world!   ");
	printf("%s\n", trimmed);
	free(trimmed);
}
