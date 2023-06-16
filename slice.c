#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* slice(char* str, int start, int end) {
	int len = strlen(str);
	if (start < 0) {
		start = len + start;
	}
	if(end < 0) {
		end = len + end;
	}
	
	int resLen = end - start;
	char* res = (char*)malloc((resLen + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	
	int i = 0;
	for (i; i < resLen; ++i) {
		res[i] = str[start + i];
	}
	res[i] = '\0';
	return res;
}


int main()
{
	char* sliced = slice("The quick brown fox jumps over the lazy dog.", 4, 19);
	printf("%s\n", sliced);
	free(sliced);
}
