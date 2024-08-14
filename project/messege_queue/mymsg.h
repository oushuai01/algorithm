

#ifndef __MYMSG__H
#define __MYMSG__H
typedef struct data_s
{
    int idno;
    char grander;
    char pname[60];

}Data;

struct msgbuf
{
    long mtype;
    Data mdata;
};



#define MYTYPE 1


#endif

