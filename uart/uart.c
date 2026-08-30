#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

void set_serial_port(int fd, int baud_rate, int data_bits, int poarity, int stop_bits)
{
    struct termios options;

    tcgetattr(fd, &options);

    options.c_lflag &= ~(ICANON | ECHO);
    options.c_cflag |= (CLOCAL | CREAD);

    switch (baud_rate)
    {
    case 9600:
        cfsetispeed(&options, B9600);
        cfsetospeed(&options, B9600);
        break;
    case 115200:
        cfsetispeed(&options, B115200);
        cfsetospeed(&options, B115200);
        break;
    default:
        break;
    }

    switch (data_bits)
    {
    case 7:
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS7;
        break;
    case 8:
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;
        break;
    default:
        break;
    }

    switch (poarity)
    {
    case 'O':
        options.c_cflag |= PARENB;
        options.c_cflag |= PARODD;
        break;
    case 'E':
        options.c_cflag |= PARENB;
        options.c_cflag &= ~PARODD;
        break;
    case 'N':
        options.c_cflag &= ~PARENB;
        break;
    }

    switch (stop_bits)
    {
    case 1:
        options.c_cflag &= ~CSTOPB;
        break;
    case 2:
        options.c_cflag |= CSTOPB;
        break;
    default:
        break;
    }
    tcsetattr(fd, TCSANOW, &options);

}

int main(int argc, char *argv[])
{
    int fd;
    char buf[100];
    fd = open("/dev/ttyS9", O_RDWR | O_NOCTTY | O_SYNC);    //可读可写，非终端设备，同步模式
    set_serial_port(fd, 115200, 8, 'N', 1); //波特率115200，8位数据，无校验位，1位停止位
    write(fd, argv[1], strlen(argv[1]));
    sleep(1);
    read(fd, buf, sizeof(buf));
    printf("buf is %s\n", buf);
    return 0;
}