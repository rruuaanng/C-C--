#include <stdio.h>
#include <malloc.h>
#include "filter.h"

int main(int argc, char const *argv[])
{

    return 0;
}

int Filter(const char *data,int *result){
    /**
     * @name filter
     * @arg data为未清洗数据,result为清洗后保存的变量
     * @return NULL
    */
    int len=0,mul=1; 
    for(const char *b=data;*b!=0;b+=1,len++){ } 
     for(int i=len-1,idx=0,x=1;i>=0;i--){
        if(data[i]>='0' && data[i]<='9'){
            *result+=(('0'-data[i])*-1)*mul;
            mul*=10;
        }
    }
    return 1;
}
