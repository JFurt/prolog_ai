#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include "math.h"


#define PI 3.141592653589793
#define BLACK(i,j) (((i)*Nx)>>1) + ((j)>>1) + halfNy*Nx + Nxm2*halfNx
#define RED(i,j) (((i)*Nx)>>1) + ((j)>>1) + Nxm2*((i)&1)
int Ny,Nx;
int tNy,tNx;
int rNy, rNx;
double hx,hy;
double k;
double verCoef, horCoef,cC;
double *f, *u,*pu,*t;
double execTime;
long int mxIt, NT;
double initTime;
void jacobi();
void rbgauss_seidel();
void writeGnuplotScript();




int main(int argc, char **argv){
   char *j_g;


   FILE *ftime = fopen("Resultados/time.txt","a");

	/* Test */
	Nx  = 8;
	Ny  = 8;
   mxIt= 20;//Defining maximum number of iterations
	/*-------*/

   if(argc == 6){
      tNx = atoi(argv[1]);
      tNy = atoi(argv[2]);
      NT = atoi(argv[3]);
      mxIt = atoi(argv[4]);
      j_g = argv[5];
   }else{
      printf("Parâmetros incorretos. Usar %s nx ny t c [j|g]\n",argv[0]);
      exit(-1);
   }
	/* Adjusting Nx */
	Nx = tNx+1;
	Ny = tNy+1;

   /* Defining hx */
	hx=2.0/tNx;
	hy=1.0/tNy;
   /*-------------*/

   /*Defining Coefficients*/
	k = 2*PI;
   verCoef = -1/(hy*hy);
   horCoef = -1/(hx*hx);
   cC = 2/(hx*hx) + 2/(hy*hy) + k*k;
   /*---------------------*/

   printf("\nResolvendo a PDE:\n");
   printf("Discretizacao: %dx%d\n",tNx,tNy);
   printf("Numero de threads: %ld\n",NT);
	if(!strcmp(j_g,"j")){
      printf("Metodo: Jacobi.\n");
		jacobi();
   }
	if(!strcmp(j_g,"g")){
      printf("Metodo: Gauss-Seidel.\n");
		rbgauss_seidel();
   }

	int i,j;
   double v,res=0; //Residue
   FILE *fout = fopen("Resultados/solution.txt","w+"); 
   // Export u 
	for(i=0;i<Ny;i++){
		for(j=0;j<Nx;j++)
			fprintf(fout,"%lf %lf %lf\n",j*hx, i*hy, *(u + i*Nx + j));
      fprintf(fout,"\n");
	}
   fclose(fout);

   // Calculate Residue 

	res = 0;
	for(i=1;i<(Ny-1);i++){
		for(j=1;j<(Nx-1);j++){
         v = *(f + i*Nx + j) - cC * *(u + i*Nx + j) - horCoef*( *(u+i*Nx+j-1) + *(u+i*Nx+j+1) ) - verCoef*( *(u+(i+1)*Nx+j) + *(u+(i-1)*Nx+j) );
			res += v*v;
		}
	}
   printf("Residuo %lf\n",sqrt(res));



	//writeGnuplotScript();
   fprintf(ftime,"%ld\t%lf\n",NT,execTime);
   fclose(ftime);
   return 0;
}

void jacobi(){
	int i,j,it;
	double tC, bC, rC, lC;
	tC = bC = verCoef;
	rC= lC = horCoef;


   /*Defining right side b (f)*/
	f=malloc(Nx*Ny*sizeof(double));
	for(i=0;i<Ny;i++){
		for(j=0;j<Nx;j++){
			*(f + i*Nx + j)=4*PI*PI*sin(k*j*hx)*sinh(k*i*hy);  
		}
	}
   /*--------------------------*/

   /*Defining initial u*/
	u=malloc(Nx*Ny*sizeof(double));
   pu=malloc(Nx*Ny*sizeof(double));
   memset(u,0,Nx*Ny*sizeof(double));
   for(j=0;j<Nx;j++){
      *(u+(Ny-1)*Nx + j) = sin(2*PI*hx*j)*sinh(2*PI);
   }
   memcpy(pu,u,Nx*Ny*sizeof(double));

   /*--------------------------*/
   initTime = omp_get_wtime();
   for(it = 0; it < mxIt;it++){
      t  = pu;
      pu =  u;
      u  =  t;
      #pragma omp parallel for num_threads(NT) firstprivate(cC,tC,bC,lC,rC,Nx,Ny,u,pu) private(i,j)
      for(i=1;i<Ny-1;i++){
         for(j=1;j<Nx-1;j++){
              *(u + i*Nx + j) = (*(f + i*Nx + j) - (tC* *(pu+(i+1)*Nx + j) + bC* *(pu+(i-1)*Nx + j) + lC* *(pu+i*Nx + j-1) + rC* *(pu+i*Nx + j+1)) )/cC;   //u[i][j]
         }
      }
   }
   printf("Tempo de execucao do metodo: %lf\n",omp_get_wtime() - initTime);
}


