#include <cstdio>
#include <cstring>
#include <cstdlib>

#define STRLEN 10000
using namespace std;

int main()
{
  
  char A[STRLEN+1],B[STRLEN+1],*temp,*temp1;
  int countA[26]={0},countB[26]={0},i,ans=0;

  scanf("%s",A);
  scanf("%s",B);

  temp=A;
  while(*temp)
    {
      countA[*temp-97]++;
      temp++;
    }


  temp=B;
  while(*temp)
    {
      countB[*temp-97]++;
      temp++;
    }
  
  for(i=0;i<26;i++)
    {
      ans+=abs(countA[i]-countB[i]);
    }

  printf("%d",ans);

  return 0;
}
