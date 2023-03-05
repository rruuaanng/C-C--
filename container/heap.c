#include <stdio.h>
#include <string.h>
#include "heap.h"


int main(int argc, char const *argv[]){
    Heap heap;
    int len;
    char *data="A1B2C3D4E5";
    for(char *d=data;*d!=0;d+=1,len++){ }
    HeapIfy(&heap,data,len);
    // printf("%c ",heap.arr[10]);
    return 0;
}



int HeapIfy(Heap *heap,char *arr,int size){
    /**
     * @brief 初始化堆
     * @param 1 堆变量
     * @param 2 初始化数组
     * @param 3 堆大小
     * @return 状态
    */
    if(size > 0){
        memcpy(heap->arr,arr,size*sizeof(char)); 
        heap->size=size;
        return MakeMaxHeap(heap);
    }
    return 0;
}

int MakeMaxHeap(Heap *heap){
    /**
     * @brief 构建堆
     * @param 1 堆变量
     * @return 状态
     * 
    */
    if(heap->size==0) return 0;
    for(int i=heap->size/2-1;i>=0;i--){
        Down(heap,i);
    }
    return 1;
}

int Down(Heap *heap,char value){
    /**
     * @brief 堆下沉
     * @param 1 堆变量
     * @param 2 值
     * @return 状态
    */
}