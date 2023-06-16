#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char* str, char* substr, int position);
int occurrence(char* str, char* substr);

char* replaceAll(char* str, char* pattern, char* replacement) {
	int count = occurrence(str, pattern);
	int len = strlen(str) - count * strlen(pattern) + count * strlen(replacement);
	char* res = (char*)malloc((len + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	int index = indexOf(str, pattern, 0);
	strncpy(res, str, index);
	strcat(res, replacement);
	printf("res1 %s\n", res);
	int current = strlen(res);
	while (count - 1) {
		index += (strlen(pattern) - 1);
		int end = indexOf(str, pattern, index);
		if (end == -1) {
			end = strlen(str);
		}
		printf("start %d end %d\n", index, end);
		for (int i = index + 1; i < end; ++i) {
			res[current] = str[i];
			++current;
		}
		index = indexOf(str, pattern, index);
		res[current] = '\0';
		if (end != strlen(str)) {
			strcat(res, replacement);
		}
		printf("res3 %s\n", res);
		current = strlen(res);
		--count;
	}
	return res;

}

int main()
{
	char* str = replaceAll("The quick brown fox jumps over the lazy dog. If the dog reacted, was it really lazy?", "dog", "cat");
	printf("%s\n", str);
	free(str);
}

int indexOf(char* str, char* substr, int start) {
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

int occurrence(char* str, char* substr) {
	int count = 0;
	int index = 0;
	while (index != -1) {
		++count;
		index = indexOf(str, substr, index + 1);
	}
	return count;
}
