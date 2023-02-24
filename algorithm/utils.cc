#include "utils.h"

int main(int argc, char const *argv[])
{
    // Utils a;
    jj.Filter("<A/145#B6>(?D\\N4501)",'(',')',MO4);    
    printf("%s ",MO4);
    return 0;
}


void _Utils::CharToBin(char n){
    /**
     * @brief 字符转换为二进制数
     * @param 1 字符
     * @return void
    */
    int len = 0;
    char *bytes=(char*)malloc(sizeof(char)),*tmp;
    for(int i=0;n!=0;i++,len++){
        *(bytes+i) = ('0'-(((int)n % 2)* -1));
        n /= 2;
    }
    bin=(char*)malloc(sizeof(char)); //清空全局变量中的值
    for (int i = len-1,idx=0;i>=0; i--,idx++){ *(bin+idx)=*(bytes+i); }
}

int _Utils::BinToDec(char *bin){
    /**
     * @brief 二进制串转换为整数
     * @param 1 二进制串
     * @return 整数值
    */
    int num[]={128,64,32,16,8,4,2,1},i=0,sum=0,len=0,idx=0;
    for(char *b=bin;*b!=0;b+=1,len++){ }
    for(char *b=bin,i=8-len;i<8;i++,idx++){ sum += (*(b+idx)-48)*num[i]; }
    return sum;
}

int _Utils::Filter(char *data,char c1,char c2,char *result){
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

char _Utils::Clear(char c){
    /**
     * @brief 将非数字或字母的字符过滤
     * @param 1 待过滤的字符
     * @return 过滤后的字符
    */
    if((c >= 65 && c <= 90) 
    || (c >= 97 && c <= 122) 
    || (c >=48 && c <= 57)){
        if(c >= 48) return c;
    }
    return O;
}