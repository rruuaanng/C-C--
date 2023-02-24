#include "parallel.h"
#include <stdio.h>
#include<wininet.h>

int main(int argc, char const *argv[]){
#pragma omp parallel for
    for(int i=0;i<=100;i++){
        printf("%d \n",i);
    }
    return 0;
}
