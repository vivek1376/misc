#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
//    if(0.00011f==0.0001f)
//	printf("rr");

//    return 0;
  
    long int T,N,M,i,j,shopDisc[3],minShop;
    float finalPrice,minPrice;
    
    scanf("%ld",&T);

    while(T--)
    {
	scanf("%ld %ld",&N,&M);

	for(i=0;i<N;i++)
	{
	    minPrice=1.0f;
	    minShop=1010;
	    
	    /* for each shop */
	    for(j=0;j<M;j++)
	    {
		scanf("%ld %ld %ld",&shopDisc[0],&shopDisc[1],&shopDisc[2]);
		finalPrice=(float)(1-(float)shopDisc[0]/100)*(1-(float)shopDisc[1]/100)*(1-(float)shopDisc[2]/100);
		
		if(finalPrice<minPrice)
		{
		    minPrice=finalPrice;
		    minShop=j+1;
		}
		else if(finalPrice==minPrice && (j+1)<minShop)
		    minShop=j+1;
	    }
	    printf("%ld ",minShop);
	}
	putchar('\n');
    }
  
    return 0;	
}
