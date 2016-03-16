// print union and intersection of two arrays
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(x,y)  ((x)<(y)?(x):(y))

int main()
{
    int arr1[]={1,4,6,14,24,82}, arr2[]={1,6,24,78},
    len1=sizeof(arr1)/sizeof(arr1[0]),
    len2=sizeof(arr2)/sizeof(arr2[0]),
    i,j,k,m,n,
    *unionArr=(int *)malloc(sizeof(int)*(len1+len2)),
    *isecArr=(int *)malloc(sizeof(int)*(MIN(len1,len2)));
    printf("len1: %d   len2: %d\n",len1,len2);//d

    i=j=m=n=0;
    while(i<len1 || j<len2)
    {
        if(i>=len1)
            unionArr[m++]=arr2[j++];
        else if (j>=len2)
            unionArr[m++]=arr1[i++];
        else if(arr1[i]<arr2[j])
            unionArr[m++]=arr1[i++];
        else if (arr1[i]>arr2[j])
            unionArr[m++]=arr2[j++];
        else if (arr1[i]==arr2[j])
        {
            unionArr[m++]=arr1[i];
            isecArr[n++]=arr1[i];
            i++;
            j++;
        }
    }

    printf("\nUnion: ");
    for(i=0;i<m;i++)
        printf("%d ",unionArr[i]);

    printf("\nIntersection: ");
    for(i=0;i<n;i++)
        printf("%d ",isecArr[i]);

    return 0;
}
