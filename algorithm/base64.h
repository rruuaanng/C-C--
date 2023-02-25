#ifndef algorithm_base64_h
#define algorithm_base64_h
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// 编码表
char encode_table[] = {'Q', 'j', '6', 'y', 'q', 'B', 'H', 'l',  // 0-7
                'b', 'i', '7', 'z', 'r', 'V', 'G', 'U',  // 7-15
                'd', 'I', '0', '1', '9', 'X', 'D', 'T',  // 16-23
                'c', 'k', 's', 't', '8', 'C', 'F', 'Y',  // 24-31
                '2', 'm', 'u', 'e', 'Z', '+', 'o', 'R',  // 32-39
                'f', 'n', 'v', '3', '/', 'L', 'A', 'E',  // 40-47
                'g', 'S', 'w', 'M', '4', 'K', 'P', 'W',  // 48-55
                'h', 'p', 'x', '5', 'N', 'J', 'O', 'a'}; // 56-63

// 解码表
int decode_table[] = {0, 1, 2, 3, 4, 5, 6, 7,
                      8, 9,10, 11,12,13,14,15,
                      16,17,18,19,20,21,22,23,
                      24,25,26,27,28,29,30,31,
                      32,33,34,35,36,37,38,39,
                      40,41,42,43,44,45,46,47,
                      48,49,50,51,52,53,54,55,
                      56,57,58,59,60,61,62,63};
static int Swap(const void*,const void*); // 交换函数模板

int result[6];

class _Base64{
  /**
   * @example
   * char data[] = "A1B2"; // 明文数据
   * char *message=base64.Encode(data);
   * base64.Recode(message,result);
   * base64.Check(result);
  */
 public:
  char *Encode(char[]); // 编码函数
  void Recode(char*,int*); // 重编码函数
  void Check(int*); // 检查函数
}base64;

// _Base64 ;

#endif // algorithm_base64_h


