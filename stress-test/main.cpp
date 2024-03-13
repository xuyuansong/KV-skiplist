#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <ctime>
#include "../src/SkipList.h"

#define THREAD_NUM 1
#define TEST_NUM 100000

SkipList<int,std::string> skiplist(18);

using namespace std;

//插入函数
void* insert_test(void* arg)
{
    int *temp = (int*)arg;
    int j = *temp;
    int t = TEST_NUM / THREAD_NUM;
    for(int i=t*(j-1); i< j*t ; i++)
    {
        skiplist.insert_node(i,"aa");
    }
    pthread_exit(NULL);
    free(temp);
}

//查询函数
void* select_test(void* arg)
{
    for(int i=0; i<= TEST_NUM ; i++)
    {
        skiplist.select_node(rand()%TEST_NUM);
    }
    pthread_exit(NULL);
}

//删除函数
void* delete_test(void* arg)
{
    for(int i=0; i<= TEST_NUM ; i++)
    {
        skiplist.delete_node(rand()%TEST_NUM);
    }
    pthread_exit(NULL);
}

int main()
{
    {
        pthread_t thread_id_insert[THREAD_NUM];
        for(int i=0;i<THREAD_NUM;i++)
        {
            int * temp = (int*)malloc(sizeof(int*));
            *temp = i+1;
            if(pthread_create(&thread_id_insert[i],NULL,insert_test,(void*)temp))
            {
                std::cout << "线程 "<< i << " 创建失败" << std::endl;
                exit(-1);
            }
        }
        void* ret;
        for(int i=0;i<THREAD_NUM;i++)
        {
            if(pthread_join(thread_id_insert[i],&ret))
            {
                std::cout << "线程 "<< i << " 创建失败" << std::endl;
                exit(-1);
            }
        }
    }
    sleep(3);
    {
        clock_t start = clock();

        pthread_t thread_id_select[THREAD_NUM];
        for(int i=0;i<THREAD_NUM;i++)
        {
            if(pthread_create(&thread_id_select[i],NULL,select_test,NULL))
            {
                std::cout << "线程 "<< i << " 创建失败" << std::endl;
                exit(-1);
            }
        }
        void* ret;
        for(int i=0;i<THREAD_NUM;i++)
        {
            if(pthread_join(thread_id_select[i],&ret))
            {
                std::cout << "线程 "<< i << " 创建失败" << std::endl;
                exit(-1);
            }
        }
        clock_t end = clock();
        auto time = (double)(end - start) / CLOCKS_PER_SEC ;
        std::cout << "执行查询数据元素执行时长为: " << time << " 秒" << std::endl;
    }
    return 0;
}