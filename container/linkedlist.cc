#include "linkedlist.h"
#include<iostream>
#include<string>

LinkedListNode* LinkedList::InitLinkedList(char *set[],int len){
    LinkedListNode *head=InitHead(set[0]),*h_node=head;
    int idx=1;
    if(IsEmpty(head)) return nullptr;
    while(len-1){
        h_node->next=new LinkedListNode;
        h_node=h_node->next;
        h_node->data=set[idx];
        idx++;
        len--;
    }
    h_node->next=nullptr;
    return head;
}

bool LinkedList::Insert(LinkedListNode* head, int index, char* data){
    LinkedListNode *h_node=head;
    if(IsEmpty(head)) return false;
    while(index){ 
        h_node = h_node->next;
        index--;
    }
    LinkedListNode *node=new LinkedListNode;
    node->data = data;
    node->next = h_node->next;
    h_node->next = node;
    return true;
}

bool LinkedList::Delete(LinkedListNode* head,int index){
    LinkedListNode *h_node=head;
    if(index>=Size(head)||IsEmpty(head)||index==0) return false;
    while(index-1){
        h_node=h_node->next;
        index--;
    }
    LinkedListNode *node = h_node->next->next;
    delete h_node->next;
    h_node->next=node;
    return true;
}

bool LinkedList::Update(LinkedListNode* head,int index,char* data){
    LinkedListNode *h_node=head;
    if(index>=Size(head)||IsEmpty(head)) return false;
    while(index){
        h_node=h_node->next;
        index--;
    }
    h_node->data=data;
    return true;
}

char* LinkedList::Find(LinkedListNode* head,char *data){
    LinkedListNode *h_node=head;
    while (h_node!=nullptr){
        if(h_node->data==data) return h_node->data;
        h_node=h_node->next;
    }
    return nullptr;
}

bool LinkedList::Clear(LinkedListNode* head){

    return true;
}

int LinkedList::Size(LinkedListNode* head){
    int cnt=0;
    LinkedListNode *h_node=head;
    if(IsEmpty(head)) return -1;
    while(h_node!=nullptr){
        cnt++;
        h_node=h_node->next;
    }   
    return cnt;
}

bool LinkedList::IsEmpty(LinkedListNode* head){
    return head == nullptr ? true : false;
}

bool LinkedList::ForEach(LinkedListNode* head){
    LinkedListNode *h_node=head;
    if(IsEmpty(head)) return false;
    while(h_node!=nullptr){
        std::cout<<h_node->data<<"->";
        h_node=h_node->next;
    }
    std::cout<<"NULL"<<std::endl;
    return true;
}

