/* breaks IP addr string into octets <vivek.1376(at)gmail.com> */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _P2I(p) (unsigned long int)(p)

char* splitOctet(char *, char **);

int main()
{
    char ip[]="192.168.1.132";
    char *p=ip, **octet=(char **)malloc(4*sizeof(char *));

    int i=0;
    while((p=splitOctet(p, &octet[i]))!=NULL)
	i++;

    for(i=0;i<4;i++)
	printf("%s\n",octet[i]);

    return 0;
}

char* splitOctet(char *ipStr, char **octet)
{
    char *p=ipStr;

    while(*p!='.' && *p!='\0')
	p++;
    
    unsigned long int count=_P2I(p)-_P2I(ipStr);

    *octet=(char *)malloc((count+1)*sizeof(char));
    strncpy(*octet,ipStr,count);

    *(*octet+count)='\0';

    return (*p?++p:NULL);
}
