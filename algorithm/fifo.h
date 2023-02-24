#ifndef algorithm_fifo_h
#define algorithm_fifo_h

#ifndef fifo_std_include
#define fifo_std_include
    #include<iostream>
    #include<queue>
    #include<list>
#endif //fifo_std_include

typedef struct{ //进程信息
    int pid;
    const char *name;
    bool (*task)(void);
}Process;

class Fifo{ //任务队列,将创建的任务函数放置到队列中并以此执行
public:
    Fifo(){ }
    ~Fifo(){ }
    bool Run(void){
        if(tasks_.empty()) return false;
        while(!tasks_.empty()){
            Process *process = tasks_.front();
            if((process->task)()){
                std::cout << "over" <<std::endl;
            }
            tasks_.pop();
        }
        return true;
    }

    int Create(const char* name,bool (*task)(void)){
        Process *process = new Process;
        process->pid = pid_cnt++;
        process->name = name;
        process->task = task;
        tasks_.push(process);
        return process->pid;
    }

    bool Kill(void){
        tasks_.pop();
        return true;
    }
private:
    int pid_cnt = 1;
    std::queue<Process*> tasks_;
};

#endif //algorithm_fifo_h