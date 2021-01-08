/* Name: Ansh Arora
   Roll_Number: 2019022 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <errno.h> 

void func(){
	long sum = 0;
	for(int i=0;i<500000000;i++){
		sum+=i;
	}
	return;
}

extern int errno; 

int main()
{	
	int errnum;
	int arr[10];
	for(int i=0;i<10;i++){
		arr[i] = rand();
	}
	printf("With Mix of Non Soft-Time and Soft Real-Time Values- \n");
	double start = omp_get_wtime();
	for(int i=1;i<=10;i++){
		int x = arr[i-1];
		int cpid = fork();
		if(cpid==0){
			//printf("%d\n",x);
			if(x%2==0){
				long errval = syscall(441,getpid(),i*100);
				if(errval!=0){
					errnum = errno;
					fprintf(stderr,"Value of errno: %d\n", errno);
					perror("ERROR");
					fprintf(stderr,"Error encountered: %s\n", strerror(errnum));
				}
			}
			func();
			double time = omp_get_wtime() - start;
			if(x%2==0){
				printf("%d. with RT %f seconds \n",i,time);
			}
			else{
				printf("%d. %f seconds \n",i,time);
			}
			exit(0);
		}
	}
	for(int i=1;i<=10;i++){
		wait(NULL);
	}

	return 0;
}