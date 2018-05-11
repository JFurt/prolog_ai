#ifndef SEARCH_H_GUARD
#define SEARCH_H_GUARD


	#include "struct.h"
    #include <stdio.h>
	void mergeSort(Point  **vec, long int ini, long int end);
	void merge(Point **vec, long int p, long int q, long int r);
	void mountStructure(FILE *border, FILE *content, MainStruct *S);
	double belongsToLine(Point *P1, Point *P2, Point *X,double theta_f);
	void sonarSearch(MainStruct *S,double g_ini, double g_end);
void findInterval(MainStruct *S, Point *X, double theta_k, double theta_f, double *dmin, double *dmax);
void fullSearch(MainStruct *S, double g_ini, double g_end);

#endif
