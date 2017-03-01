
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
	float (*pa_t)[n] = malloc (n * n * sizeof *pa_t);
	float (*pa_p)[n] = malloc (n * n * sizeof *pa_p);
	float (*pa_v)[n] = malloc (n * n * sizeof *pa_v);

	float (*pb_t)[n] = malloc (n * n * sizeof *pb_t);
	float (*pb_p)[n] = malloc (n * n * sizeof *pb_p);
	float (*pb_v)[n] = malloc (n * n * sizeof *pb_v);

	float (*pc_t)[n] = malloc (n * n * sizeof *pc_t);
	float (*pc_p)[n] = malloc (n * n * sizeof *pc_p);
	float (*pc_v)[n] = malloc (n * n * sizeof *pc_v);

	//Copy the struct in the array
	for(i=0; i < n; i++){
		for(j=0; j<n; j++){
			pa_t[i][j] = a[i][j].t;
			pa_p[i][j] = a[i][j].p;
			pa_v[i][j] = a[i][j].v;

			pb_t[i][j] = b[i][j].t;
			pb_p[i][j] = b[i][j].p;
			pb_v[i][j] = b[i][j].v;
		}
	}

	for(j = 0; j < n ; j++){
		for(i = 0; i < n; ++i){
			pc_t[i][j] = 0.0f;
			pc_p[i][j] = 0.0f;
			pc_v[i][j] = 0.0f;
			for(k = 0; k < n; k++){
				pc_t[i][j] += pa_t[i][k] * pb_t[k][j];
				pc_p[i][j] += pa_p[i][k] * pb_p[k][j];
				pc_v[i][j] += pa_v[i][k] * pb_v[k][j];
			}
		}
	}

	for(i=0; i < n; i++){
		for(j=0; j<n; j++){
			c[i][j].t = pc_t[i][j];
			c[i][j].p = pc_p[i][j];
			c[i][j].v = pc_v[i][j];
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