#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


extern uint64_t rdtsc();
extern void c_velocitySolver (float *u, float *uOld, float *v, float *vOld, float *curl, float *d, float visc, float dt, int grid_size, int vector_size);
extern void c_densitySolver (float *d, float *dOld, float diff, float *u, float *v , float dt, int grid_size, int vector_size);


static void init_array (int n, float a[n]) {
  int i;

  for (i=0; i<n; i++)
    a[i] = (float) rand() / RAND_MAX;
}

// static void print_array (int n, float a[n]) {
//   int i;

//   for (i=0; i<n; i++)
//     printf ("%f ", a[i]);

//   putchar ('\n');
// }

static void write_array_in_file (int n, float a[n],const char* s) {
  int i;
  FILE *f=fopen(s,"w");
  for (i=0; i<n; i++){
  	fprintf (f,"%f \n", a[i]);
  }
  fclose(f);
}

int main (int argc, char *argv[]) {

  /* Check arguments */
  if (argc != 3) {
    fprintf (stderr, "Usage: %s <grid size> <nb repetitions>\n", argv[0]);
    abort();
  }

  /* Read arguments */
  int n  = atoi (argv[1]);
  int nr = atoi (argv[2]);

  uint64_t t1, t2, t3, tv = 0, td = 0;
  float dt   = 0.2f;
  float visc = 0.0f;
  float diff = 0.0f;
  int size = (n + 2) * (n + 2);

  // Allocates
  float *d    = calloc (size, sizeof *d   );
  float *dOld = calloc (size, sizeof *dOld);
  float *u    = calloc (size, sizeof *u   );
  float *uOld = calloc (size, sizeof *uOld);
  float *v    = calloc (size, sizeof *v   );
  float *vOld = calloc (size, sizeof *vOld);
  float *curl = calloc (size, sizeof *curl);

  srand(0); 
  init_array (size, dOld);
  init_array (size, uOld);
  init_array (size, vOld);

  /* Warm up */
  int r;
  for (r=0; r<2; r++) {
    c_velocitySolver (u, uOld, v, vOld, curl, d, visc, dt, n, size);
    c_densitySolver (d, dOld, diff, u, v, dt, n, size);
  }

  /* Run nr repetitions */
  for (r=0; r<nr; r++) {
    t1 = rdtsc();
    c_velocitySolver (u, uOld, v, vOld, curl, d, visc, dt, n, size);
    t2 = rdtsc();
    c_densitySolver (d, dOld, diff, u, v, dt, n, size);
    t3 = rdtsc();

    tv += t2 - t1;
    td += t3 - t2;
  }


  /* Print timing results */

  write_array_in_file (size, d,"d_optim3.txt");
  write_array_in_file (size, u,"u_optim3.txt");
  write_array_in_file (size, v,"v_optim3.txt");
  puts ("Cycles per element:");
  printf (" - velocitySolver: %.2f\n", (float) tv / (nr * n * n));
  printf (" - densitySolver : %.2f\n", (float) td / (nr * n * n));

  /* Free arrays */
  free (d   );
  free (dOld);
  free (u   );
  free (uOld);
  free (v   );
  free (vOld);
  free (curl);

  return EXIT_SUCCESS;
}
