#include <stdio.h>
#include <malloc.h>
#include "mapreduce.h"

int main(int argc, char const *argv[]){
    KV *head = Init();
    Mapper("hello world");
    
    return 0;
}

KV *Mapper(char *map){
    char tmp[16];
    for(char *m=map,i=0;*m!=0;m+=1,i++){
        tmp[i] = *m;
        if((int)(*m) == 32){
            // printf("%s ",tmp);
        }
    }
    return NULL;
}

KV *GroupByKey(KV *group){
    return NULL;
}

KV *Reduce(KV * reduce){
    return NULL;
}

static int Insert(KV *head,char *key,int value){
    KV *h_node = head;
    if(head==NULL){ return 0; }
    while(h_node->next!=NULL){ h_node = h_node->next; }
    h_node->next = (KV*)malloc(sizeof(KV));
    h_node = h_node->next;
    h_node->key = key;
    h_node->value = value;
    h_node->next = NULL;
    return 1;
}

static KV *Init(void){
    KV *head = (KV*)malloc(sizeof(KV));
    head->key = NULL;
    head->value = 0;
    head->next=NULL;
    return head;
}
