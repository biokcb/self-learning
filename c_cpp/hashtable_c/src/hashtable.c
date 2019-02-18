#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

// function to initialize a new ht_item
static ht_item* ht_new_item(const char* k, const char* v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

// function to make a new empty hash table
ht_hashtable* ht_new(){
    ht_hashtable* ht = malloc(sizeof(ht_hashtable));

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));

    return ht;
}

// function to delete items from hashtable
static void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hashtable(ht_hashtable* ht){
    for (int i = 0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if (item != NULL){
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

