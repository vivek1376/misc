#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STUDENTNUM 100000
using namespace std;

int main()
{
  int N, rating,i,j,k;

  int *childRating=(int *)malloc(sizeof(int)*(STUDENTNUM+2));

  scanf("%d",&N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&childRating[i+1]);//index from 1

    }

  
  

