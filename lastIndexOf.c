#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastIndexOf(char* str, char* substr) {
	int start = 0;
	int index = -1;
	int current = index;

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
				current = index;
			}
		}
		++start;
	}
	return current;
}
	

int main()
{
	printf("last 'dog' starts at index %d\n", lastIndexOf("The quick brown fox jumps over the lazy dog. If the dog barked, was it really lazy?", "dog"));
}

