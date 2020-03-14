//Name:kevin Wilczynski
//Project: Launch Tube
//description: implents a pipe for basic message passing



#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

#define BUFF 64
/*
● The program allocates a pipe (see pipe(2))
● The program forks two children
● The parent process prints the PID of both children on stderr (see fprintf(3))
● The parent process closes access to the pipe and the child processes wires the
pipe to allow for inter-process communication (see dup2(2))
  ○ via the standard stdout-stdin approach (see close(2))
● The first process executes the first command, and the second process executes the second command (see ​execve(2))
  ○ for the first iteration keep it simple — i.e., the child has no command line args
  ○ enhance your program to allow for an arbitrary number of command line args
● The program prints the return value of the first child and then the second child on stderr

*/

void print_pid(pid_t ch1,pid_t ch2);//Prints Child PID
void RetValue(int retVal1,int retVal2);//Print RetVals

int main(int argc, char * argv[]) {
        char write_msg[BUFF]="im kevin";
        char read_msg[BUFF];
      //  int pipe[argc];
        int fd[2];
        int status1=0;
        int status2=0;
        pid_t child1,child2 ;




        if(pipe(fd)==-1){
          fprintf(stderr,"Pipe failed");
          return 1;
        }

        child1=fork();
        child2=fork();

        if((child1&&child2)>0){
          close(fd[READ_END]);
          write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
          close(fd[WRITE_END]);
        }else{
          close(fd[WRITE_END]);
          read(fd[READ_END],read_msg,BUFF);
          printf("HI %s",read_msg);
          close(fd[READ_END]);
        }



        if(child1==0 && child2==0){
          printf("Child processes\n");
        }else if((child1 > 0) && (child2 > 0)){
            waitpid(child1,&status1,WUNTRACED);
            waitpid(child2,&status2,WUNTRACED);
            print_pid(child1,child2);
        }
        RetValue(status1,status2);

        return 0;
}

void print_pid(pid_t ch1,pid_t ch2){
    fprintf(stderr, "Child 1 PID: %d\n", ch1);
    fprintf(stderr, "Child 2 PID: %d\n", ch2);
}

void RetValue(int retVal1,int retVal2){
  printf("Return Value: %d\n", retVal1);
  printf("Return Value: %d\n", retVal2);
}
