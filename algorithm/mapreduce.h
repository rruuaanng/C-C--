#ifndef algorithm_mapreduce_h
#define algorithm_mapreduce_h

#include <stdio.h>
#include <malloc.h>
typedef struct __KV{
    char *key;
    int value;
    struct __KV *next;
}KV;


KV *Mapper(char *); 
KV *GroupByKey(KV *); // sort or partition KV paris 
KV *Reduce(KV *); // reduce KV paris and output some result
static int Insert(KV *,char *,int); // add KV paris to linkedlist 
static KV *Init(void);

#endif // algorithm_mapreduce_h