#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char at(char* arr, int index) {
	int len = (int)strlen(arr);
	if (index > len | index < 0) {
		printf("Index out of range\n");
		return -1;
	}
	return arr[index];
}

int main() {
	char* str = "The quick brown fox jumps over the lazy dog.";
	int index = 5;
	printf("The character at index %d is %d\n", index, at(str, index));
}

