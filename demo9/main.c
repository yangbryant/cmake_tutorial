#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 定义callback function类型
typedef int (*exampleCallback)(char *);

// 声明函数指针变量 examplecb, 指向 NULL
static exampleCallback examplecb = NULL;

// 实现回调函数, 输出 Hello World
static
int showHelloworld(char * name)
{
    printf("Hello World, %s.\n", name);
    return 0;
}

static
void bsp_show(int time, char *name)
{
    while (time > 0)
    {
        printf("%d\n", time);

        time--;
        sleep(1);

        if ((time == 0) && examplecb)
        {
            // 调用回调函数
            examplecb(name); 
            // 清空回调函数
            examplecb = NULL;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    int timeout = atoi(argv[1]);
    char * name = argv[2];

    // 设置函数指针为 showHelloworld 回调函数
    examplecb = showHelloworld;

    bsp_show(timeout, name);
    return 0;
}