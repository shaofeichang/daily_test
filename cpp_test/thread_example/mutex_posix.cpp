#include <stdio.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 100
void *thread_inc(void *arg);
void *thread_des(void *arg);

long long num = 0;
pthread_mutex_t mutex;
/*
pthread_attr_init //初始化线程属性变量 
pthread_attr_getstackaddr, pthread_attr_setstackaddr //栈地址（已废弃） 
pthread_attr_getstacksize, pthread_attr_setstacksize //栈大小 
pthread_attr_setguardsize, pthread_attr_getguardsize //保护区大小 
pthread_attr_getdetachstate, pthread_attr_setdetachstate //分离属性 
pthread_attr_getschedparam, pthread_attr_setschedparam //调度策略变量 
pthread_attr_getschedpolicy, pthread_attr_setschedpolicy //调度策略 
pthread_attr_getinheritsched, pthread_attr_setinheritsched //继承调度策略 
pthread_attr_getscope, pthread_attr_setscope //线程调度竞争范围 
pthread_setconcurrency, pthread_getconcurrency //并发级别 
pthread_attr_destroy //销毁线程属性变量
*/
int main(int argc, char *argv[])
{
    pthread_t thread_id[NUM_THREAD];
    int i;

    //互斥量的创建
    pthread_mutex_init(&mutex, NULL);

    sched_param parm;
    parm.sched_priority = 0;
    //pthread attr
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);         //  PTHREAD_SCOPE_SYSTEM
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //PTHREAD_CREATE_DETACHED
    pthread_attr_setschedparam(&attr, &parm);
    std::string str = "abc";
    for (i = 0; i < NUM_THREAD; i++)
    {
        pthread_setname_np(thread_id[i], (str + std::to_string(i)).c_str());
        if (i % 2)
            pthread_create(&(thread_id[i]), &attr, thread_inc, (void*)(thread_id[i]));
        else
            pthread_create(&(thread_id[i]), &attr, thread_des, (void*)(thread_id[i]));
    }

    for (i = 0; i < NUM_THREAD; i++)
        pthread_join(thread_id[i], NULL);

    printf("result: %lld \n", num);
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex); //互斥量的销毁
    system("pause");
    return 0;
}

/*扩展临界区，减少加锁，释放锁调用次数，但这样变量必须加满到50000000次后其它线程才能访问.
 这样是延长了线程的等待时间，但缩短了加锁，释放锁函数调用的时间，这里没有定论，自己酌情考虑*/
void *thread_inc(void *arg)
{
    pthread_t pt = (pthread_t) arg;
    char str[128] = {'\0'};
    pthread_getname_np(pt, str, 128);
    printf("thread inc name: %s\n", str);
    pthread_mutex_lock(&mutex); //互斥量锁住
    for (int i = 0; i < 1000000; i++)
        num += 1;
    pthread_mutex_unlock(&mutex); //互斥量释放锁
    return NULL;
}

/*缩短了线程等待时间，但循环创建，释放锁函数调用时间增加*/
void *thread_des(void *arg)
{
    pthread_t pt = (pthread_t) arg;
    char str[128] = {'\0'};
    pthread_getname_np(pt, str, 128);
    printf("thread des name: %s\n", str);
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        num -= 1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}