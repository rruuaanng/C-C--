#include <stdio.h>
#include "kansas.h"

int main(int argc, char const *argv[])
{
    char message[16];
    char info[16];
    Encode("ABCDEF", 3, message);
    printf("%s ", message);
    Decode(message, 3, info);
    printf("%s ",info);
    return 0;
}
int Encode(char *info, int n, char *message)
{
    /**
     * @brief 凯撒密码加密
     * @param 1 待加密字符串
     * @param 2 待解密字符串
     * @return void
     */
    int len = 0;
    for (char *i = info; *i != 0; i += 1, len++){ }
    for (int i = 0; i < len; i++){ message[i] = info[i] + n; }
}
int Decode(char *message, int n, char *info)
{
    /**
     * @brief 凯撒密码解码
     * @param 1 待解密字符串
     * @param 2 解密后字符串
     * @return void
     *
     */
    int len = 0,i=0;
    for (char *m = message; *m != 0; m += 1,len++){ }
    for (;i<len;i++){ info[i]=message[i]-n; }
    info[i]='\0';
}
