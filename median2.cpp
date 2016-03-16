
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int findCombinedMedian(int *array1, int *array2, int len);

int main()
{
	int arr1[]={2,4,8,9}, arr2[]={1,1,1,2};
	printf("%d\n",findCombinedMedian(arr1,arr2,4));
	
	return 0;
}

int findCombinedMedian(int *array1, int *array2, int len)
{
	int i,j,k,l,med,p,temp,u, *arr1, *arr2;
	
	//l1=size1,l2=size2;
	
	for(u=0;u<2;u++)
	{
		i=0,j=len-1;
		
		//first try with arr1, if fails then with arr2
		(u==0)?(arr1=array1,arr2=array2):(arr1=array2,arr2=array1); //reverse arrays
		
		while(i<=j)
		{
			//first try ot find final median in arr1
		
			k=(i+j)/2;//position of median in array1
			med=arr1[k];
			
			p=len-k-1; //med1 should be just greater than p elements in arr2
	
			if (p==0)
			{
				if(med<=arr2[0])
					return med;
				else
					j=k-1;
			}
			else if(p==len)
			{
				if(med>=arr2[len-1])
					return med;
			}
			else if(med>=arr2[p-1] && med<=arr2[p])
				return med;
				//printf("median: %d\n",med1);
			else if (med>arr2[p])
				//now, median could possibly be left to med1's position
				j=k-1;
			else if (med<arr2[p-1])
				i=k+1;
		}
	}
}