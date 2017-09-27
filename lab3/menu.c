#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10


int help();
static tDataNode head[]=
{
    {"help","This is help information!",help,&head[1]},
    {"verison","menu program v1.0",NULL,NULL}
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
void info()
{
    printf("Author:Yu Xufeng\nProgram Version:1.0\n");
}
void echo()
{
    char command[CMD_MAX_LEN];
    scanf("%s",command);
    printf("%s\n",command);
}

