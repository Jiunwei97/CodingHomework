#include <stdio.h>

int maxScoreSightseeingPair(int* values, int valuesSize) {
    int max_score = 0;
    int max_ai_plus_i = values[0];  // Tracks the maximum A[i] + i seen so far

    for (int j = 1; j < valuesSize; j++) {
        // Calculate the score for the current pair (i, j)
        max_score = (max_score > max_ai_plus_i + values[j] - j) ? max_score : (max_ai_plus_i + values[j] - j);
        
        // Update max_ai_plus_i
        max_ai_plus_i = (max_ai_plus_i > values[j] + j) ? max_ai_plus_i : (values[j] + j);
    }
    
    return max_score;
}

int main() {
    int values[] = {8, 1, 5, 2, 6};
    int valuesSize = sizeof(values) / sizeof(values[0]);
    
    int result = maxScoreSightseeingPair(values, valuesSize);
    printf("Max Score: %d\n", result);  // Output: 11

    return 0;
}
