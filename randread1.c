#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BILLION 1000000000L
int main()
{

 int m1[8192], k,j,elems,i;
 int diff;
struct timespec start, end;
elems = (sizeof(m1))/(sizeof(int));  //calculating and storing thre value of size of array

 int m2[8192];          //creating 2nd array to clear L1
   
     for(k=0;k<elems;++k)
     { m1[k]=k;}

                             //shuffling the elements of array m1
    if (elems > 1) {
        int i;
	for (i = 0; i < elems - 1; i++) {
	int j = i + rand() / (RAND_MAX / (elems - i) + 1);
	  int t = m1[j];
	  m1[j] = m1[i];
	  m1[i] = t;        	}
    }


if(elems>8192)                       //clearing L1 as the array is already accessed earlier
       {for(i=0;i<8192;++i)
            {j=m2[i];}
       }
i = 0;
j = 0;
clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
while(i < elems)  //reading the elements from m1 randomly traversing through the shuffled index values
      {
	j = m1[j];
	i++;
      }
	clock_gettime(CLOCK_MONOTONIC, &end); /* mark finish time */
diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
diff = diff/(elems);  //calculating the access time per data point
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
return 0;
}
