#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main()
{
    int fd;
    struct input_event in_ev;

    fd = open("/dev/input/event3", O_RDONLY);

    while (1)
    {
        read(fd, &in_ev, sizeof(struct input_event));

        if (in_ev.type == EV_KEY)
        {
            switch (in_ev.code)
            {
                case KEY_VOLUMEDOWN:
                    printf("音量减");
                    break;

                case KEY_VOLUMEUP:
                    printf("音量加");
                    break;

                case KEY_MENU:
                    printf("菜单");
                    break;

                case KEY_BACK:
                    printf("回退");
                    break;
            }
           switch (in_ev.value)
            {
                case 1:
                    printf("按键按下\n");
                    break;
                case 0:
                    printf("按键弹起\n");
                    break;
            } 
        }
    }

    return 0;
}


