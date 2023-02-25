#include "base64.h"

int result[6];

int main(int argc, char const *argv[]){
	char data[] = "A1B2"; // 明文数据
	char *message=Encode(data);
	// printf("encode: %s \n",message);
	Recode(message,result);
	Check(result);
}

char *Encode(char data[]){
	/**
	 * @brief 编码函数
	 * @param 1 未编码数据
	 * @return 编码后的密文
	*/
	int data_len= strlen(data) / 3; // 分组长度
	int data_add = strlen(data) % 3;  // 分组后剩余数量
	char *message = (char*)malloc(data_len * 4 + 4 + 1);
	int cnt = 0;
	int tmp = 0;
	int n =0;
	while (cnt < data_len){
		message[n++] = encode_table[data[tmp] >> 2];
		message[n++] = encode_table[16 * (data[tmp] & 0x3) | data[tmp + 1] >> 4];
		message[n++] = encode_table[4 * (data[tmp + 1] & 0xF) | data[tmp+ 2] >> 6];
		message[n++] = encode_table[data[tmp + 2] & 0x3F];
		tmp += 3;
		cnt++;
	}
	if(data_add == 1){
		message[n++] = encode_table[data[tmp] >> 2];
		message[n++] = encode_table[16 * (data[tmp] & 0x3)];
		message[n++] = '=';
		message[n++] = '=';
		message[n] = '\0';
	}
	else if(data_add == 2){
		message[n++] = encode_table[data[tmp] >> 2];
		message[n++] = encode_table[(16 * (data[tmp] & 0x3)) | data[tmp + 1] >> 4];
		message[n++] = encode_table[4 * (data[tmp+1] & 0xF)];
		message[n++] = '=';
		message[n] = '\0';
	}
	else{
		message[n] = '\0';
	}
	return message;
}

static int Swap(const void *e1,const void *e2)
{
	/**
	 * @brief std快速排序模板
	 * @param 1 元素1
	 * @param 2 元素2
	 * @return 排序标识
	*/
	if (*(int*)e1 > *(int*)e2) { return -1; }
	else if (*(int*)e1 == *(int*)e2) { return 0; }
	else { return 1; }
}

void Recode(char *message,int *result){
	/**
	 * @brief 重编码函数
	 * @param 1 加密后未排序数据
	 * @param 2 结果指针
	 * @return 排序后的密文
	*/
	int len=0;
	for(char *m=message;*m!=0;m+=1,len++){ }
	int num[len];
	for(int i=0;i<len;i++){ num[i]=message[i]; }
	qsort(num,sizeof(num)/sizeof(num[0]),sizeof(int),Swap);
	for(int i=0;i<6;i++) { result[i]=num[i]; }
	return;
}
void Check(int *message){
	for(int *m=message;*m!=0;m+=1){ printf("%d ",*m); }
}


