#ifndef __container__queue_h
#define __container__queue_h
#define QUEUE_SIZE 10

typedef struct node{
    char *data;
    struct node *next;
    node(char *data,node *next){
        this->data=data;
        this->next=next;
    }
}QueueNode;

class Queue{
public:
    QueueNode* InitQueue(char*);
    bool Append(QueueNode*,char*);
    bool Delete(QueueNode*,char*);
    char* Front(QueueNode*);
    bool IsEmpty(QueueNode*);
    void ForEach(QueueNode*);
};

#endif //__container__queue_h