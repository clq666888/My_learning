#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open("/sys/class/leds/work/trigger", O_WRONLY);    //切换为手动模式
    write(fd, "none", 4);
    close(fd);

    fd = open("/sys/class/leds/work/brightness", O_WRONLY);

    if(strcmp(argv[1], "1") == 0)
    {
        write(fd, "1", 1);
    }
    else if(strcmp(argv[1], "0") == 0)
    {
        write(fd, "0", 1);
    }

    close(fd);

    return 0;
}