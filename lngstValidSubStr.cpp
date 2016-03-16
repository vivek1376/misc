/* 
   http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
   
   Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring 
   naive solution: iterate over all possible substring and check if all parantheses match */

#include <iostream>
#include <cstdio>
#include <cstring>
//#include <stack>

using namespace std;

int main()
{
    char inStr[]="()(()))))";
    char temp[20];
    int i,j,k,len,brkt,p,q,r,s,validCnt,unbalanceFlag=0;

    len=strlen(inStr);
    //printf("len: %d\n",len);//d

    validCnt=0;
    for(i=0;i<len;i++)
	for(j=i;j<len;j++)
	{			/* check if sub-str valid */
	    brkt=unbalanceFlag=0;		/* initialise */
	    
	    for(p=i;p<=j;p++)
	    {
		if(inStr[p]=='(')
		    brkt++;
		else if (inStr[p]==')' && brkt>0)
		    brkt--;
		else		/* unbalanced closing parantheses */
		    unbalanceFlag=1;
	    }

	    if(brkt==0 && unbalanceFlag==0)
	    {
		strncpy(temp, inStr+i,j-i+1);
		temp[j-i+1]='\0';
		
		printf("str: %s\n",temp);
		validCnt++;
	    }
	}


    printf("total valid: %d\n",validCnt);

    return 0;
}
