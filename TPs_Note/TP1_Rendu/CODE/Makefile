

CC=gcc
CFLAGS=-g -O2 -Wall
#OPT_FLAGS=-march=native
CFLAGS_KERNEL=-g -O3 -Wall $(OPT_FLAGS)

OBJS=driver.o kernel.o rdtsc.o

all: matmul

matmul : $(OBJS)
	$(CC) -o $@ $^

kernel.o : kernel.c
	$(CC) $(CFLAGS_KERNEL) -c $<

driver.o : driver.c
	$(CC) $(CFLAGS) -c $<

rdtsc.o : rdtsc.c
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -rf *.o