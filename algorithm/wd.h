#ifndef algorithm_wd_h
#define algorithm_wd_h

#ifndef wd_std_include
#define wd_std_include
    #include<iostream>
    #include<queue>
#endif //wd_std_include

typedef enum{
    kYes = 1,
    kNo = 0
}State;

typedef struct{  
    char *data;
    State flag;
}Event;

class Oper{
 public:
  bool PushYes(Event*);
  bool PushNo(char*);
  void Pop(State state);
  Event* Front(void);
 private:
  std::queue<Event*> yes_;
  std::queue<Event*> no_;
};

#endif //algorithm_wd_h