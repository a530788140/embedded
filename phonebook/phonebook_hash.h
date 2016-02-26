#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

typedef struct __phone_NAME_ENTRY{
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __phone_NAME_ENTRY *pNext;
} lastNameEntry;

typedef struct __LAST_NAME_ENTRY{
    char lastName[MAX_LAST_NAME_SIZE];
    lastNameEntry *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;

typedef unsigned int hashIndex;

typedef struct __PHONE_BOOK_HASH_TABLE {
    unsigned int tableSize;  /* the size of the table */
    entry **list;  /* the table elements */
} hashTable;

hashTable *createHashTable(int tableSize);
entry *findName(char *key, hashTable *e);
entry *append(char *key, hashTable *e);
hashIndex hash(char *key, hashTable *e);


#endif
