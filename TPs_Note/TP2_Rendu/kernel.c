
#include <stdlib.h>

typedef struct {
	float t;
	float p;
	float v;
} mytype_t;


void matmul0 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]){
	int i, j, k;
	for(i = 0; i < n ; i++){
		for(j = 0; j < n; j++){
			c[i][j].t = 0.0f;
			c[i][j].p = 0.0f;
			c[i][j].v = 0.0f;
			for(k = 0; k < n; k++){
				c[i][j].t += a[i][k].t * b[k][j].t;
				c[i][j].p += a[i][k].p * b[k][j].p;
				c[i][j].v += a[i][k].v * b[k][j].v;
			}
		}
	}
}

//Change the order of the loop
void matmul1 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]){
	int i, j, k;
	for(j = 0; j < n ; j++){
		for(i = 0; i < n; ++i){
			c[i][j].t = 0.0f;
			c[i][j].p = 0.0f;
			c[i][j].v = 0.0f;
			for(k = 0; k < n; k++){
				c[i][j].t += a[i][k].t * b[k][j].t;
				c[i][j].p += a[i][k].p * b[k][j].p;
				c[i][j].v += a[i][k].v * b[k][j].v;
			}
		}
	}
}

//Change the order of the loop
void matmul2 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]){

	int i, j, k;
	float (*pa_t) = malloc (n * n * sizeof *pa_t);
	float (*pa_p) = malloc (n * n * sizeof *pa_p);
	float (*pa_v) = malloc (n * n * sizeof *pa_v);

	float (*pb_t) = malloc (n * n * sizeof *pb_t);
	float (*pb_p) = malloc (n * n * sizeof *pb_p);
	float (*pb_v) = malloc (n * n * sizeof *pb_v);

	float (*pc_t) = malloc (n * n * sizeof *pc_t);
	float (*pc_p) = malloc (n * n * sizeof *pc_p);
	float (*pc_v) = malloc (n * n * sizeof *pc_v);

	float (*a_t)[n] = (float (*)[n]) pa_t;
	float (*a_p)[n] = (float (*)[n]) pa_p;
	float (*a_v)[n] = (float (*)[n]) pa_v;

	float (*b_t)[n] = (float (*)[n]) pb_t;
	float (*b_p)[n] = (float (*)[n]) pb_p;
	float (*b_v)[n] = (float (*)[n]) pb_v;

	float (*c_t)[n] = (float (*)[n]) pc_t;
	float (*c_p)[n] = (float (*)[n]) pc_p;
	float (*c_v)[n] = (float (*)[n]) pc_v;

	//Copy the struct in the array
	for(i=0; i < n; i++){
		for(j=0; j<n; j++){
			a_t[i][j] = a[i][j].t;
			a_p[i][j] = a[i][j].p;
			a_v[i][j] = a[i][j].v;

			b_t[i][j] = b[i][j].t;
			b_p[i][j] = b[i][j].p;
			b_v[i][j] = b[i][j].v;
		}
	}

	for(j = 0; j < n ; j++){
		for(i = 0; i < n; ++i){
			c_t[i][j] = 0.0f;
			c_p[i][j] = 0.0f;
			c_v[i][j] = 0.0f;
			for(k = 0; k < n; k++){
				c_t[i][j] += a_t[i][k] * b_t[k][j];
				c_p[i][j] += a_p[i][k] * b_p[k][j];
				c_v[i][j] += a_v[i][k] * b_v[k][j];
			}
		}
	}

	for(i=0; i < n; i++){
		for(j=0; j<n; j++){
			c[i][j].t = c_t[i][j];
			c[i][j].p = c_p[i][j];
			c[i][j].v = c_v[i][j];
		}
	}

	free(pa_t);
	free(pa_p);
	free(pa_v);
	free(pb_t);
	free(pb_p);
	free(pb_v);
	free(pc_t);
	free(pc_p);
	free(pc_v);
}