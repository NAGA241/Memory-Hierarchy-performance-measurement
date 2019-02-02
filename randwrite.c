#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdint.h>
int main()
{
   int m1[524288]; //initialising array m1
 double diff;
int t,j,i,k,elems ;
struct timespec start, end;
elems = (sizeof(m1))/(sizeof(int));  //calculating and storing thre value of size of array
 int m2[8192];          //creating 2nd array to clear L1
for(i=0;i<elems;i++) 
    {
       m1[i] = i;        //setting array m1 with successive values of indices
    }
 srand(time(0));

   for(i=0;i<elems;i++) //shuffling the elements of array m1
           {       
      k = i + rand() / (RAND_MAX / (elems - i) + 1);
	t=m1[k];
	m1[k]= m1[i];            
	m1[i] = t;
	   }
if(elems>8192)                       //clearing L1 as the array is already accessed earlier
       {for(i=0;i<8192;++i)
            {j=m2[i];}
       }
	   
 j=0;
k=0;
clock_gettime(CLOCK_MONOTONIC, &start); //marking the start time
//writing the elements into m1 randomly traversing through the shuffled index values
for(i=0;i<elems;i++)
	{          
	k= m1[j];
	 m1[j] = i;
	j = k;

	}

clock_gettime(CLOCK_MONOTONIC, &end);//marking the ending time

diff= ((end.tv_sec - start.tv_sec) * 1000000000) + (end.tv_nsec - start.tv_nsec); 
diff= diff/elems;	     //calculating the access time per data point
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

    return 0;
}
