#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    int ret = access("/sys/class/pwm/pwmchip0/pwm0" , F_OK);

    if(ret != 0 )
    {
        fd = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
        write(fd, "0", 1);
        close(fd);
    }

    fd = open("/sys/class/pwm/pwmchip0/pwm0/period", O_WRONLY);
    write(fd, "1000000", 7);
    close(fd);

    fd = open("/sys/class/pwm/pwmchip0/pwm0/polarity", O_WRONLY);
    write(fd, "normal", 6);
    close(fd);

    fd = open("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", O_WRONLY);
    write(fd, argv[1] , strlen(argv[1]));
    close(fd);    

    fd = open("/sys/class/pwm/pwmchip0/pwm0/enable", O_WRONLY);
    write(fd, "1" , 1 );
    close(fd);    

    return 0;
}