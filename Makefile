CC = gcc
CFLAGS = -Wall 

all: randread1 randwrite linearread linearwrite

randread1: randread1.c   
	$(CC) $(CFLAGS) -o randread1 randread1.c  

randwrite: randwrite.c
	$(CC) $(CFLAGS) -o randwrite randwrite.c
linearread: linearread.c 
	$(CC) $(CFLAGS) -o linearread  linearread.c 

linearwrite: linearwrite.c 
	$(CC) $(CFLAGS) -o randomwrite linearwrite.c  
clean:
	rm -f random *.o *~
	rm -f randomread *.o *~
	rm -f random *.o *~
	rm -f randomread *.o *~
