#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

int main(int argc, char const *argv[])
{
    char *data="<A/145#B6>(?D\\N4501)";
    char result[6];
    Filter(data,'(',')',result);
    printf("%s \n",result);

    Filter(data,'<','>',result);
    printf("%s \n",result);
    return 0;
}

void CharToBin(char n){
    int len = 0;
    char *bytes=(char*)malloc(sizeof(char)),*tmp;
    for(int i=0;n!=0;i++,len++){
        *(bytes+i) = ('0'-(((int)n % 2)* -1));
        n /= 2;
    }
    bin=(char*)malloc(sizeof(char)); //清空全局变量中的值
    for (int i = len-1,idx=0;i>=0; i--,idx++){ *(bin+idx)=*(bytes+i); }
    if(len<8){
        for(int i=8-len,idx=0;i>=0;i--,idx++){ // 1000001 8-7=1 
            
        }
    }
}


int Filter(char *data,char c1,char c2,char *result){
  /**
  * @brief 提取指定括号中的字符数字组合
  * @param 1 待处理的参数
  * @param 2 左括号符号
  * @param 3 右括号符号
  * @param 4 结果指针
  * @return void
  */
  char tmp;
  int i=0; 
  for(data;*data!=c1;data+=1){ }
  for(data;*data!=c2;data+=1){
    if(*data == c1) continue;
    tmp=Clear(*data);
    if(tmp!=O){
        result[i++]=tmp;
    }
  }

}

static char Clear(char c){
    if((c >= 65 && c <= 90) 
    || (c >= 97 && c <= 122) 
    || (c >=48 && c <= 57)){
        if(c >= 48) return c;
    }
    return O;
}