#ifndef algorithm_utils_h
#define algorithm_utils_h
#include<stdlib.h>
#include<stdio.h>

#define O '|' // 过滤处理占位符

class _Utils{
 public:
  int Filter(char*,char,char,char*);
    /*
        char *data="<A/145#B6>(?D\\N4501)";
        Filter(data,'(',')',MO4);
        printf("%s \n",MO4);

        Filter(data,'<','>',MO5);
        printf("%s \n",MO5);
    */
  int Filter(char*,char*);
  int Filter(char*,int*);
  char Clear(char); 
};

_Utils jj;

char *bin; //用于存储每个字符的二进制串
char MO4[6]; // 第一个字符串
char MO5[6]; // 第二个字符串

#endif //algorithm_utils_h