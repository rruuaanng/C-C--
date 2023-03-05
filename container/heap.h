#ifndef container_heap_h
#define container_heap_h

#define MAX_SIZE 16

typedef struct _Heap{
    char arr[MAX_SIZE];
    int size;
}Heap;

int HeapIfy(Heap*,char*,int); // 初始化堆
int MakeMaxHeap(Heap*); // 创建最大堆
int Down(Heap*,char); // 下沉调整




#endif //container_heap_h