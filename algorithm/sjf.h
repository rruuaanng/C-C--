#ifndef algorithm_sjf_h
#define algorithm_sjf_h

#ifndef sjf_std_include
    #include<iostream>
    #include<list>
    #include<random>
#define sjf_std_include
typedef enum{ //进程状态
    kReady = 1,
    kRunning = -1,
    kWait = 0,
}State;

typedef struct{
    int pid; //进程号
    double run_time; //程序的运行时间
    double over_time; //程序运行完毕的所需时间
    bool (*task)(void); //程序指针
    State state; //运行状态
}Process;

class Sjf{
private:
    std::list<Process> pcb;
};
#endif //sjf_std_include 

#endif //algorithm_sjf_h