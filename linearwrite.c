#pragma GCC push_options
#pragma GCC optimize ("O0")
#include <stdio.h>
#include <time.h>
#define BILLION 1000000000L

                        //creating a structure of one cache line size
struct car
{
 int arr[16];
};

int main()
{
int diff;
struct timespec start, end;
struct car m1[1024], car1; //initialising array m1 and a structure variable car1
int i, elems;

for(i=0;i<16;i++)
{car1.arr[i]=i;    }

elems = (sizeof(m1))/(sizeof(struct car)); //calculating and storing thre value of size of array
     
 
clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

    for(i=0; i<elems; i++)           //writing the value of structure variable car1 into array m1 
	     {
	      m1[i]=car1 ;
	     }
	clock_gettime(CLOCK_MONOTONIC, &end);
	
diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
diff = diff/(elems);    //calculating the access time per data point
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

     return 0;
}

#pragma GCC pop_options





