#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);
/**
 1）参数key是消息队列的关键字。
注：当参数key取值IPC_PRIVATE时，函数创建关键字为0的消息队列。在UNIX内核中虽然要求消息队列关键字唯一，但也可以创建多个关键字为0的消息队列。
2）参数msgflg的低9位指定队列的属主、属组和其他用户的访问权限，其它位指定消息队列的创建方式。
创建方式参数：
IPC_CREAT：创建，如存在则打开；
IPC_EXCL：与IPC_CREAT使用，单独使用无意义。创建时，如存在则失败。
 */


int msgsnd(int msqid, void *msgp, int msgsz, int msgflg);
/*
msgid：指定发送消息队列的标识号；
msgp：指向存储待发送消息内容的内存地址，用户可设计自己的消息结构；
msgsz：指定长度，仅记载数据的长度，不包括消息类型部分，且必须大于0；
msgflg：控制消息发送的方式，有阻塞和非阻塞（IPC_NOWAIT）两种方式。

 */