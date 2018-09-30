#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	clock_t start, end;
  	FILE* fp;
        int bufSize = strtol(argv[2], NULL, 10);
        int buf[bufSize]; 
        double cpu_time_used;
        int temp_i,temp_j;
        int p[bufSize];
	start = clock();
	MPI_Init(&argc, &argv);
        
        //read file
        fp = fopen(argv[1], "rb");
        fread(buf, sizeof(buf), 1, fp);  
                                                  
        for (int i = 0; i < bufSize; i++) {
            p[i] = buf[i];
        } 
        fclose(fp);

        unsigned long long int m[bufSize][bufSize];
        memset( m, 0, bufSize*bufSize*sizeof(unsigned long long int) );
	int s[bufSize][bufSize];
        memset( s, 0, bufSize*bufSize*sizeof(int) );
	int j;
        unsigned long long int q,min;
        
        for(int d=1;d<bufSize-1;d++){
              for(int i=1;i<bufSize-d;i++){
                   j=i+d;
                   min=1000000000000000000;
                   temp_j = p[j];
                   temp_i = p[i-1];
                   for(int k=i;k<=j-1;k++){
                         q=(unsigned long long int)m[i][k]+(unsigned long long int)m[k+1][j]+(unsigned long long int)temp_i*(unsigned long long int)p[k]*(unsigned long long int)temp_j;
                         //printf("q: %lli m[i][k]: %lli m[k+1][j]: %lli temp_i: %d p[k]: %d temp_j: %d\n x: %llu\n",q,m[i][k],m[k+1][j],temp_i,p[k],temp_j,(unsigned long long int)m[i][k]+(unsigned long long int)m[k+1][j]+(unsigned long long int)temp_i*(unsigned long long int)p[k]*(unsigned long long int)temp_j);
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
        printf("minimum: %llu time: %lf\n",m[1][bufSize-1],cpu_time_used); 
  	MPI_Finalize();

	return 0;
}

 
