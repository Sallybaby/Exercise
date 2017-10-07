#include<stdlib.h>
#include<stdio.h>
#include"linktable.h"
tLinkTable *CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    return pLinkTable;
}
int DeleteLinkTable(tLinkTable * pLinkTable)
{
    if(pLinkTable==NULL)
    {
        return FAILURE;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode *tmp = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        free(tmp);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = -1;
    free(pLinkTable);  
    return SUCCESS;   
}
int AddLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode * pNode)
{
    tLinkTableNode *p=NULL;
    tLinkTableNode *temp=NULL;
    p=pLinkTable->pHead;
    if(p == NULL)
    {
        pLinkTable->pHead=pNode;
        pLinkTable->pTail=pNode;
        pLinkTable->SumOfNode++;
        pNode->pNext=NULL;
        return 0;
    }
    pLinkTable->pTail->pNext=pNode;
    pLinkTable->pTail=pNode;
    pNode->pNext=NULL;
    pLinkTable->SumOfNode++;
    return 0;      
}
int DeleteLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode *pNode)
{
    tLinkTableNode * p;
    p=pLinkTable->pHead;
    if(pLinkTable->pHead == NULL)
    {
    return 0;
    }
    if(pLinkTable->pHead == pLinkTable->pTail && pLinkTable->pHead != NULL)
    {
    free(pNode);
        pLinkTable->pHead=NULL;
        pLinkTable->pTail=NULL;
        pLinkTable->SumOfNode--;
        return 0;
    }
    if(pLinkTable->pHead != pLinkTable->pTail && pLinkTable->pTail == pNode)
    {
    free(pNode);
        while(p->pNext != NULL)
    {
        p=p->pNext;
    }
    pLinkTable->pTail=p;
    p->pNext=NULL;
        pLinkTable->SumOfNode--;
        return 0;           
    }
    if(pLinkTable->pHead != pLinkTable->pTail && pLinkTable->pHead == pNode)
    {
    pLinkTable->pHead=pLinkTable->pHead->pNext;
        free(pNode);
        pLinkTable->SumOfNode--;
        return 0;
    }
    else
    {
        while(p->pNext != pNode);
        {
            p=p->pNext;
        }
            p->pNext=p->pNext->pNext;
            pLinkTable->SumOfNode--;
            return 0;
    }  
}
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable)
{
    return pLinkTable->pHead;
}
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable,tLinkTableNode * pNode)
{
    return pNode->pNext;
}
tDataNode* FindCmd(tLinkTable * head,char * cmd)
{
    tDataNode *p=(tDataNode *)GetLinkTableHead(head);
    if(head == NULL || cmd == NULL)
    {
    return NULL;
    }
    while(p != NULL)
    {
    if(strcmp(p->cmd,cmd) == 0)
    {
        return p;
    }
    p=(tDataNode *)GetNextLinkTableNode(head,(tLinkTableNode *)p);
    }
    return p;
}
int ShowAllCmd(tLinkTable * head)
{
    tDataNode *p=NULL;
    printf("Menu list:\n");
    p=(tDataNode *)head->pHead;;
    while(p != NULL)
    {
        printf("%s:\t %s\n",p->cmd,p->desc);
        p=(tDataNode *)p->pNext;
    }
    return 0;
}
