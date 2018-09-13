#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myqsort.h"

void myqsort(void* a, int n, int w, int(*cmp)( void*,  void*))
{
    int i,j;
    i=0;
    j=n-1;
    void* key=(void*)malloc(w);
    memcpy(key,a,w);
    if(n<2) return;
    while(i!=j)
    {
        while(j!=i && (cmp(a+j*w,key))) j--;
        //a[i]=a[j];
        memcpy(a+i*w,a+j*w,w);

        while(j!=i && (cmp(key,a+i*w))) i++;
       // a[j]=a[i];
        memcpy(a+j*w,a+i*w,w);
    }
    memcpy(a+i*w,key,w);

    myqsort(a,i,w,cmp);
    myqsort(a+(i+1)*w,n-i-1,w,cmp);
}

