#include <stdio.h>

#define IN 1 // inside word
#define OUT 0 // outside word
#define MAX_WORD_LENGTH 20

/* This will be the final project for chapter 1 in K&R called "the big one" */
// Will be a counter, histogram and frequency analyzer divided into phases

int main (){
    int tabs = 0, spaces = 0, newlines = 0, other = 0;
    int c, state = OUT;
    int wordcount = 0;
    int letters[26] = {0}; // a-z
    int digits [10] = {0}; // 0-9
    int word_lengths[MAX_WORD_LENGTH] = {0};
    int current_length = 0;

    while ((c = getchar()) != EOF){
        // Counters; words, tabs, spaces, newlines, and characters
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN && current_length > 0 && current_length < MAX_WORD_LENGTH)
            word_lengths[current_length]++;
            current_length = 0;
            state = OUT;
        } else {
        if (state == OUT){
            state = IN;
            wordcount++;
        }
        current_length++;
        }
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
        if (c == ' ')
            ++spaces;
        else 
            ++other;

        // Frequency analyzer
        if (c >= 'A' && c <= 'Z'){
            c = c + ('a' - 'A');
        }
        
        if (c >= 'a' && c <= 'z'){
            letters[c - 'a']++;
        }
        

        if (c >= '0' && c <= '9'){
            digits[c - '0']++;
        }
          
    }
    
    if (state == IN && current_length > 0 && current_length < MAX_WORD_LENGTH) {
    word_lengths[current_length]++;
}

    // Word length histogram
    printf("\n\nWord length histogram:\n");
    for (int i = 1; i < MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > 0){
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; j++)
                putchar('#');
            printf(" (%d)\n", word_lengths[i]);
        }
    }

    // Letter frequency histogram
    printf("\nLetter Frequency Histogram:\n");
    for (int i = 0; i < 26; i++) {
        printf ("%c: ", 'a' + i);
        for (int j = 0; j < letters[i]; j++) {
            putchar('#');
        }
        printf(" (%d)\n", letters[i]);
    }

    // Digit frequecy histogram
    printf("\nDigit Frequency Histogram:\n");
    for (int i = 0; i < 10; i++){
        printf ("%c: ", '0' + i);
        for (int j = 0; j < digits[i]; j++){
            putchar('#');
        }
        printf(" (%d)\n", digits[i]);
    }

    printf("\n\nNumber of words: %d\n", wordcount);
    printf("Total tabs: %d\n", tabs);
    printf("Total spaces: %d\n", spaces);
    printf("Total newlines: %d\n", newlines);
    printf("Total other characters: %d\n", other);
    printf("\nLetter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, letters[i]);
    }

    printf("\nDigit frequencies:\n");
    for (int i = 0; i < 10; i++) {
        printf("%c: %d\n", '0' + i, digits[i]);
    }

    return 0;
}