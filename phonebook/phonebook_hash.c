#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"


    int tableSize = 42737;



hashTable *createHashTable(int tableSize)
{
    hashTable *e = NULL;
    int i;

    if( tableSize < 1 ){
        return NULL;
    }

    /* Allocate the table itself. */
    if((e = (hashTable *) malloc(sizeof(hashTable))) == NULL) {
        return NULL;
    }

    /* Allocate array of list. */
    if( (e->list = (entry **)malloc(sizeof(entry *)*tableSize)) == NULL ) {
        return NULL;
    }

    /* Allocate list header */
    for( i = 0; i < tableSize; i++ ) {
        e->list[i] = NULL;
    }

    e->tableSize = tableSize;

    return e;
}

entry *findName(char *key, hashTable *e)
{
    entry *lne;
    hashIndex index = hash( key ,e);

    for(lne = e->list[index]; lne != NULL; lne = lne->pNext){
        if ( strcasecmp(key, lne->lastName) == 0 ){
            printf(" %12s is found!\n", key);
            return lne;
        }
    }
    printf(" %12s is not found!\n", key);

    return NULL;
}

entry *append(char *key, hashTable *e)
{
    hashIndex index = hash(key , e);
    entry *newEntry;
    if ((newEntry = (entry *) malloc(sizeof(entry))) == NULL){
        return 0;
    }
    strcpy(newEntry->lastName, key);
    newEntry->pNext = e->list[index];
    e->list[index] = newEntry;

    return 0;
}

hashIndex hash(char *key,hashTable *e)
{
    unsigned int hashVal = 0;
    while(*key != '\0'){
        hashVal+= *key++;
    }

    return hashVal % e->tableSize;
}
