#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char at(char* arr, int index) {
	int len = (int)strlen(arr);
	if (index > len) {
		printf("Index out of range\n");
		return -1;
	}
	else if (index < 0) {

		index = len + index;
	}

	return arr[index];
}

int main() {
	char* str = "The quick brown fox jumps over the lazy dog.";
	int index = 5;
	printf("The character at index %d is %c\n", index, at(str, index));
	index = -4;
	printf("The character at index %d is %c\n", index, at(str, index));
}
