

CC=gcc
CFLAGS=-g -O2 -Wall
OPT_FLAGS=-march=native -Ofast
CFLAGS_KERNEL=-g -O3 -Wall $(OPT_FLAGS) 

OBJS=driver.o kernel.o rdtsc.o

all: matmul

matmul : $(OBJS)
	$(CC) -o $@ $^

maqao_profile : matmul
	maqao lprof xp=$@ -- ./matmul 800 1

maqao_results : maqao_profile
	maqao lprof -df xp=$^
	maqao lprof -dl xp=$^	

maqao_hints : maqao_profile
	maqao cqa loop=$(IDLOOP) matmul uarch=HASWELL >> hint.txt

kernel.o : kernel.c
	$(CC) $(CFLAGS_KERNEL) -c $<

driver.o : driver.c
	$(CC) $(CFLAGS) -DKERNEL=$(KERNEL) -c $<

rdtsc.o : rdtsc.c
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -rf *.o matmul maqao_profile hint.txt 