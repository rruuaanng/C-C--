#ifndef algorithm_utils_h
#define algorithm_utils_h
#include <stdlib.h>
#include <stdio.h>

#define O '|' // 过滤处理占位符

int Filter1(char *, int *);
/*
int result;
Filter1("das123$%^&^%$158", &result);
printf("%d ", result);
*/

int Filter2(char *, char *);
/*
char result[8];
jj.Filter2("ACBI$%^&^123",result);
printf("%s ",result);
*/

int Filter3(char *, char, char, char *);
/*
char *data="<A/145#B6>(?D\\N4501)";
Filter3(data,'(',')',MO4);
printf("%s \n",MO4);
Filter3(data,'<','>',MO5);
printf("%s \n",MO5);
*/

char Clear(char);

char *bin;   // 用于存储每个字符的二进制串
char MO4[6]; // 第一个字符串
char MO5[6]; // 第二个字符串

#endif // algorithm_utils_h