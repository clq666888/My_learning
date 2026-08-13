#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret,fd;
    ret = access("/sys/class/gpio/gpio15", F_OK);     //判断是否存在gpio15
    if(ret != 0)
    {
        ret = open("/sys/class/gpio/export", O_WRONLY);
        write(ret, "15", 2);
        close(ret);
    }

    fd = open("/sys/class/gpio/gpio15/direction", O_WRONLY);   //设置gpio15为输出模式
    write(fd, "out", 3);
    close(fd);

    fd = open("/sys/class/gpio/gpio15/value", O_WRONLY);   //判断指令参数为1还是0
    if(strcmp(argv[1], "1") == 0)
    {
        write(fd, "1", 1);
    }
    else if(strcmp(argv[1], "0") == 0)
    {
        write(fd, "0", 1);
    }
    else
    {
        printf("error,please input 1 or 0\n");
    }
    close(fd);

    return 0;

}








