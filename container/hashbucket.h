#ifndef container_hashtable_h
#define container_hashtable_h

#define HASH_SIZE 5

typedef struct node{ 
    char *data;
    struct node *next;
    node(char *data){
        this->data = data;
        this->next = nullptr;   
    }
}HashNode;

HashNode *hash_bucket[HASH_SIZE];

class HashBucket{
 public:
  bool Insert();
  bool Delete();
  char *Get();
  int Hash();
};


#endif //container_hashtable_h