#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* padEnd(char* str, int targetLength, char* padString) {
	// allocate memory for the result string and copy the input string
	char* res = (char*)malloc((targetLength + 1) * sizeof(char));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}
	strcat(res, str);
	
	// pad the rest with the padString till it is too long to fit
	int rest = targetLength - strlen(str);
	int pad = strlen(padString);

	while (rest < targetLength) {
		strcat(res, padString);
		rest += pad;
	}
	
	// fill the remaining bytes character by character until full
	rest -= pad;
	int i = 0;
	for (rest; rest < targetLength; ++rest) {
		res[rest] = padString[i];
		++i;
	}

	//assign '\0' to the end of the result
	res[targetLength] = '\0';
	return res;
}


int main()
{
	char* str = padEnd("Breaded Mushrooms", 25, ".");
	printf("%s\n", str);
	free(str);
}
