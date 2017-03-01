//1) initialzation of arrays
//2) n array
//3) using precision
//4) r loop
//5) repeat application 

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include "kernel.h"



uint64_t rdtsc ();


static void init_array(int n, mytype_t t[n][n])
{
  int i, j;

  for(i=0; i<n; i++){
    for(j=0;j<n; j++){
      t[i][j].t = ((float)rand())/RAND_MAX;
      t[i][j].p = ((float)rand())/RAND_MAX;
      t[i][j].v = ((float)rand())/RAND_MAX;
    }
  }
}


static void print_array(int n, mytype_t t[n][n])
{
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j < n; j++){
			printf("t=%f p=%f v%f\n", t[i][j].t, t[i][j].p, t[i][j].v);
		}
	}
}



int main(int argc, char const *argv[])
{
	// check command line arguments 
	if(argc != 3){
		fprintf(stderr, "Error arguments :\n\tUsage : %s <n> <r>", argv[0]);
	}


	int i;

	// get command line arguments
	int n = atoi(argv[1]); //matrix size
	int r = atoi(argv[2]); //repetition number
	

	//For mesures 
	struct timeval debut_calcul;
	struct timeval fin_calcul;
	struct timeval duree_calcul;
	uint64_t t1;
	uint64_t t2;
	FILE* output = fopen("OUTPUT/temps_execution.txt","a+");


	//allocate arrays
	float *pa = malloc (n * n * sizeof *pa);
	float *pb = malloc (n * n * sizeof *pb);
	float *pc = malloc (n * n * sizeof *pc);

	//define new pointers, casted as 2D arrays
	float (*a)[n] = (float (*)[n]) pa;
	float (*b)[n] = (float (*)[n]) pb;
	float (*c)[n] = (float (*)[n]) pc;



	//init arrays
	srand(42);
	init_array(n, a);
	init_array(n, b);



	//Time before loop
	gettimeofday(&debut_calcul, NULL);
	t1 = rdtsc();


	/*-----------------------------------------------------*/
	/*----------- /!\ Start Warmup /!\ --------------------*/
	/*-----------------------------------------------------*/

/*****///Question prof
	for(i=0; i < r; i++){
		matmul0 (n, a, b, c);
	}

	/*-----------------------------------------------------*/
	/*----------- /!\ End Warmup /!\ ----------------------*/
	/*-----------------------------------------------------*/


	//Time after loop
	gettimeofday(&fin_calcul, NULL);
	t2 = rdtsc();


	//Write time in OUTPUT/temps_execution.txt
	timersub(&fin_calcul, &debut_calcul, &duree_calcul);
	fprintf(output, "%d %f\n", n,
			(double) (duree_calcul.tv_sec) + (duree_calcul.tv_usec / 1000000.0));



	//print performance  
	printf("C : %.2f cycles/MAD\n", (t2 - t1) / ((float) n * n * n * r));

	//print output
	print_array (n , c);

/*****///Question prof
	free(pa);
	free(pb);
	free(pc);

	return 0;
}