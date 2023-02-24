#ifndef algorithm_base64_h
#define algorithm_base64_h

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    char kChar;        // 表示base64编码表中的字符
    int kNum;          // 表示base64编码表中的数值部分
    struct node *next; // 下一个单词的链接地址
} Node;

char **group[3]; // 分组后的字符串表
/*
    char **group[10];
    char *g1[] = {"01000001","00110001", "01000010"};
    char *g2[] = {"1111", "0010", "0110"};
    *(group + 1) = g1;
    *(group + 2) = g2;
    // *(*(group+1)+0) 内层移动用来切换不同分组,外层移动用来切换分组中的数据
    printf("%s", *(*(group + 1) + 2));
*/

char *bin; //用于存储每个字符的二进制串

char *bins[24]; // 将每个分组的二进制合并,用于后续进行分4组补位操作
/*
    old: 11101010 10110100 00110111
    tmp: 111010101011010000110111 除以4然后以6位分组
    new: 111010 101011 010000 110111
    分组后的值可以直接计算二进制转十进制然后查base表
*/

int result[6]; // 存储加密后最终结果
/*
    result[0] = 0x76;
    result[1] = 0x9F;
    result[2] = 0xA5;
    printf("%x\n", result[0]);
    printf("%x\n", result[1]);
    printf("%x", result[2]);
*/

// 数字对应的字符
char chars[] = {'Q', 'j', '6', 'y', 'q', 'B', 'H', 'l',  // 0-7
                'b', 'i', '7', 'z', 'r', 'V', 'G', 'U',  // 7-15
                'd', 'I', '0', '1', '9', 'X', 'D', 'T',  // 16-23
                'c', 'k', 's', 't', '8', 'C', 'F', 'Y',  // 24-31
                '2', 'm', 'u', 'e', 'Z', '+', 'o', 'R',  // 32-39
                'f', 'n', 'v', '3', '/', 'L', 'A', 'E',  // 40-47
                'g', 'S', 'w', 'M', '4', 'K', 'P', 'W',  // 48-55
                'h', 'p', 'x', '5', 'N', 'J', 'O', 'a'}; // 56-63

int nums[64]; // 字符对应的数字

void Split(char *);                    // 分组函数
void CharToBin(char);                 // 字符转二进制(十进制转二进制)
int BinToDec(char *);                  // 二进制转十进制
/*
    char *bs[]={"11111111","10100101","11010010","11"};
    for (int i = 0; i < 4; i++)
        printf("%d\n",BinToDec(*(bs+i)));
*/
Node *InitTable(void);                 // 初始化字符表
/*
    Node *head=InitTable();
    char *data[]={"00010000","00010011",
                "00000101","00000010"};
    for(int i=0;i<4;i++){
    printf("%c ",NumGetChar(head,BinToDec(*(data+i))));
    }
*/
int CharGetNum(Node *, char);          // 通过字符查找对应数值
char NumGetChar(Node *, unsigned int); // 通过数值查找对应字符
void ForEach(Node *);                  // 检查字符表
char *GetResult(char *);               // 返回排序后加密数据的前六位
/*
    Node *head = InitTable();
    printf("num:%d", CharGetNum(head, c));
    printf("char:%c", NumGetChar(head, n));
*/
#endif // algorithm_base64_h


