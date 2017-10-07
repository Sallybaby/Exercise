#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linktable.h"
void InitMenuData(tLinkTable ** pLinkTable);
int HelpFunc();
int HelloFunc();
int QuitFunc();
int BiggerFunc();
int SmallerFunc();
int PlusFunc();
int MinusFunc();
int MultiplyFunc();
#define CMD_MAX_LEN     128
#define DESC_LEN    1024
#define CMD_NUM        10
tLinkTable * head=NULL;
/* Menu program */
int main()
{
    char *cmd;
    tDataNode *cmd_pointer;
    InitMenuData(&head);
    printf("Computer common cmd:\n");
    printf("help\thello\tquit\tbigger\tsmaller\tplus\tminus\tmultiply\n");
    while(1)
    {
    printf("Please input cmd:\n");
    scanf("%s",cmd);
    cmd_pointer=FindCmd(head,cmd);
    if(cmd_pointer == NULL)
    {
            printf("The cmd is not copmuter common cmd or it is wrong £¡\n");
        continue;
    }
    cmd_pointer->hindler();
    }
    return 0;
}
void InitMenuData(tLinkTable ** pLinkTable)
{
    *pLinkTable = CreateLinkTable();
    tDataNode * pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="This is a help cmd.";
    pNode->hindler=HelpFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="hello";
    pNode->desc="This is a hello cmd.";
    pNode->hindler=HelloFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="Quit the program.";
    pNode->hindler=QuitFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="bigger";
    pNode->desc="Find bigger data between two datas.";
    pNode->hindler=BiggerFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="smaller";
    pNode->desc="Find smaller data between two datas.";
    pNode->hindler=SmallerFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="plus";
    pNode->desc="Get sum about two datas.";
    pNode->hindler=PlusFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="minus";
    pNode->desc="Get sub about two datas.";
    pNode->hindler=MinusFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
    pNode=(tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd="multiply";
    pNode->desc="Get mul about two datas.";
    pNode->hindler=MultiplyFunc;
    AddLinkTableNode(*pLinkTable,(tLinkTableNode *) pNode);
}
int HelpFunc()
{
    printf("This is help!\n");
    return 1;
}
int HelloFunc()
{
    printf("Hello! You are the best!\n"); 
    return 1;
}
int QuitFunc()
{
    exit(0);
    return 1;
}
int BiggerFunc()
{
    int a,b,c;
    printf("Please put two numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=a>b?a:b;
    printf("The greater one is %d\n",c);
    return 1;
}
int SmallerFunc()
{
    int a,b,c;
    printf("Please put two numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=a>b?b:a;
    printf("The smaller one is %d\n",c);
    return 1;
}
int PlusFunc()
{
    int a,b,c;
    printf("Please put two numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=a+b;
    printf("The result is %d\n",c);
    return 1;
}
int MinusFunc()
{
    int a,b,c;
    printf("Please put two numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=a-b;
    printf("The result is %d\n",c);
    return 1;
}  
int MultiplyFunc()
{
    int a,b,c;
    printf("Please put two numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=a*b;
    printf("The result is %d\n",c);
    return 1;
}
