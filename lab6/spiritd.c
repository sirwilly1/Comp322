#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <signal.h>
#include <syslog.h>
#include <limits.h>
#include <unistd.h>

pid_t mole1,mole2;

int running = 1;

static void signal_handler(int sig);
void CreateRandomMole();

int main(int argc, char **argv){
  pid_t pid;
    printf("start\n");

        //pid_t pid,sid;
        pid_t sid;
        struct rlimit rl;

        int fd0,i;
        pid = fork();
        if(pid < 0) {
           printf("pid < 0\n");
                printf("fork failed!\n");
                exit(EXIT_FAILURE);
        }

        if(pid > 0) {
           printf("pid > 0\n");
            exit(EXIT_SUCCESS);
        }

        printf("made it past pid > 0\n");

        umask(0);

        signal(SIGTERM, signal_handler);
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);

printf("past sigs\n");


        if ((sid = setsid()) < 0) {
            printf("inside  setsid\n");
                exit(EXIT_FAILURE);
        }
          printf("past setsid\n");
      //  chdir("/");
        if ((chdir("/")) < 0) {
                exit(EXIT_FAILURE);
        }

        printf("past chdir\n");

        getrlimit(RLIMIT_NOFILE, &rl);
        if (rl.rlim_max == RLIM_INFINITY) {
                rl.rlim_max = 1024;
        }
        for (i = 0; i < rl.rlim_max; i++) {
          printf("in the loop\n");
          printf("%i",i);
                close(i);
        }
      printf("out of the for loop\n");

        fd0 = open("/dev/null", O_WRONLY);
        // if ((fd0 = open("/dev/null", O_WRONLY)) < 0) {
        //         perror("log");
        // }

        dup2(fd0, 0);
        dup2(fd0, 1);
        dup2(fd0, 2);


printf("before wile loop\n");
        // Deamon begins!
        while(running) {
           printf("running \n");
                sleep(1);
        }

        return 0;
}

static void signal_handler(int sig){
   printf("signal_handler \n");
        switch(sig) {
        case SIGTERM:
        printf("inside SIGTERM!\n");
                kill(mole2, SIGTERM);
                kill(mole1, SIGTERM);
                  exit(EXIT_SUCCESS);
                exit(0);

        case SIGUSR1:
        printf("inside SIGUSR1!\n");
                CreateRandomMole();
                kill(mole1, SIGKILL);

        case SIGUSR2:
        printf("inside SIGUSR2!\n");
                CreateRandomMole();
                kill(mole2, SIGKILL);
        }
}

void CreateRandomMole(){
  printf("Inside CreateRandomMole\n");
        int random = (rand() % 2);
        char Molnum[16];
        sprintf(Molnum, "%d", random + 1);
        char *moleArg[] = {"mole", Molnum, 0};
        if(random == 1) {
          printf("inside random\n");
                mole1 = fork();

                if(mole1 == 0) {
                  printf("inside mole1!\n");
                        execv(moleArg[0],moleArg);
                }
                else{
                        mole2 = fork();
                        if(mole2 == 0) {
                          printf("inside mole2\n");
                                execv(moleArg[0],moleArg);

                        }
                }

        }
}



/*
   These coding standards include:
   1. Set the file creation mask to 0
   2. Fork and have the parent exit
   3. Create a new session
   a. create a new process group
   4. Change the current working directory to be “/”
   5. Close all unneeded file descriptors
   6. Reopen the standard file descriptors to map to /dev/null
   (see umask(2)) (see fork(2)) (see setsid(2))
   (see chdir(2)) (see getrlimit(2)) (see dup(2))
 */
