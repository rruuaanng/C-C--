#include "tree.h"

Node *Insert(Node *root, int value)
{
    if(root == NULL){ // 若为空则创建根节点
        root=(Node*)malloc(sizeof(Node));
        root->value=value;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if((root->value) == value) return root;
    if((root->value) < value) root->left=Insert(root->left,value);
    if((root->value) > value) root->right=Insert(root->right,value);
    return root;
}

Node *Search(Node *root, int value)
{
    return NULL;
}

Node *Delete(Node *root, int value)
{
    return NULL;
}

void Print(Node *root)
{
    if(root==NULL) return ;
        
    Print(root->left);
    printf("%d ",root->value);
    Print(root->right);
}

bool Destroy(Node *root)
{
}

int main(int argc, char const *argv[]){
    Node *root=NULL;
    root=Insert(root,1);
    root=Insert(root,2);
    root=Insert(root,3);
    root=Insert(root,4);
    root=Insert(root,5);
    Print(root);
    return 0;
}
