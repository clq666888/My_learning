#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <string.h>

/*参数分别为fd：
    i2c总线文件描述符
    addr：i2c设备地址
    reg：寄存器地址
    data：数据指针
    len：数据长度
*/
int i2c_write_reg(int fd , unsigned char addr , unsigned char reg , unsigned char* data , int len)   //i2c写入函数，可写入len长度的数据
{
    unsigned char buf[256];
    buf[0] = reg;
    memcpy(buf + 1, data, len);
    struct i2c_msg msg[1]=
    {
        {
        .addr = addr,
        .flags = 0,
        .len = len + 1,
        .buf = buf,
        }
    };

    struct i2c_rdwr_ioctl_data i2c_msgs =
    {
        .msgs = msg,
        .nmsgs = 1,
    };
    
    return ioctl(fd, I2C_RDWR, &i2c_msgs);
}

/*参数分别为fd：
    i2c总线文件描述符
    addr：i2c设备地址
    reg：寄存器地址
*/
int i2c_read_reg(int fd , unsigned char addr , unsigned char reg)   //i2c读取函数，这里设计只能读取一个字节
{
    unsigned char data;
    struct i2c_msg msg[2]=
    {
        {
        .addr = addr,
        .flags = 0,
        .len = 1,
        .buf = &reg,
        },
        {
        .addr = addr,
        .flags = I2C_M_RD,
        .len = 1,           //只能读取一字节
        .buf = &data,
        }
    };

    struct i2c_rdwr_ioctl_data i2c_msgs =
    {
        .msgs = msg,
        .nmsgs = 2,
    };

    ioctl(fd, I2C_RDWR, &i2c_msgs);
    return data;
}

int main()
{
    int fd;
    unsigned char data = 0x55;
    unsigned char reg_data=0;
    fd = open("/dev/i2c-1", O_RDWR);
    i2c_write_reg(fd, 0x38, 0x80, &data, 1);    //这里0x38是rk3568上的显示屏从机地址
    reg_data = i2c_read_reg(fd, 0x38, 0x80);
    printf("reg_data is %x\n", reg_data);
    close(fd);
    return 0;
}










