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

//void et();
void ep();
//void mm_bench();

double etime(){

    struct timeval start, end;


    gettimeofday( &start, NULL );
    //et();
    gettimeofday( &end, NULL );

     double seconds = (end.tv_sec - start.tv_sec);
     
            return seconds;

}

double etime2(){

    struct timeval start, end;


    gettimeofday( &start, NULL );
    ep();
    gettimeofday( &end, NULL );

     double seconds = (end.tv_sec - start.tv_sec);

            return seconds;

}

double etime3(){
    struct timeval start, end;


    gettimeofday( &start, NULL );
   // mm_bench();
    gettimeofday( &end, NULL );

     double seconds = (end.tv_sec - start.tv_sec);

            return seconds;
}




int main(){

    //int* ptr;
    // Dynamically allocate memory using calloc()
    //ptr = (int*)calloc(argv[2], sizeof(int));
    double x = etime2();
    printf("%f",x);

  
    
}