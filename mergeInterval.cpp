#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct interval{
	int begin;
	int end;
} Interval;

int main()
{
	int begin[]={1,4,7,10};
	int end[]={5,5,9,13};
	
	int newBegin[4]={0}, newEnd[4]={0};
	
	int i,j,e=-1;
	
	for(i=j=0;i<4;i++)
	{		
		if(begin[i]>e)
		{
			if(e>=0)
			{
				end[j]=e;
				printf("%d ",e);//d
				j++;
			}
			newBegin[j]=begin[i];
			printf("%d->",begin[i]);//d
			e=end[i];
		}
		else if (end[i]>e)
		{
			e=end[i];
		}
	}
	end[j]=e;
	printf("%d ",e);//d
	
	
}