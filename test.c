#include <stdio.h>
#include <stdlib.h>

int ar[3][3];

int allocate (int **A, int n)
{
    if((*A=malloc(n*sizeof(int)))!=NULL)
	return 0;
    
    return 1;
}

void processArray(int **arr);//(*arr)[3]);

int main()
{
    int *ptr=NULL,i;
    
/*    if(allocate(&ptr, 10)!=1)
	for(i=0; i<10; i++){
	    ptr[i]=i;
	    printf("%d\n",ptr[i]);
	    }*/

    processArray(ar);
    printf("%d %d\n",ar[0][0],ar[1][1]);
    
    return 0;
}

void processArray(int **arr)//(*arr)[3])
{
    arr[1][1]=1234;
}
