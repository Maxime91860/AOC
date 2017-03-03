

CC=gcc
CFLAGS=-g -O2 -Wall
OPT_FLAGS=
#= -march=native -Ofast -ffast-math
CFLAGS_KERNEL=-g -Wall $(OPT_FLAGS) 

OBJS=driver.o fluid_mihps.o rdtsc.o

all: fluide

fluide : $(OBJS)
	$(CC) -o $@ $^ -lm

maqao_profile : fluide
	maqao lprof xp=$@ -- ./fluide 250 1

maqao_results_fun : maqao_profile
	maqao lprof -df xp=$^	

maqao_results_loop : maqao_profile
	
	maqao lprof -dl xp=$^

maqao_hints : maqao_profile
	maqao cqa loop=$(IDLOOP) fluide uarch=HASWELL >> hint.txt

fluid_mihps.o : fluid_mihps.c
	$(CC) $(CFLAGS_KERNEL) -c $< 

driver.o : driver.c
	$(CC) $(CFLAGS) -DKERNEL=$(KERNEL) -c $<

rdtsc.o : rdtsc.c
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -rf *.o fluide maqao_profile hint.txt 