#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

link_table* creat_link_table()
{
    link_table* ptr_link_table = (link_table*)malloc(sizeof(link_table));
    if (ptr_link_table == NULL)
    {
        return NULL;
    }  

    ptr_link_table->ptr_head = NULL;
    ptr_link_table->ptr_tail = NULL;
    ptr_link_table->sum_of_nodes = 0;

    return ptr_link_table;
}

int delete_link_table(link_table* ptr_link_table)
{
    if (ptr_link_table == NULL)
    {
        return FAILURE;
    }

    while (ptr_link_table->ptr_head != NULL)
    {
        link_table_node* ptr_node = ptr_link_table->ptr_head;
        ptr_link_table->ptr_head = ptr_link_table->ptr_head->ptr_next;
        free(ptr_node);
        ptr_link_table->sum_of_nodes -= 1;            
    }

    ptr_link_table->ptr_head = NULL;
    ptr_link_table->ptr_tail = NULL;
    free(ptr_link_table);
    return SUCCESS;
}


int add_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node)
{
    if (ptr_link_table == NULL || ptr_node == NULL)
    {
        return FAILURE;
    }

    ptr_node->ptr_next = NULL;
    if (ptr_link_table->ptr_head == NULL)
    {
        ptr_link_table->ptr_head = ptr_node;
    }

    if (ptr_link_table->ptr_tail == NULL)
    {
        ptr_link_table->ptr_tail = ptr_node;
    }
    else
    {
        ptr_link_table->ptr_tail->ptr_next = ptr_node;
        ptr_link_table->ptr_tail = ptr_node;
    }
    ptr_link_table->sum_of_nodes += 1;

    return SUCCESS;
}

int del_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node)
{
    if (ptr_link_table == NULL || ptr_node == NULL)
    {
        return FAILURE;
    }

    // handler head == ptr_node:
    if (ptr_link_table->ptr_head == ptr_node)
    {
        ptr_link_table->ptr_head = ptr_link_table->ptr_head->ptr_next;
        ptr_link_table->sum_of_nodes -= 1;

        if (ptr_link_table->sum_of_nodes == 0)
        {
            ptr_link_table->ptr_tail = NULL;
        }       
        return SUCCESS;
    }    

    link_table_node* ptr = ptr_link_table->ptr_head;
    while (ptr != NULL)
    {
        if (ptr->ptr_next == ptr_node)
        {
            ptr->ptr_next = ptr->ptr_next->ptr_next;
            ptr_link_table->sum_of_nodes -= 1;

            if (ptr_link_table->sum_of_nodes == 0)
            {
                ptr_link_table->ptr_tail = NULL;
            }
            return SUCCESS;            
        }
        ptr = ptr->ptr_next;
    }

    return FAILURE;
}

link_table_node* get_link_table_head(link_table* ptr_link_table)
{
    if (ptr_link_table == NULL || ptr_link_table->ptr_head == NULL)
    {
        return NULL;        
    }

    return ptr_link_table->ptr_head;
}

link_table_node* get_link_table_tail(link_table* ptr_link_table)
{
    if (ptr_link_table == NULL || ptr_link_table->ptr_tail == NULL)
    {
        return NULL;
    }    

    return ptr_link_table->ptr_tail;
}

link_table_node* get_next_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node)
{
    if (ptr_link_table == NULL || ptr_node == NULL)
    {
        return NULL;
    }

    link_table_node* ptr = ptr_link_table->ptr_head;
    while (ptr != NULL)
    {
        if (ptr == ptr_node)
        {
            return ptr->ptr_next;
        }

        ptr = ptr->ptr_next;
    }
    return NULL;
}
