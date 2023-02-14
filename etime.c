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

void et(int);
void ep(int);
//void mm_bench();

double etime(int memory){

    struct timeval  start, end , compute;


    gettimeofday( &start, NULL );
    et(memory);
    gettimeofday( &end, NULL );
    timersub(&end,&start,&compute);
   // fprintf(stderr,"Hello from et\n took %d.%06d sec\n",compute.tv_sec,compute.tv_usec);
    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;

}

double etime2(int size){

    struct timeval start, end;


    gettimeofday( &start, NULL );
   // ep(size);
    gettimeofday( &end, NULL );

    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;

}

double etime3(){
    struct timeval start, end;


    gettimeofday( &start, NULL );
   // mm_bench();
    gettimeofday( &end, NULL );

     double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;
}




int main(int argc, char*argv[]){
	char *writeOp=argv[1];
	int memory=atoi(argv[2]);
	printf("%s\n",writeOp);
	printf("%d\n",memory);
    //int* ptr;
    // Dynamically allocate memory using calloc()
    //ptr = (int*)calloc(argv[2], sizeof(int));
    double x = etime(memory);
    printf("%d.%06d",x);

  
    
}


