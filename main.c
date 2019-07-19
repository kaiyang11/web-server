#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "epoll_server.h"

int main(int argc, const char* argv[])//argv[0]为程序的名字
{
    if(argc < 3)
    {
        printf("eg: ./a.out port path\n");
        exit(1);
    }

    // 端口
    int port = atoi(argv[1]);//端口在这里
    // 修改进程的工作目录, 方便后续操作
    int ret = chdir(argv[2]); //相当于cd，改为argv【2】
    if(ret == -1)
    {
        perror("chdir error");
        exit(1);
    }
    
    // 启动epoll模型 
    epoll_run(port);

    return 0;
}
