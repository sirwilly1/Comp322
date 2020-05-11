
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv){
  FILE *Log = fopen("~/lab6.log", "w+");
  fprintf(Log, "Pop %s\n", argv[0]);
  fclose(Log);
  return 0;
}
