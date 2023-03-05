#ifndef algorithm_pid_h
#define algorithm_pid_h

struct _PID
{
	float target;	  // 期望值
	float err;		  // 误差
	float err_last;	  // 上次误差,上上次误差
	float Kp, Ki, Kd; // 比例、积分、微分系数
	float integral;	  // 积分值
	int output;		  // 输出PWM
} pid;

void PID_Set(float, float, float); // 调节PID参数
int PID_Realize(int);			   // PID迭代计算

int ReadCoder();

#endif // algorithm_pid_h