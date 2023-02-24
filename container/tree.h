#ifndef container_tree_h
#define container_tree_h
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

typedef struct _TreeNode{
    int value;
    struct _TreeNode *left;
    struct _TreeNode *right;
}Node;

Node *Insert(Node *,int);
Node *Search(Node *,int);
Node *Delete(Node *,int);
bool Destroy(Node *);
void Print(Node *);

#endif //container_tree_h