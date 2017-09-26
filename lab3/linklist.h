#include <stdio.h>
#include <stdlib.h>

typdef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;
tDataNode *findCmd(tDataNode *head, char *cmd);

int showAllCmd(tDataNode *head);
