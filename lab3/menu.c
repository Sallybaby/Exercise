#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

void quit();
int help();
static tDataNode head[]=
{
    {"help","This is help information!",help,&head[1]},
    {"version","menu program v1.0",NULL,&head[2]},
    {"quit","Exit the program",quit,NULL}
};

int main()
{
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("please input the cmd >");
	scanf("%s",cmd);
	tDataNode *p = FindCmd(head,cmd);
	if(p == NULL)
	{
	    printf("ERROE:cmd not found!\n");
	    continue;
	}
	printf("%s - %s \n",p->cmd,p->desc);
        if(p->handler != NULL)
	{
	    p->handler();
	}
    }
    return 0;
}

int help()
{
    showAllCmd(head);
    return 0;
}

void quit()
{
    exit(0);
}
