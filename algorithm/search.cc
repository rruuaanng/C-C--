#include<iostream>
#include<string>
#include "search.h"

int main(int argc, char const *argv[]){
    int data[]={1,2,3,6,45};
    Search s;
    std::cout<<"index: "
    <<s.BinaySeach(data,45)
    <<std::endl;
    getchar(); 
     
    return 0;
}


int Search::LinearSeach(int *arr,int find){
    int len=0;
    for(int i=0,*a=arr;*a!=0;i++,len++,a+=i){ }
    for (int i = 0; i < len; i++){
        if(arr[i]==find) return i;
    }
    return -1;
}

int Search::SwapSeach(int *arr,int find){
    int len=0;
    for(int i=0,*a=arr;*a!=0;i++,len++,a+=i){ }
    for(int i=0,tmp=0;i < len;i++){
        if(arr[i]==find){
            tmp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=tmp;
            return i;
       }
    }
    return -1;
}

int Search::LayHeadSeach(int *arr,int find){
    int len=0;
    for(int i=0,*a=arr;*a!=0;i++,len++,a+=i){ }
    for (int i=0,tmp=0;i < len;i++){
        if(arr[i]==find){
            tmp=arr[i];
            arr[i]=arr[0];
            arr[0]=tmp;
        }
    }
    return -1;
}

int Search::BinaySeach(int *arr,int find){
    int left=0,right=-1,mid=0;
    for(int i=0,*a=arr;*a!=0;i++,right++,a+=i){ }
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==find) return mid;
        if(arr[mid]>find) right=mid-1;
        if(arr[mid]<find) left=mid+1;
    }
    return -1;
}
