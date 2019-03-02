// key value pairs within hashtable
typedef struct {
    char* key;
    char* value;
} ht_item;

// the hashtable with an array of items and details about size
typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hashtable;

void ht_insert(ht_hashtable* ht, const char* key, const char* value);
char* ht_search(ht_hashtable* ht, const char* key);
void ht_delete(ht_hashtable* h, const char* key);
