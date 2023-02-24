#include "stack.h"

StackNode* Stack::InitStack(void){
    StackNode *stack=new StackNode;
    stack->data=nullptr;
    stack->next=nullptr;
    return stack;
}

bool Stack::Push(StackNode* stack,char* data){
    StackNode *h_stack=stack;
    if(IsEmpty(stack)) return false;
    while(h_stack->next!=nullptr) h_stack=h_stack->next;
    StackNode *node=new StackNode;
    node->data=data;
    node->next=nullptr;
    h_stack->next=node;
    return true;
}

bool Stack::Pop(StackNode* stack){
    StackNode *h_stack=stack;
    if(IsEmpty(h_stack)) return false;
    while(h_stack->next->next!=nullptr) h_stack=h_stack->next;
    delete h_stack->next;
    h_stack->next=nullptr;
    return true;
}
bool Stack::Clear(StackNode* stack){
    return true;
}
bool Stack::IsEmpty(StackNode* stack){
    return stack==nullptr ? true:false;
}

char* Stack::Top(StackNode* stack){
    StackNode *h_stack=stack;
    while(h_stack->next!=nullptr) h_stack=h_stack->next;
    return h_stack->data;
}

