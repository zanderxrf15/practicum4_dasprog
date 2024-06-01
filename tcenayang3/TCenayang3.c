#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverseString(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char* line) {
    char* word_start = NULL;
    char* temp = line;

    while (*temp) {
        if ((word_start == NULL) && (*temp != ' ')) {
            word_start = temp;
        }
        if (word_start && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0'))) {
            reverseString(word_start, temp);
            word_start = NULL;
        }
        temp++;
    }
}

int main() {
    char input[MAX_LEN];

    while (1) {
        fgets(input, MAX_LEN, stdin);

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        reverseWords(input);

        char* token = strtok(input, " ");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }
}

