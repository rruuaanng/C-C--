#include <stdio.h>
#include "mapreduce.h"

int main(int argc, char const *argv[]){
    char *data="hello hallow asd qwec adq zca";
    Mapper(data);
    return 0;
}

KV *Mapper(char *map){
    printf("%s ",map);
    return NULL;
}

KV *GroupByKey(KV *group){
    return NULL;
}

KV *Reduce(KV * reduce){
    return NULL;
}
