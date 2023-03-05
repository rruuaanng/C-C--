#include "utils.h"

int main(int argc, char const *argv[])
{
  char *data = "<A/145#B6>(?D\\N4501)";
  Filter3(data, '(', ')', MO4);
  printf("%s \n", MO4);
  Filter3(data, '<', '>', MO5);
  printf("%s \n", MO5);
  return 0;
}

int Filter1(char *data, int *result)
{
  /**
   * @brief 提取字符串中的整数
   * @example ABC!@#!@1234 result:1234
   * @param 1 待处理的数据
   * @param 2 结果指针
   * @return 清洗状态
   */
  *result = 0;
  int len = 0, bit = 1, i = 0;
  char tmp[8];
  if (data == NULL)
    return 0;
  for (char *d = data; *d != 0; d += 1)
  {
    if ((*d >= 48 && *d <= 57))
    {
      tmp[len] = *d;
      len++;
    }
  }
  for (int i = 0; i < len - 1; bit *= 10, i++)
  {
  }
  for (int i = 0, x = bit; x != 0; x /= 10, i++)
  {
    *result += ((('0' - tmp[i]) * -1) * x);
  }
  return 1;
}

int Filter2(char *data, char *result)
{
  /**
   * @brief 提取字符串中的字母数字组合
   * @example ABD^!*@!@23 result:ABD23
   * @param 1 待处理的数据
   * @param 2 结果指针
   * @return 清洗状态
   */
  char tmp;
  int i = 0;
  if (data == NULL)
    return 0;
  for (char *d = data; *d != 0; d += 1)
  {
    tmp = Clear(*d);
    if ((*d >= 65 && *d <= 90) || (*d >= 48 && *d <= 57))
      result[i++] = tmp;
  }
  return 1;
}

int Filter3(char *data, char c1, char c2, char *result)
{
  /**
   * @brief 提取指定括号中的字符数字组合
   * @example <AB!@*#!12> result:AB12
   * @param 1 待处理的数据
   * @param 2 左括号符号
   * @param 3 右括号符号
   * @param 4 结果指针
   * @return 清洗状态
   */
  char tmp;
  int i = 0;
  if (data == NULL)
    return 0;
  for (data; *data != c1; data += 1)
  {
  }
  for (data; *data != c2; data += 1)
  {
    if (*data == c1)
      continue;
    tmp = Clear(*data);
    if (tmp != O)
    {
      result[i++] = tmp;
    }
  }
  return 1;
}

char Clear(char c)
{
  /**
   * @brief 将非数字或字母的字符过滤
   * @param 1 待过滤的字符
   * @return 过滤后的字符
   */
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
  {
    return c;
  }
  else
    return O;
}
