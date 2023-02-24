#include "base64.h"

int main(int argc, char *argv[])
{
    char *data=*(argv+1);
    // char **group[10];
    // char *g1[] = {"01000001","00110001", "01000010"};
    // char *g2[] = {"1111", "0010", "0110"};
    // *(group + 1) = g1;
    // *(group + 2) = g2;
    // // *(*(group+1)+0) 内层移动用来切换不同分组,外层移动用来切换分组中的数据
    // printf("%s", *(*(group + 1) + 2));
    Split(data);
}

void Split(char *str){
    int cnt=1;
    for(char *s=str;*s!=0;s+=1,cnt++){
        CharToBin(*s);
        if(cnt==3){
            cnt=0;
            printf("\n");// 分组指针移动
        }
    }
}

int BinToDec(char *bin){ // 01010
    int num[]={128,64,32,16,8,4,2,1},i=0,sum=0,len=0,idx=0;
    for(char *b=bin;*b!=0;b+=1,len++){ }
    for(char *b=bin,i=8-len;i<8;i++,idx++){ sum += (*(b+idx)-48)*num[i]; }
    return sum;
}

void CharToBin(char n){
    int len = 0;
    char *bytes=(char*)malloc(sizeof(char)),*tmp;
    for(int i=0;n!=0;i++,len++){
        *(bytes+i) = ('0'-(((int)n % 2)* -1));
        n /= 2;
    }
    bin=(char*)malloc(sizeof(char)); //清空全局变量中的值
    for (int i = len-1,idx=0;i>=0; i--,idx++){ *(bin+idx)=*(bytes+i); }
    if(len<8){
        for(int i=8-len,idx=0;i>=0;i--,idx++){ // 1000001 8-7=1 
            
        }
    }
    // printf("len:%d %s ",len,bin);
}
char *GetResult(char *message){ //加密后未排序的数据
    
}

Node *InitTable(void)
{
    for (int i = 0; i < 64; i++) nums[i] = i;
    Node *head = (Node *)malloc(sizeof(Node)), *h_node = head;
    h_node->kChar = chars[0];
    h_node->kNum = nums[0];
    h_node->next = NULL;
    for (int i = 1; i < 64; i++){
        h_node->next = (Node *)malloc(sizeof(Node));
        h_node = h_node->next;
        h_node->kChar = chars[i];
        h_node->kNum = nums[i];
    }
    h_node->next = NULL;
    return head;
}

int CharGetNum(Node *head, char c)
{
    Node *h_node = head;
    for (; h_node != NULL;){
        if (h_node->kChar == c) { return h_node->kNum; }
        else { h_node = h_node->next; }
    }
}

char NumGetChar(Node *head, unsigned int n)
{
    Node *h_node = head;
    for (; h_node != NULL;){
        if (h_node->kNum == n) { return h_node->kChar; }
        else { h_node = h_node->next; }
    }
}

void ForEach(Node *head)
{
    for (Node *n = head; n != NULL; n = n->next) { 
        printf("char:%c,num:%d\n", n->kChar, n->kNum); 
    }
}
