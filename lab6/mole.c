//
// #include <stdio.h>
// #include <string.h>
// #include <time.h>
// #include <unistd.h>

// int main(int argc, char **argv){
//   FILE *lf = fopen("~/lab6.log", "w+");
//   fprintf(lf, "Pop %s\n", argv[0]);
//   fclose(lf);
//   return 0;
// }
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
    FILE *fp = fopen("/lab6.log", "w+");
    if (fp == NULL) {
        fprintf(stderr, "Lab creation failed");
    }
    if (fp != 0) {
        char *mole;
        if (argc > 1 && strcmp(argv[1], "1") == 0)
            mole = "Pop mole1\n";
        else
            mole = "Pop mole2\n";
        fputs(mole, fp);
    }
    fclose(fp);
    return 0;
}
