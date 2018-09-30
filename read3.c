#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
  FILE* fp;
  //char buf[bufSize];
  int bufSize = strtol(argv[2], NULL, 10);
  int buf[bufSize];
  if (argc != 3)
  {
    fprintf(stderr,
            "Usage: %s <soure-file>\n", argv[0]);
    return 1;
  }
  if ((fp = fopen(argv[1], "rb")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }
  fread(buf, sizeof(buf), 1, fp);  
   
  for (int i = 0; i < bufSize; i++) {
      printf("%d\n", buf[i]);
  } 
  fclose(fp);
  return 0;
}
