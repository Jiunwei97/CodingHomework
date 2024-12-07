#include <stdio.h>
#include <stdlib.h>

// Define a hash table node structure
typedef struct HashNode {
    int key;               // The value in the array
    int index;             // The index of the value in the array
    struct HashNode* next; // Handle collisions via chaining
} HashNode;

// Define the hash table structure
typedef struct HashTable {
    HashNode** table;
    int size;
} HashTable;

// Hash function to map keys to hash indices
int hashFunction(int key, int size) {
    return (key < 0 ? -key : key) % size;
}

// Create and initialize a hash table
HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (HashNode**)calloc(size, sizeof(HashNode*));
    ht->size = size;
    return ht;
}

// Insert a key-value pair into the hash table
void insert(HashTable* ht, int key, int index) {
    int hashIndex = hashFunction(key, ht->size);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = ht->table[hashIndex];
    ht->table[hashIndex] = newNode;
}

// Search for a key in the hash table
HashNode* search(HashTable* ht, int key) {
    int hashIndex = hashFunction(key, ht->size);
    HashNode* current = ht->table[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Free memory used by the hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode* current = ht->table[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// TwoSum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* ht = createHashTable(numsSize);
    *returnSize = 0;
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HashNode* complementNode = search(ht, complement);

        if (complementNode != NULL) {
            result[0] = complementNode->index;
            result[1] = i;
            *returnSize = 2;
            freeHashTable(ht);
            return result;
        }
        insert(ht, nums[i], i);
    }

    freeHashTable(ht);
    return result; // Return empty if no solution is found
}

// Example usage
int main() {
    int nums[] = {2, 3, 7, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No solution found\n");
    }

    free(result);
    return 0;
}
