#include <stdio.h>
#include <unistd.h>    // access 需要

char filename[] = "io.txt";

int main()
{
    printf("被检查文件为：%s\n", filename);

    if (access(filename , F_OK) == 0) {
        printf("该文件 存在\n");
    } else {
        printf("该文件 不存在\n");
        return 0;
    }
    
    if (access(filename , R_OK) == 0) {
        printf("该文件 可读\n");
    } else {
        printf("该文件 不能读\n");
    }
    
    if (access(filename, W_OK) == 0) {
        printf("该文件 可写\n");
    } else {
        printf("该文件 不能写\n");
    }
    
    if (access(filename, X_OK) == 0) {
        printf("该文件 可执行\n");
    } else {
        printf("该文件 不能执行\n");
    }
    
    return 0;
}

