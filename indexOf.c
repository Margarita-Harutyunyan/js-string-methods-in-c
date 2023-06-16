#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	

int main()
{
	printf("'dog' starts at index %d\n", indexOf("The quick brown fox jumps over the lazy dog.", "dog"));
}

