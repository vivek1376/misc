#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}point;

int doOverlap(point l1, point r1, point l2, point r2);

int main()
{
    point
	l1={1,2},
	r1={2,1},
	l2={1,2},
	r2={4,1};

    printf("%d\n",doOverlap(l1,r1,l2,r2));

    return 0;
}

int doOverlap(point l1, point r1, point l2, point r2)
{
    int ifOverlap=1;

    if (r1.x<l2.x || r2.x<l1.x)
	ifOverlap=0;

    if (l1.y<r2.y || l2.y<r1.y)
	ifOverlap=0;

    return ifOverlap;
}
