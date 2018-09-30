#include <stdio.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char *argv[]){

	clock_t start, end;
        double cpu_time_used;
        int  d1,d2,d3,d4,d5;

	start = clock();
	MPI_Init(&argc, &argv);
        //printf("Enter dimension of matrix:  ");
        //scanf("%d %d %d %d %d",&d1,&d2,&d3,&d4,&d5);
        d1 = 20;
        d2 = 100;
        d3 = 100;
        d4 = 50;
        d5 = 70;
	int n = 5;
	int p[] = {d1,d2,d3,d4,d5};
	int m[5][5] = {0};
	int s[5][5] = {0};
	int j,min,q;
        
        for(int d=1;d<n-1;d++){
              for(int i=1;i<n-d;i++){
                   j=i+d;
                   min=32767;
                   for(int k=i;k<=j-1;k++){
                         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                         if(q<min){
                               min=q;
                               s[i][j] = k;
                         }
                   }
                   m[i][j] = min;
              }
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("min: %d time: %f\n",m[1][n-1],cpu_time_used); 
      
  	MPI_Finalize();

	return 0;
}
