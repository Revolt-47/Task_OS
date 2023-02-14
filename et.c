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
  
void et()
{
    pthread_t ptid;
  
    // Creating a new thread
    pthread_create(&ptid, NULL, &func, NULL);
    printf("\nhello from et");
    pthread_join(ptid, NULL);
}
  
 