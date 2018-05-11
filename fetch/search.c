#include "search.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 

void mountStructure(FILE *border_in, FILE *cont_in,  MainStruct *S){
	double x,y,Ox = 0, Oy = 0,d,theta,p_x,p_y,D;
	long int i, prev, next, j,N;
	/* alocando */
	S -> Border = malloc(sizeof(Point *));
	S -> Content = malloc(sizeof(Point *));
	S -> O = malloc(sizeof(Point));
	/* ------------ */

	/* valores iniciais */
	S -> D = -1;
	N = 0;
	/* ----------------- */

	/* lendo fronteira */
    	while(fscanf(border_in,"%lf %lf", &x, &y) != EOF){
	    	S -> Border = realloc(S -> Border,(N+1)*sizeof(Point *));
		S -> Border[N] = malloc(sizeof(Point));
		S -> Border[N] -> x = x;
		S -> Border[N] -> y = y;

		S -> Border[N] -> index = N; //indice para posteriormente linkar os vizinhos

		/* Distancia máxima */
		if(N > 0){
			D = sqrt( (p_x-x)*(p_x-x) + (p_y-y)*(p_y-y) );
			if(S -> D == -1 || D > S -> D)
				S -> D = D;
		}
		p_x = x;
		p_y = y;
		/* ---------------- */



		/* calculando ponto de origem para as coordenadas */
		Ox += x;
		Oy += y;
		/* ---- */		

	        N++;
	}
    	S -> NBorder = N;
	S -> O -> x = Ox/N;
	S -> O -> y = Oy/N;
	N= 0;
	for(i= 0; i < S -> NBorder; i++){
		d = sqrt( pow(S -> O -> x - S -> Border[i] -> x,2) + pow(S -> O -> y - S -> Border[i] -> y, 2) );

		theta =  asin(fabs(S -> O -> y - S -> Border[i] -> y)/d);

		if(S -> Border[i] -> y > S -> O -> y){
			if(S -> Border[i] -> x > S -> O -> x) //primeiro quadrante
				theta = theta;	
			else //segundo quadrante
				theta = PI - theta;
		}
		else{
			if( S -> Border[i] -> x < S -> O -> x) //terceiro quadrante
				theta = PI + theta;
			else //quarto quadrante
				theta = 2*PI - theta;
		}

		S -> Border[i] -> theta = theta;
		S -> Border[i] -> d = d;
		//printf("(%lf,%lf) d=%lf , theta=%lf\n",S -> Border[i] ->x,S -> Border[i] ->y,S -> Border[i] -> d,S -> Border[i] ->theta/G_TO_R);
	}	
	N = 0;
    	while(fscanf(cont_in," %lf %lf", &x, &y)!= EOF){
		//BROKEN?
	    	S -> Content = realloc(S -> Content,(N+1)*sizeof(Point *));
		S -> Content[N] = malloc(sizeof(Point));
		S -> Content[N]-> distancias = malloc(361*sizeof(double));
		S -> Content[N] -> x = x;
		S -> Content[N] -> y = y;
		d = sqrt( pow(S -> O -> x - x,2) + pow(S -> O -> y - y, 2) );
		theta =  asin(fabs(S -> O -> y - y)/d);
		if(y > S -> O -> y){
			if(x > S -> O -> x) //primeiro quadrante
				theta = theta;	
			else //segundo quadrante
				theta = PI - theta;
		}
		else{
			if(x < S -> O -> x) //terceiro quadrante
				theta = PI + theta;
			else //quarto quadrante
				theta = 2*PI - theta;
		}
		S -> Content[N] -> theta = theta;
		S -> Content[N] -> d = d;
	        N++;
		//printf("(%lf,%lf) d=%lf , theta=%lf\n",x,y,d,theta/G_TO_R);
	}
    	S -> NContent = N;
	mergeSort(S -> Border,0,S -> NBorder - 1);
	//printf("SORTED\n");
	for(i = 0; i < S -> NBorder; i++){
		if(S -> Border[i] -> index == 0)
			prev = S -> NBorder - 1;
		else
			prev = S -> Border[i] -> index-1;
		if(S -> Border[i] -> index == S -> NBorder -1)
			next = 0;
		else
			next =S -> Border[i] -> index  +1;
		for(j = 0; j < S -> NBorder; j++){
			if(S -> Border[j] -> index == prev)
				S -> Border[i] -> prev = S -> Border[j];
			else if(S -> Border[j] -> index == next)
				S -> Border[i] -> next = S -> Border[j];
		}
				
	}
	/*for(i = 0; i < S -> NBorder; i++)
		printf("(%lf,%lf) d=%lf , theta=%lf\n",S -> Border[i] ->x,S -> Border[i] ->y,S -> Border[i] -> d,S -> Border[i] ->theta/G_TO_R);*/
}
void merge(Point **vec, long int p, long int q, long int r){

	int mid, i,j,k;
	Point *tmp = (Point *) malloc((r + 1) *sizeof(Point));
	Point *N,*P;
	if (tmp == NULL) {
	  exit(1);
	}
 
	mid = q;
	for(i = p; i <= q; i++)
		tmp[i] = *vec[i];
	for(i = q + 1; i <= r; i++)
		tmp[r +q + 1 - i] = *vec[i];
	i = p;
	j = r;
	for(k = p; k <= r; k++){
		if(tmp[i].theta <= tmp[j].theta){
			*vec[k] = tmp[i++];
		}
		else{
			*vec[k] = tmp[j--];
		}

	}
	free(tmp);
}


