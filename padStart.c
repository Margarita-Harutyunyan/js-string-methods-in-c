#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* padStart(char* str, int targetLength, char* padString) {
	// allocate memory for the result string
	char* res = (char*)malloc((targetLength + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	int difference = targetLength - strlen(str);
	
	// pad at the start 
	int i = 0;
	while (i < difference) {
		strcat(res, padString);
		i += strlen(padString);
	}

	// trim the result string and make space for the main string
	res[difference] = '\0';
	strcat(res, str);
	return res;
}

int main()
{
	char* str = padStart("cat", 10, "**");
	printf("%s\n", str);
}
