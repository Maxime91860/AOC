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

	// //define new pointers, casted as 2D arrays
	// float (*a_t)[n] = (float (*)[n]) pa_t;
	// float (*a_p)[n] = (float (*)[n]) pa_p;
	// float (*a_v)[n] = (float (*)[n]) pa_v;

	// float (*b_t)[n] = (float (*)[n]) pb_t;
	// float (*b_p)[n] = (float (*)[n]) pb_p;
	// float (*b_v)[n] = (float (*)[n]) pb_v;

	// float (*c_t)[n] = (float (*)[n]) pc_t;
	// float (*c_p)[n] = (float (*)[n]) pc_p;
	// float (*c_v)[n] = (float (*)[n]) pc_v;

		// KERNEL(n, a_t, b_t, c_t, a_p, b_p, c_p, a_v, b_v, c_v);

	// //Copy the struc in the array
	// int j;
	// for(i=0; i < n; i++){
	// 	for(j=0; j < n; j++){
	// 		a_t[i][j] = a[i][j].t;
	// 		a_p[i][j] = a[i][j].p;
	// 		a_v[i][j] = a[i][j].v;

	// 		b_t[i][j] = b[i][j].t;
	// 		b_p[i][j] = b[i][j].p;
	// 		b_v[i][j] = b[i][j].v;
	// 	} 
	// }

	mytype_t (*bt)[n] = transposee (n, b);


static void print_array2(int n, float t[n][n], float p[n][n], float v[n][n])
{
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j < n; j++){
			printf("t=%f p=%f v=%f\n", t[i][j], p[i][j], v[i][j]);
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

//Calcul de la transposée d'une matrice carrée
mytype_t* transposee (int n, mytype_t A[n][n]){

	mytype_t *pat = malloc (n * n * sizeof *pat);
	mytype_t (*At)[n] = (mytype_t (*)[n]) pat;
	int i, j; 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			At[j][i] = A[i][j];
		}
	}
	return At;
}