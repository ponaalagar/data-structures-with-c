#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

typedef struct Node {
    char key[20];
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node** buckets;
} HashTable;

unsigned int hash_function(char* key) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % HASH_TABLE_SIZE;
}

HashTable* create_hash_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (Node**)malloc(HASH_TABLE_SIZE * sizeof(Node*));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert(HashTable* table, char* key, int value) {
    unsigned int index = hash_function(key);
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->next = table->buckets[index];
    table->buckets[index] = node;
}

int search(HashTable* table, char* key) {
    unsigned int index = hash_function(key);
    Node* node = table->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // not found
}

void delete(HashTable* table, char* key) {
    unsigned int index = hash_function(key);
    Node* node = table->buckets[index];
    Node* prev = NULL;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void print_hash_table(HashTable* table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* node = table->buckets[i];
        printf("Bucket %d: ", i);
        while (node != NULL) {
            printf("%s:%d -> ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    HashTable* table = create_hash_table();

    insert(table, "apple", 10);
    insert(table, "banana", 20);
    insert(table, "orange", 30);
    insert(table, "grape", 40);

    print_hash_table(table);

    printf("Search for 'apple': %d\n", search(table, "apple"));
    printf("Search for 'banana': %d\n", search(table, "banana"));
    printf("Search for 'orange': %d\n", search(table, "orange"));
    printf("Search for 'grape': %d\n", search(table, "grape"));
    printf("Search for 'kiwi': %d\n", search(table, "kiwi"));

    delete(table, "banana");
    print_hash_table(table);

    return 0;
}