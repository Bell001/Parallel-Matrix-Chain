#include <stdio.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char *argv[]){

	clock_t start, end;
        double cpu_time_used;
        int  d1,d2,d3,d4,d5;
        int temp_i,temp_j;
	start = clock();
	MPI_Init(&argc, &argv);
        //printf("Enter dimension of matrix:  ");
        //scanf("%d %d %d %d %d",&d1,&d2,&d3,&d4,&d5);
        d1 = 1048;
        d2 = 3470;
        d3 = 9437;
        d4 = 2842;
	int n = 4;
	int p[] = {d1,d2,d3,d4};
	unsigned long long int m[4][4] = {0};
	int s[4][4] = {0};
	int j,min;
        double q;
        
        for(int d=1;d<n-1;d++){
              for(int i=1;i<n-d;i++){
                   j=i+d;
                   min=32767;
                   temp_j = p[j];
                   temp_i = p[i-1];
                   for(int k=i;k<=j-1;k++){
                         q=m[i][k]+m[k+1][j]+temp_i*p[k]*temp_j;
                         printf("q: %llu m[i][k]: %d  m[k+1][j]: %d temp_i: %d p[k]: %d temp_j: %d\n",q,m[i][k],m[k+1][j],temp_i,p[k],temp_j);
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
        printf("min: %llu time: %lf\n",m[1][n-1],cpu_time_used); 
      
  	MPI_Finalize();

	return 0;
}
