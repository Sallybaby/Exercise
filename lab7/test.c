#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int Quit(int argc, char * argv[])
{
    exit(0);
    return 0;
}
int Optiontest(int argc, char **argv)
{
    const char *opts = "lh";
    int opt;
    while ((opt = getopt(argc, argv, opts)) != -1)
    {
        switch (opt)
        {
            case 'l':
                printf("-----This is -l option-----\n");
                break;            
            case 'h':
                printf("-----This is -h option. You can use cmds here:-----\n");
                printf("-l\n");
                printf("-h\n");
                break;
            default:
                break;
        }
    }
    return 0;
}
int main()
{
    MenuConfig("version","----- Menu Program V7.0 -----", NULL);
    MenuConfig("quit", "----- Thanks for using -----", Quit);
    MenuConfig("optest", "----- Test command with arguments -----", Optiontest);
    ExecuteMenu();
}
