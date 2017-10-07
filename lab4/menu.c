#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linktable.h"

#define CMD_NUM 10
#define CMD_MAX_LEN 128
#define CMD_ANNO_LEN 1024

typedef struct data_node {
    link_table_node* next;
    char* cmd_name;
    char* cmd_annotation;
    int (*handler)();
} data_node;

int init_menu();
data_node* search_cmd(link_table* head, char* cmd);
int show_all_cmd(link_table* head);
int cmd_help();
int cmd_version();
int cmd_quit();
int cmd_others();

link_table* head = NULL;

int main(void)
{
    char cmd[CMD_MAX_LEN];

    init_menu(&head);

    while (true)
    {
        printf("please input your command > ");
        scanf("%s", cmd);

        data_node* ptr = search_cmd(head, cmd);

        if (ptr == NULL)
        {
            printf("ERROR command: '%s'\n", cmd);
            continue;
        }

        printf("%s\n", ptr->cmd_annotation);
        if (ptr->handler != NULL)
        {
            ptr->handler();
        } 

    }

    return 0;
}

int init_menu(link_table** pp_table)
{
    *pp_table = creat_link_table();

    data_node* node = (data_node*)malloc(sizeof(data_node)); 
    node->cmd_name = "help";
    node->cmd_annotation = "you can see help list.";
    node->handler = cmd_help;
    add_link_table_node(*pp_table, (link_table_node*)node);

    node = (data_node*)malloc(sizeof(data_node));
    node->cmd_name = "version";
    node->cmd_annotation = "menu program v2.5.4";
    node->handler = NULL;
    add_link_table_node(*pp_table, (link_table_node*)node);

    node = (data_node*)malloc(sizeof(data_node));
    node->cmd_name = "quit";
    node->cmd_annotation = "you quit the menu program.";
    node->handler = cmd_quit;
    add_link_table_node(*pp_table, (link_table_node*)node);

    node = (data_node*)malloc(sizeof(data_node));
    node->cmd_name = "others";
    node->cmd_annotation = "This is 'others' command.";
    node->handler = NULL;
    add_link_table_node(*pp_table, (link_table_node*)node);

    node = (data_node*)malloc(sizeof(data_node));
    node->cmd_name = "ls";
    node->cmd_annotation = "This is 'ls' command.";
    node->handler = NULL;
    add_link_table_node(*pp_table, (link_table_node*)node);

    return 0;
}

data_node* search_cmd(link_table* head, char* cmd)
{
    data_node* ptr_node = (data_node*)get_link_table_head(head);
    while (ptr_node != NULL)
    {   
        if (strcmp(ptr_node->cmd_name, cmd) == 0)
        {
            return ptr_node;
        }
        ptr_node = (data_node*)get_next_link_table_node(head, (link_table_node*)ptr_node);
    }

    return NULL;
}

int show_all_cmd(link_table* head)
{
    data_node* ptr_node = (data_node*)get_link_table_head(head);
    while (ptr_node != NULL)
    {
        printf("%s\t - \t%s\n", ptr_node->cmd_name, ptr_node->cmd_annotation);
        ptr_node = (data_node*)get_next_link_table_node(head, (link_table_node*)ptr_node);
    }
    return 0;
}

int cmd_help()
{
    printf("------------------------------------------\n");
    show_all_cmd(head);
    printf("------------------------------------------\n");
    return 0;
}

int cmd_version()
{
    return 0;
}

int cmd_quit()
{
    exit(0);
}
