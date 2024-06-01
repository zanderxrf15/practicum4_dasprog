#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101];
    int vowels = 0, consonants = 0, uppercase = 0, lowercase = 0;

    char vowelsList[] = "AEIOUaeiou";
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isalpha(ch)) {
            if (isupper(ch)) {
                uppercase++;
            }
            else if (islower(ch)) {
                lowercase++;
            }

            int isVowel = 0;
            for (int j = 0; vowelsList[j] != '\0'; j++) {
                if (ch == vowelsList[j]) {
                    vowels++;
                    isVowel = 1;
                    break;
                }
            }
            if (!isVowel) {
                consonants++;
            }
        }
    }

    printf("Vowel Number: %d\n", vowels);
    printf("Number of Consonants: %d\n", consonants);
    printf("Total Uppercase: %d\n", uppercase);
    printf("Total Smallcase: %d\n", lowercase);
}
