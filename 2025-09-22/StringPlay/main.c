#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //const char *words[] = { "one", "two", "three", "four" };
    const char **words = malloc(4 * sizeof *words);

    char buffer[256];

    for (int i = 0; i < 4; i++) { 
        scanf("%255s", buffer);
        //words[i] = buffer;   This will NOT achieve the desired effect
        words[i] = strdup(buffer);
    }

    //for (size_t i = 0; i < (sizeof words)/(sizeof *words); i++) 
    for (size_t i = 0; i < 4; i++) 
        printf("%s ", words[i]);
    printf("\n");

    // Free up the previously allocated space for the array and
    // its contents.
    for (int i = 0; i < 4; i++)
        free((char *)words[i]);
    free(words);

    puts("Program complete");
}

