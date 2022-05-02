/*
 * @Author: Opynicus
 * @Date: 2022-05-02 19:01:26
 * @LastEditTime: 2022-05-02 20:42:33
 * @LastEditors: Opynicus
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define F_ULOCK  0
#define F_LOCK  1

int main()
{
    int fd[2];
    pipe(fd);
    pid_t p0 = fork();
    if (p0 == 0) {
        char _pipe[100];
        sprintf(_pipe, "Msg from proc %d\n", 1);
        lockf(fd[1], F_LOCK, 0);
        write(fd[1], _pipe, strlen(_pipe) + 1);
        lockf(fd[1], F_ULOCK, 0);
        return 0;
    }
    pid_t p1 = fork();
    if (p1 == 0) {
        char _pipe[100];
        sprintf(_pipe,  "Msg from proc %d\n", 2);
        lockf(fd[1], F_LOCK, 0);
        write(fd[1], _pipe,  strlen(_pipe) + 1);
        lockf(fd[1], F_ULOCK, 0);
        return 0;
    }
    pid_t p2 = fork();
    if (p2 == 0) {
        char _pipe[100];
        sprintf(_pipe,  "Msg from proc %d\n", 3);
        lockf(fd[1], F_LOCK, 0);
        write(fd[1], _pipe, strlen(_pipe) + 3);
        lockf(fd[1], F_ULOCK, 0);
        return 0;
    }
    int status = 0;
    pid_t wpid;
    do {
    } while ((wpid = waitpid(-1, NULL, 0)) > 0);
    char readBuffer[100];
    for (int i = 0; i < 3; i++) {
        read(fd[0], readBuffer, sizeof(readBuffer));
        printf("%s", readBuffer);
    }
}