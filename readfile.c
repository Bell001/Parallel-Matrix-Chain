#include <stdio.h>
#include <string.h>

int main () {
   size_t bytes_read;
   FILE *fp;
   char buffer[100];

   /* Open file for both reading and writing */
   fp = fopen("/var/nfsshare/matrix10k.dat", "r");
   bytes_read = fread(buffer, sizeof(buffer), 1, fp);
   printf("%s\n", buffer);
   fclose(fp);
   return(0);
}
