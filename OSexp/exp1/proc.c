/*
 * @Author: Opynicus
 * @Date: 2022-03-20 15:44:57
 * @LastEditTime: 2022-05-21 08:50:48
 * @LastEditors: Opynicus
 * @Description: ToyOSLab1
 * @FilePath: \OSexp\exp1\proc.c
 */

#include "proc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// ptable(链表)
struct {
  struct proc proc[NPROC];
} ptable;

int nextpid = 0;                    //初始分配进程
int unusedMemSize = MaxMemorySize;  //可用空间

/*
 *   提示
 */
void HelpMenu() {
  printf(
      "************************************************************************"
      "*************\n");
  printf(
      "* Now starting the program!                                             "
      "            *\n");
  printf(
      "* For Examples                                                          "
      "            *\n");
  printf(
      "* run pid ---process pid turn into running state                        "
      "            *\n");
  printf(
      "* rdy pid ---process pid turn into ready state                          "
      "            *\n");
  printf(
      "* blk pid ---process pid turn into block state                          "
      "            *\n");
  printf(
      "* kill pid ---process pid turn into unused state                        "
      "            *\n");
  printf(
      "* show i --- 0 for all process info, 1 for block state info, 2 for "
      "ready state info *\n");
  printf(
      "************************************************************************"
      "*************\n");
}

/*
 *   提示信息
 */
void PrintInfo(int i, int pid) {
  switch (i) {
    case 1:
      printf("******************************************\n");
      printf("Process %d has been RUNNING state already.\n", pid);
      printf("******************************************\n\n\n");
      break;
    case 2:
      printf("******************************************\n");
      printf("Process %d isn't READY state.\n", pid);
      printf("******************************************\n\n\n");
      break;
    case 3:
      printf("******************************************\n");
      printf("Process %d has been READY state already.\n", pid);
      printf("******************************************\n\n\n");
    case 4:
      printf("******************************************\n");
      printf("Process %d isn't RUNNING or BLOCK state.\n", pid);
      printf("******************************************\n\n\n");
    case 5:
      printf("******************************************\n");
      printf("Process %d has been BLOCK state already.\n", pid);
      printf("******************************************\n\n\n");
    case 6:
      printf("******************************************\n");
      printf("Process %d isn't RUNNING state.\n", pid);
      printf("******************************************\n\n\n");
    case 7:
      printf("******************************************\n");
      printf("Process %d has been KILLED already.\n", pid);
      printf("******************************************\n\n\n");

    default:
      break;
  }
}

/*
 *   随机生成各进程对应的MemorySize
 */
int MemorySizeGen() {
  int tmp = rand() % 50;
  while (tmp == 0) tmp = rand() % 50;
  return tmp;
}

/*
 *   初始化当前所有进程
 */
static struct proc *initproc() {
  struct proc *p;
  srand((unsigned)time(NULL));
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    p->state = UNUSED;
    p->pid = nextpid++;
    p->mSize = MemorySizeGen();
  }
}

/*
 *   对初始化进程做分配
 */
struct proc *allocproc() {
  struct proc *p;
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    if (unusedMemSize < p->mSize) {
      p->state = BLOCK;
    } else {
      p->state = READY;
      unusedMemSize -= p->mSize;
    }
  }
}

/*
 *   显示当前进程信息与可用空间
 */
static struct proc *show(int pid) {
  printf("******************************************\n");
  if (pid == 0) {
    struct proc *p;
    for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
      printf("Proc: %d    State: %s    MEM: %d\n", p->pid, states[p->state],
             p->mSize);
    }
    printf("\nFree Space: %d MB.\n", unusedMemSize);
  } else if (pid == 1) {
    struct proc *p;
    for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
      if (p->state == BLOCK) {
        printf("Proc: %d    State: %s    MEM: %d\n", p->pid, states[p->state],
               p->mSize);
      }
    }
    printf("\nBlockBuffer\n");
  } else {
    struct proc *p;
    for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
      if (p->state == READY) {
        printf("Proc: %d    State: %s    MEM: %d\n", p->pid, states[p->state],
               p->mSize);
      }
    }
    printf("\nReadyBuffer\n");
  }
  printf("******************************************\n\n\n\n");
}

/*
 *   每当有进程状态被修改后就检测是否有空间留给阻塞态
 */
static struct proc *reCheck() {
  struct proc *p;
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    if (p->state == BLOCK && p->mSize <= unusedMemSize) {
      p->state = READY;
      printf("******************************************\n");
      printf("Process %d is READY state automatically.\n", p->pid);
      printf("******************************************\n\n\n");
      unusedMemSize -= p->mSize;
    }
  }
}

/*
 *   程序入口
 */
int main(int argc, char const *argv[]) {
  initproc();  //分配进程，初始均为就绪态，对应0
  printf("initial processes completed\n\n");
  // show();
  allocproc();
  printf("alloc processes completed\n\n");
  show(0);  //显示进程状态
            /*初始化*/
  char *cmd;
  int pid;
  struct proc *p;
  HelpMenu();
  while (1) {
    reCheck();
    //输入
    scanf("%s%d", cmd, &pid);
    if (strcmp(cmd, "run") == 0) {
      for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->pid == pid && p->state == READY) {
          p->state = RUNNING;
          PrintInfo(1, pid);
          break;
        } else if (p->pid == pid && p->state != READY) {
          PrintInfo(2, pid);
          break;
        }
      }
    }
    if (strcmp(cmd, "rdy") == 0) {
      for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->pid == pid && (p->state == BLOCK || p->state == RUNNING)) {
          p->state = READY;
          PrintInfo(3, pid);
          break;
        } else if (p->pid == pid && p->state != READY && p->state != RUNNING) {
          PrintInfo(4, pid);
          break;
        }
      }
    }
    if (strcmp(cmd, "blk") == 0) {
      for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->pid == pid && p->state == RUNNING) {
          p->state = BLOCK;
          PrintInfo(5, pid);
          break;
        } else if (p->pid == pid && p->state != RUNNING) {
          PrintInfo(6, pid);
          break;
        }
      }
    }
    if (strcmp(cmd, "kill") == 0) {
      for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->pid == pid && p->state == RUNNING) {
          p->state = UNUSED;
          unusedMemSize += p->mSize;
          PrintInfo(7, pid);
          break;
        } else if (p->pid == pid && p->state != RUNNING) {
          PrintInfo(6, pid);
          break;
        }
      }
    }
    if (strcmp(cmd, "show") == 0)
      if (pid == 0) {
        show(0);
      } else if (pid == 1) {
        show(1);
      } else {
        show(2);
      }
  }
}
