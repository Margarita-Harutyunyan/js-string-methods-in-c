#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim(char* str) {
	int start = 0;
	int end = strlen(str) - 1;

	while (str[start] == ' ') {
		++start;
	}
	while (str[end] == ' ') {
		--end;
	}

	int len = end - start;
	char* res = (char*)malloc((len + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	int i = 0;
	for(i; i < len; ++i) {
		res[i] = str[start + i];
	}
	res[i] = '\0';
	return res;
}

int main()
{
	char* trimmed = trim("   Hello world!   ");
	printf("%s\n", trimmed);
	free(trimmed);
}

