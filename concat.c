#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char** strings, int size) {
	char* str;
	int len = 1;
	for (int i = 0; i < size; ++i) {
		len += strlen(strings[i]);
	}

	str = (char*)malloc(len);
	if (str == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	for(int j = 0; j < size; ++j) {
		strcat(str, strings[j]);
	}
	return str;
}

int main()
{
	char* strings[] = {
		"Hello",
		",",
		" ",
		"World",
		"!",
	};

	char* hello = concat(strings, 5);
	printf("%s\n", hello);
	free(hello);
}
