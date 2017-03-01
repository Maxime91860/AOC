
CC=gcc
CFLAG=-Wall 

all: executable

executable : CODE/Makefile
	make -C CODE

visu :
	evince PLOT/*

plot: 
	gnuplot SCRIPTS/*.gplot

test0:
	./SCRIPTS/tests_taille.sh

clean :
	rm -rf BIN/*

clean_plot :
	rm -rf PLOT/*

clean_output :
	rm -rf OUTPUT/*

clean_all : clean clean_output clean_plot