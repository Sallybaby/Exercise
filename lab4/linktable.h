#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#define SUCCESS 0
#define FAILURE (-1)
typedef struct LinkTableNode 
{
    struct LinkTableNode * pNext;
}tLinkTableNode;
typedef struct LinkTable
{
    tLinkTableNode  * pHead;
    tLinkTableNode  * pTail;
    int             SumOfNode;
}tLinkTable;
typedef struct DataNode
{
    tLinkTableNode * pNext;
    const char     *cmd;
    const char     *desc;
    int    (*hindler)();
}tDataNode;
tLinkTable * createLinkTabel();
int DeleteLinkTable(tLinkTable * pLinkTable);
int AddLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode * pNode);
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode * pNode);
tDataNode* FindCmd(tLinkTable * head,char * cmd);
int ShowAllCmd(tLinkTable * head);
#endif
