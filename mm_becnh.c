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

void multiplyMatrices(int first[][240],int second[][240],int result[][240],int r1, int c1, int r2, int c2) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         result[i][j] = 0; 
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

void mm_bench(){
    int first**;
    int second**;
    int result**;
    int rows=240;
    int col=240;
    first = calloc(rows, sizeof( int*));  //dynamic allocation of array
    second = calloc(rows, sizeof( int*));
    result = calloc(rows, sizeof( int*));
	for(int i=0;i<r;i++){
		first[i]=calloc(col,sizeof( int));
		second[i]=calloc(col,sizeof( int));
		result[i]=calloc(col,sizeof( int));
	}
		

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < col; j++) {
         first[i][j]=i+j;
         second[i][j]=i+j;
      }
   }

   multiplyMatrices(first,second,result,240,240,240,240);
}


