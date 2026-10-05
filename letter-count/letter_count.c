// Count how many times a letter appears in a word (case-insensitive)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 100
#define MAX_LETTER_INPUT 10

int main(void) {
    char word[MAX_WORD];
    char letter_input[MAX_LETTER_INPUT];
    int count = 0;

    // Read the word
    printf("Enter a word: ");
    if (fgets(word, sizeof(word), stdin) == NULL) {
        printf("No input received.\n");
        return 1;
    }
    if (strchr(word, '\n') == NULL && strlen(word) == sizeof(word) - 1) {
        printf("Word is too long (max %d characters).\n", MAX_WORD - 1);
        return 1;
    }
    word[strcspn(word, "\n")] = '\0';  // remove newline
    if (word[0] == '\0') {
        printf("No word entered.\n");
        return 1;
    }

    // Read the letter
    printf("Enter the letter to count: ");
    if (fgets(letter_input, sizeof(letter_input), stdin) == NULL) {
        printf("No letter received.\n");
        return 1;
    }
    letter_input[strcspn(letter_input, "\n")] = '\0';
    if (letter_input[0] == '\0') {
        printf("No letter entered.\n");
        return 1;
    }
    if (letter_input[1] != '\0') {
        printf("Please enter exactly one character.\n");
        return 1;
    }
    char letter = letter_input[0];

    // Count matches
    size_t len = strlen(word);
    for (size_t i = 0; i < len; i++) {
        if (tolower((unsigned char)word[i]) == tolower((unsigned char)letter)) {
            count++;
        }
    }

    printf("'%c' appears %d time(s) in \"%s\".\n", letter, count, word);
    return 0;
}
