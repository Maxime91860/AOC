


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