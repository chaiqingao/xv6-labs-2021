#include "user/user.h"

int main(int argc, char *argv[])
{
    int p[2];
    pipe(p);
    if (fork() > 0)
    {
        // parent process
        char ch = 'P';
        write(p[1], &ch, 1);
        read(p[0], &ch, 1);
        printf("%d: received pong\n", getpid());
    }
    else
    {
        // child process
        char ch;
        read(p[0], &ch, 1);
        printf("%d: received ping\n", getpid());
        write(p[1], &ch, 1);
        exit(0);
    }
    exit(0);
}