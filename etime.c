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

//void et(int);
//void ep(char);
void mm_bench(int);

double etime(int memory){

    struct timeval  start, end , compute;


    gettimeofday( &start, NULL );
    //et(memory);
    gettimeofday( &end, NULL );
    timersub(&end,&start,&compute);
   // fprintf(stderr,"Hello from et\n took %d.%06d sec\n",compute.tv_sec,compute.tv_usec);
    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;

}

double etime2(char op){

    struct timeval start, end;

    gettimeofday( &start, NULL );
   	//ep(op);
    gettimeofday( &end, NULL );

    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;

}

double etime3(int threads){
    struct timeval start, end;

    gettimeofday( &start, NULL );
   	mm_bench(threads);
    gettimeofday( &end, NULL );

     double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
            return seconds;
}




int main(int argc, char*argv[]){
	//char *writeOp=argv[1];
	//char operation=' ';
	
	//char op=(char)writeOp;
	//int memory=atoi(argv[2]);
	int noThreads=atoi(argv[1]);
	
	//printf("%s\n",writeOp);
	printf("%d\n",noThreads);
	
/*	if(!strcmp(writeOp,"-b")){*/
/*		operation='b';*/
/*    }*/
/*    if(!strcmp(writeOp,"-a")){*/
/*			operation='a';*/
/*    	}*/
    //int* ptr;
    // Dynamically allocate memory using calloc()
    //ptr = (int*)calloc(argv[2], sizeof(int));
    
    //double x = etime(memory);
    //double x = etime2(operation);
    double x = etime3(noThreads);
    
    //printf("%d.%06d",x);
    printf("%f",x);

  
    
}


