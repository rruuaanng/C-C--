#ifndef __algorithm_filter_h
#define __algorithm_filter_h

#define O '|' // 标志位

int Filter(char*,char,char,char*);
void CharToBin(char);
static char Clear(char);


char *bin; //用于存储每个字符的二进制串
char *MO4; // 第一个字符串
char *MO5; // 第二个字符串

#endif //__algorithm_fitler_h