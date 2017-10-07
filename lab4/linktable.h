#ifndef _LINK_TABLE_H
#define _LINK_TABLE_H

#define FAILURE -1
#define SUCCESS 0
/*
 * link table definition and its operations:
 */

typedef struct link_table_node {
    struct link_table_node* ptr_next;
} link_table_node;

typedef struct link_table {
    link_table_node* ptr_head;
    link_table_node* ptr_tail;
    int sum_of_nodes;
} link_table;

link_table* creat_link_table();

int delete_link_table(link_table* ptr_link_table);

int add_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node);

int del_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node);

link_table_node* get_link_table_head(link_table* ptr_link_table);

link_table_node* get_link_table_tail(link_table* ptr_link_table);

link_table_node* get_next_link_table_node(link_table* ptr_link_table, link_table_node* ptr_node);

#endif
