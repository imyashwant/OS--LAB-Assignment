#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 


void sighup(); 
void sigint(); 
void sigquit(); 


void main() 
{ 
	int pid; 


	if ((pid = fork()) < 0) { 
		perror("fork"); 
		exit(1); 
	} 

	if (pid == 0) { 
		signal(SIGHUP, sighup); 
		signal(SIGINT, sigint); 
		signal(SIGQUIT, sigquit); 
		for (;;) 
			; 
	}

	else 
	{ 
		printf("\nPARENT: sending End-term Practical\n\n"); 
		kill(pid, SIGHUP); 

		sleep(3); /* pause for 3 secs */
		printf("\nPARENT: sending End-term practical\n\n"); 
		kill(pid, SIGINT); 

		sleep(3); /* pause for 3 secs */
		printf("\nPARENT: sending CHILD-QUIT\n\n"); 
		kill(pid, SIGQUIT); 
		sleep(3); 
	} 
} 


void sighup() 

{ 
	signal(SIGHUP, sighup); 
	printf("CHILD: I have received the message End-term Practical\n"); 
} 


void sigint() 

{ 
	signal(SIGINT, sigint); 
	printf("CHILD:I have received the message End-term Practical\n"); 
} 


void sigquit() 
{ 
	printf("My DADDY has Killed me!!!\n"); 
	exit(0); 
} 

