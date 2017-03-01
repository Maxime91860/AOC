//1) initialzation of arrays
//2) n array
//3) using precision
//4) r loop
//5) repeat application 

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
// #include <sys/time.h>


typedef struct {
	float t;
	float p;
	float v;
} mytype_t;


uint64_t rdtsc ();
void matmul0 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]);
void matmul1 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]);


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

static void init_array2(int n, float t[n][n])
{
  int i, j;

  for(i=0; i<n; i++){
    for(j=0;j<n; j++){
      t[i][j] = ((float)rand())/RAND_MAX;
    }
  }
}

static void print_array(int n, mytype_t t[n][n])
{
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j < n; j++){
			printf("t=%f p=%f v=%f\n", t[i][j].t, t[i][j].p, t[i][j].v);
		}
	}
}

static void print_array2(int n, float t[n][n], float p[n][n], float v[n][n])
{
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j < n; j++){
			printf("t=%f p=%f v=%f\n", t[i][j], p[i][j], v[i][j]);
		}
	}
}



int main(int argc, char const *argv[])
{
	// check command line arguments 
	if(argc != 3){
		fprintf(stderr, "Error arguments :\n\tUsage : %s <n> <r>\n", argv[0]);
		exit(-1);
	}


	int i;

	// get command line arguments
	int n = atoi(argv[1]); //matrix size
	int r = atoi(argv[2]); //repetition number
	

	//For mesures 
	// struct timeval debut_calcul;
	// struct timeval fin_calcul;
	// struct timeval duree_calcul;
	uint64_t t1;
	uint64_t t2;
	// FILE* output = fopen("OUTPUT/temps_execution.txt","a+");


	//allocate arrays
	mytype_t *pa = malloc (n * n * sizeof *pa);
	mytype_t *pb = malloc (n * n * sizeof *pb);
	mytype_t *pc = malloc (n * n * sizeof *pc);

	//define new pointers, casted as 2D arrays
	mytype_t (*a)[n] = (mytype_t (*)[n]) pa;
	mytype_t (*b)[n] = (mytype_t (*)[n]) pb;
	mytype_t (*c)[n] = (mytype_t (*)[n]) pc;


	//Struct to Array
	//allocate arrays
	float *pa_t = malloc (n * n * sizeof *pa_t);
	float *pa_p = malloc (n * n * sizeof *pa_p);
	float *pa_v = malloc (n * n * sizeof *pa_v);

	float *pb_t = malloc (n * n * sizeof *pb_t);
	float *pb_p = malloc (n * n * sizeof *pb_p);
	float *pb_v = malloc (n * n * sizeof *pb_v);

	float *pc_t = malloc (n * n * sizeof *pc_t);
	float *pc_p = malloc (n * n * sizeof *pc_p);
	float *pc_v = malloc (n * n * sizeof *pc_v);

	//define new pointers, casted as 2D arrays
	float (*a_t)[n] = (float (*)[n]) pa_t;
	float (*a_p)[n] = (float (*)[n]) pa_p;
	float (*a_v)[n] = (float (*)[n]) pa_v;

	float (*b_t)[n] = (float (*)[n]) pb_t;
	float (*b_p)[n] = (float (*)[n]) pb_p;
	float (*b_v)[n] = (float (*)[n]) pb_v;

	float (*c_t)[n] = (float (*)[n]) pc_t;
	float (*c_p)[n] = (float (*)[n]) pc_p;
	float (*c_v)[n] = (float (*)[n]) pc_v;


	//init arrays
	srand(42);
	init_array(n, a);
	init_array(n, b);

	//Copy the struc in the array
	int j;
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			a_t[i][j] = a[i][j].t;
			a_p[i][j] = a[i][j].p;
			a_v[i][j] = a[i][j].v;

			b_t[i][j] = b[i][j].t;
			b_p[i][j] = b[i][j].p;
			b_v[i][j] = b[i][j].v;
		} 
	}



	//Warm up
	for(i=0; i < 2; i++){
		// KERNEL (n, a, b, c);
		KERNEL(n, a_t, b_t, c_t, a_p, b_p, c_p, a_v, b_v, c_v);
	}

	//Time before loop
	// gettimeofday(&debut_calcul, NULL);
	t1 = rdtsc();


	/*-----------------------------------------------------*/
	/*----------- /!\ Start Kernel /!\ --------------------*/
	/*-----------------------------------------------------*/

	for(i=0; i < r; i++){
		// KERNEL (n, a, b, c);
		KERNEL(n, a_t, b_t, c_t, a_p, b_p, c_p, a_v, b_v, c_v);
	}

	/*-----------------------------------------------------*/
	/*----------- /!\ End Kernel /!\ ----------------------*/
	/*-----------------------------------------------------*/


	//Time after loop
	// gettimeofday(&fin_calcul, NULL);
	t2 = rdtsc();


	//Write time in OUTPUT/temps_execution.txt
	// timersub(&fin_calcul, &debut_calcul, &duree_calcul);
	// fprintf(output, "%d %f\n", n,
			// (double) (duree_calcul.tv_sec) + (duree_calcul.tv_usec / 1000000.0));

	//print performance  
	printf("Perf : %.2f cycles / iteration\n", (t2 - t1) / (((float) n) * n * n * r));

	//print output
	// print_array (n , c);
	// print_array2(n, c_t, c_p, c_v);

	free(pa);
	free(pb);
	free(pc);

	return 0;
}