#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#define IND(i,j) (i)*Nx + j
#define PI (3.141592653589793)
#define EXPORT 1

double timestamp(void){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return((double)(tp.tv_sec + tp.tv_usec/1000000.0));
}

void createScript(long int Nx, long int Ny, char *foutName){
   /*Funcao que cria script do gnuplot especifico para a dimensao dos dados em questao*/
   FILE *f = fopen("plot.gp","w");
   fprintf(f,"set xlabel 'x'\nset ylabel 'y'\nset zlabel 'u'\n");
   fprintf(f,"splot '%s' every %ld:%ld:0:0:%ld:%ld w lines title 'u(x,y)'\n",foutName,Nx/100,Ny/10-1, Nx,Ny);
   fprintf(f,"pause -1 \"Hit any key to continue\"\n");
   fclose(f);

}

int main(int argc, char **argv){

   /*Processamento inicial e checagem dos parametros*/
   if(argc != 11){
      fprintf(stderr,"Quantidade de argumentos incorretos!\n");
      return -1;
   }
   long int Nx, Ny, maxIter,i;
   char *method = malloc(10*sizeof(char));
   char *foutName = malloc(100*sizeof(char));


   for(i = 1; i < 10; i+=2){
      if(!strcmp(argv[i],"-nx"))
         Nx = atoi(argv[i+1]);
      else if(!strcmp(argv[i],"-ny"))
         Ny = atoi(argv[i+1]);
      else if(!strcmp(argv[i],"-i"))
         maxIter = atoi(argv[i+1]);
      else if(!strcmp(argv[i],"-m"))
         sprintf(method,"%s",argv[i+1]);
      else if(!strcmp(argv[i],"-o"))
         sprintf(foutName,"%s",argv[i+1]);
      else{
         fprintf(stderr,"%s Não é um argumento correto\n",argv[i]);
         return -1;
      }
   }

   double *u = malloc(Nx*Ny*sizeof(double));
   double *f = malloc(Nx*Ny*sizeof(double));
   double *resVector = malloc(maxIter*sizeof(double));
   long int it,j;
   double hx,hy,res,v;
   double k,cC,vC,hC;
   double t_main,t_res,t1,t2,t_ini,t_initial;
   double w;

   double v1,v2,v3,v4;
   double v_unroll[4],*udup,*udbot, final_time;

   /*Setando memoria*/
   memset(u,0,Nx*Ny*sizeof(double));
   memset(f,0,Nx*Ny*sizeof(double));
   memset(resVector,0,maxIter*sizeof(double));
   
   /*Definindo espacos*/
   hx = 2./(Nx-1);
   hy = 1./(Ny-1);
//   w = (2. - (hx+hy))/2.;
   w = 2. - (hx+hy)/2.;

   /*-laplac(u) + k^2 u= f(x)*/

   //Linha eh o x
   //coluna eh o y
   //p = y*Nx + x

   /*Definindo multiplicadores*/
   
   hC = 1./hy*hy;
   vC = 1./hx*hx;
   cC = 1./(2.*(hC + vC) + 4*PI*PI);


   /*Setando f*/
   for(j=0;j<Nx;++j){
      for(i=0;i<Ny;++i){
         *(f+IND(i,j)) = 4*PI*PI*sin(2*PI*hx*j)*sinh(2*PI*hy*i);
      }
   }
   /*Setando valores iniciais da borda de u*/
   for(j=0;j<Nx;++j)
      *(u + IND(Ny-1,j)) = sin(2*PI*hx*j)*sinh(2*PI);




   if(!strcmp(method,"gs")){
	t_initial = timestamp();
      for(it=0;it<maxIter;++it){
         t_ini = timestamp();   

         /*Resolvendo*/
         for(i=1;i<(Ny-1);++i){
            for(j=1;j<(Nx-1-4);j+=4){
		udup = u+IND(i+1,j  );
		udbot = u+IND(i-1,j  );
		v_unroll[0] = (udup[0]+udbot[0]) * vC ;
		v_unroll[1] = (udup[1]+udbot[1]) * vC ;
		v_unroll[2] = (udup[2]+udbot[2]) * vC ;
		v_unroll[3] = (udup[3]+udbot[3]) * vC ;
                *(u+IND(i,j))   = cC*( (*(u+IND(i,j-1))+*(u+IND(i,j+1))) * hC + v_unroll[0] + *(f + IND(i,j  )));
                *(u+IND(i,j+1)) = cC*( (*(u+IND(i,j  ))+*(u+IND(i,j+2))) * hC + v_unroll[1] + *(f + IND(i,j+1)));
                *(u+IND(i,j+2)) = cC*( (*(u+IND(i,j+1))+*(u+IND(i,j+3))) * hC + v_unroll[2] + *(f + IND(i,j+2)));
                *(u+IND(i,j+3)) = cC*( (*(u+IND(i,j+2))+*(u+IND(i,j+4))) * hC + v_unroll[3] + *(f + IND(i,j+3)));
	    }
	   /*Resto do loop unroll*/
            if(j!=(Nx-1))
   	       for(j=j;j<(Nx-1);++j){
                  *(u+IND(i,j)) = cC*( (*(u+IND(i,j-1))+*(u+IND(i,j+1))) * hC + (*(u+IND(i+1,j))+*(u+IND(i-1,j))) * vC + *(f + IND(i,j)));
		}
	}
         t1 = timestamp();

         /*Resíduo*/
         res = 0;
         for(i=1;i<(Ny-1);++i)
            for(j=1;j<(Nx-1);++j){
               v = + *(u+IND(i,j)) - cC*(  (*(u+IND(i,j-1))+*(u+IND(i,j+1)))*hC+ (*(u+IND(i+1,j))+*(u+IND(i-1,j)))*vC + *(f + IND(i,j)));
               res += v*v;
            } 
         resVector[it] = sqrt(res);

         /*Tempos*/
         t2 = timestamp();
         t_res += t2 - t1;
         t_main += t1 - t_ini;      
      }
	final_time = timestamp() - t_initial;
	printf("Final time %lf\n",final_time);
   }


   else if(!strcmp(method,"sor")){
      for(it=0;it<maxIter;++it){
         t_ini = timestamp();   

         /*Resolvendo*/
       	 for(i=1;i<(Ny-1);++i)
            for(j=1;j<(Nx-1);++j)
                *(u+IND(i,j)) = (1.-w)* *(u+IND(i,j)) +  w*cC*(  (*(u+IND(i,j-1))+*(u+IND(i,j+1))) * hC+ (*(u+IND(i-1,j))+*(u+IND(i-1,j))) * vC + *(f + IND(i,j)));
         t1 = timestamp();

         /*Resíduo*/
         res = 0;
         for(j=1;j<(Nx-1);++j)
            for(i=1;i<(Ny-1);++i){
               v = + *(u+IND(i,j)) - cC*(  (*(u+IND(i,j-1))+*(u+IND(i,j+1)))*hC+ (*(u+IND(i-1,j))+*(u+IND(i-1,j)))*vC + *(f + IND(i,j)));
               res += v*v;
            } 
         resVector[it] = sqrt(res);

         /*Tempos*/
         t2 = timestamp();
         t_res += t2 - t1;
         t_main += t1 - t_ini;      
      }
   
   }
   else{
      fprintf(stderr,"Metodo incorreto!\n");
      return -1;
   }
   /*Computando tempo medio*/
   t_res = t_res / (double) maxIter;
   t_main = t_main / (double) maxIter;


	
   /*-------------Exportando solucao---------------------------*/
   if(EXPORT){
	   FILE *fout = fopen(foutName,"w");
	   if(!fout){
	      fprintf(stderr,"%s Não é um arquivo de saida valido\n",foutName);
	      return -1;
	   }
	   fprintf(fout,"#######################\n# Tempo Método %s: %lf\n# Tempo Resíduo: %lf\n#\n# Norma do Resíduo\n",      method,t_main,t_res);
	   for(i=0; i < maxIter;i++){
	      fprintf(fout,"# i=%ld: %.19lf\n",i+1,resVector[i]);
	   }
	   fprintf(fout,"#######################\n");
   
	   for(i=0;i<Ny;i++)
	   {
	      for(j=0;j<Nx;j++)
	         fprintf(fout, "%lf %lf %lf\n",hx*j, hy*i, *(u + IND(i,j)));
   	   fprintf(fout,"\n");
	   }   
	   fclose(fout);
   }
   /* Se for plotar a solucao, descomentar 
      a chamada de funcao abaixo e usar o script
      plot.gp que ela gera.
   */
   createScript(Nx,Ny,foutName);
   /*----------------------------------------------------------*/

   /*Uso exclusivo timemean*/
	/*
   char s[100] = "Resultados/";
   strcat(s,foutName);
   FILE *ftime = fopen(s,"a+");
   fprintf(ftime,"%lf\n",final_time);
   fclose(ftime);
	*/
}
