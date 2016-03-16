#include <cstdlib>
#include <cstdio>

using namespace std;

char line[1000];

int main()
{
    int n,offset=0;
    char *p;
//    gets(line);
//    printf("%s\n",line);

    while(gets(line))
//    printf("%s\n",line);
    {
	p=line;
	while(sscanf(p,"%d%n",&n,&offset)==1)
	{
	    printf("%d ",n);
	    p+=offset;
	}
	printf("\n");
//	fflush(stdin);
    }

    printf("\n");

    return 0;
}
    
