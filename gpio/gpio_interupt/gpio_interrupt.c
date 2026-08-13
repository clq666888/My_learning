#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret,fd;
    struct pollfd fds[1];
    char buf[2];

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

    fd = open("/sys/class/gpio/gpio40/edge", O_WRONLY);   //设置gpio40为边沿触发
    write(fd, "both", 4);
    close(fd);

    fd = open("/sys/class/gpio/gpio40/value", O_RDONLY);   //判断指令参数为1还是0
    fds[0].fd = fd;
    fds[0].events = POLLPRI;
    read(fd, buf,2);            //确认并处理此前已经存在的GPIO事件通知，防止第一次poll因为旧事件而立即返回

    poll(fds, 1, -1);
    if (fds[0].revents & POLLPRI)
    {
        lseek(fd, 0, SEEK_SET);             //将文件偏移量移动到文件开头
        read(fd, buf, 1);
        printf("value is %s, get interrupt\n", buf);
    }
    close(fd);

    return 0;

}








