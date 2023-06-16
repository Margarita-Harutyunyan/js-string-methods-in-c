#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int indexOf(char* str, char* substr, int start);
int occurrence(char* str, char* substr);

char** split(char* str, char* separator) {
	int count = occurrence(str, separator);
	char** res = (char**)malloc((count + 1) * sizeof(char*));
	if (res == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	int start = 0;
	int end = indexOf(str, separator, start);
	int i = 0;
	while(start < strlen(str)) {
		int len = end - start;
		res[i] = (char*)malloc((len + 1) * sizeof(char));
		if (res[i] == NULL) {
			printf("Failed to allocate memory\n");
			return NULL;
		}
		int j = 0;
		for (j; j < len; ++j) {
			res[i][j] = str[start + j];
		}
		res[i][j] = '\0';

		start = end + strlen(separator);
		end = indexOf(str, separator, start);
		if (end == -1) {
			end = strlen(str);
		}
		++i;
	}
	return res;
}


int main()
{
	char** tokens = split("The quick brown fox", " ");

    if (tokens != NULL) {
        int i = 0;
        while (tokens[i] != NULL) {
            printf("%s\n", tokens[i]);
            ++i;
        }

        free(tokens);
    }

    return 0;
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

