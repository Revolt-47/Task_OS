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
# include <semaphore.h>
sem_t sem ;

void initSemaphore(int thread)
{    
		//int value ;
        //sem_init(&sem,0,3); 
        sem_init(&sem, 0, thread);
}

struct Array 
{
	unsigned int startIndexr;
	unsigned int startIndexc;
	unsigned int endIndexr;
	unsigned int endIndexc;
};

unsigned int **first;
unsigned int **second;
unsigned int **result;
int r1=240,c1=240;
int r2=240,c2=240;

void *multiplyMatrices(void * args) {
	struct Array * object_indexes = (struct Array *) args;
	unsigned int startr = object_indexes->startIndexr;
	unsigned int startc = object_indexes->startIndexc;	
	unsigned int endr=object_indexes->endIndexr;
	unsigned int endc=object_indexes->endIndexc;
	
   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
         	sem_wait(&sem ) ;
            result[i][j] += first[i][k] * second[k][j];
            sem_post(&sem);
         }
      }
   }
   
}



void cyclic(int thread)
{
	initSemaphore(thread);
	int noThreads=thread;
	int rows=4;
	pthread_t *threads = calloc(noThreads, sizeof(pthread_t));
	struct Array *obj = calloc(noThreads, sizeof(struct Array));
	
	obj->startIndexr=0;
	obj->startIndexc=0;
	obj->endIndexr=rows-1;
	obj->endIndexc=c1-1;

	while(obj->endIndexr<r1)
	{
		for(int i=0;i<noThreads;i++)
		{
			pthread_create(&threads[i], NULL, multiplyMatrices,(void*) &obj );
			obj->startIndexr=obj->startIndexr+rows;
			obj->endIndexr=obj->endIndexr+rows;
		}
	}
	for(int i=0;i<noThreads;i++)
	{
		pthread_join(threads[i],NULL);
	}
	
	sem_destroy(&sem);
	 printf("The resultant matrix is: \n");
	 for (int i=0;i<r1;i++)
	 {
	 	for(int j=0;j<c1;j++)
	 	{
	 		printf("%d ",result[i][j]);
	 	}
	 	printf("\n");
	}
}

void mm_bench(int noThreads){
    int rows=240;
    int col=240;
    first = calloc(rows, sizeof(unsigned int*));  //dynamic allocation of array
    second = calloc(rows, sizeof(unsigned int*));
    result = calloc(rows, sizeof(unsigned int*));
	for(int i=0;i<rows;i++){
		first[i]=calloc(col,sizeof(unsigned int));
		second[i]=calloc(col,sizeof(unsigned int));
		result[i]=calloc(col,sizeof(unsigned int));
	}

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < col; j++) {
         first[i][j]=j;
         second[i][j]=i+j;
         result[i][j] = 0;
      }
   }
   
	cyclic(noThreads);
}


