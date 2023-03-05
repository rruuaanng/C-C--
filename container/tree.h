#ifndef container_tree_h
#define container_tree_h

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *rigth;
}Node;

class Tree{
 public:
  int *Root();
  bool IsRoot(int);
  int *Parent(int);
  int Child(int);
  int Len(Node *);
};



#endif //container_tree_h
