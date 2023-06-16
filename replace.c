#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char* str, char* substr);

char* replace(char* str, char* pattern, char* replacement) {
	int len = strlen(str) - strlen(pattern) + strlen(replacement);
	char* res = (char*)malloc((len + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	int index = indexOf(str, pattern);
	strncpy(res, str, index);
	strcat(res, replacement);
	
	int current = strlen(res);	
	int rest = index + strlen(pattern);

	for (current; current < len; ++current) {
		res[current] = str[rest];
		++rest;
	}
	res[current] = '\0';
	return res;



}

int main()
{
	char* str = replace("The quick brown fox jumps over the lazy dog.", "dog", "cat");
	printf("%s\n", str);
	free(str);
}

int indexOf(char* str, char* substr) {
	int start = 0;
	int index = -1;

	while (start < strlen(str)) {
		if (str[start] == substr[0]) {
			index = start;
			for (int i = 0; i < strlen(substr); ++i) {
				if (str[start + i] != substr[i]) {
					index = -1;
					break;
				}

			}
			if (index != -1) {
				return index;
			}
		}
		++start;
	}
	return index;
}