void mergeSort(Point  **vec, long int ini, long int end) {
	long int mid;
	if (ini < end) {
	  mid = (end + ini) / 2;
	  mergeSort(vec,ini, mid);
	  mergeSort(vec, mid+1, end);
	  merge(vec, ini, mid, end);
	}
}


//revisar belongs to line!
double belongsToLine(Point *P1, Point *P2, Point *X,double theta_f){
	double t,tg_theta_f, w;
		tg_theta_f = tan(theta_f);
	if(theta_f == 0 || theta_f == 2*PI){
		if((  (fabs(P1 -> y - P2 -> y) <= EPSLON && fabs(P1 -> y - X -> y) <= EPSLON) || (P1 -> y >= X -> y && P2 -> y <= X -> y) || (P2 -> y >= X -> y && P1 -> y <= X -> y)) && (P1 -> x >= X -> x || P2 -> x >=  X -> x))
			return 1;//fix
		else
			return -1;
	}else if(theta_f == PI){
		if(((P1 -> y >= X -> y && P2 -> y <= X -> y) || (P2 -> y >= X -> y && P1 -> y <= X -> y)) && (P1 -> x <= X -> x || P2 -> x <=  X -> x))
			return 1;//fix
		else
			return -1;


	}else if(theta_f == PI/2){
		if(((P1 -> x >= X -> x && P2 -> x <= X -> x) || (P2 -> x >= X -> x && P1 -> x <= X -> x)) && (P1 -> y >= X -> y || P2 -> y >=  X -> y))
			return 1;//fix
		else
			return -1;
		

	}else if(theta_f == 3*PI/2){
		if(((P1 -> x >= X -> x && P2 -> x <= X -> x) || (P2 -> x >= X -> x && P1 -> x <= X -> x)) && (P1 -> y <= X -> y || P2 -> y <=  X -> y))
			return 1;//fix
		else
			return -1;
	}else if(P1 -> y == P2 -> y){
		w = (P1 -> y - X -> y)/tg_theta_f;
		t = ((X -> x - P1 -> x) + w)/(P2 -> x - P1 -> x);
	}else{
		//tg_theta_f = (P2 -> y - P1 -> y)/(P2 -> x - P1 -> x);
		t = (tg_theta_f*(P1 -> x - X -> x) + (X -> y - P1 -> y)) /(tg_theta_f*(P1 -> x - P2 -> x) + (P2 -> y - P1 -> y));
		w = P1 -> x - X -> x + t*(P2 -> x - P1 -> x);
	}
	if(0 <= t && t <= 1){
		if(theta_f >= PI/2 && theta_f <=3*PI/2){
			if(w <= 0)
				return sqrt( pow(P1 -> x + t * (P2 -> x - P1 -> x) - X -> x,2) + pow(P1 -> y + t * (P2 -> y - P1 -> y) - X -> y,2)) ;
			else
				return -1;
		}else{
			if(w >= 0)
				return sqrt( pow(P1 -> x + t * (P2 -> x - P1 -> x) - X -> x,2) + pow(P1 -> y + t * (P2 -> y - P1 -> y) - X -> y,2)) ;
			else
				return -1;
		}
	}
	else
		return -1;
	
}