void rbgauss_seidel(){
	int it = 0;
	double *rb_u = malloc(Nx*Ny*sizeof(double));
	f = malloc(Nx*Ny*sizeof(double));
	u = malloc(Nx*Ny*sizeof(double));
   initTime = omp_get_wtime();
	#pragma omp parallel num_threads(NT) firstprivate(Nx,Ny,hx,hy,horCoef,verCoef,cC) shared(it,rb_u,f)
	{
		int i_ini_red, j_ini_red, i_fin_red, j_fin_red;
		int i_ini_black, j_ini_black, i_fin_black, j_fin_black;
		int c_ini, c_fin;
		int id,numThreads, NxmNT;
   	int halfNx = ceil((double) Nx/2.);
	   int halfNy = Ny/2.;
		int i,j;
		double totalSize;
   	int desl_red = ceil((double) Nx/2.);
   	int desl_black = floor((double) Nx/2.);
		int b_ex;
		int Nxm2 = Nx%2;
		int v;
		id = omp_get_thread_num();
	 	numThreads = omp_get_num_threads();


		horCoef = horCoef/cC;
		verCoef = verCoef/cC;

		/*****************************************
			* Setup and Initialization of RB matrix
		******************************************/

		/* Red Setup for Initialization */
		totalSize = ceil(Nx*Ny/2.);
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads );
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_red = floor( 2. / Nx * c_ini);
		j_ini_red = (i_ini_red%2 + (c_ini%Nx)*2)%Nx - (i_ini_red%2)*(Nx%2);

		i_fin_red = floor( 2. / Nx * c_fin);
		j_fin_red = (i_fin_red%2 + (c_fin%Nx)*2)%Nx - (i_fin_red%2)*(Nx%2);
		/* End setup */

		/*Initialize Red*/
		j = j_ini_red;
		for(i=i_ini_red;i<=i_fin_red;i++){
			while(j < Nx && (i < i_fin_red || j < j_fin_red)){
				if( i == Ny-1 ){
				   *(rb_u + RED(i,j)) = sin(2.*PI*hx*j)*sinh(2*PI);
				}
				else{
				   *(rb_u + RED(i,j)) = 0;
				}
				*(f + i*Nx + j)=4*PI*PI*sin(k*j*hx)*sinh(k*i*hy)/cC;
				j+=2;
			}
			j = (i+1)%2; //2 - i%2;
		}
		/* End of red Initialization */

		/* Setup Black Initialization */
		totalSize = floor(Nx*Ny/2.);
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads );
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_black = floor( 2. / Nx * c_ini +  1./Nx+1e-10);
		j_ini_black = ( ((i_ini_black + 1)%2) + ((c_ini+halfNx)%Nx)*2)%Nx - ((i_ini_black + 1)%2)*Nx%2;

		i_fin_black = floor( 2. / Nx * c_fin +  1./Nx+1e-10);
		j_fin_black = ( ( (i_fin_black + 1)%2) + ((c_fin+halfNx)%Nx)*2)%Nx - ((i_fin_black + 1)%2)*Nx%2;
		/* End of black setup */

		/*Initialize Black*/
		j = j_ini_black;
		for(i=i_ini_black;i<=i_fin_black;i++){
			while(j < Nx && (i < i_fin_black || j < j_fin_black)){
				if( i == Ny-1 ){
				   *(rb_u + BLACK(i,j)) = sin(2.*PI*hx*j)*sinh(2*PI);
				}
				else{
				   *(rb_u + BLACK(i,j)) = 0;
				}
				*(f + i*Nx + j)=4*PI*PI*sin(k*j*hx)*sinh(k*i*hy)/cC;
				j+=2;
			}
			j = i%2;
		}
		/* End of black Initialization */

		/*******************************************
		*** Initiating Values for the main Loop ****
		*******************************************/

		/* Red Initialization */
		totalSize = ceil(Nx*Ny/2.)  - desl_red - desl_red;
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id + desl_red;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads ) + desl_red;
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_red = floor( 2. / Nx * c_ini);
		j_ini_red = (i_ini_red%2 + (c_ini%Nx)*2)%Nx - (i_ini_red%2)*(Nx%2);

		i_fin_red = floor( 2. / Nx * c_fin);
		j_fin_red = (i_fin_red%2 + (c_fin%Nx)*2)%Nx - (i_fin_red%2)*(Nx%2);
		/* End of red Initialization */

		/* Black Initialization */
		totalSize = floor(Nx*Ny/2.) - desl_black  - desl_black;
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id + desl_black;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads ) + desl_black;
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_black = floor( 2. / Nx * c_ini +  1./Nx+1e-10);
		j_ini_black = ( ((i_ini_black + 1)%2) + ((c_ini+halfNx)%Nx)*2)%Nx - ((i_ini_black + 1)%2)*Nx%2;

		i_fin_black = floor( 2. / Nx * c_fin +  1./Nx+1e-10);
		j_fin_black = ( ( (i_fin_black + 1)%2) + ((c_fin+halfNx)%Nx)*2)%Nx - ((i_fin_black + 1)%2)*Nx%2;
		/* End of black Initialization */

		/***********************************
		*** Main Loop **********************
		***********************************/
	

		/*Main loop*/
		b_ex = 1;
		while(b_ex){
			#pragma omp single
			{  it++; }
			b_ex = it < mxIt;
			/*Red loop*/
			j = j_ini_red;
			for(i=i_ini_red;i<=i_fin_red;i++){
				while(j < (Nx-1) && (i < i_fin_red || j < j_fin_red)){
					v = BLACK(i,j-1);
					*(rb_u+RED(i,j)) = *(f + i*Nx + j) - verCoef*( *(rb_u+v + halfNx + !Nxm2 * ( (i+1)&1)) + *(rb_u+v - halfNx + Nxm2+ !Nxm2 * ( (i+1)&1))  ) - horCoef* ( *(rb_u + v) + *(rb_u + v+1));
					j+=2;
				}
				/* Eliminando contorno lateral */
				j = 2-((i+1)&1);
			}

			/*Black loop*/
			j = j_ini_black;
			for(i=i_ini_black;i<=i_fin_black;i++){
				while(j < (Nx-1) && (i < i_fin_black || j < j_fin_black)){
					v=RED(i,j-1);
					*(rb_u+BLACK(i,j)) = *(f + i*Nx + j)- verCoef*( *(rb_u+v + halfNx - !Nxm2 * ( i&1)) + *(rb_u+v - halfNx  +Nxm2 - !Nxm2 * ( i&1)) ) - horCoef * ( *(rb_u + v) + *(rb_u + v+1) );
					j+=2;
				}
				/* Eliminando contorno lateral */
				j = ((i+1)&1) + 1;
			}
		}
		/*****************************************
			* Converting RB to U
		******************************************/

		/* Red Setup for Convertion */
		totalSize = ceil(Nx*Ny/2.);
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads );
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_red = floor( 2. / Nx * c_ini);
		j_ini_red = (i_ini_red%2 + (c_ini%Nx)*2)%Nx - (i_ini_red%2)*(Nx%2);

		i_fin_red = floor( 2. / Nx * c_fin);
		j_fin_red = (i_fin_red%2 + (c_fin%Nx)*2)%Nx - (i_fin_red%2)*(Nx%2);
		/* End setup */

		/*Convert Red*/
		j = j_ini_red;
		for(i=i_ini_red;i<=i_fin_red;i++){
			while(j < Nx && (i < i_fin_red || j < j_fin_red)){
				*(u + i*Nx + j) = *(rb_u + RED(i,j));		
				j+=2;
			}
			j = (i+1)%2; //2 - i%2;
		}
		/* End of red Convertion */

		/* Setup Black Convertion */
		totalSize = floor(Nx*Ny/2.);
		NxmNT = (int) totalSize %numThreads;

		if(id < NxmNT){
			c_ini = ceil( totalSize / numThreads )*id;
			c_fin = c_ini + ceil( totalSize / numThreads );
		}if(id >= NxmNT){
			c_ini = ceil( totalSize / numThreads )*NxmNT + (id-NxmNT)*floor( totalSize / numThreads );
			c_fin = c_ini + floor( totalSize / numThreads );
		}


		i_ini_black = floor( 2. / Nx * c_ini +  1./Nx+1e-10);
		j_ini_black = ( ((i_ini_black + 1)%2) + ((c_ini+halfNx)%Nx)*2)%Nx - ((i_ini_black + 1)%2)*Nx%2;

		i_fin_black = floor( 2. / Nx * c_fin +  1./Nx+1e-10);
		j_fin_black = ( ( (i_fin_black + 1)%2) + ((c_fin+halfNx)%Nx)*2)%Nx - ((i_fin_black + 1)%2)*Nx%2;
		/* End of black convertion */

		/*Convert Black*/
		j = j_ini_black;
		for(i=i_ini_black;i<=i_fin_black;i++){
			while(j < Nx && (i < i_fin_black || j < j_fin_black)){
				*(u + i*Nx + j) = *(rb_u + BLACK(i,j));
				j+=2;
			}
			j = i%2;
		}
		/* End of black Convert */


	}
   execTime = omp_get_wtime() - initTime;
	printf("Fim da zona paralela\n");
	int i,j;
	for(i=0;i<Ny;i++){
		for(j=0;j<Nx;j++){
			*(f + i*Nx + j)=*(f + i*Nx + j)*cC;  
		}
	}
   printf("Tempo de execucao do metodo: %lf\n",execTime);

}

/*void writeGnuplotScript(){
	FILE *fscr = fopen("plot_sol.plt","w");
	fprintf(fscr,"set terminal wxt enhanced font 'Verdana,10' persist\n");
	fprintf(fscr,"set dgrid3d %d,%d\n",50+Nx%2,50+Nx%2);
//	fprintf(fscr,"set hidden3d\n");
	fprintf(fscr,"set xlabel \"x\"\nset ylabel \"y\"\nset zlabel \"u(x,y)\"\nset grid lt -1 lw 1 ls -1 lc rgb '#808080'\n");
	fprintf(fscr,"set view 56,42\n");
	fprintf(fscr,"splot \"out.txt\"  u 2:1:3 notitle w lines\n");
	fclose(fscr);
}*/

