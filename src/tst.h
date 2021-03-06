#ifndef tst_h
#define tst_h

#include <stdlib.h>

typedef struct tst_t { 
    char splitchar; 
    struct tst_t *low;
    struct tst_t *equal;
    struct tst_t *high; 
    void *value;
} tst_t; 

typedef struct tst_collect_t {
    size_t length;
    void **values;
} tst_collect_t;

typedef void (*tst_traverse_cb)(void *value, void *data);

void *tst_search(tst_t *root, const char *s, int len);

tst_t *tst_insert(tst_t *p, const char *s, int len, void *value);

void tst_traverse(tst_t *p, tst_traverse_cb cb, void *data);

tst_collect_t tst_collect(tst_t *root, const char *s, int len);

#endif
