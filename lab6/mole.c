
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv){
  FILE *lf = fopen("~/lab6.log", "w+");
  fprintf(lf, "Pop %s\n", argv[0]);
  fclose(lf);
  return 0;
}
