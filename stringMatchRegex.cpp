/* http://www.geeksforgeeks.org/wildcard-character-matching/ */

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void cmpStrRegex(char *str1, char *regex, int (*res)[10]);

int res[10][10];

int main()
{
    char st1[]="vivek",rexp[]="v*v*";
    int i,j;

    /* intialisation */
    for(i=0; i<10; i++)
	for(j=0;j<10;j++)
	    res[i][j]=-1;
    
    cmpStrRegex(st1, rexp, res);
    
    printf("%d\n",res[strlen(st1)-1][strlen(rexp)-1]);
    
    return 0;
}

void cmpStrRegex(char *str1, char *regex, int (*res)[10])
{
    int i,sLen,rLen;

    printf("%s %s\n",str1, regex);//d
    
    sLen=strlen(str1);
    rLen=strlen(regex);

    /* base condition */
    if (rLen==0 && sLen==0)
    {
	res[0][0]=0;
	return;		/* valid */
    }
    
    else if (rLen==0 && sLen!=0)
	return;

    else if (regex[0]=='*' && regex[1]=='\0')
    {
	return;
    }
    
    else if (regex[0]=='*' && regex[1]!='\0')
    {
	for(i=0; i<=sLen; i++)
	    return cmpStrRegex(str1+i, regex+1, &res[i][1]);
    }

    else if (regex[0]!='*' && sLen==0)
	return;
    
    else if(regex[0]!='*' && regex[0]!='?' && regex[0]!=str1[0])
	return;

    else if (regex[0]!='*' && regex[0]!='?' && regex[0]==str1[0])
	return cmpStrRegex(str1+1, regex+1, &res[1][1]);

    else if (regex[0]=='?')
	return cmpStrRegex(str1+1, regex+1, &res[1][1]);

	/*
    for(i=0; i<len1; i++)
    {


	else if (regex[i]!='*' && regex[i]!='?' && regex[i]==str1[p1])
	    cmpStrRegex(str1+1, regex+1, p1+1);

	else if(regex[i]=='*')
	{
	    for(j=p1+1, j<len1;j++)
		cmpStrRegex(str1+j, regex+1, 
	}
	    
	}*/
}
