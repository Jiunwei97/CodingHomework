#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // For INT_MAX
// A simple hash table node
typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

// Hash function
unsigned int hash(char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % 1000; // Modulo to keep the table size fixed
}

// Insert into hash table
void insert(HashNode **table, char *key, int value) {
    unsigned int idx = hash(key);
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = table[idx];
    table[idx] = node;
}

// Search in hash table
int search(HashNode **table, char *key) {
    unsigned int idx = hash(key);
    HashNode *current = table[idx];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

// Main function to find common strings with the minimum index sum
void findRestaurant(char **list1, int size1, char **list2, int size2) {
    HashNode *table[1000] = {0};
    int minIndexSum = INT_MAX;
    char *result[1000];
    int resultCount = 0;

    // Populate hash table with list1
    for (int i = 0; i < size1; i++) {
        insert(table, list1[i], i);
    }

    // Check common strings in list2
    for (int j = 0; j < size2; j++) {
        int idx = search(table, list2[j]);
        if (idx != -1) {
            int indexSum = idx + j;
            if (indexSum < minIndexSum) {
                minIndexSum = indexSum;
                resultCount = 0;
                result[resultCount++] = list2[j];
            } else if (indexSum == minIndexSum) {
                result[resultCount++] = list2[j];
            }
        }
    }

    // Print the result
    for (int k = 0; k < resultCount; k++) {
        printf("%s\n", result[k]);
    }
}

// Example usage
int main() {
    char *list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    char *list2[] = {"KFC", "Shogun", "Burger King"};
    findRestaurant(list1, 4, list2, 3);
    return 0;
}
