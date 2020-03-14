//Name:kevin Wilczynski
//Project: Launch Tube
//description: Forks and prints out basic info on child



#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



void child_pross(pid_t child_pross);
void retval_print(int _retval);

int main(int argc, char * argv[]) {
        pid_t ProssId, retval;
        int status;
        //char * ls_args[] = { "/bin/ls" , "-l", NULL};

        ProssId = fork();

        if(argc>=1) {

                if (ProssId < 0) {

                        printf ("%s\n", "FAIL");
                        exit (EXIT_FAILURE);

                }
                else if (ProssId == 0) {
                        execve(argv[1], argv+1, NULL);
                        //execv(argv[1], argv+1);
                        exit(EXIT_SUCCESS);

                }else if(ProssId>0) {

                        retval = waitpid(ProssId, &status, WUNTRACED);
                        child_pross(ProssId);
                        retval_print(status);
                }
        }
        return 0;
}

void child_pross(pid_t child_pross) {
        fprintf(stderr, "CPID: %d\n", child_pross);
}

void retval_print(int _retval){
        fprintf(stderr, "RetVal: %d\n", _retval);

}