void fullSearch(MainStruct *S, double g_ini, double g_end){
	unsigned int i,j,ind_grau,l;
	FILE *out = fopen("outf.dat","w");
	double theta_f,d,dmin;	
	for(i =0 ; i < S -> NContent; i++){
		ind_grau = 0;
		for(theta_f = g_ini; theta_f <= g_end; theta_f += G_TO_R){
			dmin = -1;
			for(j = 0 ; j < S -> NBorder; j++){

				d = belongsToLine(S -> Border[j], S -> Border[j] -> next, S -> Content[i], theta_f);

				if(d > 0 && ( dmin == -1 || dmin > d)){
					dmin = d;	
					S -> Content[i] -> xp1 = S -> Border[j] -> x;
					S -> Content[i] -> xp2 = S -> Border[j]->next -> x;
					S -> Content[i] -> yp1 = S -> Border[j] -> y;
					S -> Content[i] -> yp2 = S -> Border[j]->next -> y;
				}

				d = belongsToLine(S -> Border[j] -> prev, S -> Border[j], S -> Content[i], theta_f);

				if(d > 0 && ( dmin == -1 || dmin > d)){
					dmin = d;
					S -> Content[i] -> xp1 = S -> Border[j] -> prev -> x;
					S -> Content[i] -> xp2 = S -> Border[j] -> x;
					S -> Content[i] -> yp1 = S -> Border[j] -> prev -> y;
					S -> Content[i] -> yp2 = S -> Border[j] -> y;

				}
			}
			S -> Content[i] -> distancias[ind_grau] = dmin;
			ind_grau++;
		}
		S -> Content[i] -> d_med= 0;
                for(l = 0; l < ind_grau; l++)
                    S -> Content[i] -> d_med += S -> Content[i] -> distancias[l];
                S -> Content[i] -> d_med /= ind_grau;
	        fprintf(out,"%lf %lf %lf %lf %lf %lf %lf\n",S -> Content[i] -> x, S -> Content[i] -> y, S -> Content[i] -> d_med, S -> Content[i]->xp1,S -> Content[i]->yp1,S -> Content[i]->xp2,S -> Content[i]->yp2);
	}
	fclose(out);
}




