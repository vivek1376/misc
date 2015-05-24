#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char nineBoxes[520][10];
void boxNine();

int main()
{
    int i,j,k,m,n,p;
    char balls[13],box,leftBoxes[3];

    for(i=1;i<=12;i++)
	for(j=i+1;j<=12;j++)
	    for(k=j+1;k<=12;k++)
	    {
		balls[i]=balls[j]=balls[k]=1;
		
		for(box=1;box<=3;box++)
		{
		    switch(box)
		    {
		    case 1: leftBoxes[1]=2,leftBoxes[2]=3;break;
		    case 2: leftBoxes[1]=1,leftBoxes[2]=3;break;
		    case 3: leftBoxes[1]=1,leftBoxes[2]=2;break;
		    }
		    
		    nineBoxes(1,1,i,j,k);
		}
	    }
}

void nineBoxes(int index, int ball, int *leftBoxes, int i, int j, int k)
{
    if(ball>12)
	return;

    if (!(ball==i || ball==j || ball==k))
    {
	nineBoxes[index]=ball;
	index++;
    }

    nineBoxes(index, ++ball,i,j,k);
}

	
