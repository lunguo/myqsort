#include"myqsort.h"
#include<stdio.h>

typedef struct student
{
    int sno;
    char name[10];
    int  score;
}stu;

int cmp_int(void* a,void* b)
{
    stu* x=(stu*)a;
    stu* y=(stu*)b;
   if(x->sno>y->sno)  return 1;
    else
    {
        if(x->sno==y->sno)
            return (x->score<y->score)?0:1;
        else
            return 0;
    }
}

int main()
{
    stu s[3]=
    {
        {1003,"张三",80},
        {1002,"李四",67},
        {1002,"王五",90}
    };
    int i;
   

    myqsort(s,3,sizeof(s[1]),cmp_int);

    for(i=0;i<3;i++)
        printf("%d %s %d ",s[i].sno,s[i].name,s[i].score);
    printf("\n");

    return 0;
}
