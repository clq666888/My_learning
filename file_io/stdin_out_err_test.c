#include <stdio.h>
#include <stdlib.h>
int main() {
    // malloc动态分配内存  也可以用 char ch[100]接收数据
    char *ch = malloc(100);
    fgets  (ch ,100, stdin);
    printf("%s", ch);

    fputs( ch , stdout);

    fputs( ch , stderr);

    return 0;
}