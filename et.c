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

void* func(void* arg)
{
    pthread_detach(pthread_self()); 
}
  
void et(int mem)
{
    pthread_t *ptid;
	ptid=calloc(mem,sizeof(pthread_t *));  
	
    // Creating a new thread 
    for(int i=0;i<mem;i++)
    	pthread_create(&ptid[i], NULL, func, NULL);
    printf("\nhello from et ");
    for(int i=0;i<mem;i++)
    	pthread_join(ptid[i], NULL);
    printf("\n");
}
  






