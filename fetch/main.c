#include "search.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	double d;
	int i;
	Point *p = (Point *)malloc(100*sizeof(Point));

/*	for(i = 0; i < 100; i++)
		if( i < 50)
			p[i].theta = 100 -i;
		else
			p[i].theta = 100 + i;

	mergeSort(&p,0,99);
	for( i = 0; i < 100; i++)
		printf(" %lf\n",p[i].theta);


	Point P1,P2,X;
	P1.x = 0; P1.y = 0;
	P2.x = 1; P2.y = 0;
	X.x = 0.5; X.y = 0.8660254037844384; X.theta = PI/3; X.d =1;
	for(d = 0; d < PI; d += G_TO_R)
		printf("%lf ----  %ld\n",d,belongsToLine(&P2,&P1,&X,d));// aparentemente a ordem dos pontos não altera o resultado
*/
	MainStruct S;
    FILE *border, *content;
    border = fopen("contorno.txt","r");
    content = fopen("content.dat","r");
	mountStructure(border,content,&S);
	printf("%u\n",S.NContent);
	//sonarSearch(&S,PI/4,PI/4);
	fullSearch(&S,PI/4-5*G_TO_R,PI/4+5*G_TO_R);
}

