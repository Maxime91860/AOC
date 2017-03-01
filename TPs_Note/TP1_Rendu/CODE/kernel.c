


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

//Structure to array
void matmul2(int n, float a_t[n][n], float b_t[n][n], float c_t[n][n],
                   float a_p[n][n], float b_p[n][n], float c_p[n][n],
                   float a_v[n][n], float b_v[n][n], float c_v[n][n])
{
	int i, j, k;
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
}