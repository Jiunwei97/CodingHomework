#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char *s, char *t) {
    // Early exit if the strings have different lengths
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create two mapping arrays for both directions
    char mapStoT[256] = {0}; // Mapping from s -> t
    char mapTtoS[256] = {0}; // Mapping from t -> s

    for (int i = 0; s[i] != '\0'; i++) {
        char charS = s[i];
        char charT = t[i];
       printf("[a]charS: %c, charT: %c, mapStoT[%c]: %c\n", charS, charT, charS, mapStoT[(unsigned char)charS]);
        // Check the mappings in both directions
        if ((mapStoT[(unsigned char)charS] && mapStoT[(unsigned char)charS] != charT) ||
            (mapTtoS[(unsigned char)charT] && mapTtoS[(unsigned char)charT] != charS)) {
            return false;
        }
        // Create the mappings
        mapStoT[(unsigned char)charS] = charT;
        mapTtoS[(unsigned char)charT] = charS;
        printf("[b]charS: %c, charT: %c, mapStoT[%c]: %c\n", charS, charT, charS, mapStoT[(unsigned char)charS]);

    }

    return true;
}

int main() {
    char s1[] = "egr";
    char t1[] = "ada";

    printf("Are '%s' and '%s' isomorphic? %s\n", s1, t1, isIsomorphic(s1, t1) ? "Yes" : "No");
    return 0;
}
