#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trimStart(char* str) {
	int index = 0;
	while (str[index] == ' ') {
		++index;
	}
	
	int len = strlen(str) - index;
	char* res = (char*)malloc((len + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to trim\n");
		return NULL;
	}
	
	int i = 0;
	for (i; i < len; ++i) {
		res[i] = str[index + i];
	}
	res[i] = '\0';
	return res;
}

int main() {
	char* trimmed = trimStart("   Hello world!   ");
	printf("%s\n", trimmed);
	free(trimmed);
}

