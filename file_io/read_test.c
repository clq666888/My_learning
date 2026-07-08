#include <stdio.h>
#include <fcntl.h>     // open 需要
#include <unistd.h>    // read、close 需要

int main()
{
    // 1. 打开文件，只读方式
    int fd = open("io.txt", O_RDONLY);
    if (fd == -1) {
        printf("打开失败\n");
        return -1;
    }

    // 2. 准备一块内存放数据
    char buf[100] = {0};

    // 3. 读，最多读 99 个字节
    ssize_t n = read(fd, buf, 99);

    // 4. n 是实际读到的字节数
    printf("实际读到 %ld 个字节\n", n);
    printf("内容是：%s\n", buf);

    // 5. 关闭
    close(fd);
    return 0;
}