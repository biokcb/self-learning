#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashtable.h"

// null item to reference
static ht_item HT_DELETED_ITEM = {NULL, NULL};

// function to create a hash
static int ht_hash(const char* s, const int a, const int m){
    long hash = 0;
    const int len_s = strlen(s);

    // create a unique hash value based on each char in string
    // then take the remainder to reduce size
    for (int i=0; i<len_s; i++){
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }

    // cast returned hash to an int
    return (int)hash;
}

// function to deal with collisions
static int ht_get_hash(const char* s, const int num_buckets, const int attempt){
    // just picked two prime numbers above 128 for now
    const int hash_a = ht_hash(s, 191, num_buckets);
    const int hash_b = ht_hash(s, 607, num_buckets);

    // give an updated hash value if the hash produces a collision
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// function to initialize a new ht_item
static ht_item* ht_new_item(const char* k, const char* v){
    // set aside memory for size of ht item
    ht_item* i = malloc(sizeof(ht_item));

    // assign key, value given into item struct
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

// function to make a new empty hash table
ht_hashtable* ht_new(){
    // set aside memory for hash table
    ht_hashtable* ht = malloc(sizeof(ht_hashtable));

    // create an empty, fixed-size hash table
    ht->size = 53;
    ht->count = 0;
    // make all the items of the table NULL value
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));

    return ht;
}

// function to delete items from hashtable
static void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

// function to delete the whole hash table
void ht_del_hashtable(ht_hashtable* ht){
    // iterate over full table to delete each item
    for (int i = 0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if (item != NULL){
            ht_del_item(item);
        }
    }
    // then remove the items attr of the table itself
    free(ht->items);
    free(ht);
}

// function to insert a new entry to hash table
void ht_insert(ht_hashtable* ht, const char* key, const char* value){

    // create the new hash item
    ht_item* item = ht_new_item(key, value);

    // create the hash
    int index = ht_get_hash(item->key, ht->size, 0);

    // set cur_item to value in the table at hash
    ht_item* cur_item = ht->items[index];

    // search new hashes until an empty bucket is found
    int i = 1;
    while (cur_item !=NULL){
        if (cur_item != &HT_DELETED_ITEM) {
            // if the key exists when trying to insert, update it
            // first delete the current item, then update it in the table
            if (strcmp(cur_item->key, key) == 0) {
                ht_del_item(cur_item);
                ht->items[index] = item;
                return;
            }
        }
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    // then update the table value at hash to the item (key/value)
    ht->items[index] = item;

    // increase count attribute of table
    ht->count++;
}

// function to search for a key's value
char* ht_search(ht_hashtable* ht, const char* key){
    // find the hash based on key
    int index = ht_get_hash(key, ht->size, 0);

    // get the item associated with hash
    ht_item* item = ht->items[index];

    int i = 1;
    while (item !=NULL){
        // if the item hasn't been deleted
        if (item != &HT_DELETED_ITEM){
            // check if the keys are identical & return if it is
            if (strcmp(item->key, key) == 0){
                return item->value;
            }
        }

        // if not, check the next hash & items
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    // if there's no matches  & no more hashes to check then return NULL
    return NULL;
}

// function to delete an entry based on a key. Uses HT_DELETED_ITEM to make sure
// that the search function can skip over it in the collision chain
void ht_delete(ht_hashtable* ht, const char* key){
    // first get the hash and the item
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];

    // then check if the entry exists in the hash table
    int i;
    while (item != NULL){
        // check if the item references the deleted variable to indicate it was
        // deleted already
        if (item != &HT_DELETED_ITEM){
            // if the keys match, delete the item by referencing deleted variable
            if (strcmp(item->key, key) == 0){
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}