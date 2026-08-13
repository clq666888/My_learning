#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret,fd;
    ret = access("/sys/class/gpio/gpio40", F_OK);     //判断是否存在gpio40
    if(ret != 0)
    {
        ret = open("/sys/class/gpio/export", O_WRONLY);
        write(ret, "40", 2);
        close(ret);
    }

    fd = open("/sys/class/gpio/gpio40/direction", O_WRONLY);   //设置gpio40为输入模式
    write(fd, "in", 3);
    close(fd);

    fd = open("/sys/class/gpio/gpio40/value", O_WRONLY);   //判断指令参数为1还是0
    char value[2];
    read(fd, value, 2);
    printf("gpio40 value: %s\n", value);
    close(fd);

    return 0;

}








