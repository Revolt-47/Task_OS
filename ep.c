#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include<math.h>

void ep(char write)
{

	//char op=(char*)&write;
    pid_t cpid;
    if(write=='b'){
		printf("Thread creation before child is created.\n");
    }
    cpid=fork();
    if (cpid== 0)
        exit(0);           /* terminate child */
    else
        cpid = wait(NULL); /* reaping parent */
        if(write=='a'){
			printf("Thread creation after child is created.\n");
    	}
        
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
    
}


