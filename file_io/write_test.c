#include <stdio.h>
#include <fcntl.h>     // open
#include <unistd.h>    // write、close
#include <string.h>    // strlen

int main()
{
    // 1. 打开文件：只写 + 不存在就创建 + 清空原内容
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("打开失败\n");
        return -1;
    }

    // 2. 准备要写的数据
    char buf[] = "hello write";

    // 3. 写进去，写 strlen(buf) 个字节（不含结尾的 \0）
    ssize_t n = write(fd, buf, strlen(buf));

    // 4. n 是实际写了多少字节
    printf("实际写了 %ld 个字节\n", n);
    printf("实际写了 %s \n", buf);
    // 5. 关闭
    close(fd);
    return 0;
}