void sonarSearch(MainStruct *S,double g_ini, double g_end){
	Point *X;
	FILE *out = fopen("out.dat","w");
	double theta_min, theta_max, delta_theta,theta_k_new,theta_k_old, theta_f,d,trash,theta_k_max,theta_k_min	;
	double dmin, dmax, dmin_new,dfmin;
	long int i,j,Sindex,not_found,Sindex_ini,ind_grau,l,found;
	//FODE DEPOIS DE TETA_F > 90 p teste 3
	for(i=0; i < S -> NContent;i++){
	        printf("Ponto %u\n",i);

		/* selecionando o ponto */
		X = S -> Content[i];
		/*----------------------*/

		/* Selecionando o ponto de borda cujo
		   angulo é < que 1 grau a menos que o ângulo do ponto x */
		Sindex_ini = 0;
		while(Sindex_ini < S -> NBorder && S -> Border[Sindex_ini] -> theta < X -> theta)
			Sindex_ini++;
        	if(Sindex_ini > 0)
	    		Sindex_ini--;
		/*-------------------------------------------------------*/


		/* definindo os limites do ângulo de busca 
		   para o ponto x, tais limites são usados para
		   decidir se a busca é no sentido horario ou anti horario*/
		if(X -> theta < PI){
			theta_min = X -> theta;
			theta_max = X -> theta + PI;
		}else{
			theta_min = X -> theta - PI;
			theta_max = X -> theta;
		}
		/*-------------------------------------------------------*/


		ind_grau = 0;
		for(theta_f = g_ini; theta_f <= g_end; theta_f += G_TO_R){
			/* limitação atual do modelo,
			   se o ângulo a ser buscado for igual ao ângulo
			   do ponto x, sai da função */			
			if(X -> theta == theta_f){
				printf("Fronteira do modelo\n");
				exit(-1);
			}
			/*----------------------------------*/
			if( (X -> theta < PI && theta_min < theta_f && theta_f < theta_max)||
			     (X -> theta >= PI && (theta_f > theta_max || theta_f < theta_min))){
				delta_theta = G_TO_R;
				Sindex = Sindex_ini;//se for == 0

			}else{
				delta_theta = -G_TO_R;
				Sindex = Sindex_ini-1;//se for == S -> NBorder?
			}

			/*	Calculando a coroa de busca
				theta_k_min e theta_k_max são os limitantes no ângulo
				e dmin e dmax são os limitantes radiais */
			theta_k_min = X -> theta - delta_theta;
			theta_k_max = X -> theta;
			findInterval(S,X,theta_k_min,theta_f,&dmin,&trash);	
			findInterval(S,X,theta_k_max,theta_f,&dmin_new,&dmax);	
			/*--------------------------------------------------------*/

			found = 0;
			dfmin = -1;

			while(1){
				if( (delta_theta > 0 &&  S -> Border[Sindex] -> theta > theta_k_max) || 
				    (delta_theta < 0 &&  S -> Border[Sindex] -> theta < theta_k_max)){//fim do quadrante
					//muda o quadrante
					dmin = dmin_new;
					theta_k_min += delta_theta;
					theta_k_max += delta_theta;
					if(theta_k_max <= 0)
						theta_k_max = 2*PI;
					if(theta_k_max >= 2*PI)
						theta_k_max = 0;
					findInterval(S,X,theta_k_max,theta_f,&dmin_new,&dmax);	

					//se ja achou algum ponto, retorne o melhor.
					if(found)
						break;
				}
				else{
					if(delta_theta > 0)
						Sindex++;
					else
						Sindex--;
					if(Sindex <0)
						Sindex = S -> NBorder - 1;
					else if(Sindex == S -> NBorder){
						Sindex = 0;
						theta_k_min = 0;
						theta_k_max = X -> theta - 2*G_TO_R;
					}
				}

				if(dmin <= S -> Border[Sindex] -> d && S -> Border[Sindex] -> d <= dmax){
					//printf("Ponto %u no quadrante\n",Sindex);
					//se o ponto esta dentro do quadrante
					d = belongsToLine(S -> Border[Sindex], S -> Border[Sindex] -> next, X, theta_f);

					if(d >= 0 && (dfmin == -1 || d < dfmin)){
						found = 1;
						X -> distancias[ind_grau] = d;
						X -> xp1 = S -> Border[Sindex] -> x;
						X -> yp1 = S -> Border[Sindex] -> y;
						X -> xp2 = S -> Border[Sindex] -> next -> x;
						X -> yp2 = S -> Border[Sindex] -> next -> y;
						dfmin = d;
					}
					d = belongsToLine(S -> Border[Sindex]->prev, S -> Border[Sindex], X, theta_f);
					if(d >= 0 && (dfmin == -1 || d < dfmin)){
						found = 1;
						X -> distancias[ind_grau] = d;
						X -> xp1 = S -> Border[Sindex] -> prev -> x;
						X -> yp1 = S -> Border[Sindex] -> prev -> y;
						X -> xp2 = S -> Border[Sindex] -> x;
						X -> yp2 = S -> Border[Sindex] -> y;
						dfmin = d;
					}

				}



			}
			ind_grau++;
		}
                for(l = 0; l < ind_grau; l++)
                    X -> d_med += X -> distancias[l];
                X -> d_med /= ind_grau;
            fprintf(out,"%lf %lf %lf %lf %lf %lf %lf\n",X -> x, X -> y, X -> d_med, X->xp1,X->yp1,X->xp2,X->yp2);
	}
    fclose(out);
}






void findInterval(MainStruct *S, Point *X, double theta_k, double theta_f, double *dmin, double *dmax){
	//reta f: x = 1, y = tg(theta_f)
	double a1,a2,xf,yf,xx,yx,a3;
	if(theta_f == PI/2){
		xf = 0;
		yf = 1;
	}else if(theta_f == 3*PI/2){
		xf = 0;
		yf =-1;
	}else if(theta_f == 0){
		xf = 1;
		yf = 0;
	}else if(theta_f == PI){
		xf =-1;
		yf = 0;
	}else{
		xf = 1;
		yf = tan(theta_f);
	}
	xx = S -> O -> x -  X -> x;  
	yx = S -> O -> y - X -> y;
	a1 = fabs(theta_k - X -> theta);
	a2 = acos(fabs(xx*xf + yx*yf)/sqrt( (xx*xx + yx*yx)*(xf*xf + yf*yf) ));//O menor angulo entre duas retas 
	a3 = PI - a1 - a2; //Soma dos angulos de um triangulo eh 180
	//sen(a3)/(dx - D) = sen(a2)/dmin regra dos senos
	*dmin = sin(a2)*(X -> d - S -> D) / sin(a3);
	//Angulo na outra reta = angulo na reta de cima (THALES)
	*dmax = *dmin + 2*S -> D / sin(a3);
	

}
	
