//Name:kevin Wilczynski
//Project: time-4-baby-and-me
//description: Program that forks and print parent and child process info.


#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_report(pid_t cp, int status);

int main(){
								//Var declations
								int Start,Stop,Status;
								pid_t ProssId,retval;
								struct tms t;

								Start = time(NULL);
								printf("START: %d\n", Start);
								ProssId = fork();//Fork happens here

								//Begining of logic
								if(ProssId<0){
																printf("%s\n","FAIL");
																exit(EXIT_FAILURE);
								}else if(ProssId == 0) {
																retval = waitpid(ProssId, &Status, WUNTRACED); // Wait for child/parent
																print_report(retval,-1);
																exit(EXIT_SUCCESS);
								}else{
																retval = waitpid(ProssId, &Status, WUNTRACED); // Wait for child
																print_report(retval,Status);
																printf("USER: %lu , SYS: %lu \n", t.tms_utime,t.tms_stime);
																printf("CUSER: %lu , CSYS: %lu \n",t.tms_cutime,t.tms_cstime);
																Stop = time(NULL);
																printf("STOP: %d\n", Stop);
								}
								return 0;
}
void print_report(pid_t cp, int status){

								if(status==-1) {
																printf("PPID: %d, PID: %d",  getppid(),getpid());
								}else{
																printf("\nPPID: %d, PID: %d, CPID: %d, RETVAL: %d\n",  getppid(),getpid(), cp, status);
								}

}
