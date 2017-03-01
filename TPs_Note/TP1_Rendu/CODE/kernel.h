

#include <stdint.h>
#include <stdlib.h>

typedef struct {
	float t;
	float p;
	float v;
} mytype_t;

void matmul0 (int n, mytype_t a[n][n], mytype_t b[n][n], mytype_t c[n][n]);