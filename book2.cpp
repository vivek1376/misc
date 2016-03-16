#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    long int M,N,i,j,k,girlQ[1010],marutQ[110],girlQnum,totalG=0;
    int offset;
    char lineQ[10000],*p;

    scanf("%ld",&M);

    for(i=0;i<M;i++)
	scanf("%ld",&marutQ[i]);

    sort(marutQ,marutQ+M);

    scanf("%ld",&N);

    /* for each girl */
    for(i=0;i<N;i++)
    {
	girlQnum=0;
	gets(lineQ);

	p=lineQ;
	
	while(sscanf(p,"%ld%n",&girlQ[girlQnum],&offset)==1)
	{
	    p+=offset;
	    girlQnum++;
	}
//	putchar('\n');//d
//	printf("@@\n");//d

	sort(girlQ,girlQ+girlQnum);

	k=0,j=0;
	while(k<M)
	{
	    while(marutQ[k]!=girlQ[j])
	    {
		j++;
		if(j>=girlQnum)
		    goto outLoop;
	    }
	    k++;
	}

    outLoop:
	if(k==M)
	    totalG++;
    }
    

    printf("%ld\n",totalG);

    return 0;
}
