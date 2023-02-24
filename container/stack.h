#ifndef __container__stack_h
#define __container__stack_h
#define STACK_SIZE 10
typedef struct node{
    char *data;
    struct node *next;
}StackNode;
class Stack{
public:
    StackNode *InitStack(void);
    bool Pop(StackNode*);
    bool Push(StackNode*,char*);
    bool Clear(StackNode*);
    bool IsEmpty(StackNode*);
    char *Top(StackNode*);
};
#endif //__container__stack_h