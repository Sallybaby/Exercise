#include <stdio.h>
#include <stdlib.h>
typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *Next;
}tDataNode;

tDataNode *findCmd(tDataNode *head,char *cmd);

int showAllCmd(tDataNode *head);
