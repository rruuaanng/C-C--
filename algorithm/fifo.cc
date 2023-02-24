#include "fifo.h"


bool add(void){
    std::cout<< "hello" << std::endl;
    return true;
}
bool ff(void){
    std::cout<< "world" << std::endl;
    return true;
}

int main(int argc, char const *argv[]){
    Fifo f;
    f.Create("t1",add);
    f.Create("t2",ff);
    f.Run();
    getchar();
    return 0;
}