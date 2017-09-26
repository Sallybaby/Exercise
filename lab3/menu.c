#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int help();
int quit();

static tDataNode head[]=
{
    {"help","This is help information!",help,&head[1]},
    {"version","Menu program for lab3",help,&head[2]},
    {"setting","This is setting function",help,&head[3]},
    {"quit","Quit",quit,NULL}
};

int main()
{
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("please input the cmd >");
	scanf("%s",cmd);
	tDataNode *p = findCmd(head,cmd);
	if(p == NULL)
	{
	    printf("ERROE:cmd not found!\n");
	    continue;
	}
	printf("%s :%s \n",p->cmd,p->desc);
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

int quit()
{
    exit(0);
}
