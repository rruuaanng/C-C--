#ifndef algorithm_mapreduce_h
#define algorithm_mapreduce_h

typedef struct __KV{
    char *key;
    void *value;
}KV;

KV *Mapper(char *);
KV *GroupByKey(KV *);
KV *Reduce(KV *);


#endif // algorithm_mapreduce_h