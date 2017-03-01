

//1) initialzation of arrays
//2) n array
//3) using precision
//4) r loop
//5) repeat application 

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h> 

typedef struct {
	float t;
	float p;
	float v;
} mytype_t;

void matmul (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]){
	int i, j, k;
	for(i = 0; i < n ; i++){
		c[i][j].t = 0.0f;
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++){
				c[i][j].t += a[i][k].t * b[k][j].t;
				c[i][j].p += a[i][k].p * b[k][j].p;
				c[i][j].v += a[i][k].v * b[k][j].v;
			}
		}
	}
}

extern void KERNEL (int n, float a[n])


void orig (int n, float a[n], int ind )

void interch (int n, float a[n], int ind[n], float b[n], )

static void init_vector(int n, float* a){
	int i;
	for(i = 0; i < n; i++){
		a[i] = ((float)rand()) / RAND_MAX;
	}
}

static void init_ind(int n, int a[n]){
	int i;
	for(i=0; i < n; i++){
		ind[i] = rand() % n;
	}
}

static void init_matrix(int n, float a[n]){
	int i, j;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < n; j++)
		{
			a[i][j] = ((float)rand()) / RAND_MAX;
		}
	}
}

static void print_matrix (int n, float a[n][n]) {
	int i, j;
	for (int i = 0; i < count; ++i)
	{
		printf("%f\n", a[i][j]);
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
	int n = atoi(argv[1]);
	int r = atoi(argv[2]);
	

	//
	struct timeval debut_calcul, fin_calcul, duree_calcul;
	FILE* output = fopen("OUTPUT/temps_execution.txt","a+");


	//allocate arrays
	float *a = malloc (n * sizeof *a);
	int * ind = malloc (n * sizeof *ind);
	float *b = malloc (n * sizeof *b);
	float *pc = malloc (n * n * );

	//init arrays
	srand(0);






	//Temps avant boucle
	gettimeofday(&debut_calcul, NULL);

	for(i=0; i<n; i++){
		stock = n*42 + 30;
	}

	//Temps après boucle
	gettimeofday(&fin_calcul, NULL);

	timersub(&fin_calcul, &debut_calcul, &duree_calcul);
	fprintf(output, "%d %f\n", n,
			(double) (duree_calcul.tv_sec) + (duree_calcul.tv_usec / 1000000.0));

	free(a);
	free(ind);
	free(b);
	free(pc);

	return 0;
}