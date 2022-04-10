/*
 * @Author: Opynicus
 * @Date: 2022-03-20 15:39:23
 * @LastEditTime: 2022-03-22 16:12:23
 * @LastEditors: Opynicus
 * @Description: ToyOSLab1
 * @FilePath: \lab1\proc.h
 */
#define NPROC  10  // 进程最大数量
#define MaxMemorySize 100 //pcb容量
enum procstate { READY,RUNNING,BLOCK,UNUSED };
enum shellCmd { RUN,RDY,BLK,KILL };
static char *states[] = {
  [UNUSED]    "unused",
  [READY]    "ready",
  [RUNNING]  "running ",
  [BLOCK]  "block"
  };
static char *cmds[] = {
  [RUN]    "run",
  [RDY]    "rdy",
  [BLK]  "blk",
  [KILL]  "kill"
  };
struct proc
{
    int pid; //进程id
    enum procstate state; //进程状态
    //char name[16]; //进程名称
    int mSize; //进程所需内存空间
};
