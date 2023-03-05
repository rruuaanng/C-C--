#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "pid.h"

int in=500; // 编码器值(当前电机测速)

int main(int argc, char const *argv[]){
    float kp,ki,kd;
    printf("please input your target:");
    scanf("%f",&pid.target);
    printf("please input your kp:");
    scanf("%f",&kp);
    printf("please input your ki:");
    scanf("%f",&ki);
    printf("please input your kd:");
    scanf("%f",&kd);
    PID_Set(kp,ki,kd);
    
    int pwm=50;  // 输出PWM值(0为最快,50为最慢)
    while(pwm>0){
        in = ReadCoder(); // 读取当前电机转速
        printf("current speed: %d \n",in);
        pwm = PID_Realize(in); // 将当前转速输入PID并返回调整后的PWM值
        printf(" PWM: %d ",pwm); 
    }
    return 0;
}

void PID_Set(float Kp, float Ki, float Kd){
    /**
     * @brief 设置PID核心参数
     * @param 1 比例权重
     * @param 2 积分步长
     * @param 3 微分步长
     * 
    */
    pid.Kp=Kp;
    pid.Ki=Ki;
    pid.Kd=Kd;
}

int PID_Realize(int actual){
    /**
     * @brief PID计算函数
     * @param 1 当前观测值
     * @return 计算后的目标值
     * @note PWM输出为0则最快转速,最低为50
    */
    pid.err = pid.target - actual;
    pid.integral += pid.err;
    pid.output = pid.Kp * pid.err + 
                     pid.Ki * pid.integral + 
                     pid.Kd * (pid.err - pid.err_last);
    pid.err_last = pid.err;
    return pid.output;
}

int ReadCoder(){
    in++;
    return in;
}
