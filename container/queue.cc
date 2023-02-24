#include "queue.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    Queue *lst=new Queue;
    QueueNode *head=lst->InitQueue("aa");
    lst->Append(head,"bb");
    lst->Append(head,"cc");
    lst->Append(head,"dd");
    lst->ForEach(head);
    getchar();
    return 0;
}


QueueNode* Queue::InitQueue(char *data){
    return new QueueNode(data,nullptr);
}

bool Queue::Append(QueueNode *queue,char *data){
    QueueNode *h_queue = queue;
    if(IsEmpty(queue)) return false;
    while(h_queue->next != nullptr) h_queue = h_queue->next;
    QueueNode *node = new QueueNode(data,nullptr);
    h_queue->next = node;
    return true;
}

bool Queue::Delete(QueueNode *queue,char *data){
    if(IsEmpty(queue)) return false;
    queue=queue->next;
    return true;
}

void Queue::ForEach(QueueNode *queue){
    QueueNode *h_queue=queue;
    while(h_queue!=nullptr){
        std::cout<< h_queue->data <<"->";
        h_queue=h_queue->next;
    }
    std::cout<<"NULL";
}

char* Queue::Front(QueueNode *queue){
    return !IsEmpty(queue)? queue->data : nullptr;
}

bool Queue::IsEmpty(QueueNode *queue){
    return queue ==  nullptr ? true:false;
}

