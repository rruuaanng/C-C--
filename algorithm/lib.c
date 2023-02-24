#include "lib.h"

void printIntList(uint8_t N, ...){ // 可变参数
    va_list args;  // 声明参数组
    va_start(args, N);  // 初始化
    printf("%d ",va_arg(args, int));
    va_end(args);
}

int main(void)
{

}

