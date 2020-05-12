#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <string.h>

int signalIndex(char *input);
void catcher(int sig);
int count();

char *Signals[] = {  "","HUP", "INT", "QUIT", "ILL", "TRAP",
                     "ABRT", "BUS", "FPE", "KILL", "USR1",
                     "SEGV", "USR2", "PIPE", "ALRM", "TERM",
                     "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                     "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                     "VTALRM", "PROF", "WINCH"};

static int counter = 0;
int TermListCount = 0;
int arrysize=(int)(sizeof(Signals) / sizeof(Signals[0]));

int main(int argc, char *argv[]){

        if(argc < 2) {
                printf("Input required exiting....");
                return 0;
        }
        for(int i = 1; i < argc; i++) {
                int index = signalIndex(argv[i]);
                if(index == -1) {
                        exit(EXIT_FAILURE);
                }
                signal(index, catcher);
        }
        fprintf(stderr, "%s: $$ = %d\n", argv[0], getpid());

        while(TermListCount != 3) {
                pause();
        }

        return 0;
}

int count(){
        counter++;
        return counter;
}

void catcher(int input){
        signal(input, catcher);
        count();
        time_t t1;
        time(&t1);

        if(input == SIGTERM) {
                TermListCount++;
                if(TermListCount == 3) {
                        fprintf(stderr, "catcher: Total signals count = %d\n", counter);
                }
                else{
                        printf("SIG%s caught at %ld\n", Signals[input],t1);
                }
        }
        else{
                TermListCount = 0;
        }
}

int signalIndex(char *input){
        for(int k = 1; k <= arrysize; k++) {
                if(strcasecmp(input, Signals[k]) == 0) {
                        return k;
                }
        }
        return -1;
}
