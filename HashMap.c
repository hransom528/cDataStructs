// Harris Ransom
// C Hashmap
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (0xFFFFFFFFFFFFFFFFUL)

typedef struct {
	char name[MAX_NAME];
	int age;
} person;

person* hashTable[TABLE_SIZE] = { NULL };

// Initializes hash table
void initHashTable() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
	return;
}

// Simple hash function (add, multiply, mod)
unsigned int hash(char *name) {
	int length = strnlen(name, MAX_NAME);
	unsigned int hashVal = 0;
	
	for (int i = 0; i < length; i++) {
		hashVal += name[i];
		hashVal *= name[i];
		hashVal %= TABLE_SIZE;
	}
	return hashVal;
}

// Prints out hash table
void printTable() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] == NULL) {
			printf("\t%d\t---\n", i);
		}
		else if (hashTable[i] == DELETED_NODE) {
			printf("\t%d\t---<deleted>---\n", i);
		}
		else {
			printf("\t%d\t%s\n", i, hashTable[i]->name);
		}
	}
	printf("End\n");
}

// Adds person to hash table
bool insert(person *p) {
	if (p == NULL) return false;
	unsigned int index = hash(p->name);
	for (int i = 0; i < TABLE_SIZE; i++) { // Linear probing
		int try = (i + index) % TABLE_SIZE;
		if (hashTable[try] == NULL || hashTable[try] == DELETED_NODE) {
			hashTable[try] = p;
			return true;
		}
	}
	return false;
}

// Finds specified person in hash table
person *lookup(char *name) {
	int len = strlen(name);
	unsigned int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (i + index) % TABLE_SIZE;
		if (hashTable[try] == NULL) return NULL; // not here
		else if (hashTable[try] == DELETED_NODE) continue; 
		else if (hashTable[try] != NULL && (strncmp(name, hashTable[try]->name, len) == 0)) {
			return hashTable[try];
		}
	}
	return NULL;
}

// Removes specified person from hash table
person *delete(char *name) {
	int len = strlen(name);
	unsigned int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (i + index) % TABLE_SIZE;
		if (hashTable[try] == NULL) return NULL; // not here
		else if (hashTable[try] == DELETED_NODE) continue; 
		else if (hashTable[try] != NULL && (strncmp(name, hashTable[try]->name, len) == 0)) {
			person *tmp = hashTable[try];
			hashTable[try] = DELETED_NODE;
			return tmp;
		}
	}
	return NULL;
}

// MAIN
int main() {
	// Initializes empty hash table
	initHashTable();
	printTable();

	// Initializes people to add to hash table
	person jacob = {.name = "Jacob", .age = 256};
	person kate = {.name = "Kate", .age = 27};
	person mpho = {.name = "Mpho", .age = 14};
	person harris = {.name = "Harris", .age = 18};
	person sarah = {.name = "Sarah", .age = 54};
	person edna = {.name = "Enda", .age = 15};
	person maren = {.name = "Maren", .age = 25};
	person eliza = {.name = "Eliza", .age = 34};
	person robert = {.name = "Robert", .age = 1};
	person jane = {.name = "Jane", .age = 75};


	// Tests insert function
	insert(&jacob);
	insert(&kate);
	insert(&mpho);
	insert(&harris);
	insert(&sarah);
	insert(&edna);
	insert(&maren);
	insert(&eliza);
	insert(&robert);
	insert(&jane);
	printTable();

	// Tests lookup function
	person *tmp = lookup("Harris");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s.\n", tmp->name);
	}

	tmp = lookup("12345");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s.\n", tmp->name);
	}

	// Test remove function
	delete("Mpho");
	printTable();

	return 0;
}