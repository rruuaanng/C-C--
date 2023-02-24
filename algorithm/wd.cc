#include "wd.h"


int main(int argc, char const *argv[]){
    Oper oper;
    oper.PushNo("bowl 1");
    oper.PushNo("bowl 2");
    oper.PushNo("bowl 3");
    oper.PushNo("bowl 4");
    Event *event = oper.Front();
    oper.PushYes(event);
    getchar();
    return 0;
}

bool Oper::PushYes(Event *event){
    event->flag=kYes;
    if(event==nullptr) return false;
    Pop(kNo);
    yes_.push(event);
    return true;
}

bool Oper::PushNo(char *data){
    Event *event = new Event;
    event->data = data;
    event->flag = kNo;
    if(event == nullptr) return false;
    no_.push(event);
    return true;
}

void Oper::Pop(State state){
    state == kYes? yes_.pop(): no_.pop();
}

Event *Oper::Front(void){
    return no_.front();
}
