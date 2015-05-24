#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));

    int freq[13]={0},i,j,val;
    float freqPerc[13]={0.0f};

    unsigned long long int sum=0;

/*
    for(i=0;i<1000000;i++)
    {
	val=rand()%12+1;
	
	freq[val]++;

	for(j=1;j<=12;j++)
	    freqPerc[j]=((float)freq[j]/(i+1))*100.0f;
    }

    for(j=1;j<=12;j++)
	printf("%d %f\n",j,freqPerc[j]);
*/
    int freqBox[4]={0},fBox[4]={0},count=0,mul=0;

    for(i=0;i<10000000;i++)
    {
	freqBox[1]=0;
	freqBox[2]=0;
	freqBox[3]=0;
	freqBox[0]=0;

	for(j=0;j<12;j++)
	{
	    val=rand()%3+1;
	    freqBox[val]++;
	    
	    fBox[val]++;
	}

	if(freqBox[1]==3 || freqBox[2]==3 || freqBox[3]==3)
	{
	    count++;
	    
	    if((freqBox[1]==3 && freqBox[2]==3) ||
	       (freqBox[1]==3 && freqBox[3]==3) ||
	       (freqBox[2]==3 && freqBox[3]==3))
		mul++;
	}
	
/*	if((freqBox[1]==3 && freqBox[2]!=3 && freqBox[3]!=3) ||
	   (freqBox[2]==3 && freqBox[1]!=3 && freqBox[3]!=3) ||
	   (freqBox[3]==3 && freqBox[1]!=3 && freqBox[2]!=3))
	   count++;*/

//	printf("P: %f\n",(float)count/(i+1));
//	usleep(50000);
    }
    printf("count: %d\tmul: %d\n",count,mul);
    printf("P: %f\n",(float)count/(float)i);

    printf("BOXES: %f  %f  %f\n",(float)fBox[1]/(i*12),(float)fBox[2]/(i*12),(float)fBox[3]/(i*12));

    //freqPerc[j]=((float)freq[j]/i+1)*100.0f;
    
    return 0;
}

		   
