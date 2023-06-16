#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat(char* str, int count) {
	char* res = (char*)malloc((count * strlen(str) + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	for (int i = 0; i < count; ++i) {
		strcat(res, str);
	}
	return res;
}

int main()
{
	char* str = repeat("Hello! ", 3);
	printf("%s\n", str);
	free(str);
}
