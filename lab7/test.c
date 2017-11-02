#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
int Quit(int argc, char **argv)
{
    exit(0);
}
int ls(int argc, char **argv)
{
    const char *optString = "lah";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'l':
                printf("this -l option\n");
                break;            
            case 'a':
                printf("this -a option\n");
                break;
            case 'h':
                printf("in this cmd, you have 3 option can use:\n");
                printf("-l\n");
                printf("-a\n");
                printf("-h\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}
int HelloFunc(int argc, char **argv)
{
    printf("Hello! You are the best!"); 
    return 1;
}
int QuitFunc(int argc, char **argv)
{
    exit(0);
    return 1;
}
int GreaterFunc(int argc, char **argv)
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=a>b?a:b;
    printf("The greater one is %d",c);
    return 1;
}
int SmallerFunc(int argc, char **argv)
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=a>b?b:a;
    printf("The smaller one is %d",c);
    return 1;
}
int PlusFunc(int argc, char **argv)
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=a+b;
    printf("The result is %d",c);
    return 1;
}
int main(int argc, char **argv)
{
    MenuConfig("version", "Sally v7.0", NULL);
    MenuConfig("ls", "test arg option", ls);
    MenuConfig("quit", "quit from the menu", Quit);
    MenuConfig("hello","hello cmd",HelloFunc);
    MenuConfig("greater","greater cmd",GreaterFunc);
    MenuConfig("smaller","smaller cmd",SmallerFunc);
    MenuConfig("plus","return a+b",PlusFunc);
    ExcuteMenu();
    return 0;
}
