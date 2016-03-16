#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int arr1[]={1,4,5,9,14,20,22}, arr2[]={2,3,4,6,9,11,14,20,21,25};
	
	int i,j,k,l,count,len1=7,len2=10;
	
	i=j=count=0;
	while(i<len1 && j<len2)
	{
		if(arr1[i]==arr2[j])
		{
			count++;
			i++;
			j++;
		}
		else if (arr1[i]<arr2[j])
			i++;
		else if (arr1[i]>arr2[j])
			j++;
	}
	/*
	for(i=0; i<len1;)
	{
		for(j=0; j<len2; j++)
		{
			if(arr1[i]==arr2[j])
			{
				count++;
			}
			else if(arr1[i]<arr2[j])
			{
				
			}
		}
	}*/
	
	printf("%d\n",count);	
	return 0;
}