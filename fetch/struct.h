#ifndef STRUCT_H_GUARD_
#define STRUCT_H_GUARD_

#define PI 3.141592653589793
#define G_TO_R 0.017453292519943295
#define EPSLON 1e-5

typedef struct Point{
	double x;
	double y;
	double theta;
	double d;
	double *distancias;
    double d_med;
	long int index;
	struct Point *next;
	struct Point *prev;
	//Direcoes?
	double xp1;
	double yp1;
	double xp2;
	double yp2;
}Point;
typedef struct MainStruct{
	Point *O;
	int NBorder;
	int NContent;
	double D; //Distancia máxima entre pontos de borda
	Point **Border;
	Point **Content;
}MainStruct;
#endif
