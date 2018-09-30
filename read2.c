#include <stdio.h>

int main(){

FILE * fp;
int page_size=4;
size_t read=0;
char * buffer = (char *)malloc((page_size+1)*sizeof(char));
int * buffer_int = (int *)malloc((page_size+1)*sizeof(int));
fp = fopen("/var/nfsshare/matrix10k.dat", "rb"); //open the file for binary input

//loop through the file reading a page at a time
do
{
read = fread(buffer_int,sizeof(int),page_size, fp); //issue the read call

if (read > 0) //if return value is > 0
{
    buffer_int[page_size]='\0';
    printf("|%d|\n",buffer_int);
}

}
while(read == page_size); //end when a read returned fewer items
fclose(fp);
return(0);
}
