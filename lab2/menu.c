#include <stdio.h>
#include <stdlib.h>
void quit()
{
    exit(0);
}
void hello()
{
    printf("hello word!\n");
}
void help()
{
    printf("You can read the documention to get help.\n");
}
void add()
{
    double a,b,sum;
    printf("please input two numbers:\n");
    scanf("%lf %lf",&a,&b);
    sum=a+b;
    printf("%lf+%lf=%lf\n",a,b,sum);
}
void sub()
{
    double a,b,dif;
    printf("please intput two numbers:\n");
    scanf("%lf %lf",&a,&b);
    dif=a-b;
    printf("%lf-%lf=%lf\n",a,b,dif);
}
void multi()
{
    double a,b,pro;
    printf("please input two numbers:\n");
    scanf("%lf %lf",&a,&b);
    pro=a*b;
    printf("%lf*%lf=%lf\n",a,b,pro);
}
void divi()
{
    double a,b,div;
    printf("please input two numbers:\n");
    scanf("%lf %lf",&a,&b);
    if(b==0)
    {
        printf("Error:divisor can not be zero!\n");
    }
    else
    {
        div=a/b;
        printf("%lf/%lf=%lf\n",a,b,div); 
    }
}
void bigger()
{
    double a,b,bigger;
    printf("please input two numbers:\n");
    scanf("%lf %lf",&a,&b);
    bigger=a>b?a:b;
    printf("is bigger than the other.\n");
}
void main()
{
    char cmd[256];
    while(1)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"hello") == 0)
	{
	    hello();
	}
        else if(strcmp(cmd,"quit") == 0)
	{
	    quit();
	}
	else if(strcmp(cmd,"add") == 0)
	{
	    add();
	}
	else if(strcmp(cmd,"sub") == 0)
	{
	    sub();
	}
	else if(strcmp(cmd,"multi") == 0)
	{
	    multi();
	}
	else if(strcmp(cmd,"divi") == 0)
	{
	    divi();
	}
	else
	{
	    printf("Error Command!\n\n");
	    help();
	}
    }
}
