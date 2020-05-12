
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  printf("opeing file");
  FILE *Log = fopen("~/lab6.log", "w+");
  fprintf(Log, "Pop %s\n", argv[0]);
  fclose(Log);
  return 0;
}
