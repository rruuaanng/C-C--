#ifndef __container_linkedlist_h
#define __container_linkedlist_h

typedef struct node{
    char *data;
    struct node *next;
}LinkedListNode;

class LinkedList{
public:
    LinkedListNode* InitLinkedList(char*[],int);
    bool Insert(LinkedListNode*, int, char*);
    bool Delete(LinkedListNode*,int);
    bool Update(LinkedListNode*,int,char*);
    bool Clear(LinkedListNode*);
    int Size(LinkedListNode*);
    bool IsEmpty(LinkedListNode*);
    char* Find(LinkedListNode*,char*);
    bool ForEach(LinkedListNode*);
private:
    LinkedListNode *InitHead(char* data){
        LinkedListNode *head=new LinkedListNode;
        head->data=data;
        head->next=nullptr;
        return head;
    }
};

#endif //__container_linkedlist_h